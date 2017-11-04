import pdb
import logging
import time

import db

class NewVideoHandler():
  def __init__(self, db_conn):
    self.db_conn = db_conn
    
  def new_video_handler(self, filename):
    logging.log("New video notified: " + filename)
    date_str = time.strftime("%d-%m-%Y %Hh%Mm%Ss") 
    add_new_video(self, self.db_conn, 
                  date_str, 
                  conf_parser.get("general", "gumstix_name"), 
                  conf_parser.get("general", "camera_name"), 
                  filename)
    