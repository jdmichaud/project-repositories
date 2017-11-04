import os
import string
import sqlite3
import logging
import fnmatch
import ConfigParser
import MP3Info

from remotesrv import *


class db:
    def __init__(self, dbfilename, path):
        self.dbfilename = os.path.expanduser(dbfilename)
        logging.info("connecting database to : " + self.dbfilename)
        self.conn = sqlite3.connect(self.dbfilename)
        self.conn.text_factory = str
        self.cursor = self.conn.cursor()
        self.TABLE = 'songs'
        self.PATH = os.path.expanduser(path)

        try:
            self.cursor.execute('SELECT COUNT(*) FROM ' + self.TABLE + ';')
        except sqlite3.OperationalError:
            logging.info(self.TABLE + ' table does not exist, creating it')
            self.cursor.execute('CREATE TABLE ' + self.TABLE + 
                                ' (' +
                                '   _id integer primary key autoincrement,' +
                                '   title varchar,' +
                                '   artist varchar,' +
                                '   album varchar,' +
                                '   year varchar,' +
                                '   comment varchar,' +
                                '   genre varchar,' +
                                '   path varchar'
                                ' );'
                               )

    def listFiles(self, dir):
        basedir = dir
        subdirlist = []
        for item in os.listdir(dir):
            if os.path.isfile(os.path.join(basedir, item)):
                if (fnmatch.fnmatch(item, '*.mp3')):
#                    print "item: " + os.path.join(basedir, item)
                    self.mp3s.append(os.path.join(basedir, item))
            else:
                subdirlist.append(os.path.join(basedir, item))
        for subdir in subdirlist:
            self.listFiles(subdir)

    def check_database(self, ):
        logging.info("Walking through " + self.PATH + "... ")
        self.mp3s = []
        self.listFiles(self.PATH)
        count = 0
        for mp3s in self.mp3s:
            if (self.add_file(mp3s) == True):
                count += 1
                if (count % 100 == 0):
                    logging.info(str(count) + " songs registered")
                    self.conn.commit()

        self.conn.commit()
        return count

    def fetch_id3_tag(self, id3info, tag):
        value = ""
        try:
            value = id3info.__dict__[tag]
            if value is None:
                return ""
            value = ''.join(c for c in value if c in string.printable)
            value = value.replace('\"', '')
        except KeyError:
            pass
        return value

    def add_file(self, filename):
        try:
            self.file_in_database
        except AttributeError:
            self.file_in_database = self.get_all_files()
        if (filename,) in self.file_in_database:
            return False
        else:
            try:
                id3info = MP3Info.MP3Info(open(filename, 'rb'))
            except MP3Info.Error, e:
                logging.warning('MP3Info is not reading ' + filename + ' properly')
                logging.warning('fails with "' + str(e) + '"')
                self.insert_item("error",
                                 "error",
                                 "error",
                                 "error",
                                 "error",
                                 "error",
                                 filename)
            else:
                self.insert_item(self.fetch_id3_tag(id3info, 'title'),
                                 self.fetch_id3_tag(id3info, 'artist'),
                                 self.fetch_id3_tag(id3info, 'album'),
                                 self.fetch_id3_tag(id3info, 'year'),
                                 "", #self.fetch_id3_tag(id3info, 'comment'),
                                 self.fetch_id3_tag(id3info, 'genre'),
                                 filename)
            return True

    def get_all_files(self):
        self.cursor.execute('SELECT path FROM ' + self.TABLE + ';')
        files = self.cursor.fetchall()
        logging.info("fetched " + str(len(files)) + " titles")
        return files

    def insert_item(self, title, artist, album, year, comment, genre, path):
        request = 'INSERT INTO ' + self.TABLE + \
                            ' (title, artist, album, year, comment, genre, path) VALUES ( ' + \
                            '"' + title + '", ' + \
                            '"' + artist + '", ' + \
                            '"' + album + '", ' + \
                            '"' + year + '", ' + \
                            '"' + comment + '", ' + \
                            '"' + genre + '", ' + \
                            '"' + path + '" ' + \
                            ');'
        #print request
        self.cursor.execute(request)


