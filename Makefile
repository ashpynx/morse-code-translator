CC = gcc

CFLAGS = -Wall 

SRC = $(wildcard src/*.c)

OUT = mct

$(OUT) : $(SRC)
	$(CC) $(CFLAGS) -o $(OUT) $(SRC)


clean:
	rm -rf $(OUT)


