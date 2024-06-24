build:
	gcc -Wall -std=c99 ./src/*.c -Iinc -lSDL2 -o game

run:
	./game

clean:
	rm game

