NAME = FdF

CC = cc
CFLAGS = -Wall -Wextra -Werror -I minilibx_macos
LDFLAGS = -Lminilibx_macos -lmlx -framework OpenGL -framework AppKit

HEADERS = header/FdF.h

SRCS_DIR = src/
OBJS_DIR = obj/

SRCS_NAME = main.c \

OBJS = $(addprefix $(OBJS_DIR), $(OBJS_NAME))
OBJS_NAME = $(SRCS_NAME:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

$(OBJS_DIR)%.o: $(SRCS_DIR)%.c $(HEADERS) Makefile
	$(CC) $(CFLAGS) -c $< -o $@

%.o: %.c
	$(CC) -Wall -Wextra -Werror -I/usr/include -Imlx_linux -O3 -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: clean all

.PHONY: all clean fclean re