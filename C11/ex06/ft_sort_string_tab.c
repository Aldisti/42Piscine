/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_string_tab.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adi-stef <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 17:38:47 by adi-stef          #+#    #+#             */
/*   Updated: 2022/09/29 18:14:55 by adi-stef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] - s2[i] == 0)
	{
		if (s1[i] == '\0' && s2[i] == '\0')
			return (0);
		i++;
	}
	return (s1[i] - s2[i]);
}

void	ft_sort_string_tab(char **tab)
{
	char	*p;
	int		i;
	int		j;

	if (!tab || !tab[0])
		return ;
	i = -1;
	while (tab[++i])
	{
		j = i;
		while (tab[++j])
		{
			if (ft_strcmp(tab[i], tab[j]) > 0)
			{
				p = tab[i];
				tab[i] = tab[j];
				tab[j] = p;
			}
		}
	}
}
/*
#include <stdio.h>
int	main(void)
{
	char	*a[] = {"abcd ", "abcd", "dcba", "ciao", ""};
	int		i;

	a[4] = 0;
	ft_sort_string_tab(a);
	i = -1;
	while (a[++i])
		puts(a[i]);
}
*/
