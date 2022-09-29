/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_do_op.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adi-stef <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 12:12:04 by adi-stef          #+#    #+#             */
/*   Updated: 2022/09/29 18:28:27 by adi-stef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_putnbr(int nb);
int		ft_atoi(char *str);
int		sum(int a, int b);
int		min(int a, int b);
int		mul(int a, int b);
int		div(int a, int b);
int		mod(int a, int b);

typedef int	(*t_f)(int a, int b);

void	ft_calculate(int a, int b, char *op, t_f *f)
{
	if (op[0] == 43 && !op[1])
		ft_putnbr(f[0](a, b));
	else if (op[0] == 45 && !op[1])
		ft_putnbr(f[1](a, b));
	else if (op[0] == 42 && !op[1])
		ft_putnbr(f[2](a, b));
	else if (op[0] == 47 && !op[1])
	{
		if (b == 0)
			write(1, "Stop : division by zero", 23);
		else
			ft_putnbr(f[3](a, b));
	}
	else if (op[0] == 37 && !op[1])
	{
		if (b == 0)
			write(1, "Stop : modulo by zero", 21);
		else
			ft_putnbr(f[4](a, b));
	}
	else
		write(1, "0", 2);
	write(1, "\n", 1);
}

void	ft_start(char *a, char *op, char *b)
{
	t_f	f[5];
	int	n1;
	int	n2;

	f[0] = &sum;
	f[1] = &min;
	f[2] = &mul;
	f[3] = &div;
	f[4] = &mod;
	n1 = ft_atoi(a);
	n2 = ft_atoi(b);
	ft_calculate(n1, n2, op, f);
}

int	main(int ac, char **av)
{
	if (ac != 4)
		return (1);
	else
		ft_start(av[1], av[2], av[3]);
	return (0);
}
