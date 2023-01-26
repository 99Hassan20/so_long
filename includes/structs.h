/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoigag <hoigag@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 16:35:12 by hoigag            #+#    #+#             */
/*   Updated: 2023/01/19 15:33:27 by hoigag           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H
# define W_KEY 13
# define A_KEY 0
# define D_KEY 2
# define S_KEY 1
# define UP_KEY 126
# define LEFT_KEY 123
# define RIGHT_KEY 124
# define DOWN_KEY 125
# define ESC_KEY 53
# define ON_KEYPRESS 2
# define ON_DESTROY 17
# define IMG_WIDTH 50
# define IMG_HEIGHT 50
# define MAX_HEIGHT 25
# define MAX_WIDTH 51

typedef struct s_mlx
{
	void	*ptr;
	void	*win;
}	t_mlx;

typedef struct s_comp
{
	int	p_count;
	int	e_count;
	int	c_count;
}	t_comp;

typedef struct s_img
{
	void	*img_ptr;
	int		w;
	int		h;
}	t_img;

typedef struct s_map
{
	int		width;
	int		height;
	char	**content;
}	t_map;

typedef struct s_prams
{
	int		moves;
	int		collectible_count;
	int		player_x;
	int		player_y;
	int		is_right;
	int		door_x;
	int		door_y;
	int		is_door_open;
	t_map	map;
	t_mlx	mlx;
	t_img	img;
	t_comp	components;
}	t_params;

#endif