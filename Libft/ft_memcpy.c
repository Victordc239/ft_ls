/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdiez-cu <vdiez-cu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 12:41:44 by vdiez-cu          #+#    #+#             */
/*   Updated: 2025/03/21 12:41:44 by vdiez-cu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char	*aux_src;
	char	*aux_dest;
	size_t	i;

	if (!dest && !src)
		return (NULL);
	i = 0;
	aux_dest = (char *) dest;
	aux_src = (char *) src;
	while (i < n)
	{
		aux_dest[i] = aux_src[i];
		i++;
	}
	return (dest);
}
/*
int	main(void)
{
	const char	src[] = "HOLA";
	char	dest[20];
	size_t	n = 5;

	printf("Resultado:%s\n", ft_memcpy(dest, src, n));
	return(0);
}*/