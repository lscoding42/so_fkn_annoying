/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Louisa <Louisa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 00:13:47 by lhafsi            #+#    #+#             */
/*   Updated: 2022/07/28 23:53:44 by Louisa           ###   ########.fr       */
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

// SRCS
// SRCS > PARSING
// SRCS > PARSING > FILE_NAME.C
int	ft_find_dot(char *av);
int	ft_file_name(char *av);

// SRCS > PARSING > MAP_TO_ARRAY.C
char	*ft_map_to_str(int fd);
int		ft_is_map_valid(char *str);
int		ft_manage_gnl(char *map);

// SRCS > PARSING > CHECK_MAP_UTILS.C
int	ft_check_rectangle(char **map);
int	ft_check_wall(char *line);
int	ft_check_mid(char *line);
int	ft_run_checks(char **map);

// SRCS > PARSING > CHECK_MAP_UTILS.C
int	ft_dstrlen(char **str);
int	ft_check_c(char *line);
int	ft_count_c(char **map, char c);
int	ft_count_CEP(char **map);

#endif