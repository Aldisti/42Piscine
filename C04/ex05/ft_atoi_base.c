/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adi-stef <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 12:35:36 by adi-stef          #+#    #+#             */
/*   Updated: 2022/09/21 15:18:20 by adi-stef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

int	ft_get_sign(char *str, int i, int j, int c)
{
	while (str[++i])
	{
		if (str[i] == 43 || str[i] == 45)
		{
			if (!j)
				j = 1;
			if (str[i] == 43)
				c++;
			if (str[i] == 45)
				c--;
		}
		else if (j)
		{
			if (str[i] < 48 || str[i] > 57)
				return (0);
			else if (c < 0)
				return (-1);
			else
				return (1);
		}
	}
	return (1);
}

int	ft_check_base(char *base)
{
	int	i;
	int	j;

	i = -1;
	while (base[++i])
	{
		j = i;
		while (base[++j])
			if (base[j] == base[i] || base[i] == 43 || base[i] == 45
				|| base[i] == 32 || base[i] == '\t' || base[i] == '\n'
				|| base[i] == '\v' || base[i] == '\f' || base[i] == '\r')
				return (0);
	}
	if (i < 2)
		return (0);
	return (i);
}

int	ft_3(char c, char *base, char *str)
{
	int	i;
	int	div;

	i = -1;
	if (base == str)
	{
		while (base[++i])
			if (c == base[i])
				return (i);
		return (-1);
	}
	else
	{
		i++;
		div = 1;
		while (str[++i])
			div *= ft_check_base(base);
		return (div);
	}
}

char	*ft_getstr(char *str, char *base, int i, int k)
{
	int	s;
	int	c;

	s = 0;
	c = -1;
	while (str[++i])
	{
		if (ft_3(str[i], base, base) != -1)
		{
			if (k == -1)
				k = i;
			s++;
		}
		else if (k != -1)
			break ;
	}
	str[i] = 0;
	return (&str[k]);
}

int	ft_atoi_base(char *str, char *base)
{
	int	i;
	int	res;
	int	div;
	int	sign;

	res = 0;
	if (ft_check_base(base))
	{
		sign = ft_get_sign(str, -1, 0, 0);
		str = ft_getstr(str, base, -1, -1);
		div = ft_3(str[0], base, str);
		i = -1;
		while (str[++i])
		{
			res += (base[ft_3(str[i], base, base)] - 48) * div;
			div /= ft_check_base(base);
		}
		return (res * sign);
	}
	return (0);
}
/*
int	main(void)
{
	char	num[] = "---++--++10000000000000000000000000000000-23mfdkljnn dsf ";
	char	base[] = "01";

	printf("%d\n", ft_atoi_base(num, base));
}
*/
