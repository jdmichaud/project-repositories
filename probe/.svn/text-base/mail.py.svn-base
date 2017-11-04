#!/usr/bin/python

import smtplib
import poplib
import re
import logging
from email.MIMEMultipart import MIMEMultipart
from email.MIMEBase import MIMEBase
from email.MIMEText import MIMEText
from email import Encoders
import email
import os

gmail_user = "laurence.de.cinqcygne@gmail.com"
gmail_pwd = "mariepaul"

def mail(user,   # "project.repositories@gmail.com"
         passwd, # "goullote"
         server, # "smtp.gmail.com"
         port,   # 587
         to,     # receiver's email
         subject, 
         text, 
         attach = ""):

   logging.info("sending mail to " + to + " [" + subject + "]")
   msg = MIMEMultipart()
   msg['From'] = user
   msg['To'] = to
   msg['Subject'] = subject

   msg.attach(MIMEText(text))

   part = MIMEBase('application', 'octet-stream')
   if (attach != ""):
      part.set_payload(open(attach, 'rb').read())
      Encoders.encode_base64(part)
      part.add_header('Content-Disposition',
                      'attachment; filename="%s"' % os.path.basename(attach))
      msg.attach(part)

   mailServer = smtplib.SMTP(server, port)
   mailServer.ehlo()
   mailServer.starttls()
   mailServer.ehlo()
   mailServer.login(user, passwd)
   mailServer.sendmail(user, to, msg.as_string())
   # Should be mailServer.quit(), but that crashes...
   mailServer.close()
   logging.info("mail sent")

def pop(user,   # "project.repositories@gmail.com"
        passwd, # "goullote"
        server, # "pop.gmail.com"
        port = 995):

   logging.info("poping email " + user)
   mailServer = poplib.POP3_SSL(server, port)
   mailServer.user(user)
   mailServer.pass_(passwd)
   numMessages = len(mailServer.list()[1])
   msgs = []
   for i in range(numMessages):
      msgs.append(mailServer.retr(i+1))
      mailServer.dele(i+1)

   logging.info(str(len(msgs)) + " new message(s)")
   mailServer.quit()
   return msgs
   
def get_text(mail):
   msglines = '\n'.join(mail[1])
   #
   # See if I can parse the message lines with email.Parser
   #
   msg = email.Parser.Parser().parsestr(msglines)
   text = ""
   if msg.is_multipart():
      for part in msg.walk():
         # multipart/* are just containers
         mptype = part.get_content_maintype()
         filename = part.get_filename()
         if mptype == "multipart": continue
         if filename: # Attached object with filename
            attachments.append(email_attachment(messagenum,
                                                attachmentnum,
                                                filename,
                                                part.get_payload(decode=1)))
            print "Attachment filename=%s" % filename
            
         else: # Must be body portion of multipart
            text += part.get_payload()
            
   else: # Not multipart, only body portion exists
      text += msg.get_payload()
      
   return text




if __name__ == "__main__":
   import sys
   import logging
   FORMAT = "%(asctime)-15s %(message)s"
   logging.basicConfig(format=FORMAT, level=logging.DEBUG)
   if len(sys.argv) != 4:
      print "number of arg: " + str(len(sys.argv) - 1)
      print "usage: mail.py address subject text"
      sys.exit(1)
   
   mail(gmail_user, 
        gmail_pwd, 
        "smtp.gmail.com", 
        587, 
        sys.argv[1], 
        sys.argv[2],
        sys.argv[3])
