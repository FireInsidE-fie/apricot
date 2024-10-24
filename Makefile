NAME=	apricot
CC=		gcc
CFLAGS=	-Wall -Wextra -Werror
RM=		rm
RMFLAGS=-f
SRCDIR=	src/
SRCS=	$(SRCDIR)apricot.c
OBJS=	$(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) -o $@ $(OBJS) `sd12-config --cflags --libs`
%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $<
clean:
	$(RM) $(RMFLAGS) $(OBJS)
fclean: clean
	$(RM) $(RMFLAGS) $(NAME)
re: all

.PHONY: all re clean fclean
