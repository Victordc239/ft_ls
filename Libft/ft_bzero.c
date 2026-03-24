/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdiez-cu <vdiez-cu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 12:45:24 by vdiez-cu          #+#    #+#             */
/*   Updated: 2025/03/19 12:45:24 by vdiez-cu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *str, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((char *)str)[i] = 0;
		i++;
	}
}
/*
int	main(void)
{
	char	str[] = "HOLA ADIOS";
	int	n = 11;
	printf("Resultado antes: %s\n", str);
	ft_bzero(str, 4);
	printf("Resultado despues: %s\n", str);
	return(0);
}*/