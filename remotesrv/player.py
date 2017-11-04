import sys
import pymedia.muxer as muxer
import pymedia.audio.acodec as acodec
import pymedia.audio.sound as sound
import time
import threading
import logging

PAUSE=0
PLAY=1
STOP=2
BUFFER_SIZE=512

class player (threading.Thread):
    def __init__(self, filename, endfunc):
        self.filename = filename
        self.endfunc = endfunc
        self.state = PAUSE
        threading.Thread.__init__(self)


    def run(self):
        logging.info('play started on ' + self.filename)
        dm= muxer.Demuxer( str.split( self.filename, '.' )[ -1 ].lower() )
        snds=sound.getODevices()
        if 0 not in range( len( snds ) ):
            print 'Cannot play sound to non existent device %d out of %d' % ( 1, len( snds ) )
            self.endfunc()
            return
        f= open(self.filename, 'rb')
        snd= resampler= dec= None
        s= f.read( 32000 )
        t= 0
        while len( s ):
            frames= dm.parse( s )
            if frames:
                for fr in frames:
                    # Assume for now only audio streams

                    if dec== None:
                        print dm.getInfo(), dm.streams
                        dec= acodec.Decoder( dm.streams[ fr[ 0 ] ] )
                        
                    r= dec.decode( fr[ 1 ] )
                    if r and r.data:
                        if snd== None:
                            print 'Opening sound with %d channels -> %s' % ( r.channels, snds[ 0 ][ 'name' ] )
                            snd= sound.Output( int( r.sample_rate ), r.channels, sound.AFMT_S16_LE, 0 )
          
                        data= r.data
                        while (self.state == PAUSE):
                            time.sleep( .05 )
                        if (self.state == STOP):
                            self.endfunc()
                            return
                        snd.play( data )

            s = f.read( BUFFER_SIZE )

        count = 0
        while snd.isPlaying():
            count = count + 1
            print "playing: ", str(count)
            time.sleep( .05 )
            while (self.state == PAUSE):
                time.sleep( .05 )
            if (self.state == STOP):
                self.endfunc()
                return

        self.endfunc()
