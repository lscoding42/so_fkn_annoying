/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Louisa <Louisa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 03:54:20 by lhafsi            #+#    #+#             */
/*   Updated: 2022/07/28 13:19:42 by Louisa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

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
	str = ft_map_to_str(fd)
;	if (fd > 0)
	{
		if (ft_is_map_valid(str) == 1)
			ok = 1;
		close(fd);
	}
	return(ok);
}

int	main(int ac, char **av)
{
	int		ok;

	ok = ft_manage_gnl(av[1]);
	if (ac != 2)
		return (0);
	if (ok == -1)
		printf("pb with map\n");
	else if (ok == 1)
		printf("no pb\n");
	return (0);
}

// checks manquants 
// 1. check nom fichier = min 1 char avant le .ber (sinon = fichier cache)
// 2. check fichier vide

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