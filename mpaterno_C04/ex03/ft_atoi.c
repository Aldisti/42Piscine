/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaterno <mpaterno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 09:15:00 by mpaterno          #+#    #+#             */
/*   Updated: 2022/09/16 09:26:26 by mpaterno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	convert(char *str, int num_counter)
{
	int	counter;
	int	result;
	int	i;

	i = 0;
	counter = 1;
	result = 0;
	while (str[i] != '\0')
	{
		result = result + ((str[num_counter - i] - 48) * counter);
		counter *= 10;
		i++;
	}
	return (result);
}

int	sign(char *str)
{
	int	i;
	int	sign;

	i = 0;
	sign = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '-')
		{
			sign++;
		}
		i++;
	}
	if (sign % 2 == 1)
	{
		return (-1);
	}
	else
	{
		return (1);
	}
}

int	ft_atoi(char *str)
{
	int		num_counter;
	int		i;
	char	num[20];

	i = 0;
	num_counter = 0;
	while (str[i] != '\0')
	{
		if ((str[i] >= '0' && str[i] <= '9') && str[i] != '\0')
		{
			num[num_counter] = str[i];
			num_counter++;
		}
		if (num_counter != 0 && (str[i] < '0' || str[i] > '9'))
		{
			num[num_counter] = '\0';
			break ;
		}
		i++;
	}
	return (convert(num, num_counter - 1) * sign(str));
}
