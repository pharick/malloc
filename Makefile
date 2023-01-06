ifeq ($(HOSTTYPE),)
	HOSTTYPE := $(shell uname -m)_$(shell uname -s)
endif

NAME	= libft_malloc

CC	= gcc
RM	= rm -f

_SRCS	= malloc.c free.c heap.c block.c
SRCS	= $(addprefix srcs/, $(_SRCS))

OBJS	= $(SRCS:.c=.o)

CFLAGS	= -Wall -Wextra -Werror

all:	$(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -I. -Ilibft -c $< -o $@

$(NAME):	$(OBJS)
	make -C libft
	$(CC) -shared -Llibft -lft -o $(NAME)_$(HOSTTYPE).so $(OBJS)
	ln -s $(NAME)_$(HOSTTYPE).so $(NAME).so

clean:
	$(RM) $(OBJS)

fclean:	clean
	$(RM) $(NAME)_$(HOSTTYPE).so $(NAME).so

re:	fclean all

.PHONY: clean fclean re all
