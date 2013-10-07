
CC=g++
CFLAGS=-W -Wall -ansi -pedantic -lglpk
LDFLAGS=-lglpk
EXEC=plam
SRC= $(wildcard *.cpp)
OBJ= $(SRC:.cpp=.o)

all: $(EXEC)

plam: $(OBJ)
	@$(CC) -o $@ $^ $(LDFLAGS)

%.o: %.cpp
	@$(CC) -o $@ -c $< $(CFLAGS)

.PHONY: clean mrproper

clean:
	@rm -rf *.o

distclean: clean
	@rm -rf $(EXEC)