/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdiez-cu <vdiez-cu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 11:41:49 by vdiez-cu          #+#    #+#             */
/*   Updated: 2025/03/20 11:41:49 by vdiez-cu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	size_t		i;
	char		*result;

	i = 0;
	result = NULL;
	while (((char *)str)[i] != '\0')
	{
		if (((unsigned char *)str)[i] == (unsigned char)c)
			result = ((char *)&str[i]);
		i++;
	}
	if ((unsigned char) c == '\0')
		return ((char *)&str[i]);
	return (result);
}
/*
int	main(void)
{
	char	str[] = "HOLA";
	int	letra = 'L';
	printf("Resultado: %d\n", ft_strrchr(str, letra));
	return(0);
}*/