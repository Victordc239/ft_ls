/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdiez-cu <vdiez-cu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 12:26:34 by vdiez-cu          #+#    #+#             */
/*   Updated: 2025/03/21 12:26:34 by vdiez-cu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*result;

	if (count == 0 || size == 0)
	{
		result = (void *)malloc(0);
		return (result);
	}
	if (((count * size) / size) != count)
		return (NULL);
	result = (void *)malloc(count * size);
	if (!result)
		return (NULL);
	ft_bzero(result, count * size);
	return (result);
}
/*
int main(void)
{
    size_t	count = 5;
    size_t	size = 1;
	size_t	i = 0;
    char *s = ft_calloc(count, size);

    if (!s)
    {
        printf("Error\n");
        return (1);
    }
    while (i < count)
    {
        printf("s[%ld] = %d\n", i, s[i]);
        i++;
    }
	free(s);
	return(0);
}*/