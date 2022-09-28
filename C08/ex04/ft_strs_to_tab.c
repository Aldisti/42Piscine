/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adi-stef <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 10:10:00 by adi-stef          #+#    #+#             */
/*   Updated: 2022/09/28 17:46:45 by adi-stef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include "ft_stock_str.h"

char	*ft_strdup(char *src)
{
	char	*ptr;
	int		i;

	i = 0;
	while (src[i])
		i++;
	ptr = (char *) malloc ((i + 1) * sizeof (char));
	i = -1;
	while (src[++i])
		ptr[i] = src[i];
	ptr[i] = src[i];
	return (ptr);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

struct	s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	t_stock_str	*ptr;
	int			i;

	ptr = (t_stock_str *) malloc ((ac + 1) * sizeof (t_stock_str));
	if (ptr == 0)
	{
		ptr = 0;
		return (ptr);
	}
	i = -1;
	while (++i < ac)
	{
		ptr[i].size = ft_strlen(av[i]);
		ptr[i].str = av[i];
		ptr[i].copy = ft_strdup(av[i]);
	}
	ptr[ac].str = 0;
	return (ptr);
}
