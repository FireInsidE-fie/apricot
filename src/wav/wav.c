#include "wav.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/**
 * @brief Parsed a 32bit value from little endian to an unsigned int.
 *
 * @param buffer4 A 4 array of integers containing the 4 bytes of the le value.
 * @return The parsed value as a uint32_t.
 */
uint32_t	parse_32_le(int *buffer4)
{
	return (buffer4[0] |
			buffer4[1]<<8 |
			buffer4[2]<<16 |
			buffer4[3]<<24);
}

/**
 * @brief Parsed a 16bit value from little endian to an unsigned int.
 *
 * @param buffer2 A 2 array of integers containing the 2 bytes of the le value.
 * @return The parsed value as a uint16_t.
 */
uint16_t	parse_16_le(int *buffer2)
{
	return (buffer2[0] |
			buffer2[1]<<8 |
			buffer2[2]<<16 |
			buffer2[3]<<24);
}

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
	header->overall_size = parse_32_le(buffer4);
	fread(header->wave, sizeof(header->wave), 1, file);
	fread(header->fmt_chunk_marker, sizeof(header->fmt_chunk_marker), 1, file);
	fread(buffer4, 4, 1, file);
	header->length_of_fmt = parse_32_le(buffer4);
	fread(buffer2, 2, 1, file);
	header->format_type = parse_16_le(buffer2);
	fread(buffer2, 2, 1, file);
	header->channels = parse_16_le(buffer2);
	fread(buffer4, 4, 1, file);
	header->sample_rate = parse_32_le(buffer4);
	fread(buffer4, 4, 1, file);
	header->byterate = parse_32_le(buffer4);
	fread(buffer2, 2, 1, file);
	header->block_align = parse_16_le(buffer2);
	fread(buffer2, 2, 1, file);
	header->bits_per_sample = parse_16_le(buffer2);
	fread(header->data_chunk_header, 4, 1, file);
	fread(buffer4, 4, 1, file);
	header->data_size = parse_32_le(buffer4);
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
	if (!header)
	{
		printf("[!] - Error when opening file!\n");
		return (-1);
	}
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
