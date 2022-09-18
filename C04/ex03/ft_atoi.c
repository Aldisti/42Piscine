/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adi-stef <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 08:42:31 by adi-stef          #+#    #+#             */
/*   Updated: 2022/09/16 09:52:04 by adi-stef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

int	ft_sign_check(int n)
{
	if (n == 43)
		return (1);
	else if (n == 45)
		return (-1);
	else
		return (0);
}

int	ft_strtoint(char *str, int sign)
{
	int	i;
	int	div;
	int	num;

	num = 0;
	div = 1;
	i = 1;
	while (str[i] != '\0')
	{
		i++;
		div *= 10;
	}
	i = 0;
	while (div != 0)
	{
		num += (str[i] - 48) * div;
		div /= 10;
		i++;
	}
	if (sign < 0)
		return (-num);
	else
		return (num);
}

int	ft_atoi(char *str)
{
	int	sign;
	int	i;
	int	j;

	i = 0;
	j = -1;
	sign = 0;
	while (str[i] != 0)
	{
		sign += ft_sign_check(str[i]);
		if (str[i] >= 48 && str[i] <= 57)
		{
			if (j == -1)
				j = i;
		}
		else if (str[i] != 43 && str[i] != 45)
		{
			if (j != -1)
			{
				str[i] = '\0';
				return (ft_strtoint(&str[j], sign));
			}
		}
		i++;
	}
	return (0);
}

int	main(void)
{
	char	a[] = " ---+--+0000   ab567";

	printf(">%d\n", ft_atoi(a));
}