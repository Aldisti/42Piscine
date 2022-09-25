/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adi-stef <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 19:10:19 by adi-stef          #+#    #+#             */
/*   Updated: 2022/09/25 19:57:19 by adi-stef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

void	ft_print_char(char *nbr, char **buf, int len);
int		ft_buflen(char *path);
void	ft_suffix(int len, char **buf);
int		ft_strlen(char *str);
void	ft_print(char *str);
char	*ft_strdup(char *src);
void	ft_case2(char *nbr, char **buf);
void	ft_case1(char *nbr, char **buf);

void	ft_doppietta(char *nbr, char **buf)
{
	char	*temp;
	char	c;

	if (nbr[0] > 49)
	{
		c = nbr[1];
		nbr[1] = 48;
		temp = ft_strdup(&nbr[0]);
		ft_print_char(temp, buf, 2);
		if (c > 48)
			ft_print_char(&c, buf, 1);
		free(temp);
	}
	else if (nbr[0] == 49)
	{
		temp = ft_strdup(nbr);
		ft_print_char(temp, buf, 2);
		free(temp);
	}	
}

void	ft_hundred(char c, char **buf)
{
	if (c > 48)
	{
		ft_print_char(&c, buf, 1);
		ft_suffix(3, buf);
	}	
}

void	ft_tripletta(char *nbr, char **buf)
{
	char	*temp;
	char	c;

	ft_hundred(nbr[0], buf);
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
		ft_case1(nbr, buf);
		if (ft_strlen(nbr) > 3)
			ft_nbr_parse(&nbr[1], buf);
	}
	else if (ft_strlen(nbr) % 3 == 2)
	{
		ft_case2(nbr, buf);
		if (ft_strlen(nbr) > 3)
			ft_nbr_parse(&nbr[2], buf);
	}
}
