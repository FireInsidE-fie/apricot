#include "wav.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

t_header	*read_wav_head(char *path)
{
	FILE		*file;
	t_header	*header;

	file = fopen(path, "r");
	header = malloc(sizeof(t_header));
	if (!file)
	{
		free(header);
		return (NULL);
	}
	// Parsing the header in the t_header struct
	fread(header->riff, 1, 4, file); // RIFF string
	// Wrapping up
	fclose(file);
	return (header);
}

int	main(int argc, char **argv)
{
	t_header	*header;
	if (argc != 2)
		return (-1);
	header = read_wav_head(argv[1]);
	printf("%s", header->riff);
	free(header);
	return (0);
}
