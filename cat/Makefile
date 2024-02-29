CC =gcc
CFLAGS = -Wall -Werror -Wextra -c
SOURCE = cat.c
OBJECTS = $(SOURCE:.c=.o)
SEND = s21_cat


s21_cat: $(OBJECTS)
	$(CC) $(OBJECTS)  -o $(SEND)
clean:
	-rm $(SEND)
	-rm *.o
.PHONY: clean
