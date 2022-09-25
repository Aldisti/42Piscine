/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adi-stef <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 19:13:09 by adi-stef          #+#    #+#             */
/*   Updated: 2022/09/25 19:44:54 by adi-stef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

void	ft_nbr_parse(char *nbr, char **buf);
int		ft_strncmp(char *s1, char *s2, unsigned int n);
char	**ft_make_list(char *path, int len);
int		ft_check_nbr(char *nbr, char *str);
int		ft_wrd_nbr(char *str, char *set);
char	**ft_split(char *str, char *set);
int		ft_buflen(char *path);
int		ft_strlen(char *str);
void	ft_print(char *str);
void	ft_print(char *str);
char	*ft_atoi(char *str);
void	ft_error(int type);
void	ft_free(char **buf);

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
	buf = ft_make_list("numbers.dict", ft_buflen("numbers.dict"));
	ft_nbr_parse(ft_atoi(argv[1]), buf);
	ft_free(buf);
}
