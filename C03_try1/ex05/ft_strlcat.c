/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adi-stef <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 10:26:57 by adi-stef          #+#    #+#             */
/*   Updated: 2022/09/15 16:19:05 by adi-stef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	int	i;
	int	sz;
	int	j;

	sz = size;
	if (!src || !*src)
		return (ft_strlen(dest));
	if (sz < ft_strlen(dest))
		return (sz + ft_strlen(src));
	i = 0;
	j = ft_strlen(dest);
	while (i < sz - j && src[i])
	{
		dest[i + j] = src[i];
		i++;
	}
	dest[i + j - 1] = '\0';
	return (j + ft_strlen(src));
}
