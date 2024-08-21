# TARGET=main
# SOURCE=$(wildcard *.c)
# OBJS=$(patsubst %.c,%.o, $(SOURCE))
# CC=gcc

# $(TARGET):$(OBJS)
# 	$(CC) -o $(TARGET) $(OBJS)

# RM=rm


# clean:
# 	$(RM) $(OBJS) $(TARGET)





INC_DIR=./include
SRC_DIR=./src
OBJ_DIR=./obj
BIN_DIR=./bin

SRC=$(wildcard $(SRC_DIR)/*.c)
OBJ=$(patsubst %.c ,$(OBJ_DIR)/%.o,$(notdir $(SRC)))


TARGET=main
BIN_TARGET=$(BIN_DIR)/$(TARGET)

CC=gcc
CFLAGS= -g -Wall -I$(INC_DIR)

$(BIN_TARGET):$(OBJ)
	$(CC)  $(OBJ) -o $@

$(OBJ_DIR)/%.o:$(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	find $(OBJ_DIR) -name *.o -exec rm -rf {} \;
	
	rm $(BIN_TARGET)
