NAME=libft							# Nombre del archivo
CC = cc 							# Compilador
CFLAGS = -Wall -Werror -Wextra		# Banderas
SRC=$(wildcard *.c) 				# Comodin para coger todos los .c
OBJ=$(SRC:.c=.o)					# Luego se genera nombres de todos los .c por .o, solo genera
RM=$(rm -f)

.SILENT:

# Comodin wildcard
all: $(NAME)						# Esto es lo que ejecuta make por defecto

# $@ coge name y luego $^ coge todos los valores.
$(NAME):$(OBJ)	
	$(CC) $(CFLAGS) -o $@ $^  

# Como los archivos .o no estan aun creados, los creara uno por uno con esta regla.
%.o:%.c
	$(CC) $(CFLAGS) -c $< -o $@ 

clean:
	$(RM) *.o

fclean: clean
	$(RM) $(NAME)

re: fclean all


