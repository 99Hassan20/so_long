/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoigag <hoigag@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 20:02:40 by hoigag            #+#    #+#             */
/*   Updated: 2023/01/20 13:12:15 by hoigag           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_UTILS_BONUS_H
# define SO_LONG_UTILS_BONUS_H
# include <mlx.h>
# include <fcntl.h>
# include "../libftprintf/ft_printf.h"
# include "structs_bonus.h"
# include "./get_next_line.h"
# include "../libft/libft.h"

int		get_map_height(char **matrix);
char	**map_to_matrix(char *map);
void	error_log(char *error_message);
int		check_file_name(char *filename);
void	check_map(t_params	*params);
void	draw_image(t_params *params, char *path, int i, int j);
void	draw_map(t_params *params);
void	game_init(t_params *params, char *map_path);
void	move_player(t_params	*params, int x, int y);
int		exit_game(t_params *params);
int		check_map_dimensions(char **matrix);
int		check_path(t_params *params);
void	free_matrix(char **matrix);
int		animate_coin(t_params *params);
#endif