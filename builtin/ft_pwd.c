/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguler <eguler@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 10:45:42 by eguler            #+#    #+#             */
/*   Updated: 2022/09/06 16:14:21 by eguler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_pwd(void)
{
	int		i;
	char	*str;

	i = 0;
	while (g_mini->env[i])
	{
		if (ft_strcmp(g_mini->env[i], "PWD="))
			str = ft_strstr(g_mini->env[i], "PWD=");
		i++;
	}
	printf("%s\n", str);
}
