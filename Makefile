CC       := gcc
STD      := -std=c11

INCLUDE  := -Iinclude -Isrc

WARNINGS := \
	-Werror \
	-Wall \
	-Wextra \
	-Wpedantic \
	-Wshadow \
	-Wconversion \
	-Wsign-conversion \
	-Wcast-qual \
	-Wwrite-strings \
	-Wformat=2 \
	-Wundef \
	-Wstrict-prototypes \
	-Wold-style-definition \
	-Wimplicit-fallthrough \
	-Wlogical-op \
	-Wcast-align \
	-Wvla \
	-Wnull-dereference \
	-Wdouble-promotion \
	-Wformat-overflow=2 \
	-Wformat-truncation=2 \
	-Walloc-zero \
	-Warray-bounds=2 \
	-Wstringop-overflow=4 \
	-Wstrict-overflow=5 \
	-Wswitch-enum \
	-Wpointer-arith \
	-Winit-self

CFLAGS   := $(STD) $(INCLUDE) $(WARNINGS) -fPIC -fvisibility=hidden -DTENCOR_BUILDING -MMD -MP
LDFLAGS  := -shared -Wl,-soname,libtencor.so -Wl,-z,defs

SRC_DIR  := src
BUILD_DIR := build
LIB_DIR  := lib

TARGET   := $(LIB_DIR)/libtencor.so

SRCS     := $(shell find $(SRC_DIR) -name '*.c')
OBJS     := $(patsubst $(SRC_DIR)/%.c,$(BUILD_DIR)/%.o,$(SRCS))
DEPS     := $(OBJS:.o=.d)

.PHONY: all clean again

all: $(TARGET)

again: clean
	$(MAKE) --no-print-directory all

$(TARGET): $(OBJS) | $(LIB_DIR)
	$(CC) $(LDFLAGS) $(OBJS) -o $@

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c | $(BUILD_DIR)
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

$(BUILD_DIR):
	@mkdir -p $(BUILD_DIR)

$(LIB_DIR):
	@mkdir -p $(LIB_DIR)

clean:
	rm -rf $(BUILD_DIR) $(LIB_DIR)

-include $(DEPS)
