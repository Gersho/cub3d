SRCS	= srcs/main.c srcs/cubinfo_utils.c srcs/draw.c srcs/data_validator.c \
srcs/ft_parse_cub.c srcs/mapinfo_utils.c srcs/debug_tools.c srcs/ft_shutdown.c \
srcs/mlx_utils.c srcs/rays.c srcs/vars_utils.c srcs/planes_utils.c

OBJS	= $(SRCS:.c=.o)
NAME = cube.a
CC		= gcc
RM		= rm -f
CFLAGS	= -Wall -Wextra -Werror -O3
AR		= ar -cr
MINILIB = libs/minilibx_opengl_20191021

%.o: %.c	cube.h
			$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

all: 		$(NAME)

$(NAME):	$(OBJS)
			make -C srcs/libft/
			cp srcs/libft/libft.a cube.a
			$(AR) $(NAME) $(OBJS)
			gcc cube.a -L $(MINILIB) -lmlx -framework OpenGL -framework AppKit

clean:
			$(RM) $(OBJS)
			make -C srcs/libft/ clean

fclean:		clean
			$(RM) $(NAME)
			$(RM) srcs/libft/libft.a

re:			fclean all

.PHONY:		bonus re fclean clean all
