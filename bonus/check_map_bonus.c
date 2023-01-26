/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoigag <hoigag@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 10:38:18 by hoigag            #+#    #+#             */
/*   Updated: 2023/01/19 23:51:25 by hoigag           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_utils_bonus.h"

static int	check_walls(t_map map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < map.height)
	{
		if (map.content[i][0] != '1' || map.content[i][map.width - 1] != '1')
			return (0);
		if (i == 0 || i == map.height - 1)
		{
			j = 1;
			while (j < map.width - 1)
			{
				if (map.content[i][j] != '1')
					return (0);
				j++;
			}
		}
		i++;
	}
	return (1);
}

static void	update_components(t_params *params, int i, int j)
{
	if (params->map.content[i][j] == 'E')
	{
		params->components.e_count++;
		params->door_x = i;
		params->door_y = j;
	}
	if (params->map.content[i][j] == 'P')
	{
		params->components.p_count++;
		params->player_x = i;
		params->player_y = j;
	}
	if (params->map.content[i][j] == 'C')
		params->components.c_count++;
}

static int	check_map_components(t_params *params)
{
	int			i;
	int			j;

	i = 0;
	while (i < params->map.height)
	{
		j = 0;
		while (j < params->map.width)
		{
			if (!ft_strchr("01CPE", params->map.content[i][j]))
				return (0);
			update_components(params, i, j);
			j++;
		}
		i++;
	}
	return (params->components.e_count == 1 && params->components.p_count == 1
		&& params->components.c_count >= 1);
}

static int	check_if_map_is_rect(t_map map)
{
	int	i;

	i = 0;
	while (map.content[i])
	{
		if ((int)ft_strlen(map.content[i]) != map.width)
			return (0);
		i++;
	}
	return (1);
}

void	check_map(t_params *params)
{
	if (!check_if_map_is_rect(params->map))
		error_log("the map must be a rectangle");
	else if (!check_map_dimensions(params->map.content))
		error_log("fin ghadi, fin awa ghadi max_width = 51, max_height = 25");
	else if (!check_walls(params->map))
		error_log("the map must be surrounded by walls");
	else if (!check_map_components(params))
		error_log("the map should contain 1 E, one P and at least one C");
	else if (!check_path(params))
		error_log("Invalid path :(");
}
