
#include "fillit.h"

int 	check_connections(char *str)
{
	int 	i;
	int 	connection;
	int		sharps;

	i = 0;
	connection = 0;
	sharps = 0;
	while (str[i])
	{
		if (str[i] == '#')
		{
			connection += (i - 1 >= 0 && str[i - 1] == '#');
			connection += (i + 1 < 20 && str[i + 1] == '#');
			connection += (i - 5 >= 0 && str[i - 5] == '#');
			connection += (i + 5 < 20 && str[i + 5] == '#');
			sharps++;
		}
		i++;
	}
	return ((connection == 6 || connection == 8) && sharps == 4);
}

int 	check_blocks(char *str, int ret)
{
	int 	i;

	if (ret < 20 || ret > 21)
		return (0);
	i = 0;
	while (str[i])
	{
		if (i == 4 || i == 9 || i == 14 || i == 19 || i == 20)
		{
			if (str[i] != '\n')
				return (0);
			i++;
			continue;
		}
		if (str[i] != '.' && str[i] != '#')
			return (0);
		i++;
	}
	if (ret == 20 && i == 20)
		return (str[i] == '\0');
	return (1);
}

int		begin_check(int fd)
{
	char	buff[BUFF_SIZE + 1];
	int		ret;

	while ((ret = read(fd, buff, BUFF_SIZE)))
	{
		buff[ret] = '\0';
		if(!check_blocks(buff, ret) || !check_connections(buff))
			return (0);
	}
	return (1);
}
