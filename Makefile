CC := gcc

# Build settings
CFLAGS := -Wall -Wextra -O2 -I./include
LDFLAGS :=

# Override if your distro uses a different hidapi backend library.
LDLIBS := -lhidapi-hidraw

TARGET := pk3cmd
SRC := $(shell find src -name '*.c')
OBJ := $(patsubst src/%.c, obj/%.o, $(SRC))

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(OBJ) $(LDFLAGS) $(LDLIBS) -o $@

obj/%.o: src/%.c | obj
	$(CC) $(CFLAGS) -c $< -o $@

obj:
	mkdir -p obj

clean:
	rm -f $(OBJ) $(TARGET)
	rm -rf obj
