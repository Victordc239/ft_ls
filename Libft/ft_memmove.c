/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdiez-cu <vdiez-cu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 12:54:43 by vdiez-cu          #+#    #+#             */
/*   Updated: 2025/03/21 12:54:43 by vdiez-cu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*aux_dest;
	char	*aux_src;

	aux_dest = (char *)dest;
	aux_src = (char *)src;
	if (dest == src || n == 0)
		return (dest);
	else if (dest < src)
		return (ft_memcpy(dest, src, n));
	else
	{
		aux_dest += n;
		aux_src += n;
		while (n--)
			*(--aux_dest) = *(--aux_src);
	}
	return (dest);
}
/*
int	main(void)
{
	char	src[] = "HOLA";
	char	dest[20];
	size_t	n = 4;
	printf("Resultado: %s\n", ft_memmove(dest, src, n));
	return(0);
}*/