#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int	main()
{
	int fd;
	char *line;
	int	ret;

	ret = 1;
	if ((fd = open("/Users/camillebignon/Documents/42_CURSUS/GNL/get_next_line/text.txt", O_RDONLY)) == -1)
	{
		ret = -1;
		printf("erreur read\n");
		return(0);
	}
	while (ret > 0)
	{
		ret = get_next_line(fd, &line);
		if (ret == -1)
		{
			printf("erreur read()\n");
			return (0);
		}
		printf("ret %d |%s|\n",ret, line);
		free(line);
		line = NULL;
	}
	close(fd);
	return (0);
}