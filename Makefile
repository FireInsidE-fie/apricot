NAME	=	apricot
CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror
RM		=	rm
RMFLAGS	=	-f
SRCDIR	=	src/
SRCS	=	$(SRCDIR)apricot.c
OBJS	=	$(SRCS:.c=.o)
IDIR	=	include
INCL	=	apricot.h \
			raylib.h

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) -framework CoreVideo -framework IOKit -framework Cocoa -framework GLUT -framework OpenGL libraylib.a $(OBJS) -o $@
%.o: %.c
	$(CC) $(CFLAGS) -I$(IDIR) -c $< -o $@
clean:
	$(RM) $(RMFLAGS) $(OBJS)
fclean: clean
	$(RM) $(RMFLAGS) $(NAME)
re: fclean all

.PHONY: all re clean fclean
