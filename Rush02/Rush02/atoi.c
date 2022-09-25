/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agallell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 23:57:32 by agallell          #+#    #+#             */
/*   Updated: 2022/09/25 14:46:25 by adi-stef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>

int		ft_strcmp(char *s1, char *s2);
int		ft_strlen(char *str);

char	*ft_atoi(char *str)
{
	int		j;
	int		m;

	j = 0;
	m = 1;
	while ((str[j] >= 9 && str[j] <= 13) || str[j] == 32)
		j++;
	while (str[j] == 43 || str[j] == 45 || str[j] == 48)
	{
		if (str[j] == 45)
			m = -m;
		j++;
	}
	if (str[j] < 48 || str[j] > 57 || m == -1)
		return ("Number not valid");
	m = j;
	while (str[j] >= '0' && str[j] <= '9')
		j++;
	str[j] = 0;
	return (&str[m]);
}

int	ft_check_nbr(char *nbr, char *max)
{
	if (ft_strlen(nbr) < ft_strlen(max))
		return (1);
	else if (ft_strlen(nbr) > ft_strlen(max))
		return (0);
	else
	{
		if (ft_strcmp(max, nbr) < 0)
		{
			printf("%d\n", ft_strcmp(max, nbr));
			return (0);
		}
		else
			return (1);
	}
}
