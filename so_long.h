/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Louisa <Louisa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 00:13:47 by lhafsi            #+#    #+#             */
/*   Updated: 2022/07/19 04:58:15 by Louisa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "get_next_line.h"
# include "libft/libft.h"
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>

typedef	struct s_mlx
{
	void	*init;
	void	*win;
	void	*img;
	int		w;
	int		h;
}		t_mlx;

typedef struct	s_img {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_img;

// MAIN.C
int	ft_count_lines(char *map);

// SRCS
// SRCS > PARSING
// SRCS > PARSING > CHECK_MAP_UTILS.C
int	ft_check_wall(char *line);
int	ft_check_mid(char *line);
// int	ft_check_map(char **map);
#endif