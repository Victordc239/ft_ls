/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdiez-cu <vdiez-cu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 12:11:45 by vdiez-cu          #+#    #+#             */
/*   Updated: 2025/03/21 12:11:45 by vdiez-cu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*result;
	size_t	i;
	size_t	size_s;
	char	*aux;

	aux = (char *)s;
	i = 0;
	size_s = ft_strlen(aux);
	result = (char *)malloc(sizeof(char) * size_s + 1);
	if (!result)
		return (NULL);
	while (aux[i] != '\0')
	{
		result[i] = aux[i];
		i++;
	}
	result[i] = '\0';
	return (result);
}
/*
int	main(void)
{
	const char	s[] = "HOLA";
	printf("Resultado: %s",ft_strdup(s));
	return (0);
}*/