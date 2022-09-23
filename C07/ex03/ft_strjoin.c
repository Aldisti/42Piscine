/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adi-stef <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 12:54:53 by adi-stef          #+#    #+#             */
/*   Updated: 2022/09/22 15:08:44 by adi-stef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include <stdio.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_fill(char *ptr, char **strs, char *sep, int size)
{
	int	i;
	int	j;
	int	k;

	k = 0;
	i = -1;
	while (++i < size)
	{
		if (i > 0)
		{
			j = -1;
			while (sep[++j])
			{
				ptr[k] = sep[j];
				k++;
			}
		}
		j = -1;
		while (strs[i][++j])
		{
			ptr[k] = strs[i][j];
			k++;
		}
	}
	return (ptr);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*ptr;
	int		len;
	int		i;

	if (size == 0)
	{
		ptr = NULL;
		return (ptr);
	}
	i = -1;
	len = ft_strlen(sep) * (size - 1);
	while (++i < size)
		len += ft_strlen(strs[i]);
	ptr = (char *) malloc (len * sizeof (char));
	return (ft_fill(ptr, strs, sep, size));
}
/*
int	main(void)
{
	char	*ptr[] = {"Ciao", "come", "stai"};
	char	*str;
	char	sep[] = "\nSEP\n";

	str = ft_strjoin(3, ptr, sep);
	puts(str);
	free(str);
}
*/
