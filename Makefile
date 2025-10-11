NAME = libft.a						# Nombre del archivo
PROJECT = libft
CC = cc 							# Compilador
CFLAGS = -Wall -Werror -Wextra		# Banderas
SRC=ft_calloc.c ft_isascii.c ft_itoa.c ft_memcpy.c ft_putchar_fd.c ft_putstr_fd.c ft_strdup.c ft_strlcat.c ft_strmapi.c ft_strrchr.c ft_tolower.c Makefile\
ft_atoi.c ft_isalnum.c ft_isdigit.c ft_memchr.c ft_memmove.c ft_putendl_fd.c ft_split.c ft_striteri.c ft_strlcpy.c ft_strncmp.c ft_strtrim.c ft_toupper.c\
ft_bzero.c ft_isalpha.c ft_isprint.c ft_memcmp.c ft_memset.c ft_putnbr_fd.c ft_strchr.c ft_strjoin.c ft_strlen.c ft_strnstr.c ft_substr.c
OBJ=$(SRC:.c=.o)					# Luego se genera nombres de todos los .c por .o, solo genera
RM=rm -f
AR= ar -rcs							# Crea biblioteca estatica, -r replace, -c create, -s index

# .SILENT:

# Comodin wildcard
all: $(NAME)						# Esto es lo que ejecuta make por defecto

# $@ coge name y luego $^ coge todos los valores.
$(NAME):$(OBJ)	
	$(AR) $(NAME) $(OBJ)
#	$(CC) $(CFLAGS) -o $@ $^  

# Como los archivos .o no estan aun creados, los creara uno por uno con esta regla.<<<
%.o:%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) *.o

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re			# En caso ya este creado el archivo, no le importe y lo ejecute.