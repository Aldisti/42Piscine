/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adi-stef <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 18:11:41 by adi-stef          #+#    #+#             */
/*   Updated: 2022/09/18 10:54:17 by adi-stef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strstr(char *str, char *to_find)
{
	int	check;
	int	i;
	int	j;

	i = -1;
	j = 0;
	if (str[0] == 0 && to_find[0] == 0)
		return (str);
	while (str[++i] != '\0')
	{
		if (str[i] == to_find[j])
		{
			if (j == 0)
				check = i;
			j += 1;
		}
		else
		{
			check = 0;
			j = 0;
		}
		if (j == ft_strlen(to_find))
			return (&str[check]);
	}
	return (NULL);
}
