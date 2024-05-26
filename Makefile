# Comments



#################################
# Target selection
#################################
all: $(TARGET)

TARGET = ml


#################################
# OS detection
#################################
ifeq ($(OS),Windows_NT)
	MAKE_CLEAN_CMD = del
	MAKE_CLEAN_FLAGS = /f
else
	UNAME_S := $(shell uname -s)
	ifeq ($(UNAME_S),Linux)
		MAKE_CLEAN_CMD = rm
		MAKE_CLEAN_FLAGS = -rf
	endif
	ifeq ($(UNAME_S),Darwin)
		MAKE_CLEAN_CMD = rm
		MAKE_CLEAN_FLAGS = -fR
	endif
endif




# Variables
CC = gcc
CFLAGS = -Wall -Wextra -lm
SRC_DIR = src
INC_DIR = inc
BUILD_DIR = build
EXECUTABLE = myprog



#################################
# C source files
#################################
SOURCES = \
$(SRC_DIR)/main.c \
$(SRC_DIR)/ml.c \
$(INC_DIR)/ml.h \
#$(INC_DIR)/algorithms.h \



# src files
#SOURCES = $(wildcard $(SRC_DIR/*.c)) 
#SOURCES += $(wildcard $(SRC_DIR/*.cpp)) # If including CPP files, un-comment.
OBJECTS = $(patsubst $(SRC_DIR)/%.c, $(BUILD_DIR)/%.o, $(SOURCES))


# rules
all: $(BUILD_DIR) $(EXECUTABLE)

$(EXECUTABLE): $(SOURCES)
	$(CC) $(CFLAGS) $(SOURCES) -o $(BUILD_DIR)/$(EXECUTABLE)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) -I$(INC_DIR) -c $< $@

$(BUILD_DIR):
	mkdir $@


run:
	./build/./myprog

.PHONY: clean
clean:
	$(MAKE_CLEAN_CMD) $(MAKE_CLEAN_FLAGS) $(BUILD_DIR)
	# rm -rf build/



