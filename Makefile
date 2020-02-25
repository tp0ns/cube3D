CC = gcc

NAME = Cub3D
# -lmlx -framework OpenGL -framework AppKit
FLAGS = -Wall -Wextra -Werror 
# FLAGS = -Wall -Wextra -Werror -fsanitize=address -lmlx -framework OpenGL -framework AppKit

INCLUDE = -I cub.h

SRCS =	main.c leave.c \
		parsing/get_param.c parsing/map.c parsing/texture_res.c parsing/colors.c parsing/check_param.c \
		

OBJS = $(SRCS:.c=.o)

$(NAME) : $(OBJS) 
		$(MAKE) -C ./Libft/
		gcc -o $(NAME) Libft/libft.a $(OBJS) $(INCLUDE) $(FLAGS)

all : $(NAME)

clean :
		rm -f $(OBJS)
		$(MAKE) clean -C ./Libft
fclean : clean
		rm -f $(NAME)
		rm -f libft.a
		$(MAKE) fclean -C ./Libft
re : fclean all

# %.o: %.c
	# $(CC) $(FLAGS) -I cube3d.h -c $<  -o $(<:.c=.o)