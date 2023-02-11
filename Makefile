ifeq ($(HOSTTYPE),)
	HOSTTYPE := $(shell uname -m)_$(shell uname -s)
endif

NAME	= libft_malloc

CC	= gcc
RM	= rm -f

_SRCS	= malloc.c free.c realloc.c show_alloc_mem.c heap.c block.c globals.c
SRCS	= $(addprefix srcs/, $(_SRCS))

OBJS	= $(SRCS:.c=.o)

CFLAGS	= -Wall -Wextra -Werror

all:	$(NAME)_$(HOSTTYPE).so

%.o: %.c
	$(CC) $(CFLAGS) -I. -Ilibft -c $< -o $@

$(NAME)_$(HOSTTYPE).so:	$(OBJS)
	make -C libft
	$(CC) -shared -fPIC -ldl -Llibft -lft -o $(NAME)_$(HOSTTYPE).so $(OBJS)
	ln -sf $(NAME)_$(HOSTTYPE).so $(NAME).so

clean:
	$(RM) $(OBJS)

fclean:	clean
	$(RM) $(NAME)_$(HOSTTYPE).so $(NAME).so

re:	fclean all

.PHONY: clean fclean re all
