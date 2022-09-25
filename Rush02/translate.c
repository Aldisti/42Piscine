/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adi-stef <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 19:10:19 by adi-stef          #+#    #+#             */
/*   Updated: 2022/09/25 19:20:03 by adi-stef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

void	ft_print_char(char *nbr, char **buf, int len);
void	ft_suffix(int len, char **buf);
int		ft_strlen(char *str);
void	ft_print(char *str);
char	*ft_strdup(char *src);

void	ft_doppietta(char *nbr, char **buf)
{
	char	*temp;
	char	c;

	c = nbr[1];
	nbr[1] = 48;
	temp = ft_strdup(&nbr[0]);
	ft_print_char(temp, buf, 2);
	if (c > 48)
		ft_print_char(&c, buf, 1);
	free(temp);
}

void	ft_hundred(char c, char **buf, int len)
{
	if (c > 48)
	{
		ft_print_char(&c, buf, 1);
		ft_suffix(len, buf);
	}	
}

void	ft_tripletta(char *nbr, char **buf)
{
	char	*temp;
	char	c;

	ft_hundred(nbr[0], buf, ft_strlen(nbr));
	if (nbr[1] == 49)
	{
		temp = ft_strdup(&nbr[1]);
		ft_print_char(temp, buf, 2);
		free(temp);
	}
	else if (nbr[1] > 49)
	{
		ft_doppietta(&nbr[1], buf);
	}
	else if (nbr[1] == 48 && nbr[2] > 48)
	{
		c = nbr[2];
		ft_print_char(&c, buf, 1);
	}
}

void	ft_suffix(int len, char **buf)
{
	char	*n;

	n = "1000000000000000000000000000000000000";
	ft_print_char(n, buf, len);
}

void	ft_nbr_parse(char *nbr, char **buf)
{
	if (ft_strlen(nbr) % 3 == 0)
	{
		ft_tripletta(nbr, buf);
		if (ft_strlen(nbr) > 3)
		{
			ft_suffix(ft_strlen(nbr), buf);
			ft_nbr_parse(&nbr[3], buf);
		}
	}
	else if (ft_strlen(nbr) % 3 == 1)
	{
		ft_print_char(nbr, buf, 1);
		ft_suffix(ft_strlen(nbr), buf);
		if (ft_strlen(nbr) > 3)
			ft_nbr_parse(&nbr[1], buf);
	}
	else if (ft_strlen(nbr) % 3 == 2)
	{
		ft_doppietta(nbr, buf);
		ft_suffix(ft_strlen(nbr), buf);
		if (ft_strlen(nbr) > 3)
			ft_nbr_parse(&nbr[2], buf);
	}
}
