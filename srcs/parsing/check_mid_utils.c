/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_mid_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Louisa <Louisa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 00:13:47 by lhafsi            #+#    #+#             */
/*   Updated: 2022/07/28 19:17:07 by Louisa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

int	ft_dstrlen(char **str)
{
	int i;
	
	i = 0;
	while (str[i])
		i++;
	return(i);
}

int	ft_check_c(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (!(line[i] == 'C' || line[i] == 'P' || line[i] == 'E'
			|| line[i] == '0' || line[i] == '1'))
			return (0);
		i++;
	}
	return (1);
}

int	ft_count_c(char **map, char c)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	count = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == c)
				count++;
			j++;
		}
		i++;
	}
	return (count);
}

int	ft_count_CEP(char **map)
{
	int	C;
	int E;
	int	P;

	C = ft_count_c(map, 'C');
	E = ft_count_c(map, 'E');
	P = ft_count_c(map, 'P');
	if (C < 1 || E < 1 || P < 1)
		return (0);
	return (1);
}