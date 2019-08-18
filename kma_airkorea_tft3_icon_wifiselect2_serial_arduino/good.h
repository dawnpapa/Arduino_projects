// We need this header file to use FLASH as storage with PROGMEM directive:
#include <pgmspace.h>

// Icon width and height
const uint16_t goodWidth = 95;
const uint16_t goodHeight = 25;

const unsigned short  good[2375] PROGMEM={
0x0800, 0x0800, 0x0000, 0x0000, 0x0020, 0x0040, 0x0002, 0x0005, 0x52d3, 0x4a96, 0x843f, 0x94df, 0x843f, 0x845f, 0x7c1f, 0x7c3f, 0x843f, 0x843f, 0x843f, 0x843f, 0x843f, 0x843f, 0x843f, 0x843f, 0x843f, 0x843f, 0x843f, 0x843f, 0x843f, 0x843f, 0x843f, 0x843f, 0x7c3f, 0x7c3f, 0x7c5f, 0x845f, 0x843f, 0x843f, 0x843f, 0x843f, 0x841f, 0x843f, 0x7c1f, 0x7c3f, 0x8c7f, 0x7c3f, 0x843f, 0x843f, 0x845f, 0x7c1f, 0x843f, 0x841f, 0x843f, 0x83ff, 0x8c1f, 0x83ff, 0x841f, 0x841f, 0x843f, 0x841f, 0x845f, 0x841f, 0x8bff, 0x8c1f, 0x83ff, 0x8c3f, 0x8c1f, 0x841f, 0x841f, 0x7bff, 0x841f, 0x843f, 0x83ff, 0x8c5f, 0x845f, 0x7c1f, 0x8c1f, 0x8c1f, 0x841f, 0x845f, 0x7c1f, 0x741f, 0x845f, 0x94bf, 0x845f, 0x3a17, 0x4ab5, 0x0006, 0x0002, 0x0000, 0x0000, 0x0040, 0x0000, 0x0000, 0x0000,
0x0000, 0x0000, 0x0000, 0x0001, 0x0002, 0x2149, 0x847a, 0x73ba, 0x39f6, 0x10d4, 0x1097, 0x0857, 0x0037, 0x0879, 0x0039, 0x003a, 0x0059, 0x0059, 0x0059, 0x0059, 0x0059, 0x0059, 0x0059, 0x0059, 0x0059, 0x0059, 0x0059, 0x0059, 0x0059, 0x0059, 0x0059, 0x0059, 0x005a, 0x0059, 0x0058, 0x0058, 0x0058, 0x0038, 0x0058, 0x0058, 0x0879, 0x0018, 0x089a, 0x0017, 0x0038, 0x0057, 0x0859, 0x0839, 0x0037, 0x0879, 0x0859, 0x0019, 0x003a, 0x085a, 0x0019, 0x0859, 0x0838, 0x0038, 0x0038, 0x0038, 0x0038, 0x0879, 0x0039, 0x0839, 0x0859, 0x109a, 0x0018, 0x0839, 0x005a, 0x005a, 0x0058, 0x0036, 0x0878, 0x0037, 0x0078, 0x0058, 0x0858, 0x0858, 0x0017, 0x0038, 0x005a, 0x08bb, 0x0058, 0x0857, 0x0877, 0x18d7, 0x39f7, 0x6359, 0x7bd8, 0x296b, 0x0022, 0x0000, 0x0020, 0x0020, 0x0000,
0x0000, 0x0840, 0x0000, 0x0002, 0x296e, 0x841e, 0x319b, 0x0839, 0x001a, 0x001b, 0x083c, 0x001d, 0x083e, 0x003e, 0x001d, 0x003e, 0x001d, 0x001d, 0x001d, 0x001d, 0x001d, 0x001d, 0x001d, 0x001d, 0x001d, 0x001d, 0x001d, 0x001d, 0x001d, 0x001d, 0x001d, 0x001d, 0x003e, 0x003d, 0x003d, 0x003d, 0x001d, 0x001d, 0x001d, 0x001d, 0x001d, 0x001c, 0x003d, 0x003d, 0x001d, 0x001d, 0x001c, 0x001d, 0x001d, 0x001d, 0x001d, 0x001d, 0x001e, 0x003d, 0x003d, 0x001d, 0x001d, 0x001d, 0x003c, 0x003c, 0x001c, 0x001d, 0x007e, 0x003d, 0x001c, 0x003d, 0x003d, 0x003e, 0x003d, 0x003d, 0x003d, 0x005d, 0x003d, 0x001c, 0x003d, 0x003d, 0x005e, 0x001c, 0x005d, 0x001d, 0x001d, 0x001c, 0x001c, 0x085d, 0x001c, 0x001b, 0x107c, 0x0839, 0x295a, 0x73be, 0x298e, 0x0003, 0x0001, 0x0000, 0x0000,
0x0000, 0x0000, 0x0001, 0x296c, 0x5ada, 0x20fa, 0x001b, 0x081f, 0x001f, 0x081f, 0x001f, 0x001e, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001e, 0x001b, 0x18fe, 0x083b, 0x001a, 0x085a, 0x0839, 0x0859, 0x0019, 0x003b, 0x003c, 0x001e, 0x001e, 0x005f, 0x001c, 0x003b, 0x10bc, 0x297d, 0x297d, 0x191c, 0x089b, 0x001b, 0x003d, 0x005e, 0x001c, 0x003b, 0x001a, 0x003d, 0x005f, 0x001e, 0x001f, 0x001f, 0x007f, 0x001e, 0x001d, 0x001a, 0x087a, 0x215c, 0x31be, 0x20fc, 0x083a, 0x083c, 0x001e, 0x001f, 0x081f, 0x001f, 0x001e, 0x001c, 0x0878, 0x529a, 0x7397, 0x0003, 0x0000, 0x0000,
0x0020, 0x0021, 0x31ae, 0x5ada, 0x0838, 0x001c, 0x001e, 0x001e, 0x001f, 0x001f, 0x001e, 0x001e, 0x003e, 0x003e, 0x003f, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001d, 0x001d, 0x001e, 0x001e, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001d, 0x529f, 0xc67f, 0xa53f, 0xa53f, 0xa53f, 0xa53f, 0x9d3e, 0xa57f, 0x9d3f, 0x423d, 0x003b, 0x003d, 0x001b, 0x1078, 0x5adc, 0xbddf, 0xefbf, 0xf7df, 0xce9f, 0x843f, 0x18d9, 0x087a, 0x085a, 0x735f, 0x9c9f, 0x841f, 0x211e, 0x001e, 0x001d, 0x083f, 0x001f, 0x001e, 0x081e, 0x1059, 0x7b9d, 0xc61f, 0xe77f, 0xefbf, 0xd6df, 0x8c7e, 0x10b6, 0x005a, 0x001d, 0x001f, 0x001e, 0x005f, 0x003e, 0x003d, 0x0019, 0x529c, 0x296c, 0x0001, 0x0021,
0x0060, 0x2149, 0x7c1e, 0x18d9, 0x001c, 0x001f, 0x001f, 0x003f, 0x001f, 0x001f, 0x003e, 0x003e, 0x001d, 0x001d, 0x003f, 0x001f, 0x003e, 0x003e, 0x003e, 0x003e, 0x003e, 0x003e, 0x003e, 0x003e, 0x003e, 0x003e, 0x003e, 0x003e, 0x003e, 0x003e, 0x003e, 0x001e, 0x003d, 0x001d, 0x001e, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x081f, 0x001d, 0x39fe, 0x6b9f, 0xb5df, 0xefbf, 0xf7bf, 0xf7ff, 0xefdf, 0xe79f, 0xe73f, 0x6bbf, 0x005c, 0x001b, 0x18da, 0x9cbf, 0xffbf, 0xffdf, 0xe79f, 0xefdf, 0xf7df, 0xf79f, 0xd63f, 0x1035, 0x0816, 0xce5f, 0xffbf, 0xf79f, 0x421f, 0x083e, 0x081d, 0x001d, 0x001f, 0x001d, 0x105a, 0xa49f, 0xffbf, 0xf7bf, 0xf7df, 0xf7df, 0xf7ff, 0xf7df, 0xb5ff, 0x0896, 0x005d, 0x003f, 0x001e, 0x001e, 0x001e, 0x005f, 0x001e, 0x0859, 0x7bdb, 0x296a, 0x0001,
0x0002, 0x7c18, 0x317b, 0x001b, 0x001e, 0x001e, 0x001e, 0x001e, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x003f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001e, 0x001e, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001e, 0x001e, 0x001d, 0x0038, 0x2993, 0xe75f, 0xffff, 0xf7bf, 0x737e, 0x1099, 0x083a, 0x085d, 0x003d, 0x0039, 0x5abc, 0xff9f, 0xff9f, 0xc61f, 0x3a1b, 0x1937, 0xad7f, 0xffdf, 0xff9f, 0x9c7f, 0x1094, 0xd6df, 0xf7df, 0xef9f, 0x31db, 0x001d, 0x083e, 0x001e, 0x001f, 0x005b, 0x4a9b, 0xef5f, 0xf7df, 0xc65f, 0x4219, 0x18d6, 0xa51f, 0xf7bf, 0xf7df, 0x94ff, 0x085b, 0x001e, 0x005f, 0x005f, 0x003d, 0x003e, 0x001e, 0x083b, 0x2137, 0x7399, 0x0004,
0x214b, 0x7bfc, 0x081a, 0x081f, 0x001f, 0x001e, 0x005f, 0x001e, 0x003f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001e, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x003f, 0x003f, 0x003f, 0x003f, 0x001e, 0x001f, 0x0039, 0x94ff, 0xf7ff, 0xf7bf, 0xd6bf, 0x2958, 0x001a, 0x081e, 0x001f, 0x001e, 0x0079, 0xad3f, 0xff9f, 0xff7f, 0x39b3, 0x0039, 0x005a, 0x2133, 0xce5f, 0xff9f, 0xef1f, 0x4257, 0xd71f, 0xffff, 0xe73f, 0x3a19, 0x0059, 0x0019, 0x083c, 0x001e, 0x0059, 0x94ff, 0xf7df, 0xef9f, 0x1932, 0x087a, 0x001a, 0x18b6, 0xc61f, 0xf7bf, 0xdf1f, 0x18fb, 0x003f, 0x003f, 0x003e, 0x003e, 0x003d, 0x001e, 0x003c, 0x0017, 0x739e, 0x210b,
0x5b18, 0x39f8, 0x081b, 0x001f, 0x001f, 0x001f, 0x003f, 0x003f, 0x003e, 0x001f, 0x001f, 0x001f, 0x001e, 0x001e, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x003e, 0x003e, 0x003e, 0x001e, 0x087f, 0x001d, 0x213b, 0xef9f, 0xf7ff, 0xffff, 0xef3f, 0x633b, 0x0857, 0x001c, 0x001f, 0x003f, 0x0059, 0xad7f, 0xffdf, 0xe6df, 0x1072, 0x005b, 0x003c, 0x0076, 0x9cdf, 0xf7df, 0xef9f, 0x42b5, 0xdf5f, 0xffdf, 0xffff, 0xd6bf, 0xc65f, 0xce3f, 0x399c, 0x001d, 0x10da, 0xbe3f, 0xffff, 0xdedf, 0x18d7, 0x085c, 0x001c, 0x0818, 0x8c3f, 0xf7ff, 0xe75f, 0x213a, 0x001d, 0x001e, 0x003f, 0x003f, 0x001e, 0x001f, 0x083e, 0x001b, 0x295a, 0x6356,
0x633d, 0x1096, 0x001c, 0x001f, 0x001e, 0x005f, 0x003f, 0x001e, 0x003e, 0x001e, 0x001f, 0x001f, 0x001e, 0x001e, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001e, 0x003d, 0x003e, 0x003f, 0x001c, 0x109b, 0x9cff, 0xf7ff, 0xf7df, 0xef5f, 0xef3f, 0xef3f, 0x947f, 0x20db, 0x083c, 0x001d, 0x009a, 0xad9f, 0xf7bf, 0xe71f, 0x18d2, 0x0059, 0x007a, 0x08b5, 0xad7f, 0xf7df, 0xe79f, 0x4af5, 0xe79f, 0xffff, 0xe71f, 0xad9f, 0xc5ff, 0xb57f, 0x20da, 0x001d, 0x089a, 0xad9f, 0xf7bf, 0xe71f, 0x2937, 0x0019, 0x083a, 0x1057, 0xa4ff, 0xf7ff, 0xdf5f, 0x213a, 0x001e, 0x001d, 0x001e, 0x001f, 0x001f, 0x001f, 0x001e, 0x001d, 0x109a, 0x9d1f,
0xa51f, 0x1098, 0x001d, 0x001f, 0x001d, 0x003e, 0x001f, 0x003f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001e, 0x001e, 0x001f, 0x001f, 0x001e, 0x001e, 0x001f, 0x085c, 0x2996, 0xdf1f, 0xffff, 0xffff, 0x8bd9, 0x6277, 0xe6bf, 0xf77f, 0xbd9f, 0x18f8, 0x001c, 0x005b, 0x7bfe, 0xf7df, 0xffff, 0x8437, 0x18f4, 0x0873, 0x6b76, 0xf7df, 0xefbf, 0xad9f, 0x5af7, 0xf79f, 0xffff, 0xd65f, 0x0855, 0x001a, 0x083b, 0x081c, 0x001e, 0x001a, 0x6b9c, 0xf7df, 0xf7df, 0x949d, 0x18f5, 0x18d5, 0x6319, 0xef7f, 0xefbf, 0xa57f, 0x105a, 0x081f, 0x081f, 0x081f, 0x001e, 0x003f, 0x001f, 0x001e, 0x103f, 0x0819, 0x9d1f,
0x8c9f, 0x0838, 0x001c, 0x001f, 0x003e, 0x001d, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001e, 0x001f, 0x001f, 0x001f, 0x001f, 0x001e, 0x001f, 0x085b, 0x94df, 0xf7df, 0xf7ff, 0xef5f, 0x8bda, 0x6298, 0x41b4, 0xbdbf, 0xf79f, 0x6b7f, 0x085c, 0x001b, 0x2159, 0xce9f, 0xf7ff, 0xf7df, 0xbddf, 0xb57f, 0xf79f, 0xffdf, 0xe71f, 0x41f8, 0x62da, 0xef5f, 0xffdf, 0xce3f, 0x1079, 0x001f, 0x001d, 0x001e, 0x003f, 0x007d, 0x10b6, 0xd69f, 0xef7f, 0xffdf, 0xce3f, 0xbdbf, 0xffdf, 0xf7df, 0xe75f, 0x4258, 0x081a, 0x001f, 0x081f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x081f, 0x083b, 0x845f,
0x847f, 0x0878, 0x085d, 0x001f, 0x001d, 0x001e, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001e, 0x001d, 0x001e, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001e, 0x109e, 0x6b5f, 0xd6ff, 0xf7df, 0xe75f, 0xffdf, 0xffbf, 0x737e, 0x0835, 0x5abf, 0x085a, 0x001d, 0x003e, 0x001b, 0x297c, 0xa57f, 0xf7bf, 0xf7bf, 0xf7bf, 0xf7bf, 0xce3f, 0x39dd, 0x0017, 0x62be, 0xf75f, 0xffbf, 0xb57f, 0x0039, 0x001f, 0x005f, 0x003e, 0x003f, 0x003e, 0x0039, 0x2956, 0xffbf, 0xffdf, 0xffbf, 0xffdf, 0xf7bf, 0xffff, 0xa53f, 0x1096, 0x081c, 0x081f, 0x081f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001e, 0x081b, 0x841f,
0x8cbf, 0x0015, 0x003c, 0x001f, 0x001e, 0x005f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001d, 0x003d, 0x001e, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001e, 0x001c, 0x0058, 0x1094, 0x10ce, 0xbe3f, 0xf7df, 0xffdf, 0x5af9, 0x0875, 0x0016, 0x003a, 0x001d, 0x001f, 0x003f, 0x003d, 0x0878, 0x31b9, 0x7c1f, 0x845f, 0x4a5b, 0x0857, 0x105d, 0x083d, 0x399e, 0x945f, 0x8c5f, 0x739f, 0x001b, 0x001f, 0x001d, 0x003e, 0x001f, 0x001d, 0x001a, 0x2136, 0xffdf, 0xf79f, 0xe71e, 0xce3a, 0xffff, 0xf7bf, 0x843c, 0x0834, 0x081b, 0x001e, 0x001f, 0x003f, 0x001e, 0x001f, 0x001f, 0x001f, 0x081f, 0x001a, 0x845f,
0x9d5f, 0x08d8, 0x003c, 0x001f, 0x001f, 0x001f, 0x001f, 0x003f, 0x001f, 0x001e, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001e, 0x001e, 0x001e, 0x001e, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x107d, 0x423d, 0x5ada, 0x7bf9, 0xef7f, 0xffff, 0xf7bf, 0xdf3f, 0xcedf, 0xd6df, 0xad7f, 0x085d, 0x001f, 0x081f, 0x001e, 0x003d, 0x001b, 0x003a, 0x005a, 0x007c, 0x003c, 0x001d, 0x001e, 0x001d, 0x003c, 0x003b, 0x001b, 0x003e, 0x005f, 0x005f, 0x001e, 0x081f, 0x001d, 0x215c, 0x843f, 0xf7df, 0xffff, 0xe73f, 0xe75f, 0xffdf, 0xffff, 0xe71f, 0xdedf, 0x5adf, 0x003e, 0x003f, 0x001e, 0x003f, 0x003f, 0x001f, 0x001e, 0x083e, 0x085a, 0x9cdf,
0x4ad9, 0x10d5, 0x001b, 0x001f, 0x003f, 0x001e, 0x001f, 0x001f, 0x001e, 0x001e, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001e, 0x001e, 0x001e, 0x001e, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x081c, 0x9cdf, 0xdf1f, 0xbdff, 0xce7f, 0xf79f, 0xf79f, 0xdf1f, 0xb61f, 0xb5df, 0x73df, 0x107d, 0x001f, 0x001f, 0x001f, 0x001f, 0x003f, 0x003f, 0x001f, 0x001e, 0x003f, 0x003f, 0x001f, 0x001f, 0x001f, 0x001f, 0x003f, 0x001f, 0x001f, 0x001e, 0x081f, 0x001f, 0x081d, 0x215d, 0xcebf, 0xce9f, 0xc65f, 0xb5ff, 0xbdff, 0xbdff, 0xbdff, 0xc61f, 0xa51f, 0x4a5f, 0x001d, 0x001e, 0x005f, 0x001f, 0x001f, 0x003f, 0x001e, 0x001d, 0x1099, 0x94bf,
0x6356, 0x31b5, 0x001a, 0x001f, 0x001e, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001e, 0x001e, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001e, 0x001f, 0x001f, 0x001f, 0x001e, 0x001f, 0x001f, 0x001c, 0x211a, 0x52bb, 0x2953, 0x6315, 0xef7f, 0xef7f, 0xb5de, 0x10b0, 0x0037, 0x001b, 0x001d, 0x003e, 0x001e, 0x003f, 0x001e, 0x001e, 0x001f, 0x001f, 0x001e, 0x001e, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001e, 0x087e, 0x213f, 0x211d, 0x0059, 0x0019, 0x085a, 0x0039, 0x0859, 0x0839, 0x001a, 0x003d, 0x003f, 0x001f, 0x001f, 0x001e, 0x003f, 0x003f, 0x001e, 0x001c, 0x20f9, 0x6335,
0x192a, 0x6bba, 0x0839, 0x001f, 0x003f, 0x001e, 0x003f, 0x003f, 0x001f, 0x003f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001e, 0x001e, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001e, 0x001e, 0x081f, 0x001c, 0x4a5e, 0xe73f, 0xdeff, 0xdedf, 0xffdf, 0xffdf, 0xe73f, 0x8c5f, 0x62ff, 0x10bd, 0x003d, 0x001e, 0x003f, 0x003f, 0x001e, 0x001e, 0x001f, 0x001f, 0x001e, 0x001e, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x003f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x003e, 0x005e, 0x001e, 0x001e, 0x085b, 0x62fd, 0x216b,
0x0002, 0x73d8, 0x291a, 0x001c, 0x083f, 0x005f, 0x001d, 0x001e, 0x001f, 0x001f, 0x001e, 0x001e, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x003d, 0x003d, 0x001f, 0x001b, 0x3a1a, 0xc67f, 0xf7ff, 0xf7ff, 0xbdbf, 0xce3f, 0xf7df, 0xf7bf, 0xf7bf, 0x8c5f, 0x001b, 0x003f, 0x003f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x003f, 0x001f, 0x001e, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x003f, 0x001f, 0x001f, 0x003f, 0x003c, 0x003c, 0x001d, 0x085d, 0x18d8, 0x6339, 0x0002,
0x0020, 0x214a, 0x739e, 0x1059, 0x001c, 0x001f, 0x001e, 0x005e, 0x001f, 0x001f, 0x001e, 0x001e, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x003d, 0x003d, 0x001f, 0x003b, 0x1916, 0xdf3f, 0xf7ff, 0x8c97, 0x1071, 0x20d3, 0xc61e, 0xffff, 0xd6df, 0x2976, 0x085c, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x003f, 0x003f, 0x001f, 0x001f, 0x001f, 0x001f, 0x003f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001e, 0x003c, 0x001b, 0x087d, 0x0038, 0x633c, 0x296d, 0x0021,
0x0000, 0x0001, 0x420f, 0x6b3c, 0x081b, 0x001e, 0x085f, 0x001d, 0x001f, 0x001f, 0x001f, 0x003f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001e, 0x001e, 0x001f, 0x003c, 0x1938, 0xd71f, 0xf7ff, 0x8479, 0x1056, 0x0815, 0xa53c, 0xf7df, 0xdf1f, 0x18d7, 0x001c, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x003f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x003f, 0x001f, 0x003f, 0x003f, 0x001f, 0x001f, 0x001f, 0x001f, 0x003f, 0x001e, 0x085d, 0x0017, 0x52bb, 0x3a10, 0x0002, 0x0000,
0x0020, 0x0000, 0x0863, 0x8439, 0x62ff, 0x105b, 0x001a, 0x085d, 0x001e, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001e, 0x001e, 0x001f, 0x003d, 0x0899, 0xa57f, 0xefbf, 0xdf1f, 0x527c, 0x6b1f, 0xe73f, 0xf7bf, 0xa51f, 0x0017, 0x083d, 0x001f, 0x001f, 0x003f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x003e, 0x003e, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x003f, 0x003f, 0x001e, 0x001d, 0x083d, 0x0838, 0x5adc, 0x7c1a, 0x0044, 0x0020, 0x0000,
0x0001, 0x0001, 0x0000, 0x1085, 0x39cf, 0x739c, 0x2138, 0x0018, 0x083e, 0x001f, 0x001e, 0x001d, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001e, 0x001d, 0x001a, 0x31ba, 0xce9f, 0xef9f, 0xef9f, 0xf7bf, 0xef9f, 0xce5f, 0x291b, 0x083d, 0x001d, 0x001e, 0x003f, 0x001e, 0x001f, 0x001f, 0x001f, 0x001f, 0x001e, 0x003e, 0x003d, 0x003d, 0x001e, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x001f, 0x003f, 0x001f, 0x001f, 0x001f, 0x001e, 0x001e, 0x001d, 0x083b, 0x18d8, 0x631b, 0x3a0f, 0x0023, 0x0042, 0x0001, 0x0001,
0x0002, 0x0001, 0x0000, 0x0000, 0x0002, 0x298c, 0x6359, 0x62fd, 0x20fa, 0x109b, 0x085a, 0x003a, 0x003b, 0x003b, 0x001b, 0x001b, 0x003b, 0x003b, 0x003b, 0x003b, 0x003b, 0x003b, 0x003b, 0x003b, 0x003b, 0x003b, 0x003b, 0x003b, 0x003b, 0x003b, 0x003b, 0x003b, 0x001c, 0x001b, 0x003a, 0x003a, 0x003b, 0x003b, 0x003b, 0x003b, 0x001b, 0x083b, 0x0839, 0x0036, 0x2114, 0x5b39, 0x6358, 0x5b37, 0x6338, 0x20f3, 0x0838, 0x083c, 0x001a, 0x085b, 0x001b, 0x003b, 0x003c, 0x003c, 0x003c, 0x003b, 0x003b, 0x003a, 0x005a, 0x003a, 0x003b, 0x003b, 0x003b, 0x003b, 0x003b, 0x003b, 0x003b, 0x003b, 0x003b, 0x001b, 0x001b, 0x003b, 0x003c, 0x003b, 0x001b, 0x003b, 0x001b, 0x001b, 0x001c, 0x083b, 0x083a, 0x0859, 0x293b, 0x529d, 0x635a, 0x216c, 0x0002, 0x0000, 0x0000, 0x0000, 0x0000,
0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0001, 0x0003, 0x214b, 0x5b36, 0x94df, 0x94bf, 0x845f, 0x843f, 0x845f, 0x843f, 0x843f, 0x843f, 0x843f, 0x843f, 0x843f, 0x843f, 0x843f, 0x843f, 0x843f, 0x843f, 0x843f, 0x843f, 0x843f, 0x843f, 0x843f, 0x843f, 0x843f, 0x843f, 0x843f, 0x845f, 0x845f, 0x843f, 0x843f, 0x843f, 0x843f, 0x843f, 0x843f, 0x843f, 0x843f, 0x843f, 0x8c5f, 0x8c5f, 0x8c5f, 0x8c3f, 0x8c3f, 0x8c1f, 0x8c1f, 0x843f, 0x843f, 0x843f, 0x843f, 0x843f, 0x843f, 0x843f, 0x843f, 0x843f, 0x843f, 0x843f, 0x843f, 0x843f, 0x843f, 0x843f, 0x843f, 0x843f, 0x843f, 0x843f, 0x843f, 0x843f, 0x843f, 0x843f, 0x843f, 0x843f, 0x843f, 0x843f, 0x843f, 0x843f, 0x843f, 0x843f, 0x843f, 0x8c9f, 0x8c9f, 0x5af6, 0x214b, 0x0002, 0x0001, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000
};
