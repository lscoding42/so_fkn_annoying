/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Louisa <Louisa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 03:54:20 by lhafsi            #+#    #+#             */
/*   Updated: 2022/07/29 07:10:55 by Louisa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	main(int ac, char **av)
{
	int		ok;

	if (ac != 2 || !av[1])
	{
		write(1,"Error\n", 6);
		write(1,"Input incorrect: enter 1 existing map file.\n", 35);
		return (0);
	}
	if (ft_file_name(av[1]) == 0)
	{
		write(1,"Error\n", 6);
		write(1,"File name incorrect: name should include at least 1 letter and end with the .ber extension.\n", 92);
		return (0);
	}
	ok = ft_manage_gnl(av[1]);
	if (ok == -1)
	{
		write(1,"Error\n", 6);
		write(1,"Map format incorrect.\n", 22);
	}
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