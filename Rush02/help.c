/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adi-stef <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 19:07:33 by adi-stef          #+#    #+#             */
/*   Updated: 2022/09/25 19:56:19 by adi-stef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include <unistd.h>

void	ft_print_char(char *nbr, char **buf, int len);
void	ft_doppietta(char *nbr, char **buf);
void	ft_suffix(int len, char **buf);
int		ft_strlen(char *str);

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

void	ft_case2(char *nbr, char **buf)
{
	ft_doppietta(nbr, buf);
	if (ft_strlen(nbr) > 3)
		ft_suffix(ft_strlen(nbr), buf);
}

void	ft_case1(char *nbr, char **buf)
{
	ft_print_char(nbr, buf, 1);
	if (ft_strlen(nbr) > 3)
		ft_suffix(ft_strlen(nbr), buf);
}
