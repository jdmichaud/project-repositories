import mail as _mail
import logging
import config as _config

def respond(address, subject, text, attach = ""):
    _mail.mail("laurence.de.cinqcygne@gmail.com",
               "mariepaul",
               "smtp.gmail.com",
               587,
               address,
               subject,
               text,
               attach)

def usage():
    u = ""
    for command in commands_pool:
        u = u + commands_pool[command][1] + '\n'
    return u

def _usage(mail, command):
    logging.info("usage command")
    respond(mail['From'], "Usage", usage())

def error(mail, command):
    logging.info("syntax error: " + str(command))
    respond(mail['From'], "Syntax Error", usage())

def status():
    import os
    import time
    import datetime

    s = "Report from "
    uname = os.uname()
    now = datetime.datetime.now()
    now = time.mktime(now.timetuple())
    now = datetime.datetime.fromtimestamp(now)
    now = now.ctime()
    s += uname[1] + " - " + uname[2] + ' at ' + now + '\n'

    try:
        f = open( "/proc/uptime" )
        contents = f.read().split()
        f.close()
    except:
        logging.info("Cannot open uptime file: /proc/uptime")
    total_seconds = float(contents[0])
    days    = int( total_seconds / (60 * 60 * 24) )
    hours   = int( ( total_seconds % (60 * 60 * 24) ) / (60 * 60) )
    minutes = int( ( total_seconds % (60 * 60) ) / 60 )
    seconds = int( total_seconds % 60 )
    s += 'uptime: ' + str(days) + ' day(s), ' + str(hours) + ' hour(s), ' + str(minutes) + ' minute(s), ' + str(seconds) + ' second(s)\n'

    import commands
    s += '\n ====== memory report ======\n'
    res = commands.getstatusoutput('free')[1]
    s += res + '\n'

    s += '\n ====== disk report =========\n'
    res = commands.getstatusoutput('df -h')[1]
    s += res + '\n'

    s += '\n ====== process report =====\n'
    res = commands.getstatusoutput('ps')[1]
    s += res + '\n'

    s += "\n\n **** END OF REPORT ****"
    return s


def _status(mail, command):
    logging.info("status command")
    respond(mail['From'], "Status", status())

def _log(mail, command):
    logging.info("log command")
    respond(mail['From'], "Log", "You'll find the logs attached\n\nKind Regards.\n", _config.LOG_FILENAME)
    pass

def geturl(url, filename):
    import urllib
    logging.info('downloading page')
    f = urllib.urlopen(url)
    s = f.read()
    f = open(filename, 'w')
    f.write(s)
    f.close()

def _geturl(mail, command):
    logging.info('get command')
    import re
    import os
    m = re.search('\S+\s+(\S+)', command)
    if m == None:
        return error(mail, command)
    address = m.group(1)
    logging.info('address: ' + address)
    m = re.search('.*/(.*)', address)
    if m == None:
        import tempfile
        filename = tempfile.mkstemp()[1] + '.html'
    else:
        filename = _config.TMP_FOLDER + m.group(1)
        if filename == _config.TMP_FOLDER:
            import tempfile
            filename = tempfile.mkstemp()[1] + '.html'
    try:
        geturl(address, filename)
    except:
        respond(mail['From'], 'geturl error', 'Error retrieving ' + address + '\nHint: must start with http.', filename)
    respond(mail['From'], 'Interesting ' + address, 'This might interest you.\n\nKind Regards.\n', filename)
    os.remove(filename)

def exec_detach(command):
    import os
    import commands

    if os.fork() == 0:
        os.setsid()
        s = command + '\n\n' + '******** start of output *********\n'
        res = commands.getstatusoutput(command)
        s += res[1]
        s +=                   '********* end of output **********'
        if res[0] == 0:
            respond(mail['From'], 'Command executed', s)
        else:
            respond(mail['From'], 'Command failed', s)
        
        raise SystemExit



def _exec(mail, command):
    logging.info('get command')
    import commands
    import re
    m = re.search('\S+\s+(.+)', command)
    if m == None:
        return error(mail, command)
    command = m.group(1)
    exec_detach(command)

def _wol(mail, command):
    logging.info('wol command')
    import wol
    import re
    m = re.search('\S+\s+(\S+)\s+(\S+)', command)
    if m == None:
        return error(mail, command)
    ip_address = m.group(1)
    ethernet_address = m.group(2)
    logging.info('wol ip: ' + ip_address + ' mac: ' + ethernet_address)
    wol.WakeOnLan(ip_address, ethernet_address)
    respond(mail['From'], 'wol command sent', '')

commands_pool = {'usage'  : (_usage, "usage: display this message"),
                 'status' : (_status, "status: give the probe status"),
                 'log' : (_log, "log: retrieve the log file as attachement"),
                 'geturl' : (_geturl, "geturl ADDRESS: retrieve page or file at ADDRESS\nIf the address points to an html page, the page is attached.\nif the address points to a file, the file is downloaded and placed on the probe's web site."),
                 'exec' : (_exec, 'exec COMMAND: execute COMMAND in a shell and return the output'),
                 'wol' : (_wol, 'wol ip_address mac_address: wake up on lan') }
