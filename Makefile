SRCS	= srcs/main.c srcs/cubinfo_utils.c srcs/draw.c srcs/data_validator.c \
srcs/ft_parse_cub.c srcs/mapinfo_utils.c srcs/debug_tools.c srcs/ft_shutdown.c \
srcs/mlx_utils.c srcs/rays.c srcs/vars_utils.c srcs/planes_utils.c \
srcs/movements.c srcs/precalculator.c srcs/xpm_loader.c srcs/trgb_from_xpm.c \
srcs/hooks.c srcs/img_to_bmp.c srcs/math_utils.c srcs/ft_parse_cf.c \
srcs/ft_parse_path.c srcs/ft_parse_r.c srcs/rays_utils.c srcs/sprites_inter.c

OBJS	= $(SRCS:.c=.o)
NAME = cube.a
CC		= gcc
RM		= rm -f
CFLAGS	= -Wall -Wextra -Werror -O3 -g
AR		= ar -cr
MINILIB = libs/minilibx_opengl_20191021

%.o: %.c	cube.h
			$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

all: 		$(NAME)

$(NAME):	$(OBJS)
			make -C srcs/libft/
			cp srcs/libft/libft.a cube.a
			$(AR) $(NAME) $(OBJS)
			gcc $(NAME) -L $(MINILIB) -lmlx -framework OpenGL -framework AppKit -o cub3D

clean:
			$(RM) $(OBJS)
			make -C srcs/libft/ clean

fclean:		clean
			$(RM) $(NAME)
			$(RM) srcs/libft/libft.a
			$(RM) cub3D

re:			fclean all

.PHONY:		bonus re fclean clean all
