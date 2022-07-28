/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Louisa <Louisa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 00:13:47 by lhafsi            #+#    #+#             */
/*   Updated: 2022/07/28 18:15:54 by Louisa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

int	ft_check_wall(char *line)
{ 
	int	i;

	i = 0;
	// if (line[i] == '\0')
	// 	return (0)
	while (line[i] && line[i] != '\n')
	{	
		if (line[i] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	ft_check_mid(char *line)
{
	int	i;
	int	j;

	j = ft_strlen(line);
	if (line[0] != '1')
		return (0);
	i = 1;
	while (line[i] && i < j - 1)
	{	
		if (ft_is_char_ok(line) == 0)
			return (0);
		i++;
	}
	if (line[i] != '1')
		return (0);
	return (1);
}

int	ft_run_checks(char **map)
{
	int	i;
	int	size;

	size = ft_dstrlen(map);
	if (ft_check_wall(map[0]) == 0 || ft_count_CEP(map) == 0)
		return (0);
	i = 1;
	while (map[i] && i < size - 1)
	{
		//printf("map[%i] == %s\n", i, map[i]);    
		if (ft_check_mid(map[i]) == 0)
			return (0);
		i++;
	}
	//printf("map[%i] == %s\n", i, map[i]);
	if (ft_check_wall(map[i]) == 0)
		return (0);
	return (1);
}

// int	main(int ac, char **av)
// {
// 	if (ac != 2)
// 		return (0);
// 	if (ft_check_mid(av[1]) != 1)
// 		printf("mid not ok\n");
// 	else
// 		printf("ok\n"); 
// 	return (0);
// }
