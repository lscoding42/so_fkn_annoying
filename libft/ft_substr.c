/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Louisa <Louisa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 19:03:07 by lhafsi            #+#    #+#             */
/*   Updated: 2022/07/19 04:39:15 by Louisa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char *s, unsigned int start, int len)
{
	int		i;
	int		j;
	char	*sub;

	if (!s)
		return (NULL);
	if (start >= (unsigned long int)ft_strlen(s))
		return (ft_strdup(""));
	if (len + start >= (unsigned long int)ft_strlen(s))
		sub = malloc (sizeof (*sub) * (ft_strlen(s) - start + 1));
	else
		sub = malloc(sizeof(*sub) * (len + 1));
	if (!sub)
		return (NULL);
	i = 0;
	j = 0;
	while (s[j])
	{
		if (j >= start && i < len)
			sub[i++] = s[j];
		j++;
	}
	sub[i] = 0;
	return (sub);
}
