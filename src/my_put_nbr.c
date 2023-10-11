/*
** EPITECH PROJECT, 2021
** my_put_nbr
** File description:
** my_put_nbr
*/

void my_putchar(char c);

int my_put_nbr(int n)
{
    int	x;

    if (n < 0) {
        my_putchar('-');
        n = n * (-1);
    }
    if (n >= 0) {
        if (n >= 10) {
            x = (n % 10);
            n = (n - x) / 10;
            my_put_nbr(n);
            my_putchar(48 + x);
        }
        else
            my_putchar(48 + n % 10);
    }
    return (0);
}
