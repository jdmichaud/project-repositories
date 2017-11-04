import pdb
import logging
from pysqlite2 import dbapi2 as sqlite

class ErrorDBFile(Exception):
  def __init__(self, msg=""):
    pass
  def __str__(self):
    if (msg = ""):
      return "Error DB File"
    else:
      return msg

class UnknownVideo(Exception):
  def __init__(self, msg=""):
    pass
  def __str__(self):
    if (msg = ""):
      return "Unknown video"
    else:
      return msg

def check_db(filename, connection):
    try:
        connection = sqlite.connect(filename)
    except:
        raise ErrorDBFile("Cannot open " + filename)

    cursor = connection.cursor()
    try:
        query = 'SELECT * FROM videos'
        logging.log('DB: ' + query)
        cursor.execute(query)
    except pysqlite2.dbapi2.OperationalError:
        logging.warning("warning: db does not exist. creating it...")
        query = 'CREATE TABLE videos (date        VARCHAR,   \
                                             unit_name   VARCHAR,   \
                                             camera_name VARCHAR,   \
                                             filename    VARCHAR,   \
                                             curve       BLOB);'
        logging.log('DB: ' + query)
        cursor.execute(query)

def add_new_video(connection,
                  date, 
                  unit_name = "", 
                  camera_name = "",
                  filename,
                  curve = ""):
    cursor = connection.cursor()
    query = 'INSERT INTO videos VALUES (' + str(date), ', ' \
                                          + unit_name, ',' \
                                          + camera_name, ',' \
                                          + filename, ',') # no curve for now
    logging.log('DB: ' + query)
    cursor.execute(query)
