/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdiez-cu <vdiez-cu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 13:42:33 by vdiez-cu          #+#    #+#             */
/*   Updated: 2025/03/21 13:42:33 by vdiez-cu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*aux_s1;
	unsigned char	*aux_s2;
	size_t			i;

	i = 0;
	aux_s1 = (unsigned char *)s1;
	aux_s2 = (unsigned char *)s2;
	while (i < n)
	{
		if ((aux_s1[i] != aux_s2[i]))
			return (aux_s1[i] - aux_s2[i]);
		i++;
	}
	return (0);
}
/*
int	main(void)
{
	const char	s1[] = "HOLA";
	const	char	s2[] = "HoLA";
	size_t	n = 4;
	printf("Resultado: %d\n", ft_memcmp(s1, s2, n));
	return(0);
}*/