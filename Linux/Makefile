NAME = fdf

CC = cc
CFLAGS = -I minilibx_macos
LDFLAGS = -Lminilibx_macos -lmlx -framework OpenGL -framework AppKit

SRCS_DIR = src/
OBJS_DIR = obj/
HEADERS_DIR = header/

SRCS_NAME = draw_shape.c \
			draw_utils.c \
			error_handling.c \
			fdf_start.c \
			fdf_utils.c \
			file_control.c \
			for_math.c \
			get_next_line_utils.c \
			get_next_line.c \
			images.c \
			input.c \
			landscape_utils.c \
			landscape.c \
			libft_funcs.c \
			main.c \
			render.c \
			update_utils.c \
			update.c \
			utils.c \
			validation.c \

HEADERS = draw.h \
		  fdf.h \
		  file_control.h \
		  for_math.h \
		  get_next_line.h \
		  images.h \
		  landscape.h \
		  utils.h \

OBJS = $(addprefix $(OBJS_DIR), $(OBJS_NAME))
OBJS_NAME = $(SRCS_NAME:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

$(OBJS_DIR)%.o: $(SRCS_DIR)%.c $(addprefix $(HEADERS_DIR), $(HEADERS)) Makefile
	$(CC) $(CFLAGS) -c $< -o $@

%.o: %.c
	$(CC) -Wall -Wextra -Werror -I/usr/include -Imlx_linux -O3 -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: clean all

.PHONY: all clean fclean re