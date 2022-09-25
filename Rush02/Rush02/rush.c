/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adi-stef <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 15:43:35 by adi-stef          #+#    #+#             */
/*   Updated: 2022/09/25 17:27:35 by adi-stef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>

void	ft_nbr_parse(char *nbr, char **buf);
int		ft_strncmp(char *s1, char *s2, unsigned int n);
int		ft_check_nbr(char *nbr, char *str);
int		ft_wrd_nbr(char *str, char *set);
char	**ft_split(char *str, char *set);
int		ft_strlen(char *str);
void	ft_print(char *str);
void	ft_print(char *str);
char	*ft_atoi(char *str);
void	ft_error(int type);

void	ft_free(char **buf)
{
	int	i;

	i = -1;
	while (buf[++i])
		free(buf[i]);
	free(buf[i]);
	free(buf);
}

int	ft_buflen(char *path)
{
	char	buf[1];
	int		file;
	int		len;
	int		i;

	len = 0;
	i = 1;
	file = open(path, O_RDONLY);
	if (file == -1)
		ft_error(1);
	while (i)
	{
		i = read(file, buf, 1);
		if (i == -1)
			ft_error(1);
		len += i;
	}
	close(file);
	return (len);
}

char	**ft_make_list(char *path)
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
		ft_error(1); // da controllare
	i = read(file, str, len);
	if (i == -1)
		ft_error(1); // da controllare
	str[len] = 0;
	set = "\n";
	buf = ft_split(str, set);
	i = -1;
	close(file);
	free(str);
	return (buf);
}

void	ft_print_name(char *str, in n)
{
	int	i;
	int	j; // spaces 0:start 1:print 2:during

	j = 0;
	i = -1;
	while (str[++i])
	{
		if (j == 0 && str[i] != 32)
			j = 1;
		else if (j == 1 && str[i] == 32)
		{
			write(1, " ", 1);
			j = 0;
		}
		if (j == 1 && str[i] != 32)
			write(1, &str[i], 1);
	}
	if (n)
		write(1, " ", 1);
}

char	*ft_get_name(int i, int	n)
{
	int	j;
	int	k;

	j = -1;
	while (buf[i][++j])
	{
		if (buf[i][j] == 58)
		{
			ft_print_name(&buf[i][j + 1], n);
			break ;
		}
	}
}

void	ft_print_char(char *nbr, char **buf, int len, int n)
{
	int	i;
	int	j;
	int	k;

	i = -1;
	while (buf[++i])
	{
		if (ft_strncmp(buf[i], nbr, len) == 0)
		{	
			k = 1;
			break ;
		}
	}
	if (k)
		ft_get_name(i, n);
}

int	main(int argc, char **argv)
{
	char	**buf;

	if (argc < 2)
		return (1);
	if (!ft_check_nbr(ft_atoi(argv[1]), "4294967295"))
	{
		ft_print("Error\n");
		return (1);
	}
	//if (!ft_check_dict())
	//{
	//	ft_error(1);
	//	return (1);
	//}
	buf = ft_make_list("numbers.dict");
	ft_nbr_parse(argv[1], buf);
	ft_free(buf);

}
