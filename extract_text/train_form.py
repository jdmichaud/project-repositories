# -*- coding: utf-8 -*-

# Form implementation generated from reading ui file 'train_form.ui'
#
# Created: Sun Apr 6 12:34:15 2008
#      by: The PyQt User Interface Compiler (pyuic) 3.17.4
#
# WARNING! All changes made in this file will be lost!


from qt import *


class TrainForm(QDialog):
    def __init__(self,parent = None,name = None,modal = 0,fl = 0):
        QDialog.__init__(self,parent,name,modal,fl)

        if not name:
            self.setName("TrainForm")



        self.trainButton = QPushButton(self,"trainButton")
        self.trainButton.setGeometry(QRect(850,790,111,21))

        self.stringList = QListView(self,"stringList")
        self.stringList.addColumn(self.__tr("Text list"))
        self.stringList.header().setResizeEnabled(0,self.stringList.header().count() - 1)
        self.stringList.setGeometry(QRect(1,1,960,780))
        self.stringList.setSizePolicy(QSizePolicy(QSizePolicy.Maximum,QSizePolicy.Maximum,0,0,self.stringList.sizePolicy().hasHeightForWidth()))
        self.stringList.setRootIsDecorated(1)

        self.languageChange()

        self.resize(QSize(965,815).expandedTo(self.minimumSizeHint()))
        self.clearWState(Qt.WState_Polished)

        self.connect(self.trainButton,SIGNAL("clicked()"),self.train)


    def languageChange(self):
        self.setCaption(self.__tr("TrainForm"))
        self.trainButton.setText(self.__tr("Train"))
        self.stringList.header().setLabel(0,self.__tr("Text list"))


    def train(self):
            self.output = []
        

    def __tr(self,s,c = None):
        return qApp.translate("TrainForm",s,c)
