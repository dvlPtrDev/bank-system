CC = gcc

SRC_DIR = src
OUT_DIR = out

SRC = $(shell find $(SRC_DIR) -name "*.c")
OBJ = $(addprefix $(OUT_DIR)/,$(notdir $(SRC:.c=.o)))

CFLAGS = -I../lib/strlib/include \
         -I../lib/sqlitelib/include \
         -I./include

LDFLAGS = -L../lib/strlib/out \
          -L../lib/sqlitelib/out

LIBS = -l:libstr.a -lsqlite -lsqlite3

TARGET = bank

all: run
run: $(TARGET)
	./$(OUT_DIR)/$(TARGET)

$(TARGET): $(OBJ)
	$(CC) $^ -o $(OUT_DIR)/$(TARGET) $(LDFLAGS) $(LIBS)

$(OUT_DIR)/%.o:
	mkdir -p $(OUT_DIR)
	$(CC) $(CFLAGS) -c $(shell find $(SRC_DIR) -name $*.c) -o $@

	
clean:
	rm -rf $(OUT_DIR)