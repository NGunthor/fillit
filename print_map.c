#include "fillit.h"

void print_map(char **map, int map_size)
{
    int i;
    int j;

    i = 0;
    while (i < map_size)
    {
        j = 0;
        while (j < map_size)
        {
            ft_putchar(map[i][j]);
            j++;
        }
        ft_putchar('\n');
        i++;
    }
}

