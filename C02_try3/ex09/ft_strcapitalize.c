/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adi-stef <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 09:59:58 by adi-stef          #+#    #+#             */
/*   Updated: 2022/09/15 10:04:09 by adi-stef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_positive(char *c)
{
	if (*c >= 65 && *c <= 90)
		return (0);
	else if (*c >= 97 && *c <= 122)
	{
		*c -= 32;
		return (0);
	}
	else if (*c > 47 && *c < 58)
		return (0);
	else
		return (1);
}

int	ft_negative(char *c)
{
	if (*c >= 65 && *c <= 90)
		return (0);
	else if (*c >= 97 && *c <= 122)
		return (0);
	else if (*c > 47 && *c < 58)
		return (0);
	else
		return (1);
}

char	*ft_strcapitalize(char *str)
{
	int	check;
	int	i;

	check = 1;
	i = 0;
	while (str[i] != '\0')
	{
		if (check)
			check = ft_positive(&str[i]);
		else
			check = ft_negative(&str[i]);
		i++;
	}
	return (str);
}
