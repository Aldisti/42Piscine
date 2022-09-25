/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adi-stef <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 15:46:50 by adi-stef          #+#    #+#             */
/*   Updated: 2022/09/25 17:27:31 by adi-stef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

void	ft_print_char(char *nbr, char **buf, int len, int k);
void	ft_suffix(int len, char **buf);
int		ft_strlen(char *str);
void	ft_print(char *str);

char	*ft_strdup(char *src)
{
	char	*ptr;
	int		i;

	i = 0;
	while (src[i])
		i++;
	ptr = (char *) malloc (i * sizeof (char));
	i = -1;
	while (src[++i])
		ptr[i] = src[i];
	ptr[i] = src[i];
	return (ptr);
}

void	ft_doppietta(char *nbr, char **buf, char *temp)
{
	char	*c;

	c = nbr[1];
	nbr[1] = 48;
	temp = ft_strdup(&nbr[0]);
	ft_print_char(temp, buf, 2, 0);
	if (c > 48)
		ft_print_char(&c, buf, 1, 0);
	free(temp);
}

void	ft_hundred(char *nbr, char **buf)
{
	char	*c;

	if (nbr[0] > 48)
	{
		c = nbr[0];
		ft_print_char(&c, buf, 1, 0);
		ft_suffix(ft_strlen(nbr), buf);
	}	
}

void	ft_tripletta(char *nbr, char **buf, char *temp)
{
	char *c;

	if (nbr[1] == 49)
	{
		temp = ft_strdup(&nbr[1]);
		ft_print_char(temp, buf, 2, 0);
		free(temp);
	}
	else if (nbr[1] > 49)
	{
		ft_doppietta(&nbr[1], buf, temp);
	}
	else if (nbr[1] == 48 && nbr[2] > 48)
		c = nbr[2];
		ft_print_char(&c, buf, 1, 0);
}

void	ft_suffix(int len, char **buf)
{
	char	*n;

	n = "1000000000000000000000000000000000000";
	ft_print_char(n, buf, len, 0);
}

void	ft_nbr_parse(char *nbr, char **buf)
{
	char	*temp;

	if (ft_strlen(nbr) % 3 == 0)
	{
		ft_tripletta(nbr, buf, temp);
		if (ft_strlen(nbr) > 3)
			ft_suffix(ft_strlen(nbr), buf);
	}
	else if (ft_strlen(nbr) % 3 == 1)
	{
		ft_print_char(nbr, buf, 1, 0);
		ft_suffix(ft_strlen(nbr), buf);
		if (ft_strlen(nbr) > 3)
			ft_nbr_parse(&nbr[1], buf);
	}
	else if (ft_strlen(nbr) % 3 == 2)
	{
		ft_doppietta(nbr, buf, temp);
		ft_suffix(ft_strlen(nbr), buf);
		if (ft_strlen(nbr) > 3)
			ft_nbr_parse(&nbr[2], buf);
	}
}
