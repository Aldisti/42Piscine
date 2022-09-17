/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaterno <mpaterno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 09:15:11 by mpaterno          #+#    #+#             */
/*   Updated: 2022/09/16 10:13:30 by mpaterno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

int	double_char(char *base)
{
	int	i;
	int	j;

	i = 0;
	while (base[i] != '\0')
	{
		j = i + 1;
		if (base[i] == '-' || base[i] == '+')
		{
			return (0);
		}
		while (base[j] != '\0')
		{
			if (base[i] == base[j])
			{
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	controll(char *base)
{
	if (ft_strlen(base) < 2)
	{
		return (0);
	}
	else if (double_char(base) == 0)
	{
		return (0);
	}
	else
	{
		return (1);
	}
}

void	ft_putnbr_base(int nbr, char *base)
{
	int	len;

	if (nbr < 0)
	{
		write(1, "-", 1);
		nbr *= -1;
	}
	if (controll(base) == 1)
	{
		len = ft_strlen(base);
		if (nbr < 0)
		{
			nbr *= -1;
		}
		if (nbr == 0)
		{
			write(1, &nbr, 1);
		}
		else
		{
			ft_putnbr_base(nbr / len, base);
			write(1, &base[nbr % len], 1);
		}
	}
}
