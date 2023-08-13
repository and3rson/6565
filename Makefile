TARGET = bin/6565
SRC = $(shell ls src/*.c)
DEPS = $(shell ls src/*.h)
OBJ = $(patsubst %.c,%.o,$(SRC))

all: $(TARGET)

$(TARGET): $(OBJ)
	gcc $^ -o $@

src/%.o: src/%.c $(DEPS)
	gcc -c $< -o $@

.PHONY: clean
clean:
	rm -rf $(TARGET) $(OBJ)
