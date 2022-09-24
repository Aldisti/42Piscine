/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adi-stef <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 15:46:50 by adi-stef          #+#    #+#             */
/*   Updated: 2022/09/24 16:42:36 by adi-stef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

void	ft_print(char *str);

int	main(void)
{
	char	**list;
	char	*str[1];
	int		file;
	int		i;

	file = open("numbers.dict", O_RDONLY);
	if (file == -1)
		ft_print("open() error\n");
	read(file, str, 1);
	
}

