/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdiez-cu <vdiez-cu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 10:53:47 by vdiez-cu          #+#    #+#             */
/*   Updated: 2025/03/27 10:53:47 by vdiez-cu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*result;
	unsigned int	i;
	size_t			len;
	char			c;

	if (!s || !f)
		return (NULL);
	len = 0;
	while (s[len] != '\0')
		len++;
	result = (char *)malloc(sizeof(char) * (len + 1));
	i = 0;
	if (!result)
		return (NULL);
	while (i < len)
	{
		c = s[i];
		result[i] = f(i, c);
		i++;
	}
	result[i] = '\0';
	return (result);
}
/*
char	ft_tolower_modificado(unsigned int i, char s)
{
	if (i > 0 && i < 5)
	{
		s += 32;
	}
	return (s);
}

int	main(void)
{
	char	s[] = "HOLA";
	printf("Resultado: %s\n", ft_strmapi(s, &ft_tolower_modificado));
	return(0);
}*/