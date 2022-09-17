/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_div_mod.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adi-stef <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 11:12:06 by adi-stef          #+#    #+#             */
/*   Updated: 2022/09/12 11:17:39 by adi-stef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
void	ft_ultimate_div_mod(int *a, int *b)
{
	int	divisor;
	int	dividend;

	divisor = *a;
	dividend = *b;
	*a = divisor / dividend;
	*b = divisor % dividend;
}
