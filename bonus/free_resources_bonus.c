/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_resources_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoigag <hoigag@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 17:36:38 by hoigag            #+#    #+#             */
/*   Updated: 2023/01/18 16:02:55 by hoigag           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_utils_bonus.h"

void	free_matrix(char **matrix)
{
	int	i;

	i = 0;
	while (matrix[i])
	{
		free(matrix[i]);
		i++;
	}
	free(matrix);
}

static void	destroy_window(t_params *params)
{
	free_matrix(params->map.content);
	mlx_destroy_window(params->mlx.ptr, params->mlx.win);
}

int	exit_game(t_params *params)
{
	destroy_window(params);
	exit(0);
	return (0);
}

void	print_map(char **matrix)
{
	while (*matrix)
	{
		ft_printf("%s\n", *matrix);
		matrix++;
	}
}
