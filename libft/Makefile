NAME		= libft.a

CC			= gcc
AR			= ar rcs
RM			= rm -f

SRCS		= ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c \
			  ft_memchr.c ft_memcmp.c ft_strlen.c ft_strlcpy.c ft_strlcat.c \
			  ft_strchr.c ft_strrchr.c ft_strnstr.c ft_strncmp.c ft_atoi.c \
			  ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
			  ft_toupper.c ft_tolower.c ft_calloc.c ft_strdup.c ft_substr.c \
			  ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c \
			  ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
			  ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c \
			  ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c \
			  ft_lstmap.c ft_numlen.c ft_putnstr_fd.c ft_strcmp.c \
			  ft_realloc.c ft_free_tokens.c ft_tokens_len.c ft_lst_to_array.c \
			  gnl/get_next_line.c gnl/get_next_line_utils.c ft_putstr.c \
			  ft_putendl.c ft_isspace.c ft_lst_remove_if.c ft_str_tolower.c \
			  ft_free_ntokens.c ft_putchar.c ft_lst_at.c

OBJS		= $(SRCS:.c=.o)

CFLAGS		= -Wall -Wextra -Werror
DEPS		= libft.h

.c.o:		$(DEPS)
			$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

$(NAME):	$(OBJS)
			$(AR) $(NAME) $(OBJS)

clean:
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

all:		$(NAME)

.PHONY: clean fclean re all
