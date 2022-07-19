/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Louisa <Louisa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 20:45:40 by lhafsi            #+#    #+#             */
/*   Updated: 2022/07/19 04:38:13 by Louisa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strlcat(char *dst, char *src, int dstsize)
{
	size_t	j;
	size_t	dst_l;
	size_t	src_l;

	dst_l = ft_strlen(dst);
	src_l = ft_strlen(src);
	j = 0;
	if (dst_l >= dstsize)
		return (src_l + dstsize);
	while (src[j] && (j < dstsize - dst_l - 1))
	{
		dst[dst_l + j] = src[j];
		j++;
	}
	dst[dst_l + j] = '\0';
	return (src_l + dst_l);
}
