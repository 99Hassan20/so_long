/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoigag <hoigag@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 16:33:25 by hoigag            #+#    #+#             */
/*   Updated: 2023/01/20 15:36:01 by hoigag           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_utils.h"

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
		error_log(".ber file doesn't exist or \
there is empty lines in the map file");
	params->is_door_open = 0;
	params->map.height = get_map_height(params->map.content);
	params->map.width = ft_strlen(params->map.content[0]);
	params->img.w = IMG_WIDTH;
	params->img.h = IMG_HEIGHT;
	params->is_right = 1;
	comp_init(&params->components);
	check_map(params);
	params->mlx.ptr = mlx_init();
	if (!params->mlx.ptr)
		error_log("Could not establish a connection to the X server");
	params->mlx.win = mlx_new_window(params->mlx.ptr,
			params->map.width * 50, params->map.height * 50, "so_long");
	if (!params->mlx.win)
		error_log("Could not open the window");
}
