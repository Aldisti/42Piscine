/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adi-stef <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 14:38:55 by adi-stef          #+#    #+#             */
/*   Updated: 2022/09/18 10:59:17 by adi-stef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int	i;
	unsigned int	ln;

	ln = 0;
	while (dest[ln])
		ln++;
	i = 0;
	while (i < nb && src[i] != '\0')
	{
		dest[ln + i] = src[i];
		i++;
	}
	while (i < nb)
	{
		dest[ln + i] = 0;
		i++;
	}
	return (dest);
}
