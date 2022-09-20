/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adi-stef <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 12:35:36 by adi-stef          #+#    #+#             */
/*   Updated: 2022/09/20 15:01:57 by adi-stef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

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
	return (1);
}

int	ft_num_in_base(char c, char *base)
{
	int	i;
	int	k;

	i = -1;
	while (base[++i])
		if (c == base[i])
			k = 1;
	if (k == 1)
		return (1);
	return (0);
}

char	*ft_getstr(char *str, char *base, int i, int k)
{
	int	s;
	int	c;

	s = 0;
	c = -1;
	while (str[++i])
	{
		if ((str[i] == 43 || str[i] == 45 || str[i] == 32 || str[i] == '\t'
				|| str[i] == '\n' || str[i] == '\v' || str[i] == '\f'
				|| str[i] == '\r') && c == -1)
		{
			if (str[i] == 43 || str[i] == 45)
			{
				if (k == -1)
					k = i;
				if (str[i] == 43)
					s++;
				else
					s--;
			}
		}
		else if (ft_num_in_base(str[i], base))
		{
			if (c == -1)
				c = i;
		}
		else if (c != -1 && k != -1)
		{
			str[i] = 0;
			printf("%d\n%d\n", i, s);
			return (&str[c]);
		}
	}
	if (c != -1)
		return (&str[c]);
	return (str);
}

int	ft_atoi_base(char *str, char *base)
{
	if (ft_check_base(base))
	{
		str = ft_getstr(str, base, -1, -1);
		puts(str);
	}
	return (0);
}

int	main(void)
{
	char	num[] = "-123+nkdeasjd";
	char	base[] = "0123456789";

	printf("%d\n", ft_atoi_base(num, base));
}
