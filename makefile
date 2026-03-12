CC = gcc

SRC_DIR = src
OUT_DIR = out

SRC = $(wildcard $(SRC_DIR)/*.c)
obj = $(SRC: $(SRC_DIR)/%.c=$(OUT_DIR/%.o))

CFLAGS = -I../lib/strlib/include \
         -I../lib/sqlitelib/include \
         -I./include

LDFLAGS = -L../lib/strlib/out \
          -L../lib/sqlitelib/out

LIBS = -l:libstr.a -lsqlite -lsqlite3

TARGET = bank

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(OBJ) -o $(OUT_DIR)/$(TARGET) $(LDFLAGS) $(LIBS)

$(OUT_DIR)/%.o: $(SRC_DIR)/%.c
	mkdir -p $(OUT_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OUT_DIR) $(TARGET)
