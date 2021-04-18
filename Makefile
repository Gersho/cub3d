SRCS	= srcs/main.c srcs/cubinfo_utils.c srcs/draw.c srcs/data_validator.c \
srcs/ft_parse_cub.c srcs/mapinfo_utils.c srcs/ft_shutdown.c \
srcs/mlx_utils.c srcs/rays.c srcs/vars_utils.c srcs/planes_utils.c \
srcs/movements.c srcs/precalculator.c srcs/xpm_loader.c srcs/trgb_from_xpm.c \
srcs/hooks.c srcs/img_to_bmp.c srcs/math_utils.c srcs/ft_parse_cf.c \
srcs/ft_parse_path.c srcs/ft_parse_r.c srcs/rays_utils.c srcs/sprites_inter.c

OBJS		= $(SRCS:.c=.o)
NAME		= cub3D
CC			= gcc
RM			= rm -f
CFLAGS		= -Wall -Wextra -Werror -O3
MINILIB		= libs/minilibx_opengl_20191021
FRAMEWORK	= -framework OpenGL -framework AppKit

%.o: 		%.c	cube.h
			$(CC) $(CFLAGS) -c -o $*

all: 		$(NAME)

bonus:		all

$(NAME):	$(OBJS)
			make -C srcs/libft/
			make -C libs/minilibx_opengl_20191021
			gcc $^ srcs/libft/libft.a -L $(MINILIB) $(FRAMEWORK) -lmlx -o $(NAME)

clean:
			$(RM) $(OBJS)
			make -C srcs/libft/ clean
			make -C libs/minilibx_opengl_20191021 clean

fclean:		clean
			$(RM) $(NAME)
			$(RM) srcs/libft/libft.a
			$(RM) cub3D
			$(RM) libs/minilibx_opengl_20191021/libmlx.a

re:			fclean all

.PHONY:		bonus re fclean clean all
