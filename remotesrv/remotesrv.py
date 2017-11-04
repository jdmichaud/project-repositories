import os
import logging
import ConfigParser

import db
import server

if __name__ == "__main__": 
    FORMAT = "%(asctime)-15s %(message)s"
    logging.basicConfig(format=FORMAT, level=logging.DEBUG)
    
    logging.info("remotesrv starting up")

    logging.info("reading configuation file .remotesrv.rc")
    default = {'port' : 85296, 'db_filename' : os.getcwd() + "/mp3.db", "path" : os.path.expanduser("~/") } 
    config = ConfigParser.ConfigParser(default)
    
    try:
        config.readfp(open(os.path.expanduser(".remotesrv.rc")))
    except IOError:
        logging.info("configuration file does not exist. Using default")

    database = db.db(config.get("main", "db_filename"), config.get("main", "path"))
    port = config.get("main", "port")

    new_files = database.check_database()
    logging.info("found " + str(new_files) + " new files")

    server = server.server(port, database)
    server.serve()

    
