build:
	gcc -Wall -std=c99 ./src/*.c -Iinc -lSDL2 -lSDL2_ttf -o game

run:
	./game

clean:
	rm game

