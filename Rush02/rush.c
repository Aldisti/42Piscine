/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adi-stef <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 15:43:35 by adi-stef          #+#    #+#             */
/*   Updated: 2022/09/24 18:55:22 by adi-stef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>

void	ft_print(char *str);
int		ft_wrd_nbr(char *str, char *set);
char	**ft_split(char *str, char *set);

void	ft_print(char *str)
{
	int	i;

	i = -1;
	while (str[++i] != 10)
	if (str[i] != 32 && (str[i] < 9 || str[i] > 13))
		write(1, &str[i], 1);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_error(int type)
{
	if (type == 1)
	{
		ft_print("Dict Error\n");
		return (0);
	}
	return (1);
}

void	ft_free(char **buf, int len)
{
	int	i;

	if (len > 0)
	{
		i = -1;
		while (++i < len)
			free(buf[i]);
	}
	free(buf);
}

int	ft_buflen(char *path)
{
	char	buf[1];
	int		file;
	int		len;
	int		i;

	len = 0;
	file = open(path, O_RDONLY);
	if (file == -1)
		return (ft_error(0));
	while (i)
	{
		i = read(file, buf, 1);
		if (i == -1)
			return(ft_error(1));
		len += i;
	}
	close(file);
	return (len);
}

void	ft_make_list(char *path)
{
	char	**buf;
	char	*str;
	char	*set;
	int		file;
	int		len;
	int		i;

	len = ft_buflen(path);
	if (!len)
		ft_error(1);
	str = (char *) malloc ((len + 1) * sizeof (char));
	file = open(path, O_RDONLY);
	if (file == -1)
		file = ft_error(1); // da controllare
	i = read(file, str, len);
	if (i == -1)
		i = ft_error(1); // da controllare
	set = "\n";
	buf = ft_split(str, set);
	i = -1;
	while (++i < ft_wrd_nbr(str, set))
		puts(buf[i]);
	ft_free(buf, ft_wrd_nbr(str, set));
	free(str);
}


int	main(void)
{
	char	*str;
	int		len;

	ft_make_list("numbers.dict");
}

