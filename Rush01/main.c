/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adi-stef <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 16:46:01 by adi-stef          #+#    #+#             */
/*   Updated: 2022/09/18 17:34:08 by adi-stef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <stdio.h>

void	rush(int row, int col, char *input);

int	ft_argv_check(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if (str[i] != 32)
			if (str[i] < 48 || str[i] > 57)
				return (0);
	}
	if (i != 31)
		return (0);
	return (1);
}

int	main(int argc, char **argv)
{
	if (argc == 2 && ft_argv_check(argv[1]))
		rush(4, 4, argv[1]);
	else
		write(1, "Error\n", 6);
	return (0);
}
