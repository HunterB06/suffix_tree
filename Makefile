CC=gcc
CFLAGS=-Wall -Wextra -Werror -std=c99 -pedantic -g3

SRC=suffix_tree.c main.c
VPATH=src
OBJ=$(SRC:.c=.o)

TEST=mississippi roXor

BIN=trie

all: $(BIN)

$(BIN): $(OBJ)
	$(CC) $^ -o $@

check: $(BIN)
	for i in $(TEST); do  \
		./trie "$$i" "$$i".dot; \
		dot -Tpng "$$i".dot -o "$$i".png; \
	done

.PHONY: clean
clean:
	$(RM) $(OBJ)
	$(RM) $(BIN)
	$(RM) *.dot *.png
