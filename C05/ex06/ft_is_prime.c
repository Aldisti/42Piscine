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

int main(void)
{
    printf("%d\n", ft_is_prime(2));
}