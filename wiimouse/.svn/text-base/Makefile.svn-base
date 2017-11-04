CC=gcc
CFLAGS=-c -Wall -I/home/jedi/local/include/ -ggdb3
LDFLAGS=-L/usr/lib -L/home/jedi/local/lib/ -lX11 -lXtst -lcwiid -lgsl -lgslcblas
SOURCES=xdrive.c calibrate.c wiimote.c wiimouse.c
OBJECTS=$(SOURCES:.c=.o)
EXECUTABLE=wiimouse

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.c.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -fr $(OBJECTS)

re: clean all