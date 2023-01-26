/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoigag <hoigag@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 12:36:28 by hoigag            #+#    #+#             */
/*   Updated: 2023/01/17 16:09:09 by hoigag           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_UTILS_H
# define SO_LONG_UTILS_H
# include <mlx.h>
# include <fcntl.h>
# include "../libftprintf/ft_printf.h"
# include "./get_next_line.h"
# include "../libft/libft.h"
# include "structs.h"

int		get_map_height(char **matrix);
char	**map_to_matrix(char *map);
void	error_log(char *error_message);
int		check_file_name(char *filename);
void	check_map(t_params	*params);
void	draw_map(t_params *params);
void	game_init(t_params *params, char *map_path);
void	move_player(t_params	*params, int x, int y);
int		exit_game(t_params *params);
int		check_path(t_params *params);
void	free_matrix(char **matrix);
void	print_map(char **matrix);
int		check_map_dimensions(char **matrix);
#endif