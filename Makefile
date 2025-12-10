CC = gcc

SRCS = main.c
OBJS = $(SRCS:.c=.o)
 
TARGET = bytes_dumper

all: $(TARGET)

$(TARGET) : $(OBJS)
	$(CC) $(OBJS) -o $(TARGET)
%.o: %.c
	$(CC) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET) 
