/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_to_array.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Louisa <Louisa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 17:00:20 by lhafsi            #+#    #+#             */
/*   Updated: 2022/07/28 19:45:56 by Louisa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

//check leaks dans ft_check_map

char	*ft_map_to_str(int fd)
{
	char	*gnl;
	char	*str;

	gnl = get_next_line(fd);
	str = malloc(sizeof(char) * (ft_strlen(gnl) + 1));
	while (gnl != NULL)
	{
		str = ft_strjoin(str, gnl);
		free (gnl);
		gnl = get_next_line(fd);
	}
	free(gnl);
	return(str);
}

int	ft_is_map_valid(char *str)
{
	char **map;
	int i;

	map = ft_split(str, '\n');
	if (map == NULL)
		return (0);
	if (ft_run_checks(map) == 0)
		return (0);
	return (1);
}

int	ft_manage_gnl(char *map)
{	
	int		fd;
	int		ok;
	char	*str;

	ok = -1;
	fd = open(map, O_RDONLY);
	str = ft_map_to_str(fd);
	if (fd > 0)
	{
		if (ft_is_map_valid(str) == 1)
			ok = 1;
		close(fd);
	}
	return(ok);
}