CC := g++
CFLAGS := -Wall -g
TARGET := out

SRCS := $(wildcard *.cpp)
OBJS := $(patsubst %.cpp,build/%.o,$(SRCS))

all: mkdir_build $(TARGET)
mkdir_build: 
	mkdir -p build
$(TARGET):  $(OBJS)
	$(CC) -o $@ $^
build/%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@
clean:
	rm -rf $(TARGET) build/
	
.PHONY: all clean
