/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Louisa <Louisa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 00:13:47 by lhafsi            #+#    #+#             */
/*   Updated: 2022/07/24 19:05:29 by Louisa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

int	ft_check_wall(char *line)
{ 
	int	i;

	i = 0;
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
	int	e;

	j = ft_strlen(line);
	printf("len = %i\n", j);
	printf("i = 0 // line[0] = %c\n", line[0]);
	if (line[0] != '1')
		return (0);
	i = 1;
	while (line[i] && i < j - 2)
	{	
		if (!(line[i] == 'C' || line[i] == 'P' || line[i] == 'E'
			|| line[i] == '0' || line[i] == '1'))
			return (0);
		printf("i = %i // line[i] = %c\n", i, line[i]);
		i++;
	}
	printf("i = %i // line[i] = %c\n", i, line[i]);
	if (line[i] != '1')
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
