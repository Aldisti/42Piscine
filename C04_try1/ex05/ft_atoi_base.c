/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adi-stef <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 11:47:10 by adi-stef          #+#    #+#             */
/*   Updated: 2022/09/17 14:12:32 by adi-stef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <stdio.h>

int	ft_sn_ln(int n, int v, char *str)
{
	int	i;

	if (v == 0)
	{
		if (n == 43)
			return (1);
		if (n == 45)
			return (-1);
		else
			return (0);
	}
	else
	{
		i = 0;
		while (str[i] != '\0')
			i++;
		return (i);
	}
}

int	ft_bc(char *base, char c, int v)
{
	int	i;
	int	j;

	i = -1;
	if (v == 0)
	{
		while (base[i++] != '\0')
		{
			if (base[i] == 43 || base[i] == 45)
				return (0);
			j = i;
			while (base[j++] != '\0')
				if (base[i] == base[j])
					return (0);
		}
		return (1);
	}
	else
	{
		while (base[i++] != '\0')
			if (c == base[i])
				return (1);
		return (0);
	}
	return (0);
}

int	ft_fc(char *base, char c, int v)
{
	int	i;
	int	r;

	i = -1;
	if (v == 0)
	{
		while (base[i++] != '\0')
			if (base[i] == c)
				return (i + 1);
		return (0);
	}
	else
	{
		r = 1;
		while (i++ < v)
			r *= ft_sn_ln(base[i], 1, base);
		return (r);
	}
	return (0);
}

int	ft_str_to_int(char *n, char *b, int sign)
{
	int	res;
	int	i;
	int	j;

	i = -1;
	res = 0;
	j = ft_sn_ln(0, 1, n);
	if (sign < 0)
		write(1, "-", 1);
	while (n[i++] != '\0')
	{
		res += ft_fc(b, n[i], 0) * ft_fc(b, b[i], 1);
	}
	if (sign < 0)
		return (-res);
	return (res);
}

int	ft_atoi_base(char *str, char *base)
{
	int	i;
	int	j;
	int	s;

	if (ft_bc(base, base[0], 0) == 1)
	{
		s = 0;
		i = -1;
		while (str[i++] != '\0')
		{
			s += ft_sn_ln(str[i], 0, base);
			if (ft_bc(base, str[i], 1) == 1)
			{
				if (j != -1)
				{
					puts("Qui entra");
					j = i;
				}
			}
			else
			{
				if (j != -1)
				{
					str[i] = '\0';
					return (ft_str_to_int(&str[j], base, s));
				}
			}
		}
	}
	return (0);
}
