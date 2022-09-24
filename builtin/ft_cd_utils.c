/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguler <eguler@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 12:21:11 by eguler            #+#    #+#             */
/*   Updated: 2022/09/07 12:27:32 by eguler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_dash(void)
{
	char	*temp;

	temp = ft_strdup(g_mini->new_pwd);
	chdir(g_mini->old_pwd);
	free(g_mini->new_pwd);
	g_mini->new_pwd = g_mini->old_pwd;
	g_mini->old_pwd = temp;
}

void	ft_dot_or_twodots(void)
{
	free(g_mini->old_pwd);
	g_mini->old_pwd = getcwd(NULL, 0);
	chdir(g_mini->command[1]);
	free(g_mini->new_pwd);
	g_mini->new_pwd = getcwd(NULL, 0);
}

void	ft_updates(void)
{
	ft_updatenv();
	ft_updatexport();
}
