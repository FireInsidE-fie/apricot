NAME=	apricot
CC=		gcc
CFLAGS=	-Wall -Wextra -Werror
RM=		rm
RMFLAGS=-f
SRCDIR=	src/
SRCS=	$(SRCDIR)apricot.c
OBJS=	$(SRCS:.c=.o)
INCLDIR=include/
INCL=	$(INCLDIR)apricot.h

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) -o $@ $(OBJS)
%.o: %.c
	$(CC) $(CFLAGS) -o $@ -include $(INCL) -c $<
clean:
	$(RM) $(RMFLAGS) $(OBJS)
fclean: clean
	$(RM) $(RMFLAGS) $(NAME)
re: all

.PHONY: all re clean fclean
