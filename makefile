CC = gcc

TARGET = dirMgt

$(TARGET):
	$(CC) -o $(TARGET) *.c

clean:
	rm $(TARGET)
