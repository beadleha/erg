all:
	gcc main.c enemies.c level.c print.c -lncurses -o erg
clean:
	rm erg
