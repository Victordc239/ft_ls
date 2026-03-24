/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdiez-cu <vdiez-cu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 11:18:35 by vdiez-cu          #+#    #+#             */
/*   Updated: 2025/03/20 11:18:35 by vdiez-cu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	size_t			i;
	unsigned char	new_c;

	if (c < 0 || c > 255)
		new_c = (unsigned char)(c % 256);
	else
		new_c = (unsigned char)c;
	i = 0;
	while ((unsigned char)str[i] != '\0')
	{
		if ((unsigned char)str[i] == new_c)
			return ((char *)&str[i]);
		i++;
	}
	if (c == '\0' || new_c == '\0')
		return ((char *)&str[i]);
	return (NULL);
}
/*
int	main(void)
{
	char	str[] = "\0";
	int	letra = 'L';
	printf("Resultado: %d\n", ft_strchr(str, letra));
	return(0);
}*/