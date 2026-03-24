/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdiez-cu <vdiez-cu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 11:32:01 by vdiez-cu          #+#    #+#             */
/*   Updated: 2025/03/18 11:32:01 by vdiez-cu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;

	i = ft_strlen(dst);
	j = 0;
	if (size <= i)
		return (size + ft_strlen(src));
	while (src[j] != '\0' && ((i + j) < (size - 1)))
	{
		dst[i + j] = src[j];
		j++;
	}
	dst[i + j] = '\0';
	return (i + ft_strlen(src));
}
/*
int	main(void)
{
	char	src[] = "ADIOS";
	char	dest[20] = "HOLA ";
	size_t	size = 20;
	printf("Resultado: %d\n", ft_strlcat(dest,src,size));
	printf("Dest :%s\n", dest);
	return (0);
}*/