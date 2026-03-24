/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victor <victor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 14:30:24 by victor            #+#    #+#             */
/*   Updated: 2026/03/24 15:24:41 by victor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	list_directory_recursive(char *path, t_flags *flag, int print_header)
{
	t_entry	*entries;
	int		count;
	int		i;
	long	total;

	count = count_visible_entries(path, flag);
	if (count < 0)
		return ;
	entries = load_entries(path, flag, count);
	if (!entries)
		return ;
	sort_entries(entries, flag);
	if (flag->r)
		reverse_entries(entries);
	if (print_header)
	{
		ft_putstr_fd(path, 1);
		ft_putstr_fd(":\n", 1);
	}
	if (flag->l)
	{
		total = get_total_blocks(entries, count);
		ft_putstr_fd("total ", 1);
		putnbr_ulong_fd((unsigned long)total, 1);
		ft_putstr_fd("\n", 1);
	}
	i = 0;
	while (i < count)
	{
		if (flag->l)
			print_long_entry(&entries[i]);
		else
		{
			ft_putstr_fd(entries[i].name, 1);
			ft_putstr_fd("\n", 1);
		}
		i++;
	}
	if (flag->uper_r)
	{
		i = 0;
		while (i < count)
		{
			if (S_ISDIR(entries[i].st.st_mode) && !is_dot_or_dotdot(entries[i].name))
			{
				ft_putstr_fd("\n", 1);
				list_directory_recursive(entries[i].path, flag, 1);
			}
			i++;
		}
	}
	free_entries(entries, count);
}

void	list_path(char *path, t_flags *flag)
{
	struct stat	st;
	t_entry		entry;

	if (lstat(path, &st) == -1)
	{
		perror(path);
		return ;
	}
	if (S_ISDIR(st.st_mode))
	{
		list_directory_recursive(path, flag, 0);
		return ;
	}
	if (flag->l)
	{
		if (!fill_single_entry(path, &entry))
			return ;
		print_long_entry(&entry);
		(free(entry.name), free(entry.path));
	}
	else
	{
		ft_putstr_fd(path, 1);
		ft_putstr_fd("\n", 1);
	}
}

void	print_directory_header(char *path)
{
	ft_putstr_fd(path, 1);
	ft_putstr_fd(":\n", 1);
}

void	print_symlink_target(t_entry *entry)
{
	char	*buf;
	ssize_t	len;

	if (!S_ISLNK(entry->st.st_mode))
		return ;
	buf = malloc((size_t)entry->st.st_size + 1);
	if (!buf)
		return ;
	len = readlink(entry->path, buf, (size_t)entry->st.st_size);
	if (len == -1)
	{
		free(buf);
		return ;
	}
	buf[len] = '\0';
	ft_putstr_fd(" -> ", 1);
	ft_putstr_fd(buf, 1);
	free(buf);
}

void	print_long_entry(t_entry *entry)
{
	print_permissions(entry->st.st_mode);
	write(1, " ", 1);
	putnbr_ulong_fd((unsigned long)entry->st.st_nlink, 1);
	write(1, " ", 1);
	print_owner_name(entry->st.st_uid);
	write(1, " ", 1);
	print_group_name(entry->st.st_gid);
	write(1, " ", 1);
	putnbr_ulong_fd((unsigned long)entry->st.st_size, 1);
	write(1, " ", 1);
	print_date(entry->st.st_mtime);
	write(1, " ", 1);
	ft_putstr_fd(entry->name, 1);
	print_symlink_target(entry);
	write(1, "\n", 1);
}

int	is_dot_or_dotdot(char *name)
{
	if (ft_strcmp(name, ".") == 0)
		return (1);
	if (ft_strcmp(name, "..") == 0)
		return (1);
	return (0);
}
