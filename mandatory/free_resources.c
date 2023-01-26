/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_resources.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoigag <hoigag@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 17:36:38 by hoigag            #+#    #+#             */
/*   Updated: 2023/01/17 12:19:42 by hoigag           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_utils.h"

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
	free(params->mlx.ptr);
	exit(0);
}

int	exit_game(t_params *params)
{
	ft_printf("game exited\n");
	destroy_window(params);
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
