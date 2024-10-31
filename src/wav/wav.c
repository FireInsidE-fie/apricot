#include "wav.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int	read_wav_head(char *path)
{
	FILE		*file;
	t_header	*header;

	file = fopen(path, "r");
	header = malloc(sizeof(t_header));
	if (!file)
		return (-1);
	// Parsing the header in the t_header struct
	fread(header->riff, 1, 4, file); // RIFF string
	// Wrapping up
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
