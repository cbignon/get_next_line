#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int	main(int argc, char **argv)
{
	int fd;
	char *line;
	int	ret;

	if (!(fd = open("/Users/camillebignon/Documents/42_CURSUS/GNL/get_next_line/text.txt", O_RDONLY)))
		return (-1);
	ret = 1;
	while (ret > 0)
	{
		ret = get_next_line(fd, &line);
		printf("return = %d- %s\n",ret, line);
	//	free(line);
	//	line = NULL;
	}
	if (ret == -1)
		printf("erreur read");
	close(fd);
	return (0);
}