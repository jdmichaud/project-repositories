import os
import logging
import ConfigParser
import hashlib
import string
import time

import socket
import db
import player

class server:
    def __init__(self, port, database):
        self.BUFFER_SIZE = 1024
        self.PORT = port
        self.database = database
        self.player = None

    def serve(self):
        s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        ret = 0
        while ret == 0:
            try:
                ret = s.bind(('', string.atoi(self.PORT)))
            except socket.error, e:
                logging.error(str(e) + " -- " + str(ret))
                logging.warning("sleeping 2 seconds")
                time.sleep(2)

        logging.info("listing client on " + self.PORT + " ...")
        
        while 1:
            s.listen(1)
            
            self.conn, addr = s.accept()
            logging.info('Connected to ' + str(addr[0]) + ":" + str(addr[1]))
            
            while 1:
                try:
                    data = self.conn.recv(1024)
                except socket.error, e:
                    logging.error(str(e) + " -- " + str(ret))
                    logging.warning("sleeping 2 seconds")
                    time.sleep(2)
                    break
                    
                if not data: break
            
                # remove CRLF return if any
                if (data[-1] == "\n"):
                    data = data[:-2]
                logging.info("received: [" + data + "]")

                #for i in range(1, len(data)):
                #    print str(i) + ": " + data[i]
                #print data
                data=data.split()
                print data
                if (len(data) == 0):
                    logging.debug("No data received")
                    continue

                if (data[0] == "status"):
                    logging.info("returning status")
                    try:
                        if self.player is None:
                            self.conn.send("wait\n")
                        elif self.player.state == player.PLAY:
                            self.conn.send("play " + player.filename + "\n")
                        elif self.player.state == player.PAUSE:
                            self.conn.send("pause " + player.filename + "\n")
                    except:
                        self.conn.send("wait\n")                        
                elif (data[0] == "hello"):
                    logging.info("handshaking")
                    self.conn.send("hi\n")
                elif (data[0] == "get_database_md5"):
                    statinfo = os.stat(self.database.dbfilename)
                    logging.info("database size: " + str(statinfo.st_size))

                    m = hashlib.md5()
                    buffer = open(self.database.dbfilename, mode='rb').read()
                    m.update(buffer)
                    md5 = m.digest()
                    md5str = ""
                    for i in range(0, len(md5)):
                        if (ord(md5[i]) <= 15):
                            md5str += '0'  # this one comes from far away!!
                        md5str += hex(ord(md5[i]))[2:]
                    logging.info("md5 computed: " + md5str)
                    self.conn.send(md5str + "\n")
                elif (data[0] == "get_database"):
                    self.get_database()
                elif (data[0] == "play"):
                    logging.info("play requested")
                    if len(data) == 1:
                        if self.player is None:
                            logging.info("play requested but no song selected")
                            self.conn.send("no_song_selected\n")
                        else:
                            logging.info("play ...")
                            self.player.state = player.PLAY
                    else:
                        if not self.player is None:
                            self.player.state = player.STOP
                            self.player.join()
                        song = ' '.join(data[1:])
                        logging.info("play " + song + " ...")
                        self.player = player.player(song, self.finish)
                        self.player.state = player.PLAY
                        self.player.start()
                elif (data[0] == "pause"):
                    if self.player is None:
                        logging.info("nothing to pause ...")
                    else:
                        logging.info("pause ...")
                        self.player.state = player.PAUSE
                elif (data[0] == "close"):
                    logging.info("client closed connection")                    
                    break;
                else:
                    logging.debug("Unknown command")
                    self.conn.send("unknown_command\n")

            self.conn.close()

    def get_database(self):
        statinfo = os.stat(self.database.dbfilename)
        logging.info("database size: " + str(statinfo.st_size))
        self.conn.send(str(statinfo.st_size) + "\n")
        file = open(self.database.dbfilename, mode='rb')
        no_data = False
        counter = 0
#        while (not no_data):
        buffer = file.read(statinfo.st_size)
#        counter += len(buffer)
        self.conn.send(buffer)
#        logging.info(str(counter) + " bytes sent on " + str(statinfo.st_size) + " (+" + str(len(buffer)) + ")")
#            if (counter == statinfo.st_size):
#                no_data = True
#        self.conn.send("\n")
        file.close

    def finish(self):
        self.conn.send("finish")
        self.player = None
        
