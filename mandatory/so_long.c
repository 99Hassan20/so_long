/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoigag <hoigag@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 22:26:51 by hoigag            #+#    #+#             */
/*   Updated: 2023/01/20 16:12:42 by hoigag           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_utils.h"

int	handle_key_press(int keycode, t_params *params)
{
	if (keycode == W_KEY || keycode == UP_KEY)
		move_player(params, -1, 0);
	else if (keycode == S_KEY || keycode == DOWN_KEY)
		move_player(params, 1, 0);
	else if (keycode == D_KEY || keycode == RIGHT_KEY)
	{
		params->is_right = 1;
		move_player(params, 0, 1);
	}
	else if (keycode == A_KEY || keycode == LEFT_KEY)
	{
		params->is_right = 0;
		move_player(params, 0, -1);
	}
	else if (keycode == ESC_KEY)
		exit_game(params);
	return (0);
}

int	main(int argc, char **argv)
{
	char		*map_path;
	t_params	params;

	if (argc != 2)
		error_log("plese provide the path to the map\nusage : ./so_long map");
	map_path = argv[1];
	if (!check_file_name(map_path))
		error_log("please provide a file that ends with the extension .ber");
	game_init(&params, map_path);
	draw_map(&params);
	mlx_hook(params.mlx.win, ON_KEYPRESS, 0, handle_key_press, &params);
	mlx_hook(params.mlx.win, ON_DESTROY, 0, exit_game, &params);
	mlx_loop(params.mlx.ptr);
	return (0);
}
