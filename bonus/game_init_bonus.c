/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoigag <hoigag@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 16:33:25 by hoigag            #+#    #+#             */
/*   Updated: 2023/01/26 19:00:15 by hoigag           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_utils_bonus.h"

void	comp_init(t_comp *components)
{
	components->c_count = 0;
	components->p_count = 0;
	components->e_count = 0;
}

void	game_init(t_params *params, char *map_path)
{
	params->is_right = 1;
	params->moves = 0;
	params->collectible_count = 0;
	params->map.content = map_to_matrix(map_path);
	if (!params->map.content)
		error_log("the map file your provided doesn't exist");
	params->is_door_open = 0;
	params->map.height = get_map_height(params->map.content);
	params->map.width = ft_strlen(params->map.content[0]);
	params->img.w = IMG_WIDTH;
	params->img.h = IMG_HEIGHT;
	params->window_width = params->map.width * params->img.w;
	params->window_height = params->map.height * params->img.h;
	params->is_right = 1;
	comp_init(&params->components);
	check_map(params);
	params->mlx.ptr = mlx_init();
	if (!params->mlx.ptr)
		error_log("Could not establish a connection to the X server");
	params->mlx.win = mlx_new_window(params->mlx.ptr,
			params->window_width, params->window_height, "so_long");
	if (!params->mlx.win)
		error_log("Could not open the window");
}
