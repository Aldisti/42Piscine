/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adi-stef <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 15:37:00 by adi-stef          #+#    #+#             */
/*   Updated: 2022/09/22 12:34:00 by adi-stef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

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
/*
#include <stdio.h>
int	main(void)
{
	char	a[] = "Ciao come stai?";
	char*	dup;

	dup = ft_strdup(a);
	puts(dup);
	free(dup);
}
*/
