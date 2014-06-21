reverse:main_reverse.o list_reverse.o list_show.o
	gcc -o ./bin/reverse main_reverse.o list_reverse.o list_show.o -I ./include
main_reverse.o:./src/main_reverse.c
	gcc -c ./src/main_reverse.c -I ./include
list_reverse.o:./src/list_reverse.c
	gcc -c ./src/list_reverse.c -I ./include
list_show.o:./src/list_show.c
	gcc -c ./src/list_show.c -I ./include

