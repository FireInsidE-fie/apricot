#include "wav.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

t_header	*read_wav_head(char *path)
{
	FILE		*file;
	t_header	*header;
	int			buffer4[4] = {0};
	//int			i;

	file = fopen(path, "r");
	header = malloc(sizeof(t_header));
	if (!file)
	{
		free(header);
		return (NULL);
	}
	// Parsing the header in the t_header struct
	fread(header->riff, sizeof(header->riff), 1, file);
	fread(buffer4, 4, 1, file);
	header->overall_size = buffer4[0] |
    						buffer4[1]<<8 |
    						buffer4[2]<<16 |
							buffer4[3]<<24;
	fread(header->wave, sizeof(header->wave), 1, file);
	fread(header->fmt_chunk_marker, sizeof(header->fmt_chunk_marker), 1, file);
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
	write(1, header->riff, 4);
	write(1, "\n", 1);
	printf("%u\n", header->overall_size);
	write(1, header->wave, 4);
	write(1, "\n", 1);
	write(1, header->fmt_chunk_marker, 4);
	write(1, "\n", 1);
	free(header);
	return (0);
}
