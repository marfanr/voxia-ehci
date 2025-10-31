# cari semua file .cpp di folder ini dan subdir
CPP_FILES := $(shell find . -type f -name '*.cpp')
OBJ := $(CPP_FILES:.cpp=.o)
ROOT ?= $(realpath $(dirname $(realpath $0)))

LIB_INCLUDE_DIR := $(ROOT)/library/ioforge/include/

OUT_DIR ?= $(ROOT)/build/modules
MODULE_NAME := ehci
OUT_ELF := $(MODULE_NAME).elf
OUT_VOXMO := ../../initrd/modules/$(MODULE_NAME).voxmo

CXX := clang++        # ganti compiler ke clang++
LD := ld

CXXFLAGS := -Wall -Wextra -O2 -pipe \
    -ffreestanding -nostdlib -fno-exceptions -fno-rtti -fno-builtin \
    -fno-use-cxa-atexit -fno-asynchronous-unwind-tables -fno-common \
    -mno-red-zone -std=c++20 -ggdb -g -fPIC \
    -I$(LIB_INCLUDE_DIR) -I .

LDFLAGS := -shared -m elf_x86_64 -e module_init -L $(ROOT)/library/ioforge -lioforge

.PHONY: all clean

all: $(OUT_ELF)
	voxmo -o $(OUT_VOXMO) $(OUT_ELF) ./manifest.yaml
#	cp $(OUT_VOXMO) ../../initrd/modules/

$(OUT_ELF): $(OBJ)
	mkdir -p $(OUT_DIR)
	$(LD) $(LDFLAGS) $(OBJ) -o $(OUT_ELF)

%.o: %.cpp
	mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ) $(OUT_ELF) $(OUT_VOXMO)
