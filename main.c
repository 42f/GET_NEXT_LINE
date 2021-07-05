#include <stdio.h>
#include "get_next_line_bonus.h"

int main(void)	{

	char	*line;
	int		ret = 1;

	while ( (ret = get_next_line(0, &line)) == 1)	{
		printf("[%d] %s\n", ret, line);
	}
	return (ret);
}
