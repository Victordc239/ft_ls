/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mix.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victor <victor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 14:32:57 by victor            #+#    #+#             */
/*   Updated: 2026/03/24 15:15:05 by victor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int	is_directory(char *path)
{
	struct stat	st;

	if (lstat(path, &st) == -1)
		return (0);
	return (S_ISDIR(st.st_mode));
}

void	putnbr_ulong_fd(unsigned long n, int fd)
{
	char	c;

	if (n >= 10)
		putnbr_ulong_fd(n / 10, fd);
	c = (n % 10) + '0';
	write(fd, &c, 1);
}

char	get_file_type_char(mode_t mode)
{
	if (S_ISDIR(mode))
		return ('d');
	if (S_ISLNK(mode))
		return ('l');
	if (S_ISCHR(mode))
		return ('c');
	if (S_ISBLK(mode))
		return ('b');
	if (S_ISFIFO(mode))
		return ('p');
	if (S_ISSOCK(mode))
		return ('s');
	return ('-');
}

void	print_permissions(mode_t mode)
{
	char	type;

	type = get_file_type_char(mode);
	write(1, &type, 1);

	if (mode & S_IRUSR)
		write(1, "r", 1);
	else
		write(1, "-", 1);
	if (mode & S_IWUSR)
		write(1, "w", 1);
	else
		write(1, "-", 1);
	if (mode & S_ISUID)
	{
		if (mode & S_IXUSR)
			write(1, "s", 1);
		else
			write(1, "S", 1);
	}
	else
	{
		if (mode & S_IXUSR)
			write(1, "x", 1);
		else
			write(1, "-", 1);
	}
	if (mode & S_IRGRP)
		write(1, "r", 1);
	else
		write(1, "-", 1);
	if (mode & S_IWGRP)
		write(1, "w", 1);
	else
		write(1, "-", 1);
	if (mode & S_ISGID)
	{
		if (mode & S_IXGRP)
			write(1, "s", 1);
		else
			write(1, "S", 1);
	}
	else
	{
		if (mode & S_IXGRP)
			write(1, "x", 1);
		else
			write(1, "-", 1);
	}
	if (mode & S_IROTH)
		write(1, "r", 1);
	else
		write(1, "-", 1);
	if (mode & S_IWOTH)
		write(1, "w", 1);
	else
		write(1, "-", 1);
	if (mode & S_ISVTX)
	{
		if (mode & S_IXOTH)
			write(1, "t", 1);
		else
			write(1, "T", 1);
	}
	else
	{
		if (mode & S_IXOTH)
			write(1, "x", 1);
		else
			write(1, "-", 1);
	}
}

void	print_owner_name(uid_t uid)
{
	struct passwd	*pw;

	pw = getpwuid(uid);
	if (pw && pw->pw_name)
		ft_putstr_fd(pw->pw_name, 1);
	else
		putnbr_ulong_fd((unsigned long)uid, 1);
}

void	print_group_name(gid_t gid)
{
	struct group	*gr;

	gr = getgrgid(gid);
	if (gr && gr->gr_name)
		ft_putstr_fd(gr->gr_name, 1);
	else
		putnbr_ulong_fd((unsigned long)gid, 1);
}

void	print_date(time_t mtime)
{
	time_t	now;
	char	*date;
	long	diff;

	now = time(NULL);
	date = ctime(&mtime);
	if (!date)
		return ;
	diff = (long)(now - mtime);
	if (diff < 0)
		diff = -diff;
	if (diff > 15778476)
	{
		write(1, date + 4, 7);
		write(1, "  ", 2);
		write(1, date + 20, 4);
	}
	else
		write(1, date + 4, 12);
}

long	get_total_blocks(t_entry *entries, int count)
{
	int		i;
	long	total;

	i = 0;
	total = 0;
	while (i < count)
	{
		total += (long)(entries[i].st.st_blocks / 2);
		i++;
	}
	return (total);
}

int	fill_single_entry(char *path, t_entry *entry)
{
	entry->name = ft_strdup(path);
	if (!entry->name)
		return (0);
	entry->path = ft_strdup(path);
	if (!entry->path)
	{
		free(entry->name);
		entry->name = NULL;
		return (0);
	}
	if (lstat(path, &entry->st) == -1)
	{
		free(entry->name);
		free(entry->path);
		entry->name = NULL;
		entry->path = NULL;
		return (0);
	}
	return (1);
}
