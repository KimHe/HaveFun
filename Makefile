# Makefile

NAME = HaveFun

CC = gcc

CFLAGS = -Wall -g

GTK_LIB = `pkg-config --cflags --libs gtk+-3.0`

LD = gcc
LDFLAGS = $(GTK_LIB) -lm

havefun: main.o dayNum.o JULE2GRE.o GRE2JULE.o getTime.o printStr.o gui.o
	$(CC) -o $(NAME) $(CFLAGS) main.o dayNum.o JULE2GRE.o GRE2JULE.o getTime.o printStr.o gui.o $(LDFLAGS)

main.o: main.c printStr.c defs.h
	$(CC) -c $(CFLAGS) main.c printStr.c

dayNum.o: dayNum.c defs.h
	$(CC) -c $(CFLAGS) dayNum.c

JULE2GRE.o: JULE2GRE.c defs.h
	$(CC) -c $(CFLAGS) JULE2GRE.c

GRE2JULE.o: GRE2JULE.c defs.h
	$(CC) -c $(CFLAGS) GRE2JULE.c

getTime.o: getTime.c defs.h
	$(CC) -c $(CFLAGS) getTime.c

printStr.o: printStr.c defs.h
	$(CC) -c $(CFLAGS) printStr.c

gui.o: gui.c defs.h
	$(CC) -c $(CFLAGS) gui.c $(GTK_LIB)

clean: 
	rm *.c~ *.o
	@echo "all *.c~ *.o have cleaned up"
