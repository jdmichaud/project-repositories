#!/usr/bin/python

import sys
import re
import email
import mail as _mail
import logging
import probe_cmds
import time
import config as _config


def treat(item):
    command = _mail.get_text(item)
    mail = email.message_from_string('\n'.join(item[1]))
    m = re.search('(\S+)', command)
    if m == None:
        return probe_cmds.error(mail, command)
    verb = m.group(0)
    try: probe_cmds.commands_pool[verb][0](mail, command)
    except KeyError: 
        try:
            return probe_cmds.error(mail, command)
        except: 
            logging.error("Internal error. Life goes on.")
            logging.error(sys.exc_info())
    except: 
        logging.error("Internal error. Life goes on.")
        logging.error(sys.exc_info())


def poll():
    logging.info("polling")
    items = _mail.pop("laurence.de.cinqcygne@gmail.com",
                      "mariepaul",
                      "pop.gmail.com")

    for item in items:
        treat(item)

if __name__ == "__main__":
    FORMAT = "%(asctime)-15s %(message)s"
    logging.basicConfig(filename=_config.LOG_FILENAME, format=FORMAT, level=logging.DEBUG)
    logging.info("probe starting up")

    #_mail.mail("project.repositories@gmail.com",
    #           "goullote",
    #           "smtp.gmail.com",
    #           587,
    #           "laurence.de.cinqcygne@gmail.com",
    #           "This is a test",
    #           "Text message")

    while 1:
        poll()
        logging.info("sleeping")
        time.sleep(30)
