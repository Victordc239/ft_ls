/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victor <victor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 10:55:32 by victor            #+#    #+#             */
/*   Updated: 2026/03/24 16:16:01 by victor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int	main(int argc, char **argv)
{
	t_flags	flag;
	int		start;
	char	**targets;
	int		i;
	int		dir_count;
	int		file_count;

	init_flags(&flag);
	if (!parse_options(argc, argv, &flag, &start))
		return (1);
	targets = build_targets(argc, argv, start);
	if (!targets)
		return (1);
	sort_targets(targets, &flag);
	if (flag.r)
		reverse_targets(targets);
	dir_count = 0;
	file_count = 0;
	i = 0;
	while (targets[i])
	{
		if (is_directory(targets[i]))
			dir_count++;
		else
			file_count++;
		i++;
	}
	i = 0;
	while (targets[i])
	{
		if (!is_directory(targets[i]))
			list_path(targets[i], &flag);
		i++;
	}
	if (file_count > 0 && dir_count > 0)
		ft_putstr_fd("\n", 1);
	i = 0;
	while (targets[i])
	{
		if (is_directory(targets[i]))
		{
			if (file_count > 0 || dir_count > 1)
				print_directory_header(targets[i]);
			list_directory_recursive(targets[i], &flag, 0);
			dir_count--;
			if (dir_count > 0)
				ft_putstr_fd("\n", 1);
		}
		i++;
	}
	free_targets(targets);
	return (0);
}
