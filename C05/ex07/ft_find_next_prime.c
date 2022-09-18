#include <stdio.h>

int ft_sqrt(int nb)
{
    int i;

    i = 0;
    while (i * i < nb)
        i++;
    return (i);
}

int ft_is_prime(int nb)
{
    int i;

    i = 1;
    while (++i <= ft_sqrt(nb))
        if (nb % i == 0 && i != nb)
            return (0);
    return (1);
}

int ft_find_next_prime(int nb)
{
    if (ft_is_prime(nb))
        return (nb);
    else
        if (nb % 2)
            ft_find_next_prime(nb + 2);
        else
            ft_find_next_prime(nb + 1);
}

int main(void)
{
    printf(">%d\n", ft_find_next_prime(555));
}