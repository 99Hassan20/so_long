/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_utils_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoigag <hoigag@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 17:17:13 by hoigag            #+#    #+#             */
/*   Updated: 2023/01/26 16:25:56 by hoigag           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_utils_bonus.h"

static void	set_player_pos(t_params *params, int x, int y)
{
	params->player_x = x;
	params->player_y = y;
}

static void	update_map(t_params *params, int x, int y, char c)
{
	if (params->map.content[params->player_x][params->player_y] == 'e')
		params->map.content[params->player_x][params->player_y] = 'E';
	else
		params->map.content[params->player_x][params->player_y] = '0';
	set_player_pos(params, params->player_x + x, params->player_y + y);
	params->map.content[params->player_x][params->player_y] = c;
}

void	move_player(t_params	*params, int x, int y)
{
	if (params->map.content[params->player_x + x][params->player_y + y] == 'E'
		&& params->collectible_count == params->components.c_count)
	{
		ft_printf("you win\n");
		exit_game(params);
	}
	else if (params->map.content
		[params->player_x + x][params->player_y + y] == 'E')
	{
		params->moves += 1;
		update_map(params, x, y, 'e');
	}
	else if (params->map.content
		[params->player_x + x][params->player_y + y] != '1')
	{
		params->moves += 1;
		if (params->map.content
			[params->player_x + x][params->player_y + y] == 'C')
			params->collectible_count += 1;
		if (params->collectible_count == params->components.c_count)
			params->is_door_open = 1;
		update_map(params, x, y, 'P');
	}
	draw_map(params);
}
