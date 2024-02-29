CC =gcc
CFLAGS = -Wall -Werror -Wextra -std=c11 -c
SOURCE = grepnew.c
OBJECTS = $(SOURCE:.c=.o)
SEND = s21_grep


s21_grep: $(OBJECTS)
	$(CC) $(OBJECTS)  -o $(SEND)
clean:
	-rm $(SEND)
	-rm *.o
.PHONY: clean