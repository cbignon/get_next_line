#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int	main()
{
	int fd;
	char *line;
	int	ret;

	fd = open("/Users/camillebignon/Documents/42_CURSUS/get_next_line/text.txt", O_RDONLY);
	ret = 1;
	while (ret > 0)
	{
		ret = get_next_line(fd, &line);
		printf("return = %d\n",ret);
		printf("%s\n", line);
		//free(line);
		//line = NULL;
	}
	close(fd);
	return (0);
}