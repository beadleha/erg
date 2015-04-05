all:
	gcc main.c enemies.c level.c drawutil.c player.c -lncurses -o erg
clean:
	rm erg
