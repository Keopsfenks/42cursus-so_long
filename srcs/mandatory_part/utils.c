#include "so_long.h"

size_t	ft_strlen_nl(char *str)
{
	size_t i;

	i = 0;
	while((str[i] != '\0' && str[i] != '\n'))
	{
		i++;
	}
	return (i);
}

void	error_print(char *str)
{
	ft_printf("%s", str);
	exit(0);
}

