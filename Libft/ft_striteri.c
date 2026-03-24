/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdiez-cu <vdiez-cu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 10:43:41 by vdiez-cu          #+#    #+#             */
/*   Updated: 2025/03/27 10:43:41 by vdiez-cu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	i = 0;
	while (s[i] != '\0')
	{
		f(i, &s[i]);
		i++;
	}
}
/*
void	ft_tolower_modificado(unsigned int i, char *s)
{
	if (i > 0 && i < 5)
	{
		*s += 32;
	}
}

int	main(void)
{
	char	s[] = "HOLA";
	ft_striteri(s, &ft_tolower_modificado);
	printf("Resultado: %s\n", s);
	return(0);
}*/