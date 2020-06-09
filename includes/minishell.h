/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macrespo <macrespo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/20 19:41:53 by cclaude           #+#    #+#             */
/*   Updated: 2020/06/09 15:37:55 by macrespo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <fcntl.h>
# include <dirent.h>
# include <sys/wait.h>
# include <limits.h>
# include <errno.h>
// # include <sys/types.h>
// # include <stdbool.h>
// # include <stdarg.h>

# define EMPTY 0
# define CMD 1
# define ARG 2
# define TRUNC 3
# define APPEND 4
# define REDIR 5
# define PIPE 6
# define END 7

typedef struct	s_token
{
	char			*str;
	int				type;
	struct s_token	*prev;
	struct s_token	*next;
}				t_token;

typedef struct	s_mini
{
	t_token			*start;
	char			**env;
	int				run;
}				t_mini;

t_token			*get_args(char *line);
void			del_args(t_token *start);
void			parse(t_mini *mini);
void			del_tab(char **tab);
/* BUILTINS */
int		ft_echo(char **args);
int		ft_cd(char **args, char **env);
int		ft_pwd(void);
void	ft_env(char **env);
/* BUILTINS UTILITIES */
int		is_builtin(char	*command);
int		exec_builtins(char **args, char **env);
#endif
