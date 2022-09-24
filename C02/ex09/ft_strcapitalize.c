/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adi-stef <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 09:59:58 by adi-stef          #+#    #+#             */
/*   Updated: 2022/09/21 10:01:23 by adi-stef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

char	*ft_lower(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		if (str[i] >= 65 && str[i] <= 90)
			str[i] += 32;
	return (str);
}

char	*ft_strcapitalize(char *str)
{
	int	i;
	int	k;

	k = 1;
	i = -1;
	str = ft_lower(str);
	while (str[++i])
	{
		if (str[i] >= 97 && str[i] <= 122)
		{
			if (k)
				str[i] -= 32;
			k = 0;
		}
		else if (str[i] >= 65 && str[i] <= 90)
			k = 0;
		else if (str[i] >= 48 && str[i] <= 57)
			k = 0;
		else
			k = 1;
	}
	return (str);
}
/*
int	main(void)
{
	char	a[] = "ReKt17+LOl MdR Mdr 4242l42";
	char	b[] = "salut, comment tu vas ? 42mots quarante-deux; cinquante+et+un";

	puts(ft_strcapitalize(a));
	puts(ft_strcapitalize(b));
}
*/
