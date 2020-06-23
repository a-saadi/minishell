/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macrespo <macrespo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/17 15:42:31 by cclaude           #+#    #+#             */
/*   Updated: 2020/06/23 17:54:26 by macrespo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**cmd_tab(t_token *start)
{
	t_token	*token;
	char	**tab;
	int		i;

	token = start->next;
	i = 2;
	while (token && token->type < TRUNC)
	{
		token = token->next;
		i++;
	}
	tab = malloc(sizeof(char *) * i);
	token = start->next;
	tab[0] = start->str;
	i = 1;
	while (token && token->type < TRUNC)
	{
		tab[i] = token->str;
		token = token->next;
		i++;
	}
	tab[i] = NULL;
	return (tab);
}

void	exec_cmd(t_mini *mini, t_token *token)
{
	char	**cmd;
	int		i;

	cmd = cmd_tab(token);
	i = 1;
	while (cmd[i])
	{
		// cmd[i] = env_name_to_value(cmd[i], mini->env);
		expansions(cmd[i], mini->env);
		i++;
	}
	if (ft_strcmp(cmd[0], "exit") == 0)
		mini->run = 0;
	if (is_builtin(cmd[0]))
		exec_builtin(cmd, mini);
	else
		exec_bin(cmd, mini->env);
	ft_memdel(cmd);
	close(mini->pipin);
	close(mini->pipout);
	mini->pipin = -1;
	mini->pipout = -1;
}
