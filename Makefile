# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sergio-alejandro <sergio-alejandro@stud    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/13 21:31:32 by sergio-alej       #+#    #+#              #
#    Updated: 2025/10/13 21:44:54 by sergio-alej      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

AR= ar -rcs							# Crea biblioteca estatica, -r replace, -c create, -s index
RM=rm -f

CC = cc 							# Compilador
CCFLAGS = -Wall -Werror -Wextra		# Banderas
INCLUDE = libft.h

NAME = libft.a						# Nombre del archivo
SRC=ft_calloc.c ft_isascii.c ft_itoa.c ft_memcpy.c ft_putchar_fd.c ft_putstr_fd.c ft_strdup.c ft_strlcat.c ft_strmapi.c ft_strrchr.c ft_tolower.c Makefile\
ft_atoi.c ft_isalnum.c ft_isdigit.c ft_memchr.c ft_memmove.c ft_putendl_fd.c ft_split.c ft_striteri.c ft_strlcpy.c ft_strncmp.c ft_strtrim.c ft_toupper.c\
ft_bzero.c ft_isalpha.c ft_isprint.c ft_memcmp.c ft_memset.c ft_putnbr_fd.c ft_strchr.c ft_strjoin.c ft_strlen.c ft_strnstr.c ft_substr.c
OBJ_SRC=$(SRC:.c=.o)					# Luego se genera nombres de todos los .c por .o, solo genera

SRC_BONUS= ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c\
ft_lstlast_bonus.c ft_lstadd_back_bonus.c ft_lstdelone_bonus.c\
ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c
OBJ_BONUS=$(SRC_BONUS:.c=.o)


# .SILENT:

# Comodin wildcard
all: $(NAME)						# Esto es lo que ejecuta make por defecto

# $@ coge name y luego $^ coge todos los valores.
$(NAME):$(OBJ_SRC) $(INCLUDE)
	$(AR) $(NAME) $(OBJ_SRC)
#	$(CC) $(CCFLAGS) -o $@ $^  

bonus: $(OBJ_SRC) $(OBJ_BONUS) $(INCLUDE)
	$(AR) $(NAME) $(OBJ_BONUS) $(OBJ_SRC)

# Como los archivos .o no estan aun creados, los creara uno por uno con esta regla.<<<
%.o:%.c
	$(CC) $(CCFLAGS) -c $< -o $@

clean:
	$(RM) *.o

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re	bonus		# En caso ya este creado el archivo, no le importe y lo ejecute.