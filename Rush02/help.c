/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adi-stef <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 19:07:33 by adi-stef          #+#    #+#             */
/*   Updated: 2022/09/25 19:12:45 by adi-stef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include <unistd.h>

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

void	ft_free(char **buf)
{
	int	i;

	i = -1;
	while (buf[++i])
		free(buf[i]);
	free(buf[i]);
	free(buf);
}
