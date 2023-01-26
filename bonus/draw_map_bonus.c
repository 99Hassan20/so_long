/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoigag <hoigag@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 16:51:56 by hoigag            #+#    #+#             */
/*   Updated: 2023/01/20 14:58:37 by hoigag           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_utils_bonus.h"

void	draw_image(t_params *params, char *path, int i, int j)
{
	params->img.img_ptr = mlx_xpm_file_to_image(params->mlx.ptr,
			path, &params->img.w, &params->img.h);
	mlx_put_image_to_window(params->mlx.ptr, params->mlx.win,
		params->img.img_ptr, j * params->img.w, i * params->img.h);
	mlx_destroy_image(params->mlx.ptr, params->img.img_ptr);
}

static void	something(t_params *params, int i, int j)
{
	if (params->map.content[i][j] != '1')
		draw_image(params, "textures/free.xpm", i, j);
	if (params->map.content[i][j] == '1')
		draw_image(params, "textures/wall.xpm", i, j);
	else if (params->map.content[i][j] == 'C')
		draw_image(params, "textures/collectible.xpm", i, j);
	else if (params->map.content[i][j] == 'E' && !params->is_door_open)
		draw_image(params, "textures/door_closed.xpm", i, j);
	else if (params->map.content[i][j] == 'E' && params->is_door_open)
		draw_image(params, "textures/door_open.xpm", i, j);
	else if (params->map.content[i][j] == 'e')
	{
		draw_image(params, "textures/door_closed.xpm",
			params->door_x, params->door_y);
		if (params->is_right)
			draw_image(params, "textures/player.xpm",
				params->player_x, params->player_y);
		else
			draw_image(params, "textures/player_left.xpm",
				params->player_x, params->player_y);
	}
	else if (params->map.content[i][j] == 'P' && params->is_right)
		draw_image(params, "textures/player.xpm", i, j);
	else if (params->map.content[i][j] == 'P' && !params->is_right)
		draw_image(params, "textures/player_left.xpm", i, j);
}

void	draw_map(t_params *params)
{
	int		i;
	int		j;
	char	*n;

	i = 0;
	mlx_clear_window(params->mlx.ptr, params->mlx.win);
	while (i < params->map.height)
	{
		j = 0;
		while (j < params->map.width)
		{
			something(params, i, j);
			j++;
		}
		i++;
	}
	n = ft_itoa(params->moves);
	mlx_string_put(params->mlx.ptr, params->mlx.win,
		params->window_width / 2, 0, 0xFFFFFF, n);
	free(n);
}
