/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entries.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victor <victor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 14:28:23 by victor            #+#    #+#             */
/*   Updated: 2026/03/24 15:16:02 by victor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int	count_visible_entries(char *path, t_flags *flag)
{
	DIR				*dir;
	struct dirent	*entry;
	int				count;

	count = 0;
	dir = opendir(path);
	if (!dir)
	{
		perror(path);
		return (-1);
	}
	entry = readdir(dir);
	while (entry)
	{
		if (flag->a || entry->d_name[0] != '.')
			count++;
		entry = readdir(dir);
	}
	closedir(dir);
	return (count);
}

t_entry	*load_entries(char *path, t_flags *flag, int count)
{
	DIR				*dir;
	struct dirent	*entry;
	t_entry			*entries;
	int				i;

	entries = malloc(sizeof(t_entry) * (count + 1));
	if (!entries)
		return (NULL);
	dir = opendir(path);
	if (!dir)
	{
		free(entries);
		perror(path);
		return (NULL);
	}
	i = 0;
	entry = readdir(dir);
	while (entry)
	{
		if (flag->a || entry->d_name[0] != '.')
		{
			if (!read_entry_info(path, entry->d_name, &entries[i]))
			{
				while (i > 0)
				{
					i--;
					free(entries[i].name);
					free(entries[i].path);
				}
				free(entries);
				closedir(dir);
				return (NULL);
			}
			i++;
		}
		entry = readdir(dir);
	}
	entries[i].name = NULL;
	entries[i].path = NULL;
	closedir(dir);
	return (entries);
}

void	free_entries(t_entry *entries, int count)
{
	int	i;

	if (!entries)
		return ;
	i = 0;
	while (i < count)
	{
		free(entries[i].name);
		free(entries[i].path);
		i++;
	}
	free(entries);
}

char	*join_path(char *dirpath, char *name)
{
	char	*path;
	int		i;
	int		j;
	int		len1;
	int		len2;
	int		need_slash;

	len1 = ft_strlen(dirpath);
	len2 = ft_strlen(name);
	need_slash = 0;
	if (len1 > 0 && dirpath[len1 - 1] != '/')
		need_slash = 1;
	path = malloc(len1 + need_slash + len2 + 1);
	if (!path)
		return (NULL);
	i = 0;
	while (i < len1)
	{
		path[i] = dirpath[i];
		i++;
	}
	if (need_slash)
		path[i++] = '/';
	j = 0;
	while (j < len2)
	{
		path[i + j] = name[j];
		j++;
	}
	path[i + j] = '\0';
	return (path);
}

int	read_entry_info(char *dirpath, char *name, t_entry *entry)
{
	entry->name = ft_strdup(name);
	if (!entry->name)
		return (0);
	entry->path = join_path(dirpath, name);
	if (!entry->path)
	{
		free(entry->name);
		entry->name = NULL;
		return (0);
	}
	if (lstat(entry->path, &entry->st) == -1)
	{
		free(entry->name);
		free(entry->path);
		entry->name = NULL;
		entry->path = NULL;
		return (0);
	}
	return (1);
}
