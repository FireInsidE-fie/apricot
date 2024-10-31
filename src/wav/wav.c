#include "wav.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int	read_wav_head(char *path)
{
	FILE	*file;
	int		i;
	int		c;

	file = fopen(path, "r");
	if (!file)
		return (-1);
	i = 0;
	while (i++ < 44)
	{
		c = fgetc(file);
		write(1, &c, 1);
	}
	fclose(file);
	return (0);
}

int	main(int argc, char **argv)
{
	if (argc != 2)
		return (-1);
	read_wav_head(argv[1]);
	return (0);
}
