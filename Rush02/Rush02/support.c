/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   support.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adi-stef <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 10:48:11 by adi-stef          #+#    #+#             */
/*   Updated: 2022/09/25 13:46:16 by adi-stef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>

void	ft_print(char *str)
{
	int	i;

	i = -1;
	while (str[++i] != 10)
	if (str[i] != 32 && (str[i] < 9 || str[i] > 13))
		write(1, &str[i], 1);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_error(int type)
{
	if (type == 1)
	{
		ft_print("Dict Error\n");
		return ;
	}
	return ;
}

int	ft_strcmp(char *s1, char *s2)
{
	int	res;
	int	i;

	i = 0;
	res = 0;
	while (s1[i] || s2[i])
	{
		res += s1[i] - s2[i];
		i++;
	}
	return (res);
}

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;
	int				res;

	res = 0;
	i = 0;
	while (i < n && res == 0)
	{
		if (s1[i] == '\0' || s2[i] == '\0')
		{
			res = s1[i] - s2[i];
			break ;
		}
		res = s1[i] - s2[i];
		i++;
	}
	return (res);
}



