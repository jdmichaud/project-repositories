import pdb
import logging
import time
import glob

class Poller
  def __init__(self, 
               polling_directory, 
               polling_interval,
               new_video_handler):
    self.polling_directory = polling_directory
    self.polling_interval  = polling_interval
    self.new_video_handler = new_video_handler
    self.last = []
    logging.log("Poller created with polling_directory: " + self.polling_directory  \
                 + " polling_interval: " + str(self.polling_interval))
    
  def poll(self):
    logging.log("start polling")
    
    while True:
      if (self.last == []):
        self.last = glob.glob('*.avi')
      else:
        now = glob.glob('*.avi')
        new = filter(lambda x:x not in self.last, now)
        logging.log("New files: " + str(new))
        for n in new:
          self.new_video_handler.new_video(filename = n)
        self.last = now
        
      logging.log("going to sleep for " + str(self.polling_interval) + "s now...")
      time.sleep(self.polling_interval)
      
      