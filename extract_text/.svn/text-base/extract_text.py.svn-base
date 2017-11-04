#!/usr/bin/python

import re
import os
import sys
import pdb
import urllib
from pyfann import fann, libfann

from line_holder import *
 
def load_page(html):
    # Derive from formatter.AbstractWriter to store paragraphs.
    page = LineHolder()
    # Default formatter sends commands to our writer.
    f = formatter.AbstractFormatter(page)
    # Derive from htmllib.HTMLParser to track parsed bytes.
    parser = TrackingParser(page, f)
    # Give the parser the raw HTML data.
    parser.feed(html)
    parser.close()
    # compute density of each lies
    page.compute_density()
    return page

def load_html(url):
    # Get a file-like object for the Python Web site's home page.
    r = re.search("(?:http://)?([^/]*).*", sys.argv[1])
    print "waiting for " + r.group(1) + " ...",
    sys.stdout.flush()
    f = urllib.urlopen(sys.argv[1])
    print " ok"

# Read from the object, storing the page's contents in 's'.
    print "reading " + sys.argv[1] + " ...",
    sys.stdout.flush()
    s = f.read()
    print " ok"
    f.close()
    return s

def manual_training(page, filename):
    if (os.path.exists(filename) == True):
        file = open(filename, "r")
        filelines = file.readlines()
        file.close()
    else:
        filelines = []

    output = page.get_manual_answers()

    file = open(filename, "w")
    file.write(str(((len(filelines) - 1) / 2) + len(output)) + ", 9, 1\n")
    file.writelines(filelines[1:])
                
    for i in xrange(0, len(output)):
        if (i == 0):
            file.write("0.0 0 0 ")
        else:
            file.write(page.lines[i - 1].density + " " +
                       page.lines[i - 1].bytes + " " +
                       len(page.lines[i - 1].text) + " ")
        file.write(page.lines[i].density + " " +
                   page.lines[i].bytes + " " +
                   len(page.lines[i].text) + " ")
        if (i == len(output) - 1):
            file.write("0.0 0 0\n")
        else:
            file.write(page.lines[i + 1].density + " " +
                       page.lines[i + 1].bytes + " " +
                       len(page.lines[i + 1].text) + "\n")
    file.close()

def main():
    if (len(sys.argv) != 3):
        print "bad number of argument. got: " + str(len(sys.argv)) + " expected: 3"
        print "usage: extract_text.py <newswatch-db-file> <training_file>"
        sys.exit(1)

    page = load_page(load_html(sys.argv[1]))
    manual_training(page, sys.argv[2])
    
# This creates a new single-layer perceptron with 1 output and 3 inputs.
    obj = libfann.fann_create_standard_array(2, (3, 1))
    ann = fann.fann_class(obj)

# Load the data we described above.
    if (os.path.exists(sys.argv[2]) == True):
        patterns = fann.read_train_from_file(sys.argv[2])
    ann.train_on_data(patterns, 1000, 1, 0.0)
 
# Then test it with different data.
    for index, line in enumerate(page.lines):
        if (index == 0):
            input = [0.0, 0.0, 0.0]
        else:
            input = [page.lines[index - 1].density, 
                     page.lines[index - 1].bytes,
                     len(page.lines[index - 1].text)]
        input = [line.density. line.bytes, len(line.text)]
        if (index + 1 >= len(page.lines) - 1):
            input = [0.0, 0.0, 0.0]
        else:
            input = [page.lines[index + 1].density, 
                     page.lines[index + 1].bytes,
                     len(page.lines[index + 1].text)]

        result = ann.run(input)
        print line.text + "\n" + 'Got:', result

if __name__ == "__main__":
#pdb.set_trace()
    main()
