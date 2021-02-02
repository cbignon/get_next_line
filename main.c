//#include "get_next_line.h"
#include "get_next_line_bonus.h"
#include <fcntl.h>
#include <stdio.h>

int	main()
{
	int fd;
	int fd1;
	char *line;
	int	ret;
	int ret1;

	ret = 1;
	ret1 = 1;
	if ((fd = open("/Users/camillebignon/Documents/42_CURSUS/get_next_line/text.txt", O_RDONLY)) == -1)
	{
		ret = -1;
		printf("erreur read 1\n");
		return(0);
	}
		if ((fd1 = open("/Users/camillebignon/Documents/42_CURSUS/get_next_line/text copy.txt", O_RDONLY)) == -1)
	{
		ret1 = -1;
		printf("erreur read 2\n");
		return(0);
	}
	while (ret > 0 || ret1 > 0)
	{
		ret = get_next_line(fd, &line);
		if (ret == -1)
		{
			printf("erreur read()\n");
			return (0);
		}
		printf("FD0 ret %d |%s|\n",ret, line);
		ret1= get_next_line(fd1,&line);
		if (ret1== -1)
		{
			printf("erreur read()\n");
			return (0);
		}
		printf("FD1 ret %d |%s|\n",ret1, line);
		free(line);
		line = NULL;
	}
	close(fd);
	close(fd1);
	return (0);
}