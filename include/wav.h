#ifndef WAV_H
# define WAV_H
# include <stdint.h>

// WAVE file header format
typedef struct s_header {
	unsigned char	riff[4];					// RIFF string (4 length)
	uint32_t		overall_size;				// overall size of file in bytes
	unsigned char	wave[4];					// WAVE string (4 length)
	unsigned char	fmt_chunk_marker[4];		// fmt string with trailing null char
	uint32_t		length_of_fmt;				// length of the format data
	uint16_t		format_type;				// format type. 1-PCM, 3- IEEE float, 6 - 8bit A law, 7 - 8bit mu law
	uint16_t		channels;					// no.of channels
	uint32_t		sample_rate;				// sampling rate (blocks per second)
	uint32_t		byterate;					// SampleRate * NumChannels * BitsPerSample/8
	uint16_t		block_align;				// NumChannels * BitsPerSample/8
	uint16_t		bits_per_sample;			// bits per sample, 8- 8bits, 16- 16 bits etc
	unsigned char	data_chunk_header[4];		// DATA string or FLLR string
	uint32_t		data_size;					// NumSamples * NumChannels * BitsPerSample/8 - size of the next chunk that will be read
} t_header;

t_header	*read_wav_head(char *path);

#endif