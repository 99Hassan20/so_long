CC = cc
CFLAGS = -Wall -Werror -Wextra
NAME = so_long
srcs_dir = mandatory
bonus_dir = bonus
BONUS_NAME = so_long_bonus

SRCS = ./mandatory/check_map.c ./mandatory/draw_map.c ./mandatory/free_resources.c ./mandatory/game_init.c ./mandatory/get_next_line.c ./mandatory/get_next_line_utils.c\
	./mandatory/player_utils.c ./mandatory/so_long_utils.c ./mandatory/so_long.c ./mandatory/check_path.c
OBJS = $(SRCS:.c=.o)

SRCS_BONUS = ./bonus/check_map_bonus.c ./bonus/draw_map_bonus.c ./bonus/free_resources_bonus.c \
    ./bonus/game_init_bonus.c ./bonus/get_next_line.c ./bonus/get_next_line_utils.c\
	./bonus/player_utils_bonus.c ./bonus/so_long_utils_bonus.c ./bonus/so_long_bonus.c ./bonus/check_path_bonus.c
OBJS_BONUS = $(SRCS_BONUS:.c=.o)

all: $(NAME)


$(bonus_dir)/%.o : %.c
	$(CC) $(CFLAGS) -c $^

$(NAME) : $(OBJS)
	make -C libft/ all
	make -C libftprintf/ all
	$(CC) $(CFLAGS)  $^ -L./libft -lft -L./libftprintf -lftprintf -lmlx -framework OpenGL -framework AppKit -o $@

bonus: $(BONUS_NAME)

$(BONUS_NAME) : $(OBJS_BONUS)
	make -C libft/ bonus
	make -C libftprintf/ all
	$(CC) $(CFLAGS)  $^ -L./libft -lft -L./libftprintf -lftprintf -lmlx -framework OpenGL -framework AppKit -o $@



clean:
	make -C libft/ clean
	make -C libftprintf/ clean
	rm $(OBJS)
 
fclean: clean
	make -C libft/ fclean
	make -C libftprintf/ fclean
	rm $(NAME)

re: fclean all


clean_bonus:
	make -C libft/ clean
	make -C libftprintf/ clean
	rm $(OBJS_BONUS)

fclean_bonus: clean_bonus
	make -C libft/ fclean
	make -C libftprintf/ fclean
	rm $(BONUS_NAME)

re_bonus: fclean_bonus bonus

rungame:
	./$(NAME) maps/map.ber

runbonus:
	./$(BONUS_NAME) maps/bonus.ber

.PHONY: clean fclean re bonus all