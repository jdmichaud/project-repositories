#!/usr/bin/python

import os
import sys
import pdb
import unittest
import logging

import poller
import db
import ConfigParser

if __name__ == "__main__":
#pdb.set_trace()
    FORMAT = "%(asctime)-15s %(message)s"
    logging.basicConfig(format=FORMAT)
    
    logging.log("watch starting up")
    
    logging.log("reading configuation file")
    conf_file = "watch.rc"
    global conf_parser = ConfigParser.SafeConfigParser()
    config.readfp(open('watch.rc'))
    
    logging.log("connecting to database...")
    db_conn = None
    db.check_db(conf_parser.get("db", "file"), db_conn)
    logging.log("connected")

    new_video_handler = notifier.NewVideoHandler()
    poller = poller.Poller(conf_parser.get("poller", "directory"), 
                           conf_parser.get("poller", "delay"), 
                           new_video_handler)
    poller.poll() 

    logging.log("watch exiting...")
    

