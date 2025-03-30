const WavHeader = struct {
    id_riff: u8[4], // RIFF string (4 length)
    file_size: u32, // overall size of file in bytes
    id_wave: u8[4], // WAVE string (4 length)
    id_fmt: u8[4], // fmt string with trailing null char
    fmt_length: u32, // length of the format data
    fmt_type: u16, // format type. 1-PCM, 3- IEEE float, 6 - 8bit A law, 7 - 8bit mu law
    channels: u16, // no.of channels
    sample_rate: u32, // sampling rate (blocks per second)
    byte_rate: u32, // SampleRate * NumChannels * BitsPerSample/8
    block_align: u16, // NumChannels * BitsPerSample/8
    bits_per_sample: u16, // bits per sample, 8- 8bits, 16- 16 bits etc
    id_data: u8[4], // DATA string or FLLR string
    size_data: u32, // NumSamples * NumChannels * BitsPerSample/8 - size of the next chunk that will be read
};
