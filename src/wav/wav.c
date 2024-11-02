#include "wav.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

t_header	*read_wav_head(char *path)
{
	FILE		*file;
	t_header	*header;
	int			buffer2[2] = {0};
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
	fread(buffer4, 4, 1, file);
	header->length_of_fmt = buffer4[0] |
    						buffer4[1]<<8 |
    						buffer4[2]<<16 |
							buffer4[3]<<24;
	fread(buffer2, 2, 1, file);
	header->format_type = buffer2[0] |
    						buffer2[1]<<8;
	fread(buffer2, 2, 1, file);
	header->channels = buffer2[0] |
    						buffer2[1]<<8;	
	fread(buffer4, 4, 1, file);
	header->sample_rate = buffer4[0] |
    						buffer4[1]<<8 |
    						buffer4[2]<<16 |
							buffer4[3]<<24;
	fread(buffer4, 4, 1, file);
	header->byterate = buffer4[0] |
    						buffer4[1]<<8 |
    						buffer4[2]<<16 |
							buffer4[3]<<24;
	fread(buffer2, 2, 1, file);
	header->block_align = buffer2[0] |
    						buffer2[1]<<8;	
	fread(buffer2, 2, 1, file);
	header->bits_per_sample = buffer2[0] |
    						buffer2[1]<<8;	
	fread(header->data_chunk_header, 4, 1, file);
	fread(buffer4, 4, 1, file);
	header->byterate = buffer4[0] |
    						buffer4[1]<<8 |
    						buffer4[2]<<16 |
							buffer4[3]<<24;
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
	printf("%u\n", header->length_of_fmt);
	printf("%u\n", header->format_type);
	printf("%u\n", header->channels);
	printf("%u\n", header->sample_rate);
	printf("%u\n", header->byterate);
	printf("%u\n", header->block_align);
	printf("%u\n", header->bits_per_sample);
	write(1, header->data_chunk_header, 4);
	write(1, "\n", 1);
	printf("%u\n", header->data_size);
	free(header);
	return (0);
}
