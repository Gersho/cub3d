SRC_FILES	= main.c cubinfo_utils.c draw.c data_validator.c \
ft_parse_cub.c mapinfo_utils.c debug_tools.c ft_shutdown.c \
mlxcolors_utils.c mlx_utils.c

SRC_DIR = srcs
SRCS = $(addprefix $(SRC_DIR)/, $(SRC_FILES))
OBJS	= $(SRCS:.c=.o)
NAME = cube.a
CC		= gcc
RM		= rm -f
CFLAGS	= -Wall -Wextra -Werror
AR		= ar -cr

%.o: %.c	cube.h
			$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

$(NAME):	$(OBJS)
			make -C srcs/libft/
			cp srcs/libft/libft.a cube.a
			$(AR) $(NAME) $(OBJS)

all: 		$(NAME)

clean:
			$(RM) $(OBJS)
			make -C srcs/libft/ clean

fclean:		clean
			$(RM) $(NAME)
			$(RM) srcs/libft/libft.a

re:			fclean all
			
.PHONY:		bonus re fclean clean all