/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdiez-cu <vdiez-cu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 12:09:06 by vdiez-cu          #+#    #+#             */
/*   Updated: 2025/03/24 12:09:06 by vdiez-cu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_aux_n_len(int n)
{
	int	i;

	i = 1;
	if (n < 0)
	{
		i++;
	}
	while (n / 10 != 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

static void	ft_aux_lines(char *result, int i, int n)
{
	if (n == -2147483648)
	{
		result[i--] = '8';
		n /= 10;
	}
	if (n < 0)
	{
		result[0] = '-';
		n = -n;
	}
	while (n != 0)
	{
		result[i--] = (n % 10) + '0';
		n /= 10;
	}
}

char	*ft_itoa(int n)
{
	char	*result;
	int		i;

	i = ft_aux_n_len(n);
	result = (char *)malloc(sizeof(char) * (i + 1));
	if (!result)
		return (NULL);
	result[i] = '\0';
	if (n == 0)
	{
		result[0] = '0';
		return (result);
	}
	ft_aux_lines(result, i - 1, n);
	return (result);
}
/*
int	main(void)
{
	int	n = 408985204;
	printf("Resultado: %s\n", ft_itoa(n));
	return(0);
}*/