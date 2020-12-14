CC := g++
INC_DIR := include
SRC_DIR := src

OBJ := $(SRC_DIR)/cuenta.cpp $(SRC_DIR)/cuenta_ahorros.cpp $(SRC_DIR)/cuenta_cheques.cpp main.cpp

CFLAGS   := -I$(INC_DIR) -Wall 
EXEC := a.out


$(EXEC) : $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(EXEC)


clean:
	rm *.out 