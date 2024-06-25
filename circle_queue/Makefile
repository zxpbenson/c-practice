CC = gcc
CFLAGS = -Wall -g -pthread
OBJS = queue.o main.o
TARGET = queue_test

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

queue.o: queue.c queue.h

main.o: main.c queue.h

