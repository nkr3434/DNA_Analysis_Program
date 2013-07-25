derle: main.c
	clear
	gcc main.c -o main

calistir: main
	clear
	./main

install: main
	cp main /usr/bin
