all:
	gcc main.c util.c -lncurses -o erg
clean:
	rm erg
