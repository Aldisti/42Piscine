/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adi-stef <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 18:34:58 by adi-stef          #+#    #+#             */
/*   Updated: 2022/09/15 18:40:45 by adi-stef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <string.h>
#include "ft_strncmp.c"

int	main(void)
{
	char	a[] = "Ciao come stai?";
	char	b[] = "Ciao come Stai?";

	printf("Correct: %d\nProgram: %d\n", strncmp(a, b, 8), ft_strncmp(a, b, 8));
	printf("Correct: %d\nProgram: %d\n", strncmp(a, b, 15), ft_strncmp(a, b, 15));
}
