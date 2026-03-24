/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdiez-cu <vdiez-cu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 10:59:23 by vdiez-cu          #+#    #+#             */
/*   Updated: 2025/03/24 10:59:23 by vdiez-cu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*result;
	size_t	i;
	size_t	k;

	i = 0;
	k = 0;
	result = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!result)
		return (NULL);
	while (s1[k] != '\0')
	{
		result[k] = s1[k];
		k++;
	}
	while (k < (ft_strlen(s1) + ft_strlen(s2)))
	{
		result[k] = s2[i];
		k++;
		i++;
	}
	result[k] = '\0';
	return (result);
}
/*
int	main(void)
{
	char const	s1[] = "HOLA_";
	char const	s2[] = "ADIOS";
	printf("Resultado: %s\n", ft_strjoin(s1, s2));
	return(0);
}*/