/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adi-stef <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 10:24:06 by adi-stef          #+#    #+#             */
/*   Updated: 2022/09/20 12:29:30 by adi-stef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_base_control(char *base)
{
	int	i;
	int	j;

	i = -1;
	while (base[i++] != '\0')
	{
		if (base[i] == 43 || base[i] == 45)
			return (0);
		j = i;
		while (base[j++] != '\0')
		{
			if (base[i] == base[j])
				return (0);
		}
	}
	return (1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	if (ft_base_control(base) && ft_strlen(base) > 1)
	{
		if (nbr == 0)
			write(1, &nbr, 1);
		if (nbr < 0)
		{
			write(1, "-", 1);
			ft_putnbr_base(nbr * -1, base);
		}
		else if (nbr > 0)
		{
			ft_putnbr_base(nbr / ft_strlen(base), base);
			write(1, &base[nbr % ft_strlen(base)], 1);
		}
	}
}
/*
int	main(void)
{
	int		nbr;
	char	base[] = "poneyvif";

	nbr = -;
	ft_putnbr_base(nbr, base);
}
*/
