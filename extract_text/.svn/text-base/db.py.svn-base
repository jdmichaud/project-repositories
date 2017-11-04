import sqlite3
import logging

class db:
    def __init__(dbfilename):
        self.dbname = dbfilename
        self.con = sqlite3.connect("mydb")
        self.cursor = conn.cursor()
        self.nn_table_article = 'nn_article'
        self.nn_table_line = 'nn_article_lines'

        try:
            self.cursor.execute('SELECT COUNT(*) FROM ?' + self.nn_table_article + ';')
        except sqlite3.OperationalError:
            logging.info(self.nn_table_article + ' does not exist, creating it')
            self.cursor.execute('CREATE TABLE ' + self.nn_table_article + ' (uid integer);')

        try:
            self.cursor.execute('SELECT COUNT(*) FROM ?' + self.nn_table_line + ';')
        except sqlite3.OperationalError:
            logging.info(self.nn_table_line + ' does not exist, creating it')
            self.cursor.execute('CREATE TABLE ' + self.nn_table_line + ' (uid integer, content text, is_text boolean);')

    def get_newspaper_list():
        self.cursor.execute('SELECT uid, name FROM newspaper')
        return self.cursor.fetchall()

    def get_all_article(newspaperuid):
        self.cursor.execute('SELECT * FROM article WHERE newspaperuid = ' + str(newspaperuid) + ';')
        return self.cursor.fetchall()

    def get_article(uid):
        self.cursor.execute('SELECT * FROM article WHERE uid = ' + str(uid) + ';')
        return self.cursor.fetchall()

    def get_all_unflagged_article():
        self.cursor.execute('SELECT * FROM article WHERE uid NOT IN (SELECT * FROM ' + self.nn_table_article ');')
        return self.cursor.fetchall()

    def is_article_flagged(uid):
        self.cursor.execute('SELECT * FROM ' + self.nn_table_article + ' WHERE uid = ' + str(uid) + ';')
        if (len(self.cursor.fetchone()) > 0):
            return True
        else:
            return False

    def flag_article(uid):
        self.cursor('INSERT INTO ' + self.nn_table_article + ' VALUES ( ' + uid + ' );')
        
    def add_lines(uid, content, is_text):
        if (is_text):
            self.cursor('INSERT INTO ' + self.nn_table_line + ' VALUES ( ' + str(uid) + ', ' + content + ', TRUE );')
        else:
            self.cursor('INSERT INTO ' + self.nn_table_line + ' VALUES ( ' + str(uid) + ', ' + content + ', FALSE );')

