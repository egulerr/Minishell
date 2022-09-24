/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dolar_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguler <eguler@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 14:33:52 by eguler            #+#    #+#             */
/*   Updated: 2022/09/12 12:32:19 by eguler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_dolar_cont_2(char *s)
{
	int	i;

	i = 1;
	if (s[i] == '_')
	{
		if (s[i + 1] == '\0')
			return (2);
	}
	else if (s[1] == '\0')
		return (0);
	return (1);
}

int	ft_dolar_cont(char *s)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] == '$')
			j++;
		i++;
	}
	if (j > 0)
		return (1);
	else
		return (0);
}

char	*ft_is_return_before_dolar(char *s)
{
	int		i;
	char	*str;

	i = 0;
	while (s[i] && s[i] != '$')
		i++;
	str = malloc(sizeof(char) * i + 1);
	i = 0;
	while (s[i] && s[i] != '$')
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_dolar2_utils(int f, char *s)
{
	char	*str;

	if (f == 1)
	{
		str = ft_dolar3(s, 0);
		free(s);
		return (str);
	}
	else if (f == 2)
	{
		free(s);
		return (g_mini->last_command);
	}
	else
	{
		str = ft_strdup(s);
		free(s);
		return (str);
	}
}

char	*ft_dolar3_utils(char **com, int flag, char *comm, char *s)
{
	int	i;

	if (flag == 0)
	{
		if (ft_dolar_and_equal_check(s))
		{
			ft_putstr_fd("minishell: export: '", 2);
			ft_putstr_fd(s, 2);
			ft_putstr_fd("': not a valid identifier\n", 2);
			g_mini->e_flag = 1;
			g_mini->dolar_number = 1;
			return (NULL);
		}
		free(comm);
		ft_double_free(com);
		return (ft_is_return_before_dolar(s));
	}
	i = 0;
	while (com[i])
	{
		comm = ft_strjoin(comm, com[i++]);
	}
	ft_double_free(com);
	return (comm);
}
