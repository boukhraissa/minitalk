NAME = libftprintf.a
SOURCES = \
	ft_print_adress.c ft_printf_buf.c ft_printf.c ft_putchar.c ft_putnbr_base_10.c ft_putnbr_base_hexa.c ft_putnbr_base_hexa2.c ft_putstr.c ft_printunsigned.c
OBJECTS = $(SOURCES:.c=.o)
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs

all: $(NAME)

$(NAME): $(OBJECTS)
	$(AR) -r $@ $?

%.o: %.c ft_printf.h
	$(CC) -c $(CFLAGS) $< -o $@

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean