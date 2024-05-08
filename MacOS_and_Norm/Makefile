NAME = fdf

CC = cc
CFLAGS = -Wall -Wextra -Werror -I minilibx_macos
LDFLAGS = -Lminilibx_macos -lmlx -framework OpenGL -framework AppKit

SRCS_DIR = src/
OBJS_DIR = obj/
HEADERS_DIR = header/

SRCS_NAME = color_norm_1.c \
			color.c \
			coordinate_utils_norm_1.c \
			coordinate_utils.c \
			draw_shape_norm_1.c \
			draw_shape_norm_2.c \
			draw_shape_norm_3.c \
			draw_shape.c \
			draw_utils.c \
			error_handling_norm_1.c \
			error_handling.c \
			fdf_start.c \
			fdf_utils.c \
			file_control_norm_1.c \
			file_control.c \
			for_math_norm_1.c \
			for_math.c \
			get_next_line_utils.c \
			get_next_line.c \
			images_norm_1.c \
			images.c \
			input.c \
			landscape_utils.c \
			landscape.c \
			libft_funcs_norm_1.c \
			libft_funcs.c \
			main.c \
			render.c \
			update_norm_1.c \
			update_norm_2.c \
			update_norm_3.c \
			update_norm_4.c \
			update_utils.c \
			update.c \
			utils.c \
			validation.c \

HEADERS = color.h \
		  draw.h \
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
	$(CC) $(CFLAGS) $^ -o $@ $(LDFLAGS)

$(OBJS_DIR)%.o: $(SRCS_DIR)%.c $(addprefix $(HEADERS_DIR), $(HEADERS)) Makefile
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: clean all

.PHONY: all clean fclean re