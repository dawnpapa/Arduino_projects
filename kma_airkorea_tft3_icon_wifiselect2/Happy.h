// We need this header file to use FLASH as storage with PROGMEM directive:
#include <pgmspace.h>

// Icon width and height
const uint16_t happyWidth = 171;
const uint16_t happyHeight = 28;

const unsigned short  happy[171*28] PROGMEM={
0x0000, 0x0040, 0x0000, 0x0020, 0x0000, 0x0020, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0021, 0x0000, 0x0000, 0x0000, 0x0000, 0x0020, 0x0000, 0x0000, 0x0000, 0x0000, 0x0800, 0x0800, 0x0060, 0x0040, 0x0020, 0x0000, 0x0800, 0x0800, 0x0001, 0x0000, 0x0001, 0x0001, 0x0000, 0x0020, 0x0000, 0x0001, 0x0002, 0x0001, 0x0020, 0x0020, 0x0000, 0x0000, 0x0000, 0x0020, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0820, 0x0800, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0020, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0020, 0x0020, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0020, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0800, 0x0000, 0x0800, 0x0000, 0x0000, 0x0000, 0x0800, 0x0000, 0x0000, 0x0020, 0x0040, 0x0000, 0x0000, 0x0001, 0x0001, 0x0001, 0x0000, 0x0021, 0x0001, 0x0001, 0x0000, 0x0000, 0x0800, 0x0000, 0x0000, 0x0020, 0x0021, 0x0000, 0x0000, 0x0800, 0x0000, 0x0801, 0x0000, 0x0020, 0x0000, 0x0000, 0x0020, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0001, 0x0001, 0x0000, 0x0020, 0x0000, 0x0020, 0x0000, 0x0000, 0x0001, 0x0002, 0x0021, 0x0000, 0x0040, 0x0000, 0x0020, 0x0020, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0001, 0x0001, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0040, 0x0020, 0x0800, 0x0000, 0x0020, 0x0000, 0x0000, 0x0000, 0x0000,
0x0021, 0x0000, 0x0841, 0x0000, 0x0000, 0x0020, 0x0000, 0x0000, 0x0000, 0x0000, 0x0040, 0x0000, 0x0000, 0x0021, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0040, 0x0020, 0x0040, 0x0000, 0x0000, 0x0000, 0x0001, 0x0001, 0x0000, 0x0000, 0x0020, 0x0000, 0x0000, 0x0001, 0x0000, 0x0020, 0x0000, 0x0000, 0x0000, 0x0021, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0020, 0x0000, 0x0820, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0020, 0x0000, 0x0000, 0x0000, 0x0020, 0x0000, 0x0020, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0021, 0x0000, 0x0000, 0x0020, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0060, 0x0020, 0x0020, 0x0000, 0x0000, 0x0001, 0x0001, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0021, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0040, 0x0040, 0x0000, 0x0000, 0x0020, 0x0000, 0x0001, 0x0021, 0x0000, 0x0000, 0x0040, 0x0000, 0x0000, 0x0000, 0x0001, 0x0001, 0x0000, 0x0020, 0x0000, 0x0000, 0x0040, 0x0000, 0x0000, 0x0000, 0x0001, 0x0000, 0x0000, 0x0000, 0x0820, 0x0000, 0x0000, 0x0001, 0x0000, 0x0020, 0x0000, 0x0000, 0x0020, 0x0000, 0x0000, 0x0000, 0x0000, 0x0840, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
0x0001, 0x0001, 0x0000, 0x0000, 0x0000, 0x0020, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0862, 0x0000, 0x0000, 0x0020, 0x0020, 0x0061, 0x0020, 0x0000, 0x0000, 0x0000, 0x0001, 0x0002, 0x0001, 0x0000, 0x0000, 0x0020, 0x0020, 0x0020, 0x0000, 0x0000, 0x0000, 0x0821, 0x0000, 0x0020, 0x0000, 0x0800, 0x0800, 0x0000, 0x0020, 0x0060, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0020, 0x0000, 0x0020, 0x0000, 0x0000, 0x0802, 0x0002, 0x0001, 0x0000, 0x0000, 0x0001, 0x0000, 0x0000, 0x0800, 0x0800, 0x0000, 0x0020, 0x0020, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0001, 0x0000, 0x0000, 0x0001, 0x0002, 0x0002, 0x0022, 0x0000, 0x0020, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0021, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0001, 0x0000, 0x0000, 0x0042, 0x0022, 0x0000, 0x0000, 0x0001, 0x0000, 0x0000, 0x0000, 0x0800, 0x0000, 0x0020, 0x0000, 0x0000, 0x0801, 0x0800, 0x0800, 0x0020, 0x0040, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0840, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0040, 0x0020, 0x0000, 0x0020, 0x0000, 0x0001, 0x0022, 0x0001, 0x0000, 0x0020, 0x0000, 0x0020, 0x0020, 0x0000, 0x0821, 0x0000, 0x0001, 0x0021, 0x0000, 0x0000, 0x0000, 0x0020, 0x0000, 0x0021, 0x0000, 0x0000, 0x0020, 0x0000, 0x0000, 0x0001, 0x0000, 0x0000, 0x0821, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
0x0822, 0x0000, 0x0000, 0x0800, 0x0000, 0x0800, 0x1800, 0x2000, 0x2800, 0x2000, 0x2000, 0x1000, 0x0800, 0x0801, 0x0000, 0x0000, 0x0000, 0x0800, 0x0800, 0x0000, 0x0000, 0x0841, 0x0001, 0x0001, 0x0001, 0x0001, 0x0000, 0x0020, 0x0040, 0x0040, 0x0080, 0x0040, 0x0020, 0x0020, 0x0040, 0x0040, 0x0020, 0x0000, 0x0820, 0x0000, 0x0000, 0x0040, 0x0000, 0x0020, 0x0800, 0x0800, 0x0000, 0x0020, 0x0020, 0x0020, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0020, 0x0000, 0x0800, 0x0820, 0x0000, 0x0800, 0x1000, 0x0000, 0x0020, 0x0000, 0x0000, 0x0000, 0x0020, 0x0020, 0x0040, 0x0000, 0x0020, 0x0020, 0x0020, 0x0040, 0x0000, 0x0000, 0x0000, 0x0020, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0041, 0x0020, 0x0022, 0x0023, 0x8494, 0x7cb5, 0x4c35, 0x4c55, 0x8516, 0x0083, 0x0001, 0x0000, 0x0040, 0x0020, 0x0021, 0x0021, 0x0020, 0x0062, 0x0002, 0x0002, 0x0000, 0x0000, 0x0000, 0x0040, 0x0000, 0x0000, 0x0800, 0x0801, 0x0801, 0x0001, 0x0000, 0x0001, 0x0000, 0x0801, 0x0000, 0x0001, 0x0000, 0x0000, 0x0000, 0x0020, 0x0040, 0x0020, 0x0060, 0x0020, 0x0020, 0x0000, 0x0000, 0x0020, 0x0040, 0x0020, 0x0040, 0x0000, 0x0000, 0x0000, 0x0000, 0x0040, 0x0000, 0x0000, 0x0041, 0x0000, 0x0020, 0x0000, 0x0000, 0x0000, 0x0000, 0x0020, 0x0040, 0x0040, 0x0040, 0x0020, 0x0020, 0x0020, 0x0020, 0x0020, 0x0040, 0x0020, 0x0000, 0x0000, 0x0000,
0x0000, 0x0000, 0x0000, 0x0800, 0x2020, 0x58c2, 0xe38e, 0xca09, 0xc167, 0xb947, 0xcacc, 0xf4f4, 0x71ca, 0x1001, 0x1000, 0x6a48, 0xfdf7, 0xfdd7, 0x4021, 0x2000, 0x0840, 0x0020, 0x0020, 0x0000, 0x0000, 0x0001, 0x0000, 0x08a1, 0xa5f4, 0x7d50, 0x7dd1, 0x8e53, 0xaef7, 0x6cef, 0x00c0, 0x0120, 0x00c0, 0x00c0, 0x0020, 0x0042, 0x0021, 0x0000, 0x0000, 0x62a5, 0xdded, 0xe62c, 0xde4e, 0xde6f, 0xe6b1, 0xeed2, 0xeeb2, 0xc58f, 0x1060, 0x10a0, 0x0020, 0xd6b3, 0xad09, 0x1860, 0x1060, 0x0820, 0x0800, 0x0000, 0x0000, 0x0000, 0x0000, 0x0040, 0x0000, 0x842d, 0xbe30, 0xbe4f, 0xced2, 0xced2, 0xd732, 0x29e0, 0x00a0, 0x0080, 0x0080, 0x08a0, 0x0080, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0020, 0x0020, 0x0000, 0x00a2, 0x0063, 0x00a6, 0x00a6, 0x971f, 0x65fd, 0x24fb, 0x24fb, 0x5dbc, 0x0128, 0x00a5, 0x00a4, 0x64b3, 0xa6dc, 0x865a, 0x00e5, 0x00e5, 0x0064, 0x00a6, 0x0085, 0x0043, 0x0001, 0x0820, 0x0000, 0x0000, 0x6acb, 0xbc95, 0xabf5, 0xa3f6, 0xcdbb, 0x736f, 0x0000, 0xd5d9, 0xddda, 0xcd9a, 0x628e, 0x0822, 0x0001, 0x0002, 0x0000, 0x8caf, 0xc693, 0xbe6f, 0xbe6e, 0xced1, 0xdf33, 0xd713, 0x08a0, 0x00c0, 0x08e0, 0x0080, 0x08a0, 0x52c5, 0xd715, 0xdf73, 0x29c0, 0x0860, 0x0840, 0x0000, 0x0020, 0x0000, 0x0020, 0x0000, 0x0000, 0x0020, 0xb675, 0x6d0d, 0x6daf, 0x7653, 0x8ed6, 0x9676, 0xae97, 0xaef8, 0x1a26, 0x00a0, 0x0060, 0x0000, 0x0000, 0x0000,
0x0020, 0x0020, 0x0800, 0x40c2, 0xecd2, 0xc269, 0xc146, 0xc946, 0xc926, 0xc967, 0xc145, 0xb9e8, 0xdbd2, 0x7168, 0x2000, 0x6143, 0xc269, 0xb186, 0xa9e9, 0xc3f1, 0x734c, 0x0020, 0x0020, 0x0000, 0x0000, 0x0020, 0x0000, 0xa554, 0x748e, 0x750f, 0x6d4e, 0x654e, 0x5cce, 0x5cee, 0x4ceb, 0x44eb, 0x5d6d, 0x75d1, 0x9636, 0x4b2d, 0x0001, 0x0000, 0x0800, 0x6ac2, 0xfe69, 0xee05, 0xee4a, 0xee8d, 0xe66e, 0xe66f, 0xee4e, 0xe62f, 0xd651, 0xc631, 0x4200, 0xcdec, 0xee69, 0xe64a, 0xe6b3, 0x3143, 0x0000, 0x0821, 0x0000, 0x0000, 0x0000, 0x0000, 0x52a9, 0xa551, 0xce90, 0xceaf, 0xc6af, 0xced0, 0xc6ae, 0xbead, 0xbeac, 0xcf2e, 0xcf2f, 0xcf12, 0xd6f7, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0020, 0x0000, 0x0020, 0x0020, 0xc6db, 0x7d36, 0x3c56, 0x34b8, 0x3d3a, 0x1c78, 0x1cfa, 0x1cda, 0x2cfa, 0x55bc, 0x765d, 0x869d, 0x761c, 0x4517, 0x24b6, 0x2cb6, 0x6e5d, 0x5559, 0x3cf8, 0x5d7a, 0x53d2, 0x0022, 0x0000, 0x0800, 0x0800, 0x72ac, 0xbc16, 0x9272, 0x92b4, 0xac17, 0x7350, 0x0801, 0xb455, 0x92b0, 0x92f3, 0x8b33, 0xde7c, 0x1063, 0x0001, 0x0000, 0x73cb, 0x9d4e, 0xc6b0, 0xcef0, 0xcecf, 0xbe4d, 0xc6ae, 0xbeac, 0xbecb, 0xc70d, 0xc710, 0xd773, 0xefd5, 0xc6ce, 0xae69, 0xbecd, 0xced5, 0x7bce, 0x0000, 0x0000, 0x0840, 0x0000, 0x0000, 0x0000, 0x0060, 0xb6f4, 0x4ce9, 0x3d2a, 0x2d2c, 0x4d90, 0x6550, 0x7530, 0x64ef, 0x5cae, 0x6caf, 0x7cd1, 0x0020, 0x0000, 0x0000,
0x0040, 0x0000, 0x4983, 0xdc2e, 0xc985, 0xd925, 0xea8b, 0xf3b0, 0xf4b3, 0xe40f, 0xf36c, 0xc1a5, 0xc1a8, 0xdb6f, 0x81e7, 0xb30b, 0xda07, 0xd925, 0xc928, 0xcaef, 0x1001, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x1162, 0x84ef, 0x6c4d, 0x6c4d, 0x4baa, 0x3b88, 0x5d0b, 0x558b, 0x2d49, 0x252a, 0x55d2, 0x2b6c, 0x0041, 0x0000, 0x20e0, 0xac86, 0xfe45, 0xfe23, 0xf66a, 0xdded, 0x9c49, 0xa4ab, 0x9be6, 0x9c06, 0x8be7, 0x41e0, 0x5a40, 0xee4a, 0xfe23, 0xfe46, 0xf6b1, 0x3100, 0x0800, 0x0000, 0x0000, 0x0000, 0x0000, 0x0020, 0x0040, 0x0000, 0x73a8, 0x9d2c, 0x846a, 0x7c68, 0x7426, 0x7ca4, 0xc729, 0xb6e6, 0xbee6, 0xb6aa, 0xd737, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0020, 0x0020, 0x0000, 0x7cb4, 0x85fb, 0x3d5b, 0x14ba, 0x24da, 0x665f, 0x75fb, 0x75fb, 0x455b, 0x1cba, 0x14da, 0x2d3b, 0x4dbd, 0x2cda, 0x0cfa, 0x1d7c, 0x5e9f, 0x355b, 0x14fa, 0x2d3a, 0x4c74, 0x0022, 0x0021, 0x0800, 0x0800, 0x622b, 0xbbb6, 0xa274, 0x9a75, 0xb3b8, 0xa414, 0x6a6c, 0xcc57, 0x9272, 0x9294, 0x9314, 0xeebe, 0x1083, 0x0000, 0x0040, 0x0020, 0x0020, 0x8c8e, 0x8c8c, 0x848a, 0x8468, 0x7445, 0x8d05, 0xbf08, 0xbf07, 0xbf09, 0xbeeb, 0xdfaf, 0xcf4b, 0xb726, 0xaec7, 0xb611, 0x0000, 0x0821, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0020, 0xa692, 0x4548, 0x2d48, 0x3d8d, 0x9797, 0x5c6d, 0x640c, 0x4bcb, 0x3b69, 0x4bab, 0x3aa8, 0x0020, 0x0000, 0x0000,
0x0020, 0x0000, 0x9b29, 0xcae8, 0xd904, 0xf188, 0xfcb4, 0xff3d, 0xff9d, 0xff9d, 0xfe97, 0xf34b, 0xc905, 0xc167, 0xfd13, 0xfd13, 0xd965, 0xe8c4, 0xe969, 0xe2ae, 0x2800, 0x1000, 0x1000, 0x0800, 0x0000, 0x0000, 0x0000, 0x0000, 0x0040, 0x0060, 0x0060, 0x0060, 0x0080, 0x00c0, 0x4447, 0x768e, 0x1d68, 0x25ac, 0x5e53, 0x3bed, 0x0020, 0x0000, 0x41e2, 0xff71, 0xfe43, 0xfe42, 0xee2a, 0xbd0b, 0x0820, 0x0000, 0x1000, 0x1000, 0x0800, 0x0820, 0xcdcc, 0xf66a, 0xfe22, 0xfe43, 0xfece, 0x4180, 0x1000, 0x0000, 0x0000, 0x0020, 0x0000, 0x0000, 0x0000, 0x0000, 0x0040, 0x0040, 0x0060, 0x0060, 0x0080, 0x00a0, 0xdfeb, 0xbf04, 0xbf05, 0xbf0a, 0xd737, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0020, 0x0000, 0x0000, 0x0001, 0x74b5, 0x655a, 0x14ba, 0x151b, 0x669f, 0xc7ff, 0xe7ff, 0xe7ff, 0x9f7f, 0x2d1b, 0x0cfb, 0x157e, 0x465f, 0x255d, 0x0d1c, 0x1d9e, 0x4ebf, 0x1d5c, 0x051c, 0x257b, 0x4c95, 0x0041, 0x0020, 0x0000, 0x0800, 0x6a2b, 0xb334, 0xa254, 0x9a55, 0x9294, 0xac34, 0xb434, 0xab14, 0xa273, 0x9a54, 0xa356, 0x7b30, 0x0821, 0x0000, 0x0000, 0x0000, 0x0000, 0x0020, 0x0000, 0x0020, 0x0040, 0x0060, 0x2a20, 0xd7c9, 0xb703, 0xb6e7, 0xcf8b, 0xe7ef, 0xbec7, 0xb743, 0xb705, 0xae0d, 0x0040, 0x0000, 0x0000, 0x0020, 0x0000, 0x0001, 0x0000, 0x0040, 0x9671, 0x3528, 0x2d89, 0x3dae, 0xa7d9, 0x0060, 0x0020, 0x0060, 0x0060, 0x0040, 0x0020, 0x0000, 0x0000, 0x0000,
0x0000, 0x1000, 0x8a04, 0xd2a8, 0xd145, 0xe22a, 0xfe5b, 0xff9f, 0xffff, 0xfffe, 0xffbb, 0xec4e, 0xd925, 0xe167, 0xebcf, 0xfcd2, 0xd945, 0xe8c4, 0xd906, 0xd188, 0xa166, 0x9a48, 0xa2eb, 0xb451, 0x0000, 0x0000, 0x0000, 0x0000, 0x1162, 0x644c, 0x3ba8, 0x33c8, 0x444b, 0x4c8c, 0x758d, 0x5dac, 0x252a, 0x2d4c, 0x7635, 0x4bce, 0x0021, 0x0000, 0x4202, 0xff50, 0xf643, 0xfe22, 0xf66c, 0xb4ee, 0x0000, 0x0002, 0x0000, 0x0801, 0x0002, 0x0000, 0xcdef, 0xee6a, 0xfe23, 0xfe43, 0xf669, 0xbd27, 0xbd28, 0xb50a, 0xbd92, 0x41c6, 0x0000, 0x0001, 0x0000, 0x0000, 0x7c29, 0x9528, 0x8d06, 0x9d88, 0x9589, 0xa5e9, 0xc749, 0xb6e6, 0xb6c7, 0xc70e, 0xdf58, 0x0020, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0001, 0xbeff, 0x4d19, 0x0cfc, 0x153c, 0xb7ff, 0xe7ff, 0xfffe, 0xf7ff, 0xdfff, 0x5d7a, 0x1d1a, 0x0d3b, 0x2ddf, 0x1d1c, 0x14dc, 0x151d, 0x153d, 0x0cfc, 0x0cfd, 0x353c, 0x5cf5, 0x0040, 0x0020, 0x0000, 0x0800, 0x620a, 0xab34, 0xa274, 0x9ab6, 0xabd7, 0xc578, 0xcd37, 0xa2d2, 0xa233, 0xa275, 0xab56, 0x30c7, 0x0001, 0x0001, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0020, 0x2a00, 0xc768, 0xb724, 0xb709, 0xcf8e, 0xefef, 0xc6e8, 0xb704, 0xb746, 0xb6ab, 0x8d29, 0x952a, 0x9d8e, 0xa5b3, 0x0020, 0x0000, 0x0000, 0x0060, 0x8e30, 0x2d29, 0x256b, 0x4590, 0x1b09, 0x0020, 0x0000, 0x0000, 0x0020, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
0x0000, 0x1000, 0xa286, 0xc246, 0xd145, 0xd20a, 0xfe1a, 0xffbf, 0xf7ff, 0xffff, 0xff19, 0xf42e, 0xd905, 0xd884, 0xfc71, 0xfcf3, 0xd0e4, 0xe905, 0xd926, 0xd1e9, 0xb1c8, 0x8985, 0x81e7, 0xccf3, 0x0800, 0x0021, 0x0020, 0x0061, 0xb677, 0x8d92, 0x64ee, 0x442a, 0x4c8c, 0x5d0d, 0x64eb, 0x4cc9, 0x2d4b, 0x2d2d, 0x7e15, 0x4b6d, 0x0020, 0x0020, 0x4202, 0xeeee, 0xfe84, 0xfe43, 0xee6d, 0xbd50, 0x0021, 0x0002, 0x0001, 0x0001, 0x0002, 0x0820, 0xc5cd, 0xe669, 0xfe64, 0xfe44, 0xf66a, 0xd5ca, 0xcd69, 0xcd8c, 0xde55, 0x4a07, 0x0000, 0x0000, 0x0000, 0x7bed, 0xce93, 0xb62e, 0xae0b, 0xa5ca, 0xb66d, 0xbeed, 0xbf08, 0xb6e6, 0xbf09, 0xbeef, 0xced6, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0800, 0x0800, 0x0001, 0xc71f, 0x44b8, 0x04db, 0x1d7d, 0xafdf, 0xefff, 0xfffe, 0xffff, 0xe7ff, 0x65bb, 0x0cb9, 0x0d5c, 0x25de, 0x153c, 0x14fc, 0x0cdc, 0x0cfc, 0x0cfc, 0x0cdd, 0x3d5c, 0x5cf5, 0x0060, 0x0020, 0x0000, 0x1020, 0x6a2b, 0xb334, 0x9a13, 0x9295, 0xd53d, 0xff9f, 0xff7f, 0xc3d6, 0xaa54, 0x9a34, 0xbbf9, 0x3928, 0x0001, 0x0001, 0x0000, 0x0000, 0x0000, 0x0840, 0x0000, 0x0000, 0x0020, 0x10c1, 0xdf95, 0xc747, 0xbf24, 0xae89, 0xdfd1, 0xe7ad, 0xcf28, 0xbf66, 0xa6e5, 0xb6cb, 0xa60c, 0xadec, 0xadef, 0xae14, 0x0061, 0x0000, 0x0000, 0xb653, 0x85ee, 0x354a, 0x254b, 0x4db1, 0x0143, 0x0020, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
0x0000, 0x1000, 0x9b2a, 0xcac9, 0xd946, 0xd967, 0xfc74, 0xff1e, 0xffbf, 0xffbe, 0xfdf6, 0xe208, 0xe0e6, 0xe947, 0xfd35, 0xfc0f, 0xe125, 0xd8c5, 0xd1a9, 0xebd1, 0x3000, 0x1800, 0x2000, 0x1000, 0x0000, 0x0000, 0x0021, 0x0020, 0x0060, 0x0040, 0x0040, 0x0080, 0x0100, 0xa693, 0xb733, 0x552a, 0x2d4b, 0x3dcf, 0x33cc, 0x0061, 0x0061, 0x0020, 0x4a21, 0xff2f, 0xfe22, 0xfde2, 0xee6c, 0xbd4e, 0x0000, 0x0000, 0x0800, 0x1040, 0x0820, 0x0820, 0xc5a8, 0xf6a7, 0xf621, 0xfe44, 0xff31, 0x4140, 0x1000, 0x1000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0020, 0x0000, 0x0020, 0x0040, 0x0040, 0x6be7, 0xe7f3, 0xc747, 0xbf25, 0xb6e8, 0xcf4f, 0x08e0, 0x0060, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0800, 0x0001, 0xc71f, 0x5d5b, 0x1d5c, 0x0cfb, 0x873f, 0xdfff, 0xefdf, 0xf7ff, 0xb79f, 0x455d, 0x151c, 0x0d7d, 0x2e1f, 0x0d1b, 0x0cfc, 0x0d3c, 0x1d7c, 0x0d1a, 0x04db, 0x3d9c, 0x6515, 0x0040, 0x0000, 0x0000, 0x51e7, 0xf5fa, 0xb2b3, 0xaa55, 0x9ad6, 0xd57e, 0xffdf, 0xff7f, 0xbb75, 0xaa94, 0x9233, 0xb3f8, 0x3107, 0x0021, 0x0021, 0x0000, 0x0020, 0x0000, 0x0000, 0x0000, 0x0000, 0x0020, 0x0880, 0xe7b3, 0xbf25, 0xb6e3, 0xbeec, 0xeff3, 0xefee, 0xbec6, 0xa6e4, 0xb749, 0xae8f, 0x00a0, 0x0040, 0x0020, 0x0040, 0x0020, 0x0000, 0x0020, 0xbe92, 0x75ab, 0x3549, 0x2d6a, 0x5e53, 0x0162, 0x0060, 0x0020, 0x0040, 0x0040, 0x0060, 0x0040, 0x0020, 0x0040, 0x0020,
0x0841, 0x0800, 0x59c5, 0xcbce, 0xc986, 0xd126, 0xda0a, 0xfc33, 0xfe39, 0xfd76, 0xf2eb, 0xd905, 0xd107, 0xe22b, 0xfe78, 0xfc2f, 0xd904, 0xe967, 0xc1c9, 0xecb5, 0x1000, 0x0000, 0x0800, 0x0800, 0x0000, 0x0021, 0x0001, 0x0001, 0x0000, 0x0000, 0x0000, 0x0020, 0x0080, 0x2ae4, 0xa732, 0x4d2a, 0x250a, 0x356e, 0x4c6f, 0x0041, 0x0020, 0x0020, 0x4a00, 0xf6ad, 0xfe03, 0xfe64, 0xfeac, 0xde4f, 0x8387, 0x8bc8, 0x7b65, 0x7b43, 0x7b44, 0x7300, 0xe628, 0xf644, 0xfe63, 0xf5e5, 0xff54, 0x4183, 0x0800, 0x0800, 0x0000, 0x0000, 0x0000, 0x0000, 0x0020, 0x0000, 0x0000, 0x0000, 0x0020, 0x0040, 0x0060, 0xc70d, 0xbf46, 0xb704, 0xb6c8, 0xcf51, 0x1140, 0x0020, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x1000, 0x0001, 0x6c33, 0x861c, 0x1c78, 0x14b9, 0x3d5a, 0x86df, 0xc7bf, 0xaf1f, 0x5ddf, 0x1cbb, 0x1cfb, 0x35de, 0x3e3f, 0x14fb, 0x151c, 0x25de, 0x467f, 0x153a, 0x051b, 0x359c, 0x7d57, 0x0000, 0x0021, 0x0000, 0x4986, 0xf5da, 0xaa93, 0x99f3, 0x9ab5, 0xe59f, 0xfeff, 0xff1f, 0xab14, 0x9a52, 0x92d4, 0xb479, 0x3148, 0x0000, 0x0000, 0x0000, 0x0000, 0x0020, 0x0000, 0x0020, 0x0000, 0x0020, 0x10c0, 0xe7b1, 0xbf24, 0xbf24, 0xbeee, 0xe7f4, 0xdf8b, 0xc746, 0xaf05, 0xb74a, 0xb692, 0x0020, 0x0040, 0x0000, 0x0020, 0x0020, 0x0000, 0x0020, 0xbed3, 0x758b, 0x34e8, 0x2d4a, 0x5e11, 0x3c8d, 0x4bec, 0x4bab, 0x436a, 0x3b29, 0x32e8, 0x32a8, 0x21e6, 0x0040, 0x0040,
0x0000, 0x0000, 0x0820, 0x4103, 0xd32c, 0xc986, 0xd146, 0xd967, 0xeaac, 0xc9c8, 0xd946, 0xd147, 0xc26c, 0xfd97, 0xff19, 0xe40c, 0xd144, 0xd905, 0xc22a, 0xdcd4, 0x0021, 0x0062, 0x0000, 0x0820, 0x0000, 0x0020, 0x0001, 0x0001, 0x0001, 0x0000, 0x0000, 0x5368, 0x3be8, 0x4d2a, 0x662d, 0x3509, 0x354c, 0x4570, 0x6d13, 0x0022, 0x0001, 0x0000, 0x49c0, 0xfead, 0xfe25, 0xfe24, 0xee48, 0xfecd, 0xf68e, 0xee4e, 0xfeb0, 0xee4e, 0xe66e, 0xee8c, 0xee47, 0xf645, 0xfe04, 0xfe4a, 0x9c09, 0x1880, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0840, 0x0000, 0x0020, 0x0040, 0x2180, 0x8cc9, 0x7ca4, 0xcf6a, 0xb705, 0xb706, 0xbf0c, 0xd774, 0x08e0, 0x0020, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0800, 0x0001, 0x0043, 0x4bb2, 0x659a, 0x2cb8, 0x24da, 0x2d3c, 0x457d, 0x3d7d, 0x14db, 0x1cba, 0x44f8, 0x8f1f, 0x6e5f, 0x2cfb, 0x14ba, 0x2d7d, 0x4e5f, 0x0cba, 0x0d5c, 0x35bc, 0x7cf6, 0x0000, 0x0001, 0x0021, 0x51c8, 0xdd58, 0x9a91, 0xaa93, 0xa2b4, 0xbb97, 0xc3d8, 0xb396, 0x92b3, 0x92d4, 0x82d2, 0xb4b8, 0x3988, 0x0000, 0x0000, 0x0020, 0x0000, 0x0020, 0x0000, 0x0001, 0x0001, 0x0000, 0x08c0, 0xdf6e, 0xbee4, 0xb6e5, 0xc710, 0xeff6, 0xdfac, 0xbf04, 0xaf04, 0xb74b, 0xb693, 0x0020, 0x0000, 0x0800, 0x0000, 0x0000, 0x0001, 0x0000, 0xbe94, 0x756c, 0x3cea, 0x3d6c, 0x454d, 0x6df0, 0x7e11, 0x754f, 0x754f, 0x6cef, 0x6ccf, 0x8531, 0x4b2a, 0x0020, 0x0020,
0x0000, 0x0000, 0x0000, 0x0800, 0x50a2, 0xec0f, 0xc1a6, 0xc966, 0xb986, 0xc187, 0xc166, 0xdaac, 0xfdb9, 0xff1d, 0xfef8, 0xf40c, 0xd123, 0xd125, 0xca4a, 0xed15, 0x0000, 0x0021, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0801, 0x0000, 0x7c0b, 0x9df0, 0x4d0a, 0x354b, 0x354b, 0x352b, 0x3d0c, 0x5db1, 0x6cf3, 0x0042, 0x0001, 0x0000, 0x4a02, 0xeeb0, 0xf62b, 0xf629, 0xee6c, 0xf6ae, 0xfed0, 0xfed1, 0xff54, 0xff32, 0xff91, 0xffaf, 0xff4b, 0xfe46, 0xfe25, 0xf629, 0x6261, 0x0000, 0x0000, 0x0041, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0020, 0x0000, 0x10c0, 0xced1, 0xc6cc, 0xbee8, 0xbee6, 0xbee7, 0xb6c9, 0xbece, 0xe7f8, 0x08a1, 0x0041, 0x0020, 0x0000, 0x0000, 0x0001, 0x0000, 0x0000, 0x0000, 0x0020, 0x0020, 0x0020, 0x0000, 0x0000, 0x0021, 0x0022, 0x5c53, 0x7e1c, 0x34b9, 0x2478, 0x2cda, 0x2499, 0x24b8, 0x55dc, 0x8e3b, 0x4c14, 0x6e1f, 0x2cdb, 0x14db, 0x3e1f, 0x569f, 0x1cda, 0x0cd9, 0x2cd7, 0x00e6, 0x0801, 0x0000, 0x0000, 0x49e8, 0xcd78, 0x8ad0, 0x92b1, 0xaaf4, 0x9a32, 0xa274, 0x9a94, 0xb3b7, 0xee1f, 0x9bf5, 0x28a6, 0x0802, 0x0021, 0x0000, 0x0020, 0x0000, 0x0000, 0x0000, 0x0001, 0x0001, 0x0820, 0x0860, 0xd710, 0xc6e9, 0xbeaa, 0xc6d2, 0xeff8, 0xdf8e, 0xbec8, 0xb709, 0xb70d, 0xbeb5, 0x0000, 0x0000, 0x0800, 0x0800, 0x0000, 0x0001, 0x0000, 0xb634, 0x750c, 0x44cb, 0x454c, 0x5d8e, 0x6df0, 0x7610, 0x9f15, 0xa736, 0xaf36, 0xa6f6, 0x0100, 0x0101, 0x0020, 0x0040,
0x0001, 0x0000, 0x0020, 0x0000, 0x1000, 0x2000, 0x8248, 0xdcf2, 0xd4b2, 0xd4b2, 0xb38e, 0xa2cb, 0xed15, 0xf4d4, 0xfc91, 0xfb6c, 0xfacb, 0xfa4a, 0xe2ac, 0xfc94, 0x4023, 0x30c5, 0x1001, 0x0800, 0x0800, 0x0000, 0x0020, 0x0020, 0x0020, 0x0040, 0x8d2e, 0x9e91, 0x454b, 0x2d2b, 0x4df0, 0xaffa, 0xbffb, 0xa717, 0x11c4, 0x00c2, 0x0000, 0x0020, 0x0000, 0x0840, 0x0800, 0x1000, 0x0800, 0x0800, 0x0800, 0x0800, 0x0840, 0xff95, 0xff31, 0xff8f, 0xfea9, 0xfec8, 0xfea7, 0xfe88, 0x8380, 0x3140, 0x3122, 0x18a3, 0x0000, 0x0000, 0x0001, 0x0000, 0x0000, 0x0000, 0x0000, 0x2120, 0xf7f2, 0xc708, 0xbee5, 0xbf06, 0xdfef, 0xf7f5, 0xeff6, 0x5b67, 0x2164, 0x0000, 0x0020, 0x0020, 0x0000, 0x0001, 0x0001, 0x0001, 0x0000, 0x0020, 0x0000, 0x0000, 0x0820, 0x0000, 0x0000, 0x0020, 0x0021, 0x0022, 0x95d8, 0x9e5b, 0x8e1a, 0x8e3a, 0x0a49, 0x0082, 0x0022, 0x5c14, 0x665f, 0x153c, 0x051b, 0x1d9e, 0x35ff, 0x3d7c, 0x2455, 0x2b70, 0x0022, 0x0000, 0x0000, 0x0020, 0x0000, 0x0000, 0x0801, 0x1802, 0xfe5f, 0xbb35, 0x9a34, 0x9254, 0xbc99, 0x38e8, 0x40e7, 0x30c6, 0x2926, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0020, 0x0000, 0x0000, 0x0000, 0x0020, 0x0040, 0x7429, 0xc6b6, 0x2160, 0xc631, 0xb5cd, 0xa5ee, 0x95af, 0x9573, 0x0001, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0841, 0x1921, 0x11a1, 0x0242, 0x0201, 0x0201, 0x01a0, 0x0201, 0x01c0, 0x01a0, 0x0180, 0x01a1, 0x0162, 0x0060, 0x0020, 0x0040,
0x0000, 0x0000, 0x0020, 0x0000, 0x0000, 0x0000, 0x0800, 0x0800, 0x0800, 0x1000, 0x0800, 0x830c, 0xccb2, 0xbb4d, 0xcaec, 0xca28, 0xd1e8, 0xd187, 0xe229, 0xd24a, 0xd30f, 0xfd99, 0x38e6, 0x0001, 0x0800, 0x0800, 0x0000, 0x3247, 0x3286, 0x1a43, 0x750c, 0x75ed, 0x352a, 0x2d6c, 0x3d8e, 0x7ed4, 0x9f16, 0xa6d6, 0xb6d7, 0x538c, 0x0020, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0820, 0x0000, 0x0020, 0x0000, 0x0060, 0xef77, 0xeeb1, 0xee6e, 0xf68c, 0xf649, 0xf647, 0xf667, 0xee67, 0xf6cd, 0xf6d6, 0xacf3, 0x0000, 0x0021, 0x0001, 0x0020, 0x1901, 0x4a85, 0x4aa5, 0x5303, 0xdf8d, 0xbf06, 0xb704, 0xbf06, 0xcf8e, 0xdfb3, 0xd773, 0xdf77, 0xdf5b, 0x0020, 0x0020, 0x0000, 0x0000, 0x0001, 0x0001, 0x0000, 0x0000, 0x0020, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0020, 0x0000, 0x0000, 0x0040, 0x0020, 0x0040, 0x0040, 0x0060, 0x5391, 0x759b, 0x24da, 0x04db, 0x0d1b, 0x0cfa, 0x1d3c, 0x565f, 0x1b71, 0x0084, 0x0022, 0x0000, 0x0020, 0x0020, 0x10a1, 0x4a08, 0x4167, 0x4928, 0xe53b, 0x9a93, 0x9a75, 0x9294, 0xac17, 0xcd79, 0xddba, 0xcd99, 0xdebc, 0x0862, 0x0000, 0x0020, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0040, 0x0000, 0x0000, 0x0820, 0x0040, 0x0040, 0x0041, 0x0001, 0x0000, 0x0000, 0x0000, 0x0820, 0x0000, 0x0000, 0xbe36, 0xb6b5, 0x9eb4, 0x8e73, 0x8e73, 0x8632, 0x658f, 0x65b0, 0x6d70, 0x650f, 0x6510, 0x7d72, 0x4b6b, 0x0020, 0x0000,
0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x39a6, 0x8b4d, 0x7a8a, 0x7a49, 0x79a6, 0x7904, 0xeb6d, 0xd144, 0xd124, 0xc989, 0xfc56, 0x40c6, 0x0001, 0x0001, 0x0000, 0x0000, 0xb655, 0x752e, 0x658e, 0x554b, 0x3d2a, 0x2d8b, 0x35ed, 0x3dad, 0x4dae, 0x5dcf, 0x6db1, 0x8e35, 0x4b2b, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0040, 0x0020, 0x73ac, 0x7baa, 0x8388, 0x7345, 0x7b43, 0xa443, 0xf6a8, 0xfe62, 0xf665, 0xee70, 0xb531, 0x0000, 0x0000, 0x0000, 0x0020, 0x5b47, 0xd713, 0xcf10, 0xcf0c, 0xb6c6, 0xbf25, 0xbf25, 0xbf47, 0xbf2a, 0xc70d, 0xcf0f, 0xcf33, 0xced8, 0x0020, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0020, 0x5c11, 0x65bc, 0x24ba, 0x14db, 0x255c, 0x561d, 0x357a, 0x0cdb, 0x14da, 0x65dc, 0x43b2, 0x0002, 0x0000, 0x0000, 0x0000, 0x41a6, 0xc536, 0xa3d3, 0xa333, 0x9af3, 0x9ad4, 0xa2d5, 0xa2f5, 0xa334, 0xa394, 0x9bb3, 0xa474, 0xc5f9, 0x10a3, 0x0000, 0x0020, 0x0000, 0x0020, 0x0000, 0x0020, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0040, 0xae35, 0x8570, 0x85f1, 0x8632, 0x8633, 0x8e74, 0x8eb4, 0x5cee, 0x1224, 0x1a45, 0x2286, 0x2aa8, 0x1184, 0x0040, 0x0000,
0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0020, 0x0040, 0x0000, 0x1800, 0x2800, 0x2800, 0x2800, 0x3000, 0xe3ae, 0xe1c5, 0xe144, 0xc928, 0xfc55, 0x4907, 0x0001, 0x0021, 0x0000, 0x0820, 0x3a46, 0xaef4, 0xa795, 0x8f73, 0x4e4e, 0x2d8b, 0x2dab, 0x3d8b, 0x6eb1, 0x8fb7, 0x0264, 0x2ac9, 0x0903, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0020, 0x0000, 0x1000, 0x1000, 0x0800, 0x0820, 0x5200, 0xfeeb, 0xf601, 0xfe64, 0xee6f, 0xb510, 0x0000, 0x0000, 0x0000, 0x0000, 0x1100, 0x9d6c, 0xdfb0, 0xe7ed, 0xd7c9, 0xbf25, 0xbf66, 0xb706, 0xc769, 0xdfee, 0x84e7, 0x3a61, 0x3a45, 0x0020, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0020, 0xa67b, 0x24da, 0x0cfc, 0x2d5d, 0x877f, 0xbfff, 0x9f3f, 0x2d7c, 0x151b, 0x2cb8, 0x7e1b, 0x0022, 0x0000, 0x0000, 0x0000, 0x1842, 0x9370, 0xcc97, 0xdcfa, 0xed9d, 0xe55d, 0xa355, 0x486a, 0x4829, 0x58ca, 0x40c9, 0x498a, 0x4a0a, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0020, 0x2a45, 0xc799, 0xb778, 0xb7b8, 0xbffa, 0xbffa, 0x12c5, 0x01e2, 0x0100, 0x0080, 0x0080, 0x0060, 0x0080, 0x0020, 0x0000,
0x0020, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0820, 0x0000, 0x0020, 0x7b2b, 0xcbae, 0xc26a, 0xcacb, 0xd32c, 0xcbae, 0xf470, 0xc965, 0xd146, 0xc189, 0xfd17, 0x4105, 0x0020, 0x0000, 0x0000, 0x0000, 0x0020, 0x3aa4, 0xbfb5, 0x5dac, 0x3d8b, 0x2d4b, 0x2d4b, 0x2d29, 0x352a, 0x4def, 0x7655, 0x0061, 0x0001, 0x0000, 0x0000, 0x0020, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0800, 0xeeb5, 0xddcc, 0xe5eb, 0xdded, 0xe62d, 0xee6d, 0xfe8a, 0xfe66, 0xf5e6, 0xd58e, 0x1840, 0x0800, 0x0000, 0x0000, 0x0000, 0x0000, 0x1920, 0xc6ce, 0xcf6c, 0xbee7, 0xbf26, 0xb6e5, 0xb706, 0xc768, 0xbf0a, 0xcf33, 0x3a86, 0x0040, 0x0020, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0040, 0x0000, 0x0000, 0x8dda, 0x1499, 0x0cfb, 0x5e5f, 0xc7ff, 0xf7ff, 0xe7df, 0x55fc, 0x0cf9, 0x1cf9, 0x5dda, 0x0082, 0x0000, 0x0000, 0x0000, 0x0801, 0x6a8c, 0xb455, 0x9b52, 0x9b53, 0x9b94, 0x8af2, 0x7a30, 0x9a93, 0xa2d3, 0x9b14, 0xb498, 0x2907, 0x0021, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0840, 0x0020, 0x0040, 0xb696, 0x74ef, 0x64ce, 0x650f, 0x652f, 0x4c6a, 0x4449, 0x4d0c, 0x4cec, 0x6570, 0x64d0, 0x0020, 0x0000, 0x0000,
0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x936b, 0xe36d, 0xc946, 0xd186, 0xc9c6, 0xc2eb, 0xc30b, 0xd249, 0xda4a, 0xc24b, 0xfdd9, 0x4125, 0x0000, 0x0841, 0x0000, 0x0000, 0x0020, 0x4b25, 0x758c, 0x454b, 0x2d0a, 0x55ce, 0x6650, 0x55ac, 0x3d6a, 0x2d2c, 0x5df2, 0x74f3, 0x0022, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0020, 0x0000, 0x1020, 0xff35, 0xf628, 0xf605, 0xf649, 0xf64c, 0xf66d, 0xfe8c, 0xfe49, 0xf62a, 0xcd8e, 0x1000, 0x0800, 0x0800, 0x0000, 0x0840, 0x0000, 0x1920, 0xa5e9, 0xb6c8, 0xbf09, 0xbf0a, 0xd78d, 0xc74b, 0xaec5, 0xbf08, 0xbeb0, 0xe7ba, 0x1102, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0040, 0x0000, 0x8d58, 0x34fa, 0x14fb, 0x5e1e, 0xbfff, 0xf7ff, 0xdfdf, 0x55dc, 0x1519, 0x2519, 0x5599, 0x0041, 0x0000, 0x0000, 0x0000, 0x0000, 0x520a, 0xbcd6, 0xb495, 0x9391, 0x8b51, 0x7acf, 0xabf5, 0xa2d3, 0x9a72, 0x92d4, 0xac17, 0x3148, 0x0821, 0x0000, 0x0000, 0x0841, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0040, 0x0020, 0xa5d4, 0x8d72, 0x8531, 0x64af, 0x546d, 0x5c8b, 0x6dae, 0x3d2a, 0x352b, 0x452e, 0x4c6e, 0x0041, 0x0002, 0x0000,
0x0000, 0x0000, 0x0000, 0x0000, 0x0001, 0x0001, 0x0000, 0x0000, 0x0000, 0x0000, 0x0840, 0x9b6b, 0xf32d, 0xd8e4, 0xd8e3, 0xfacb, 0xfdf8, 0xfe59, 0xfe38, 0xfdf8, 0xfdb7, 0xfe5a, 0x9b8f, 0x0800, 0x0000, 0x0041, 0x0020, 0x0060, 0xaf12, 0x4528, 0x2d6b, 0x460f, 0xc7fc, 0xe7fc, 0xb794, 0x558b, 0x254a, 0x358f, 0x5cf1, 0x0021, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x1040, 0xff52, 0xf664, 0xfe82, 0xee24, 0xffcf, 0xfff3, 0xffb2, 0xfff2, 0xffd3, 0xeef3, 0x6b06, 0x3143, 0x0800, 0x0000, 0x0000, 0x0820, 0x8468, 0xcf4a, 0xbf07, 0xbf0c, 0xdff5, 0xf7fb, 0xfff8, 0xcf89, 0xb6e4, 0xbf0c, 0xd795, 0x08a0, 0x0041, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0001, 0x0000, 0x0000, 0x0800, 0x6bd2, 0x659a, 0x24b8, 0x24d9, 0x6edf, 0x86df, 0x6e3e, 0x251a, 0x1cf9, 0x55bb, 0x3bb0, 0x0020, 0x0000, 0x0000, 0x0021, 0x0001, 0x0000, 0x1002, 0x1000, 0x0800, 0x0800, 0x0801, 0xbcd7, 0xb375, 0x9a73, 0x9294, 0xac38, 0x3107, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0800, 0x0000, 0x0000, 0x0040, 0x0040, 0x0020, 0x0040, 0x0060, 0x0080, 0x2242, 0xaf54, 0x3569, 0x258a, 0x356e, 0x5510, 0x0021, 0x0001, 0x0000,
0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0020, 0x0000, 0x82a8, 0xe2cb, 0xd8e5, 0xd925, 0xf28a, 0xfc93, 0xfc93, 0xe3af, 0xe3cf, 0xd3cf, 0xbbaf, 0xe5f8, 0x0801, 0x0001, 0x0021, 0x0000, 0x00a0, 0xa732, 0x4528, 0x254b, 0x5651, 0xcffc, 0xe7fc, 0xcff8, 0x660d, 0x258b, 0x358e, 0x440e, 0x0021, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0040, 0x0800, 0xff10, 0xfe85, 0xf621, 0xfea6, 0xff2c, 0xff0f, 0xff10, 0xf6cf, 0xeeb0, 0xe6d2, 0xe736, 0x7bac, 0x0000, 0x0000, 0x0000, 0x0020, 0x8c88, 0xc708, 0xbf06, 0xbf0b, 0xe7f5, 0xf7fc, 0xfff9, 0xcfa9, 0xbf24, 0xbf0a, 0xc711, 0x08c0, 0x0001, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0020, 0x0000, 0x0000, 0x0000, 0x0801, 0x0001, 0x5412, 0x7e7d, 0x4559, 0x2496, 0x2c97, 0x34b8, 0x3519, 0x6e7e, 0x43f2, 0x0042, 0x0020, 0x0020, 0x0000, 0x0000, 0x0021, 0x0000, 0x0000, 0x0800, 0x0000, 0x0820, 0x0000, 0xb4b5, 0xa312, 0x9a72, 0x9294, 0xbc9a, 0x3969, 0x0000, 0x0021, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0800, 0x0000, 0x0820, 0x0000, 0x0000, 0x0040, 0x0020, 0x0040, 0x0040, 0x2a02, 0xa6d2, 0x3d8a, 0x256a, 0x2d0c, 0x5d72, 0x0021, 0x0001, 0x0000,
0x0800, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0840, 0x0000, 0x82c9, 0xd30c, 0xb946, 0xb9a6, 0xb1e7, 0xa9e8, 0xaa09, 0xc28c, 0xc2ed, 0xc38f, 0xcc92, 0xf6ba, 0x0800, 0x0000, 0x0000, 0x0000, 0x00a0, 0xc796, 0x552a, 0x352b, 0x356d, 0xa798, 0xcffc, 0x9713, 0x456b, 0x254b, 0x3d6f, 0x64b1, 0x0001, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0020, 0x0000, 0x1040, 0xff12, 0xe608, 0xe606, 0xee4a, 0xe64c, 0xe66c, 0xe66c, 0xeeaf, 0xeeb1, 0xef14, 0xf779, 0x7bae, 0x0000, 0x0001, 0x0000, 0x0000, 0x9cec, 0xcf2b, 0xbee5, 0xbf07, 0xcf6c, 0xf7f4, 0xe7f1, 0xc767, 0xb6e4, 0xb6cb, 0xdfb6, 0x1923, 0x0002, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0020, 0x0020, 0x0020, 0x0000, 0x0000, 0x0000, 0x0062, 0x19a7, 0x0106, 0x85d9, 0xa6fd, 0x7557, 0x0167, 0x11c9, 0x0022, 0x0021, 0x0000, 0x0000, 0x0020, 0x0000, 0x0021, 0x0041, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xb4f5, 0xabb3, 0x9291, 0x8273, 0xc51b, 0x3968, 0x0000, 0x0000, 0x0020, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0800, 0x0841, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x39c3, 0xbed4, 0x44c9, 0x352b, 0x55b0, 0x6552, 0x0021, 0x0001, 0x0000,
0x0800, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0020, 0x6a89, 0xc3af, 0xdbf0, 0xecd3, 0xf554, 0x9228, 0x3000, 0x3800, 0x3000, 0x2800, 0x2000, 0x1820, 0x0000, 0x0000, 0x0000, 0x0000, 0x0020, 0x2202, 0x85ef, 0x44ec, 0x3cec, 0x4ced, 0x4d0d, 0x44eb, 0x3d0b, 0x350d, 0x4d2f, 0x0061, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0840, 0xde72, 0xde0e, 0xf690, 0xee92, 0xd610, 0x1880, 0x1860, 0x2060, 0x1860, 0x1040, 0x1080, 0x0000, 0x0001, 0x0000, 0x0000, 0x0000, 0x0860, 0x9d47, 0xc6e9, 0xbee7, 0xbee8, 0xbeea, 0xbeea, 0xbee7, 0xb6a8, 0xc6cf, 0x3a43, 0x0000, 0x0001, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0020, 0x0040, 0x0020, 0x0000, 0x0020, 0x0000, 0x0000, 0x0000, 0x0021, 0x0042, 0x00c3, 0x0062, 0x0020, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0020, 0x0000, 0x0000, 0x8bd0, 0x82ef, 0x8290, 0x7a91, 0xac57, 0x3968, 0x0001, 0x0000, 0x0000, 0x0000, 0x0000, 0x0020, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x3142, 0xa591, 0x548a, 0x3c4a, 0x446d, 0x6cd1, 0x0001, 0x0001, 0x0000,
0x0800, 0x0800, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0800, 0x1800, 0x1800, 0x1000, 0x0800, 0x0800, 0x0800, 0x0800, 0x0800, 0x0000, 0x0000, 0x0000, 0x0800, 0x0800, 0x0800, 0x0000, 0x0000, 0x0060, 0x2a23, 0x7d4f, 0x6d6f, 0x552e, 0x4d6e, 0x556e, 0x65b0, 0x54ae, 0x0080, 0x0020, 0x0800, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0020, 0x0020, 0x0800, 0x0800, 0x0000, 0x0000, 0x0000, 0x0000, 0x0800, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0020, 0x0040, 0x0040, 0x9d49, 0xc6ed, 0xc70b, 0xc70c, 0xbecb, 0xcf2e, 0xbe8f, 0x3a22, 0x0040, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0801, 0x1002, 0x1003, 0x0802, 0x0001, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0060, 0x0060, 0x0040, 0x0020, 0x0000, 0x0000, 0x0000,
0x0800, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0020, 0x0020, 0x0020, 0x0020, 0x0000, 0x0000, 0x0000, 0x0000, 0x0801, 0x0800, 0x0000, 0x0000, 0x0020, 0x0040, 0x42a7, 0x5bcb, 0x3ba9, 0x2b88, 0x3389, 0x544d, 0x00e1, 0x0020, 0x0020, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0020, 0x0000, 0x0000, 0x0001, 0x0002, 0x0002, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0800, 0x0000, 0x0000, 0x0020, 0x10c0, 0x8468, 0x7425, 0x6c04, 0x6c25, 0x6bc7, 0x4ac6, 0x0840, 0x0000, 0x0020, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0001, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0800, 0x0800, 0x0801, 0x0001, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0020, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0020, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0001, 0x0001, 0x0000, 0x0000, 0x0000, 0x0800, 0x0000, 0x0000, 0x0000, 0x0001, 0x0000, 0x0000, 0x0820, 0x0040, 0x0020, 0x0000, 0x0040, 0x0020, 0x0020, 0x0020, 0x0020, 0x0000, 0x0020, 0x0020, 0x0000, 0x0000, 0x0800, 0x0801, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0001, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0800, 0x0801, 0x0001, 0x0042, 0x0020, 0x0000, 0x0020, 0x0020, 0x0020, 0x0060, 0x0040, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0001, 0x0001, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0020,
0x0001, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0020, 0x0000, 0x0000, 0x0000, 0x0020, 0x0020, 0x0001, 0x0001, 0x0001, 0x0000, 0x0800, 0x0800, 0x0800, 0x0800, 0x0000, 0x0000, 0x0001, 0x0001, 0x0000, 0x0000, 0x0000, 0x0020, 0x0000, 0x0000, 0x0000, 0x0000, 0x0800, 0x0000, 0x0820, 0x0020, 0x0020, 0x0020, 0x0000, 0x0801, 0x0801, 0x0801, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0001, 0x0001, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0800, 0x0800, 0x0800, 0x0000, 0x0001, 0x0001, 0x0001, 0x0001, 0x0021, 0x0000, 0x0000, 0x0000, 0x0001, 0x0001, 0x0001, 0x0802, 0x0000, 0x0000, 0x0020, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0800, 0x0000, 0x0000, 0x0020, 0x0001, 0x0001, 0x0000, 0x0000, 0x0000, 0x0000, 0x0002, 0x0001, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0001, 0x0001, 0x0001, 0x0000, 0x0000, 0x0000, 0x0020, 0x0020
};