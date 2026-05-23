build:
	gcc src/main.c src/run.c -I include -o bin/app

test:
	gcc src/main.c tests/test.c -I include -o bin/test