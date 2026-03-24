/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdiez-cu <vdiez-cu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 13:31:14 by vdiez-cu          #+#    #+#             */
/*   Updated: 2025/03/21 13:31:14 by vdiez-cu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*aux_s;
	size_t			i;

	aux_s = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (aux_s[i] == (unsigned char)c)
		{
			return (&aux_s[i]);
		}
		i++;
	}
	return (NULL);
}
/*
int	main(void)
{
	const char	s[] = "HOLA";
	int	c = 'O';
	size_t	n = 5;
	printf("Resultado: %s\n", ft_memchr(s, c, n));
	return(0);
}*/