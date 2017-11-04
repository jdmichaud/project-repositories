from qt import *

import sys
import train_form

class TrainFormImpl(train_form.TrainForm):
    def __init__(self, parent=None):
        train_form.TrainForm.__init__(self, parent)
        self.init()

    def init(self):
        self.stringList.setSorting(-1)
        pass

    def addString(self, s, checked = False):
        words = s.split()
        s = ""
        size = 0
        nchar = self.stringList.width() / 7
        for word in words:
            s += word + " "
            size += len(word) + 1
            if (size > nchar):
                s += "\n"
                size = 0

        ci = QCheckListItem(self.stringList, s[:-2], QCheckListItem.CheckBox)
        ci.setMultiLinesEnabled(True)

    def train(self):
        pass

        

