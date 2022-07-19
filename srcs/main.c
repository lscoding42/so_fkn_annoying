/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Louisa <Louisa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 03:54:20 by lhafsi            #+#    #+#             */
/*   Updated: 2022/07/19 14:43:35 by Louisa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_count_lines(char *map)
{
	int		fd;
	int		count;
	char	*gnl;

	fd = open(map, O_RDONLY);
	if (fd > 0)
	{
		count = 0;
		gnl = get_next_line(fd);
		while (gnl != NULL)
		{ 
			count++;
			free (gnl);
			gnl = get_next_line(fd);
		}
		close (fd);
		free (gnl);
		return (count);
	}
	else
		write(1, "Error counting lines\n", 21);
	return (-1);
}

// int	main(int ac, char **av)
// {
// 	if (ac != 2)
// 		return (0);
// 	if (ft_count_lines(av[1]) != -1)
// 		printf("lines: %i\n", ft_count_lines(av[1]));
// 	else
// 		printf("Incorrect\n");
// 	return (0);
// }

int	main(int ac, char **av)
{
	if (ac != 2)
		return (0);
	if (ft_count_lines(av[1]) != -1)
		printf("lines: %i\n", ft_count_lines(av[1]));
	else
		printf("Incorrect\n");
	return (0);
}