/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdiez-cu <vdiez-cu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 13:12:32 by vdiez-cu          #+#    #+#             */
/*   Updated: 2025/03/19 13:12:32 by vdiez-cu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (((s1[i] != '\0') || (s2[i] != '\0')) && (s1[i] == s2[i]) && (i < n))
	{
		i++;
	}
	if (s1[i] == s2[i])
	{
		return (0);
	}
	else if (i < n)
	{
		return ((unsigned char)s1[i] - (unsigned char)s2[i]);
	}
	else
	{
		return (0);
	}
}
/*
int	main(void)
{
	char a[]="HOLA";
	char b[]="HoLA";
	unsigned int c = 2;

	printf("Resutado: %d\n", ft_strncmp(a, b, c));
	return(0);
}*/
