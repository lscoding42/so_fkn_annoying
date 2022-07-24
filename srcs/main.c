/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Louisa <Louisa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 03:54:20 by lhafsi            #+#    #+#             */
/*   Updated: 2022/07/24 19:33:23 by Louisa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
//check leaks ici
int	ft_check_map(int fd)
{
	char	*last;
	char	*gnl;

	gnl = get_next_line(fd);
	if(ft_check_wall(gnl) == 0)
		return (0);
	while (gnl != NULL)
	{
		last = gnl;
		printf("\nlast = %s", last);
		free (gnl);
		gnl = get_next_line(fd);
		if (ft_check_wall(gnl) == 1)
		{
			printf("check last = %i", ft_check_wall(last));
			free (gnl);
			break ;
		}
		printf("gnl = %s\n", gnl);
		if(ft_check_mid(gnl) == 0)
			return (0);
	}
	if(ft_check_wall(last) == 0)
		return (0);
	free(gnl);
	free(last);
	return(1);
}

int	ft_manage_gnl(char *map)
{	
	int	fd;
	int	ok;

	ok = -1;
	fd = open(map, O_RDONLY);
	if (fd > 0)
	{
		ok = ft_check_map(fd);
		close(fd);
	}
	return(ok);
}

int	main(int ac, char **av)
{
	int ok;

	ok = ft_manage_gnl(av[1]);
	if (ac != 2)
		return (0);
	if (ok == -1)
		printf("pb with ft_manage and fd\n");
	else if (ok == 1)
		printf("no pb\n");
	else if (ok == 0)
		printf("pb with map\n"); 
	return (0);
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