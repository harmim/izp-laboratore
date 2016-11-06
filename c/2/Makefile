.PHONY: clean

CLFAGS=-std=c99 -Wall -Wextra -Werror -g
out=bin/Debug/Hello
source=hello.c

$(out): $(source)
	gcc $(source) -o $(out)

clean:
	rm $(out)

