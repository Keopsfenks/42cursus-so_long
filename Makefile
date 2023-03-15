SRCS = ./srcs/mandatory_part/main.c \
		./srcs/mandatory_part/utils.c  \
		./srcs/mandatory_part/map_function.c \
		./srcs/mandatory_part/map_function_2.c \
		./srcs/mandatory_part/map_function_3.c \
		./srcs/mandatory_part/map_render_function.c \
		./srcs/mandatory_part/key_event_function.c
SRCBS = ./srcs/bonus_part/main_bonus.c
NAME = so_long
CC = gcc
CFLAGS = -Wall -Wextra -Werror
LFLAGS = -framework AppKit -framework OpenGL -L./srcs/libary/mlx -lmlx
MLX = ./srcs/libary/mlx/libmlx.a
FT_PRINTF = ./srcs/libary/ft_printf/libftprintf.a
GET_NEXT_LINE = ./srcs/libary/get_next_line/get_next_line.c ./srcs/libary/get_next_line/get_next_line_utils.c
FT_LIBFT = ./srcs/libary/ft_libft/libft.a
RM = rm -rf
LIBC = ar -rcs

all: $(MLX) $(NAME)

$(NAME): $(SRCS) $(MLX) $(FT_PRINTF) $(FT_LIBFT) $(GET_NEXT_LINE)
	@gcc $(CFLAGS) $(LFLAGS) $(SRCS) $(FT_PRINTF) $(FT_LIBFT) $(GET_NEXT_LINE) -o $(NAME)
	@echo "leblebi"

bonus : $(SRCBS) $(MLX) $(FT_PRINTF) $(FT_LIBFT) $(GET_NEXT_LINE)
	@gcc $(CFLAGS) $(LFLAGS) $(SRCBS) $(FT_PRINTF) $(FT_LIBFT) $(GET_NEXT_LINE) -o $(NAME)
	@echo "leblebi"

$(MLX) :
	@make -C ./srcs/libary/mlx

$(FT_PRINTF) :
	@make -C ./srcs/libary/ft_printf

$(FT_LIBFT) :
	@make -C ./srcs/libary/ft_libft

clean:

fclean: clean
	@rm -rf $(NAME)
	@make clean -C ./srcs/libary/mlx
	@make fclean -C ./srcs/libary/ft_printf
	@make fclean -C ./srcs/libary/ft_libft

re: fclean all

.PHONY: all bonus clean fclean re .c.o