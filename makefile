# The makefile
CC = gcc

TARGET = Dolphin

$(TARGET):
	$(CC) -o $(TARGET) *.c

a:
	$(CC) -o $(TARGET) *.c

clean:
	rm $(TARGET)
