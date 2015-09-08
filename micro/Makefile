cc=gcc
CFLAGS = -O3 -c -Wall

all:	o
	$(cc) -o main.exe *.o -lpdcurses
	rm *.o

o:
	$(cc) $(CFLAGS) *.c

clean:
	rm main.exe