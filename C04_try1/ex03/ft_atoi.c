/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adi-stef <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 12:25:55 by adi-stef          #+#    #+#             */
/*   Updated: 2022/09/20 17:05:28 by adi-stef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

int	ft_get_sign(char *str, int i, int j, int c)
{
	while (str[++i])
	{
		if (str[i] == 43 || str[i] == 45)
		{
			if (j == -1)
				j = 0;
			if (str[i] == 43)
				c++;
			else if (str[i] == 45)
				c--;
		}
		else if (j != -1 || (str[i] != 45 && str[i] != 43 && str[i] != 32
				&& str[i] != '\t' && str[i] != '\n' && str[i] != '\v'
				&& str[i] != '\f' && str[i] != '\r'))
		{
			if (c < 0)
				return (-1);
			else
				return (1);
		}
	}
	return (1);
}

int	ft_get_div(char *str)
{
	int	i;
	int	j;

	j = 1;
	i = 0;
	while (str[++i])
		j *= 10;
	return (j);
}

char	*ft_get_nbr(char *str, int i, int j, int k)
{
	while (str[++i] != 0)
	{
		if (str[i] == 43 || str[i] == 45 || str[i] == 32 || str[i] == '\t'
			|| str[i] == '\n' || str[i] == '\v' || str[i] == '\f'
			|| str[i] == '\r')
			k++;
		if (str[i] >= 48 && str[i] <= 57)
		{
			if (j == -1 && i == k)
				j = i;
		}
		else if (j != -1)
		{
			str[i] = 0;
			return (&str[j]);
		}
	}
	return ("0");
}

int	ft_atoi(char *str)
{
	int	sign;
	int	res;
	int	div;
	int	i;

	i = -1;
	res = 0;
	div = 0;
	sign = ft_get_sign(str, -1, -1, 0);
	str = ft_get_nbr(str, -1, -1, 0);
	while (str[++i])
	{
		if (div == 0)
			div = ft_get_div(&str[i]);
		res += (str[i] - 48) * div;
		div /= 10;
	}
	return (res * sign);
}

int	main(void)
{
	char	a[] = "\n\v\t\f		++	-12345610m584mkmskjsh";

	printf("%d\n", ft_atoi(a));
}

