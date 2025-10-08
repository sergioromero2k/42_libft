NAME = libft.a						# Nombre del archivo
PROJECT = libft
CC = cc 							# Compilador
CFLAGS = -Wall -Werror -Wextra		# Banderas
SRC=$(wildcard *.c) 				# Comodin para coger todos los .c
OBJ=$(SRC:.c=.o)					# Luego se genera nombres de todos los .c por .o, solo genera
RM=rm -f
AR= ar -rcs							# Crea biblioteca estatica, -r replace, -c create, -s index

.SILENT:

# Comodin wildcard
all: $(NAME)						# Esto es lo que ejecuta make por defecto

# $@ coge name y luego $^ coge sdfstodos los valores.
$(NAME):$(OBJ)	
	$(AR) $(NAME) $(OBJ)
#	$(CC) $(CFLAGS) -o $@ $^  

# Como los archivos .o no estan aun creados, los creara uno por uno con esta regla.
%.o:%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) *.o

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re			# En caso ya este creado el archivo, no le importe y lo ejecute.