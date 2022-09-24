/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adi-stef <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 12:44:03 by adi-stef          #+#    #+#             */
/*   Updated: 2022/09/21 10:10:07 by adi-stef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_get_hex(int nbr)
{
	char	*str;
	char	temp[3];

	str = "0123456789abcdef";
	temp[1] = str[nbr % 16];
	temp[0] = str[(nbr / 16) / 16];
	write(1, "\\", 1);
	write(1, temp, 2);
}

void	ft_putstr_non_printable(char *str)
{
	int	i;
	int	temp;

	i = -1;
	while (str[++i])
	{
		if ((str[i] >= 0 && str[i] < 32) || str[i] == 127)
		{
			temp = str[i];
			ft_get_hex(temp);
		}
		else
			write(1, &str[i], 1);
	}
}
/*
int	main(void)
{
	char	a[] = "Ci\fao\nco\vme\tstai?";

	ft_putstr_non_printable(a);
}
*/
