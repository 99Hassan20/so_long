/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoigag <hoigag@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 15:08:30 by hoigag            #+#    #+#             */
/*   Updated: 2023/01/26 19:06:23 by hoigag           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_utils_bonus.h"

static int	is_valid(char **matrix, int x, int y)
{
	return (matrix[x][y] != '1');
}

static char	**copy_matrix(char **matrix)
{
	char	**copy;
	int		i;
	int		j;

	i = 0;
	copy = malloc(sizeof(char *) * (get_map_height(matrix) + 1));
	if (!copy)
		error_log("not enough memory");
	while (matrix[i])
	{
		j = 0;
		copy[i] = malloc(sizeof(char) * (ft_strlen(matrix[0]) + 1));
		if (!copy[i])
			error_log("not enough memory");
		while (matrix[i][j])
		{
			copy[i][j] = matrix[i][j];
			j++;
		}
		copy[i][j] = '\0';
		i++;
	}
	copy[i] = 0;
	return (copy);
}

static void	fill_map(char **matrix, int i, int j)
{
	matrix[i][j] = '1';
	if (is_valid(matrix, i + 1, j))
		fill_map(matrix, i + 1, j);
	if (is_valid(matrix, i - 1, j))
		fill_map(matrix, i - 1, j);
	if (is_valid(matrix, i, j + 1))
		fill_map(matrix, i, j + 1);
	if (is_valid(matrix, i, j - 1))
		fill_map(matrix, i, j - 1);
}

int	check_path(t_params *params)
{
	char	**copy;
	int		i;
	int		j;

	i = 0;
	copy = copy_matrix(params->map.content);
	fill_map(copy, params->player_x, params->player_y);
	while (copy[i])
	{
		j = 0;
		while (copy[i][j])
		{
			if (copy[i][j] == 'C' || copy[i][j] == 'E')
				return (0);
			j++;
		}
		i++;
	}
	free_matrix(copy);
	return (1);
}
