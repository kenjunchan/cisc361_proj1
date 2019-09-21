mp3.o: mp3.c mp3.h
	gcc -o mp3.o mp3.c mp3.h
run: mp3.o
	./mp3.o

mp3 : mp3.o
	gcc mp3.o -o mp3 -g

clean: 
	rm -f mp3.o
	rm -f mp3

leak : mp3.o
	valgrind --leak-check=full --show-leak-kinds=all ./mp3.o

