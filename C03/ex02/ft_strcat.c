/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adi-stef <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 14:25:55 by adi-stef          #+#    #+#             */
/*   Updated: 2022/09/18 11:00:24 by adi-stef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strln(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strcat(char *dest, char *src)
{
	int	ln;
	int	i;

	ln = ft_strln(dest);
	i = 0;
	while (src[i] != '\0')
	{
		dest[ln + i] = src[i];
		i++;
	}
	dest[ln + i] = '\0';
	return (dest);
}
