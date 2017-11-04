#!/usr/bin/python

import pdb
import unittest
import time
import datetime

# local imports
import poller
import notifier
import watch_api
import db

class DbTestCases(unittest.TestCase):
    def __init__(self):
        test_file = time.strftime('/tmp/db_unit_test_%d_%m_%Y_%Hh%Mm%Ss.db')
        
    def test_check_db(self):
        self.db_conn = None
        db.check_db(self.test_file, self.db_conn)
        failUnless(db_conn != None, 'db connection has not been made')
        failUnless(os.path.exists(test_file), 'file ' + test_file + ' should have been created by check_db')
        self.db_conn.close()

        self.db_conn = None        
        db.check_db(self.test_file, self.db_conn)
        failUnless(db_conn != None, 'db connection has not been made')
        failUnless(os.path.exists(test_file), 'file ' + test_file + ' should exist')

        db_conn_fail = None
        self.assertRaises(db.ErrorDBFile, db.check_db, '/cant_write_here.db', db_conn_fail)
        failIf(os.path.exists(test_file), 'file ' + '/cant_write_here.db' + ' should have not been created by check_db')
        failIf(db_conn_fail, 'db connection should not have been created')

    def test_add(self):
        db.add(self.db_conn, datetime.datetime.today(), 'gumstix1', 'camera1', '/tmp/video1')

    def test_get(self):
        db_object = DBObject()
        db.get(self.db_conn, '/tmp/video1', db_object)
        failUnlessRaises(db.UnknownVideo, db.get, self.db_conn, '/tmp/video1', db_object)

    def test_get_list(self):
        l = []
        db.get(self.db_conn, '/tmp/video1', l)
        failIf(len(l) != 1, 'There should be at one element in db. Found ' + str(len(l)))
       
    def test_remove(self):
        db.remove(self.db_conn, '/tmp/video1')
                
class PollerTestClass(unittest.TestCase):
    class new_video_handler():
      def __init__(self):
        flag = False 
      
      def new_video(self, filename):
        print 'new video ' + filename
        self.flag = True

    def __init__(self):
        self.vhandler = new_video_handler() 
        self.poller = poller.Poller('/tmp/', 10, self.vhandler)
        
    def testNewFile(self):
        self.vhandler.flag = False
        test_file = time.strftime('/tmp/new_video_test_%d_%m_%Y_%Hh%Mm%Ss.avi')
        file = open('/tmp/' + test_file, "w")
        file.write("This is the content")
        file.close()
        time.sleep(10)
        failsIf(not self.vhandler.flag, 'The new video has not been polled')

        self.vhandler.flag = False
        test_file2 = time.strftime('/tmp/new_video_test_%d_%m_%Y_%Hh%Mm%Ss.dat')
        file = open('/tmp/' + test_file2, "w")
        file.write("This is the content")
        file.close()
        time.sleep(10)
        failsIf(self.vhandler.flag, 'The new file has been polled as a video. It shouldn\'t have')



if __name__ == "__main__":
    unittest.main()
    
