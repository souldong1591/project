.PHONY:clean
CC=g++
CFLAGS=-Wall -g
BIN=main
OBJS=queue_fun.o main.o
$(BIN):$(OBJS)
	$(CC) $(CFLAGS) $^ -o $@
%.o:%.cpp
	$(CC) $(CFLAGS) -c $< -o $@
clean:
	rm -f *.o $(BIN)
