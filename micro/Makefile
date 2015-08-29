cc=gcc
CFLAGS = -O3 -c -Wall

all:	o
	$(cc) -o main.exe *.o
	rm *.o

o:
	$(cc) $(CFLAGS) *.c

clean:
	rm main.exe