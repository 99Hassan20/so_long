/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoigag <hoigag@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 12:39:05 by hoigag            #+#    #+#             */
/*   Updated: 2023/01/26 19:10:24 by hoigag           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_utils.h"

int	get_map_height(char **matrix)
{
	int	i;

	i = 0;
	while (matrix[i])
		i++;
	return (i);
}

char	**map_to_matrix(char *map_path)
{
	char	*text;
	char	*line;
	char	**lines;
	int		fd;

	fd = open(map_path, O_RDONLY);
	if (fd == -1)
		return (0);
	line = get_next_line(fd);
	if (!line)
		error_log("the map file is empty");
	text = 0;
	while (line)
	{
		if (line[0] == '\n')
			error_log("empty lines at the start | middle | end of the file");
		text = ft_strjoin_v2(text, line);
		free(line);
		line = get_next_line(fd);
	}
	if (text[ft_strlen(text) - 1] == '\n')
		error_log("empty line at the end of the file");
	lines = ft_split(text, '\n');
	free(text);
	return (lines);
}

int	check_file_name(char *filename)
{
	int		len;

	len = ft_strlen(filename);
	if (len <= 4)
		return (0);
	len = ft_strlen(filename);
	if (ft_strncmp(".ber", filename + (len - 4), 4) != 0)
		return (0);
	return (1);
}

int	check_map_dimensions(char **matrix)
{
	int	map_height;
	int	map_width;

	map_height = get_map_height(matrix);
	map_width = ft_strlen(matrix[0]);
	return (map_height <= MAX_HEIGHT && map_width <= MAX_WIDTH);
}

void	error_log(char *error_message)
{
	ft_printf("Error\n");
	ft_printf("%s\n", error_message);
	exit(0);
}
//hello