import htmllib
import formatter
import sys
import threading
import train_form_impl
from qt import *

class Paragraph:
    def __init__(self):
        self.text = ''
        self.bytes = 0
        self.density = 0.0

class TrainThread(threading.Thread):
    def __init__(self, stringList):
        threading.Thread.__init__(self)
        self.stringList = stringList
        
    def run(self):
        app = QApplication([""])
        tform = train_form_impl.TrainFormImpl()
        self.stringList.reverse()
        for s in self.stringList:
            print "addString" 
            tform.addString(s)

        tform.show()
#        app.setMainWidget()
        tform.exec_loop()

class LineHolder(formatter.AbstractWriter):
    def __init__(self, *args):
        self.last_index = 0
        self.lines = [Paragraph()]
        formatter.AbstractWriter.__init__(self)
 
    def send_flowing_data(self, data):
        # Work out the length of this text chunk.
        t = len(data)
        # We've parsed more text, so increment index.
        self.index += t
        # Calculate the number of bytes since last time.
        b = self.index - self.last_index
        self.last_index = self.index
        # Accumulate this information in current line.
        l = self.lines[-1]
        l.text += data
        l.bytes += b
 
    def send_paragraph(self, blankline):
        """Create a new paragraph if necessary."""
        if self.lines[-1].text == '':
            return
        self.lines[-1].text += 'n' * (blankline+1)
        self.lines[-1].bytes += 2 * (blankline+1)
        self.lines.append(Paragraph())
 
    def send_literal_data(self, data):
        self.send_flowing_data(data)
 
    def send_line_break(self):
        self.send_paragraph(0)

    def compute_density(self):
        """Calculate the density for each line, and the average."""
        total = 0.0
        for l in self.lines:
            l.density = len(l.text) / float(l.bytes)
            total += l.density
        # Store for optional use by the neural network.
        self.average = total / float(len(self.lines))
 
    def output(self):
        """Return a string with the useless lines filtered out."""
        self.compute_density()
        ans = ""
        for l in self.lines:
            # Check density against threshold.
            # Custom filter extensions go here.
            if l.density > 0.3:
                ans += l.text
        return ans

    def get_manual_answers(self):
        self.output = []
        
        stringList = []
        for line in self.lines:
            if (line.density > 0.2):
                stringList.append(line.text)
        trainThread = TrainThread(stringList)
        trainThread.start()
        trainThread.join()

        for line in self.lines:
            pass

#            print line.text + "\n"
#            print "Is this line, a line of text? (1 = yes, 0 = no): ",
#            self.output.append(input())

        return self.output

class TrackingParser(htmllib.HTMLParser):
    """Try to keep accurate pointer of parsing location."""
    def __init__(self, writer, *args):
        htmllib.HTMLParser.__init__(self, *args)
        self.writer = writer
    def parse_starttag(self, i):
        index = htmllib.HTMLParser.parse_starttag(self, i)
        self.writer.index = index
        return index
    def parse_endtag(self, i):
        self.writer.index = i
        return htmllib.HTMLParser.parse_endtag(self, i)

