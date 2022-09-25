A := matrix_rain
B := -std=c11 -Wall -Wextra -Werror -Wpedantic -lncurses

all: clean $(A)

$(A):
	clang $(B) -Iinc -o $(A) src/*.c

clean:
	rm -rf $(A)

uninstall:
	rm -rf $(A)

reinstall:
	make uninstall
	make
