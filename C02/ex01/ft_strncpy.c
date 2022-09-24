/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adi-stef <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 13:53:35 by adi-stef          #+#    #+#             */
/*   Updated: 2022/09/14 17:39:55 by adi-stef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	i;
	char			end;

	i = 0;
	end = 0;
	while (i < n)
	{
		if (end > 0)
			dest[i] = 0;
		else
		{
			dest[i] = src[i];
			if (src[i] == 0)
				end++;
		}
		i++;
	}
	return (dest);
}
