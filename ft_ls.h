/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victor <victor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 10:41:02 by victor            #+#    #+#             */
/*   Updated: 2026/03/24 16:14:31 by victor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <dirent.h>
# include <sys/stat.h>
# include <pwd.h>
# include <grp.h>
# include <sys/types.h>
# include <time.h>
# include "Libft/libft.h"

# ifndef S_ISVTX
#  define S_ISVTX 01000
# endif

typedef struct s_flags
{
	int	l;
	int	uper_r;
	int	a;
	int	r;
	int	t;
}	t_flags;

typedef struct s_entry
{
	char			*name;
	char			*path;
	struct stat		st;
}	t_entry;

void	init_flags(t_flags *flag);
void	free_targets(char **targets);
void	list_path(char *path, t_flags *flag);
void	free_entries(t_entry *entries, int count);
void	sort_entries(t_entry *entries, t_flags *flag);
void	reverse_entries(t_entry *entries);
void	putnbr_ulong_fd(unsigned long n, int fd);
void	print_long_entry(t_entry *entry);
void	list_directory_recursive(char *path, t_flags *flag, int print_header);
void	print_symlink_target(t_entry *entry);
void	print_directory_header(char *path);
void	print_permissions(mode_t mode);
void	print_owner_name(uid_t uid);
void	print_group_name(gid_t gid);
void	print_date(time_t mtime);
void	sort_targets(char **targets, t_flags *flag);
void	reverse_targets(char **targets);

int		set_option_flag(t_flags *flag, char c);
int		parse_options(int argc, char **argv, t_flags *flag, int *start);
int		count_targets(int argc, int start);
int		compare_target_paths(char *a, char *b, t_flags *flag);
int		is_directory(char *path);
int		count_visible_entries(char *path, t_flags *flag);
int		fill_single_entry(char *path, t_entry *entry);
int		is_dot_or_dotdot(char *name);
int		read_entry_info(char *dirpath, char *name, t_entry *entry);
int		compare_entries(t_entry *a, t_entry *b, t_flags *flag);
//int		compare_timespec(struct timespec a, struct timespec b);

char	get_file_type_char(mode_t mode);
char	*join_path(char *dirpath, char *name);
char	**build_targets(int argc, char **argv, int start);

t_entry	*load_entries(char *path, t_flags *flag, int count);

long	get_total_blocks(t_entry *entries, int count);

#endif