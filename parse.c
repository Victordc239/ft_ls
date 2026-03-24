/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victor <victor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 14:26:48 by victor            #+#    #+#             */
/*   Updated: 2026/03/24 15:20:37 by victor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	init_flags(t_flags *flag)
{
	flag->l = 0;
	flag->uper_r = 0;
	flag->a = 0;
	flag->r = 0;
	flag->t = 0;
}

int	set_option_flag(t_flags *flag, char c)
{
	if (c == 'l')
		flag->l = 1;
	else if (c == 'R')
		flag->uper_r = 1;
	else if (c == 'a')
		flag->a = 1;
	else if (c == 'r')
		flag->r = 1;
	else if (c == 't')
		flag->t = 1;
	else
		return (0);
	return (1);
}

int	parse_options(int argc, char **argv, t_flags *flag, int *start)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc && argv[i][0] == '-' && argv[i][1] != '\0')
	{
		if (argv[i][1] == '-' && argv[i][2] == '\0')
		{
			i++;
			break ;
		}
		j = 1;
		while (argv[i][j] != '\0')
		{
			if (!set_option_flag(flag, argv[i][j]))
			{
				ft_putstr_fd("ERROR: flag/option invalid\n", 2);
				return (0);
			}
			j++;
		}
		i++;
	}
	*start = i;
	return (1);
}

int	count_targets(int argc, int start)
{
	if (start >= argc)
		return (1);
	return (argc - start);
}

char	**build_targets(int argc, char **argv, int start)
{
	char	**targets;
	int		count;
	int		i;

	count = count_targets(argc, start);
	targets = malloc(sizeof(char *) * (count + 1));
	if (!targets)
		return (NULL);
	i = 0;
	if (start >= argc)
	{
		targets[i] = ft_strdup(".");
		if (!targets[i])
		{
			free(targets);
			return (NULL);
		}
		i++;
	}
	else
	{
		while (start < argc)
		{
			targets[i] = ft_strdup(argv[start]);
			if (!targets[i])
			{
				while (i > 0)
					free(targets[--i]);
				free(targets);
				return (NULL);
			}
			i++;
			start++;
		}
	}
	targets[i] = NULL;
	return (targets);
}

void	free_targets(char **targets)
{
	int	i;

	if (!targets)
		return ;
	i = 0;
	while (targets[i])
	{
		free(targets[i]);
		i++;
	}
	free(targets);
}
