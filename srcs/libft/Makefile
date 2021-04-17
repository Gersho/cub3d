SRCS    = ft_isalnum.c ft_memccpy.c ft_memset.c ft_strncmp.c ft_strchr.c ft_isalpha.c \
ft_strnstr.c ft_atoi.c ft_isascii.c ft_strlcat.c ft_strrchr.c ft_bzero.c \
ft_isdigit.c ft_memcpy.c ft_strlcpy.c ft_tolower.c ft_isprint.c ft_strlen.c \
ft_toupper.c ft_memmove.c ft_memchr.c ft_memcmp.c ft_calloc.c ft_strdup.c \
ft_substr.c ft_strjoin.c ft_strtrim.c ft_itoa.c ft_strmapi.c ft_putchar_fd.c \
ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_split.c ft_str_c_index.c \
ft_putxchary_fd.c ft_putnbr_u_fd.c ft_utoa.c ft_llutoa_base.c ft_ltoa.c \
ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c ft_lstdelone.c \
ft_lstiter.c ft_lstlast.c ft_lstnew.c ft_lstsize.c ft_lstmap.c \
ft_print_char_2d.c get_next_line.c get_next_line_utils.c

OBJS    = $(SRCS:.c=.o)

NAME    = libft.a
CC              = gcc
RM              = rm -f
CFLAGS  = -Wall -Wextra -Werror
AR              = ar -cr

%.o: %.c	libft.h
			$(CC) $(CFLAGS) -c $< -o $@

$(NAME):	$(OBJS)
			$(AR) $(NAME) $?

all:	$(NAME)

clean:
		$(RM) $(OBJS)

fclean:	clean
		$(RM) $(NAME)

re:		fclean all

.PHONY:	re fclean clean all