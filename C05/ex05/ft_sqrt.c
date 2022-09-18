#include <stdio.h>
int ft_sqrt(int nb)
{
    int i;

    i = 1;
    while (++i * i != nb)
        if (i * i > nb)
            return (0);
    return (i);
}

int main(void)
{
    printf(">%d\n", ft_sqrt(100000000));
}