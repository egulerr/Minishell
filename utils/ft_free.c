/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguler <eguler@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 14:51:52 by malasaha          #+#    #+#             */
/*   Updated: 2022/09/06 14:57:52 by eguler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_free(void)
{
	int	i;

	i = 0;
	while (g_mini->command[i])
		free(g_mini->command[i++]);
	free(g_mini->command);
}

void	ft_freepath(void)
{
	int	i;

	i = 0;
	while (g_mini->pathlst[i])
		free(g_mini->pathlst[i++]);
	free(g_mini->pathlst);
}

void	ft_double_free(char **s)
{
	int	i;

	i = 0;
	while (s[i])
		free(s[i++]);
	free(s);
}

void	ft_double_free_int(int **s)
{
	int	i;

	i = 0;
	while (i < g_mini->pipe_count)
		free(s[i++]);
	free(s);
}

void	ft_pwd_free(void)
{
	if (g_mini->old_pwd != NULL)
		free(g_mini->old_pwd);
	if (g_mini->new_pwd != NULL)
		free(g_mini->new_pwd);
}
