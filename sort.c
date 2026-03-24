/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victor <victor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 14:29:38 by victor            #+#    #+#             */
/*   Updated: 2026/03/24 16:14:23 by victor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

//ordenador con nanosegundos mirar si en el entorno de 42 si que tiene el compilador en la estructura sr el st.mtim
/* int	compare_timespec(struct timespec a, struct timespec b)
{
	if (a.tv_sec > b.tv_sec)
		return (1);
	if (a.tv_sec < b.tv_sec)
		return (-1);
	if (a.tv_nsec > b.tv_nsec)
		return (1);
	if (a.tv_nsec < b.tv_nsec)
		return (-1);
	return (0);
}

int	compare_entries(t_entry *a, t_entry *b, t_flags *flag)
{
	int	cmp;

	if (flag->t)
	{
		cmp = compare_timespec(a->st.st_mtim, b->st.st_mtim);
		if (cmp != 0)
			return (-cmp);
	}
	return (ft_strcmp(a->name, b->name));
} */

int	compare_entries(t_entry *a, t_entry *b, t_flags *flag)
{
	if (flag->t)
	{
		if (a->st.st_mtime > b->st.st_mtime)
			return (-1);
		if (a->st.st_mtime < b->st.st_mtime)
			return (1);
	}
	return (ft_strcmp(a->name, b->name));
}

void	sort_entries(t_entry *entries, t_flags *flag)
{
	int		i;
	int		j;
	t_entry	tmp;

	i = 0;
	while (entries[i].name)
	{
		j = i + 1;
		while (entries[j].name)
		{
			if (compare_entries(&entries[i], &entries[j], flag) > 0)
			{
				tmp = entries[i];
				entries[i] = entries[j];
				entries[j] = tmp;
			}
			j++;
		}
		i++;
	}
}

void	reverse_entries(t_entry *entries)
{
	int		i;
	int		j;
	t_entry	tmp;

	i = 0;
	while (entries[i].name)
		i++;
	j = i - 1;
	i = 0;
	while (i < j)
	{
		tmp = entries[i];
		entries[i] = entries[j];
		entries[j] = tmp;
		i++;
		j--;
	}
}

int	compare_target_paths(char *a, char *b, t_flags *flag)
{
	struct stat	st_a;
	struct stat	st_b;

	if (flag->t)
	{
		if (lstat(a, &st_a) == 0 && lstat(b, &st_b) == 0)
		{
			if (st_a.st_mtime > st_b.st_mtime)
				return (-1);
			if (st_a.st_mtime < st_b.st_mtime)
				return (1);
		}
	}
	return (ft_strcmp(a, b));
}

void	sort_targets(char **targets, t_flags *flag)
{
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	while (targets[i])
	{
		j = i + 1;
		while (targets[j])
		{
			if (compare_target_paths(targets[i], targets[j], flag) > 0)
			{
				tmp = targets[i];
				targets[i] = targets[j];
				targets[j] = tmp;
			}
			j++;
		}
		i++;
	}
}

void	reverse_targets(char **targets)
{
	int i;
	int j;
	char *tmp;

	i = 0;
	while (targets[i])
		i++;
	j = i - 1;
	i = 0;
	while (i < j)
	{
		tmp = targets[i];
		targets[i] = targets[j];
		targets[j] = tmp;
		i++;
		j--;
	}
}
