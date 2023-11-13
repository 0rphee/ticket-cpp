CC = g++
CFLAGS = -std=c++20 -Wall

BIN_DIR = bin
TARGET = $(BIN_DIR)/main

# Use wildcard to find all .cpp files in the SRC_DIR
SOURCES = $(wildcard *.cpp)

.PHONY: all clean run force_build zip

all: $(TARGET)

$(TARGET): $(SOURCES)
	mkdir -p $(BIN_DIR)
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm -rf $(BIN_DIR)

force_build:
	@$(MAKE) clean
	@$(MAKE) all

run: force_build
	./$(TARGET)

zip:
	find . -name .DS_Store -delete  # This line deletes .DS_Store files
	zip -r $(notdir $(CURDIR)).zip . -x "bin/*"