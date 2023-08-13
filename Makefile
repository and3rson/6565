TARGET = bin/6565
SRC = $(shell ls src/*.c)
DEPS = $(shell ls src/*.h)
OBJ = $(patsubst %.c,%.o,$(SRC))
CC ?= gcc

all: $(TARGET)

$(TARGET): $(OBJ)
	@mkdir -p bin
	$(CC) $^ -o $@

src/%.o: src/%.c $(DEPS)
	$(CC) -c $< -o $@

.PHONY: clean
clean:
	rm -rf $(TARGET) $(OBJ)
