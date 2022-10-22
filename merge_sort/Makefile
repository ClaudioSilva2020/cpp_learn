
# Name of the project
PROJ_NAME=merge_sort

HEAD_DIR = include
SRCXX_DIR = src

#compiler
CC  := gcc
CXX := g++

SRCSXX	:= $(shell find $(SRCXX_DIR) -iname "*.cpp"	-printf '%h/%f ' 2>/dev/null)

BUILD_OUTPUT_DIR := build
OBJ_DIR := $(BUILD_OUTPUT_DIR)/obj
OBJS= $(patsubst $(SRCXX_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SRCSXX))

EXEC :=$(PROJ_NAME)

# Flags for compiler
C_COMMON_FLAGS=-c         \
               -W         \
               -Wall      \
               -ansi      \
               -pedantic

CXXFLAGS = $(COMMON_FLAGS) -std=gnu++17

#==============================================================================
# Regra de compilação para arquivos C++ e C
#==============================================================================

define COMPILE.cpp
@echo =========================================================================================
@echo Building $<
@mkdir -p $(shell dirname $@);
$(CXX) $(CXXFLAGS) -c $< -o $@
endef

#==============================================================================
# Regra do Make
#==============================================================================

all: dirs $(EXEC)

tempall:
	@echo $(SRCSXX)

dirs:
	@mkdir -p -m755 $(OBJ_DIR)

$(EXEC): $(OBJS) Makefile
	@echo "========================================================================================="
	@echo "Linking"
	$(CXX) $(OBJS) -o $@ $(LDFLAGS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c Makefile
	$(COMPILE.c)

$(OBJ_DIR)/%.o: $(SRCXX_DIR)/%.cpp Makefile
	$(COMPILE.cpp)

clean:
	@rm -f core `find . -type f -name 'core' -print`
	@rm -f .tmp
	@rm -f *.$$$$ *~ *.d* $(EXEC)
	@rm -rf $(OBJ_DIR)
	@rm -rf $(BUILD_OUTPUT_DIR)