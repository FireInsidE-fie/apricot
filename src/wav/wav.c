#include "wav.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int	read_wav_head(char *path)
{
	FILE	*file;
	int		i;
	char	c;

	file = fopen(path, "r");
	i = 0;
	while (i++ < 44)
	{
		c = fgetc(file);
		write(1, &c, 1);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	if (argc != 2)
		return (-1);
	read_wav_head(argv[1]);
	return (0);
}
