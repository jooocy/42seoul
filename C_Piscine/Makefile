CC = gcc
TARGET = app.out
OBJS = main.o ft_print_comb.o

CFLAGS = -Wall -g 
LDFLAGS = -lc  

all : $(TARGET)

$(TARGET) : $(OBJS)
	$(CC) -o $@ $^

.c.o :
	$(CC) -c -o $@ $<
clean :
	rm -f $(OBJS) $(TARGET)
