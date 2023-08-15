CC = gcc
TARGET = bin/6565.$(CC)
SRC = $(shell ls src/*.c)
DEPS = $(shell ls src/*.h)
OBJ = $(patsubst %.c,%.$(CC).o,$(SRC))

all: $(TARGET)

$(TARGET): $(OBJ)
	@mkdir -p bin
	$(CC) $^ -o $@

src/%.$(CC).o: src/%.c $(DEPS)
	$(CC) -c -o $@ $<

.PHONY: clean
clean:
	rm -rf bin/* src/*.o
