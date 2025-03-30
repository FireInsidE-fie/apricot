#ifndef WAV_H
# define WAV_H
# include <stdint.h>

// WAVE file header format
typedef struct s_header {
    unsigned char   riff[4];                    
    uint32_t        overall_size;               
    unsigned char   wave[4];                    
    unsigned char   fmt_chunk_marker[4];        
    uint32_t        length_of_fmt;              
    uint16_t        format_type;				
    uint16_t        channels;					
    uint32_t        sample_rate;				
    uint32_t        byterate;					
    uint16_t        block_align;				
    uint16_t        bits_per_sample;			
    unsigned char   data_chunk_header[4];		
    uint32_t        data_size;					
} t_header;

t_header	*read_wav_head(char *path);

#endif