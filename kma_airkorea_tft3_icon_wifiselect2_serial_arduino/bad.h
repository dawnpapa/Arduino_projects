// We need this header file to use FLASH as storage with PROGMEM directive:
#include <pgmspace.h>

// Icon width and height
const uint16_t badWidth = 95;
const uint16_t badHeight = 25;

const unsigned short  bad[95*25] PROGMEM={
0x0000, 0x0040, 0x0000, 0x0020, 0x0000, 0x0800, 0x0800, 0x0800, 0x6b03, 0x8c03, 0xd689, 0xffec, 0xffec, 0xffea, 0xffe9, 0xffe9, 0xffea, 0xffeb, 0xffeb, 0xffeb, 0xffeb, 0xffeb, 0xffeb, 0xffeb, 0xffeb, 0xffeb, 0xffeb, 0xffeb, 0xffeb, 0xffeb, 0xffeb, 0xffeb, 0xffeb, 0xffeb, 0xffeb, 0xffeb, 0xffeb, 0xffeb, 0xffeb, 0xffeb, 0xffeb, 0xffeb, 0xffeb, 0xffeb, 0xffeb, 0xffeb, 0xffeb, 0xffea, 0xffea, 0xffeb, 0xffec, 0xffec, 0xffeb, 0xffea, 0xffea, 0xffe9, 0xffea, 0xffeb, 0xffea, 0xffeb, 0xffea, 0xffeb, 0xffea, 0xffeb, 0xffeb, 0xffeb, 0xffeb, 0xffeb, 0xffeb, 0xffec, 0xffec, 0xffec, 0xffea, 0xffea, 0xffeb, 0xffec, 0xffec, 0xffec, 0xffeb, 0xffeb, 0xffeb, 0xffec, 0xffec, 0xffed, 0xe6ea, 0x83c1, 0x7322, 0x1020, 0x0800, 0x0800, 0x0000, 0x0000, 0x0020, 0x0000, 0x0000,
0x0020, 0x0000, 0x0040, 0x0000, 0x0000, 0x41c2, 0xad2b, 0xe70f, 0xffaf, 0xef4b, 0xffca, 0xffe8, 0xf787, 0xffa6, 0xffa5, 0xff84, 0xffa6, 0xffa6, 0xffa6, 0xffa6, 0xffa6, 0xffa6, 0xffa6, 0xffa6, 0xffa6, 0xffa6, 0xffa6, 0xffa6, 0xffa6, 0xffa6, 0xffa6, 0xffa6, 0xffa6, 0xffa6, 0xffa6, 0xffa6, 0xffa6, 0xffa6, 0xffa6, 0xffa6, 0xffa6, 0xffa6, 0xffa6, 0xffa6, 0xffa6, 0xffa6, 0xffa6, 0xffc6, 0xffc6, 0xffc6, 0xffa8, 0xffa8, 0xffa6, 0xffa5, 0xffc5, 0xf7a5, 0xf785, 0xffc6, 0xffa6, 0xffe7, 0xffa6, 0xffc6, 0xffa6, 0xffc6, 0xffc7, 0xffa7, 0xffc7, 0xffc7, 0xffa7, 0xffa7, 0xffa7, 0xf786, 0xffc6, 0xffc6, 0xffa7, 0xffc7, 0xf786, 0xffa7, 0xffc7, 0xf7a6, 0xffe7, 0xf786, 0xffc8, 0xf788, 0xf789, 0xffcc, 0xf76e, 0xef10, 0xad0b, 0x39a1, 0x0000, 0x0000, 0x0000, 0x0020, 0x0000,
0x0000, 0x0020, 0x0000, 0x0000, 0x4a40, 0xef4e, 0xf7aa, 0xf7c6, 0xffe6, 0xf7c3, 0xf7e3, 0xffe2, 0xffe2, 0xffe2, 0xffe2, 0xffe1, 0xffe2, 0xffe2, 0xffe2, 0xffe2, 0xffe2, 0xffe2, 0xffe2, 0xffe2, 0xffe2, 0xffe2, 0xffe2, 0xffe2, 0xffe2, 0xffe2, 0xffe2, 0xffe2, 0xffe2, 0xffe2, 0xffe2, 0xffe2, 0xffe2, 0xffe2, 0xffe2, 0xffe2, 0xffe2, 0xffe2, 0xffe2, 0xffe2, 0xffe2, 0xffe2, 0xffe2, 0xffe2, 0xffe2, 0xf7c1, 0xffe2, 0xffe2, 0xffe2, 0xffe1, 0xffc1, 0xffe2, 0xffe2, 0xffe2, 0xffc1, 0xffe2, 0xffe2, 0xffe2, 0xffe2, 0xffe2, 0xffe2, 0xffe2, 0xf7a1, 0xffc2, 0xf7a1, 0xffe2, 0xffe3, 0xffe2, 0xffe2, 0xffc1, 0xffc2, 0xffe3, 0xf7c2, 0xffc2, 0xffe3, 0xffe2, 0xf7c1, 0xffe2, 0xffe2, 0xffe3, 0xffc3, 0xf7c3, 0xffc4, 0xf7c6, 0xefa8, 0xef8d, 0x4220, 0x0000, 0x0000, 0x0000, 0x0000,
0x0000, 0x0820, 0x0800, 0x41e0, 0xe72c, 0xf7c8, 0xffe3, 0xffe1, 0xf7e0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffc0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffc0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe1, 0xffc3, 0xff86, 0xff85, 0xffe3, 0xffe1, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffc1, 0xffc3, 0xffc6, 0xffa5, 0xffe2, 0xf7a0, 0xffe0, 0xffe0, 0xffe0, 0xffc1, 0xffc4, 0xffc5, 0xffe5, 0xffc5, 0xf765, 0xff86, 0xffe6, 0xffc5, 0xffa5, 0xffa4, 0xffe4, 0xffe2, 0xffe0, 0xf7e0, 0xffe3, 0xf7e6, 0xdf0b, 0x94aa, 0x0000, 0x0000, 0x0000,
0x0801, 0x0000, 0x4200, 0xef4d, 0xf7c7, 0xffe3, 0xf7c0, 0xffc0, 0xffe0, 0xffe0, 0xffe1, 0xffc1, 0xffe1, 0xffe1, 0xffe1, 0xffe1, 0xffc0, 0xffc0, 0xffc0, 0xffc0, 0xffc0, 0xffc0, 0xffc0, 0xffc0, 0xffc0, 0xffc0, 0xffc0, 0xffc0, 0xffc0, 0xffc0, 0xffc0, 0xffc0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffc0, 0xffc0, 0xffc0, 0xffc0, 0xffc0, 0xffc0, 0xffc0, 0xffe0, 0xffe0, 0xffc0, 0xffe0, 0xffc0, 0xffe0, 0xffc1, 0xffa3, 0xeee7, 0xa427, 0xb4a9, 0xeee6, 0xffc3, 0xffe1, 0xffc0, 0xffe0, 0xffe1, 0xffc5, 0xde66, 0xb4ca, 0xe62d, 0xf765, 0xffe2, 0xffa0, 0xffe1, 0xffc0, 0xffc4, 0xf6eb, 0xd5ca, 0xde29, 0xff0e, 0xb489, 0xa407, 0xa445, 0xf6ef, 0xd5eb, 0xe64b, 0xeea9, 0xff87, 0xffe2, 0xffe0, 0xf7c0, 0xffe2, 0xf7e5, 0xe74a, 0x4202, 0x0800, 0x0820,
0x0800, 0x41c3, 0xf7b0, 0xef87, 0xf7c2, 0xffe0, 0xffe1, 0xffe0, 0xffc0, 0xffe0, 0xffc1, 0xffe1, 0xffe2, 0xffe1, 0xffe0, 0xffc0, 0xffe1, 0xffe1, 0xffe1, 0xffe1, 0xffe1, 0xffe1, 0xffe1, 0xffe1, 0xffe1, 0xffe1, 0xffe1, 0xffe1, 0xffe1, 0xffe1, 0xffe1, 0xffe1, 0xffe1, 0xffe1, 0xffe1, 0xffe1, 0xffe1, 0xffe1, 0xffe1, 0xffe1, 0xffe1, 0xffe1, 0xffe1, 0xffe1, 0xffe1, 0xffe1, 0xffe1, 0xffe0, 0xffe0, 0xffc0, 0xffe1, 0xffc0, 0xffe0, 0xffc2, 0xffa6, 0xde09, 0x61c8, 0x7249, 0xde08, 0xff84, 0xffe1, 0xffe0, 0xffe0, 0xffc2, 0xff88, 0x93a2, 0x6a09, 0x7aa9, 0xf728, 0xffa0, 0xffe3, 0xffa1, 0xffe0, 0xffc7, 0xb489, 0x7226, 0x7a85, 0xe5f3, 0x828c, 0x69ea, 0x82c9, 0xee35, 0x7248, 0x6a24, 0x9c04, 0xff8a, 0xff82, 0xffe0, 0xffe1, 0xf7c0, 0xffe1, 0xf7c6, 0xef51, 0x3982, 0x0000,
0x0800, 0xa4ca, 0xffea, 0xffe3, 0xffe1, 0xffe0, 0xffe1, 0xffc0, 0xffc0, 0xffe0, 0xffc0, 0xffe0, 0xffe0, 0xffc0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffc0, 0xffe0, 0xffc0, 0xffe0, 0xffc2, 0xffa8, 0xc509, 0x71cd, 0x69cd, 0xe62c, 0xff86, 0xffc2, 0xffe0, 0xffc0, 0xff82, 0xff4a, 0x8305, 0x71cf, 0x7a4d, 0xff6b, 0xff80, 0xffc3, 0xffe2, 0xffc0, 0xff67, 0xa3ec, 0x69ad, 0x71ec, 0xed9c, 0x8a93, 0x71cf, 0x7a4d, 0xedfb, 0x69ad, 0x722b, 0xc4ea, 0xff8a, 0xffe4, 0xffa0, 0xffa2, 0xffe2, 0xffe0, 0xffe4, 0xf7ac, 0xad4a, 0x0840,
0x3980, 0xef50, 0xf7c5, 0xffe0, 0xffe0, 0xffc0, 0xffe1, 0xffc1, 0xffe0, 0xffe0, 0xffc0, 0xffe0, 0xffe0, 0xffc0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffc2, 0xff88, 0xac48, 0x71ce, 0x69ad, 0xee8d, 0xffa6, 0xffa1, 0xffe0, 0xffe0, 0xffc4, 0xff4c, 0x82e6, 0x6990, 0x7a50, 0xff30, 0xffa7, 0xff66, 0xffa4, 0xffe2, 0xff27, 0xa3cf, 0x69b0, 0x698e, 0xbc39, 0x71d2, 0x71b1, 0x722e, 0xa374, 0x71b1, 0x69ac, 0xd58d, 0xff48, 0xffc3, 0xffe1, 0xffc3, 0xffc3, 0xffe1, 0xf7e2, 0xf7c6, 0xf7ad, 0x3180,
0x83e3, 0xffad, 0xf7e4, 0xffe0, 0xffc0, 0xffe0, 0xffc0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe1, 0xffe1, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe1, 0xffe2, 0xffc1, 0xffe1, 0xffe0, 0xffc0, 0xffc3, 0xff89, 0xa427, 0x69cd, 0x6a0b, 0xf6c9, 0xffc2, 0xffc0, 0xffe0, 0xffe0, 0xffc4, 0xff0c, 0x82e7, 0x71d0, 0x69b0, 0x8b08, 0x7b20, 0x9c21, 0xff48, 0xffe3, 0xf747, 0xa3af, 0x71d1, 0x69cd, 0x82b0, 0x69b0, 0x69cf, 0x7a6e, 0x8b11, 0x6991, 0x71ee, 0xddee, 0xff68, 0xff82, 0xffe1, 0xffe1, 0xffa0, 0xffe1, 0xffe1, 0xf7c3, 0xf7ca, 0x7be5,
0xa4e2, 0xf7a9, 0xffe3, 0xffe0, 0xffe0, 0xffe0, 0xffc0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe1, 0xffe1, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe1, 0xffc1, 0xffc1, 0xffe1, 0xffe1, 0xffe0, 0xffa3, 0xff6a, 0x9be8, 0x69ce, 0x69eb, 0xeeaa, 0xffc4, 0xffc4, 0xffe4, 0xffc4, 0xff67, 0xff0e, 0x7ac7, 0x618e, 0x8ab2, 0xc4ef, 0x9c24, 0xa441, 0xf727, 0xffe3, 0xff89, 0x9b8f, 0x69b0, 0x69cc, 0xd519, 0x8272, 0x698e, 0xabf3, 0xccf7, 0x69d1, 0x69cc, 0xd5cc, 0xffa8, 0xffc2, 0xffe0, 0xffe1, 0xffe1, 0xffc0, 0xf7c0, 0xffe2, 0xf7e8, 0xdf0f,
0xffec, 0xffe8, 0xf7c2, 0xffe0, 0xffc0, 0xffe1, 0xffe0, 0xffc0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffa3, 0xff4c, 0x9baa, 0x6991, 0x7211, 0xee90, 0xffac, 0xff6c, 0xff2c, 0xff2c, 0xf70e, 0xf6d0, 0x7267, 0x69ce, 0xb434, 0xff2d, 0xffa5, 0xffa5, 0xffe5, 0xffa2, 0xff49, 0x936d, 0x69d0, 0x8af1, 0xdd5b, 0x7212, 0x71d1, 0xbc96, 0xa3d2, 0x618e, 0x724b, 0xe66b, 0xf765, 0xffe2, 0xffc0, 0xffa1, 0xffe2, 0xffe0, 0xffe0, 0xffe2, 0xefa5, 0xfff0,
0xffeb, 0xf786, 0xffe2, 0xffe1, 0xffc1, 0xffc1, 0xffc0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffc0, 0xffe4, 0xff6b, 0x9bc8, 0x69ce, 0x61ad, 0xa428, 0xa483, 0xa464, 0xa444, 0x9c23, 0x9c24, 0xe64f, 0x7ae7, 0x6a0c, 0xb450, 0xff88, 0xffe1, 0xffe1, 0xffa1, 0xffe2, 0xf727, 0x9bc9, 0x61e9, 0x61c8, 0x724c, 0x69ae, 0x69cf, 0x8aef, 0x8aed, 0x6a0c, 0x6a26, 0xe689, 0xffc4, 0xffe1, 0xffc0, 0xffe2, 0xffc2, 0xffe0, 0xffe0, 0xf7e0, 0xf7c4, 0xffee,
0xffec, 0xffe8, 0xffe2, 0xf7a0, 0xffe1, 0xffe2, 0xf7a0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe1, 0xffe1, 0xffe1, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffc0, 0xffe0, 0xffe1, 0xffe2, 0xffe0, 0xffa2, 0xeee5, 0x9c02, 0x6a63, 0x7ac6, 0xa466, 0xaca3, 0xb4e4, 0xb4e3, 0xb503, 0xc586, 0xe64c, 0x7ac3, 0x6a06, 0xbccc, 0xffc7, 0xffc0, 0xffe1, 0xffe2, 0xffc1, 0xffa5, 0xbd24, 0xaca7, 0xbccb, 0x9bca, 0x7249, 0x69c9, 0x7209, 0xa3cf, 0xb470, 0xb4aa, 0xef07, 0xffe3, 0xffc0, 0xffe1, 0xffe1, 0xffa0, 0xffe0, 0xffe0, 0xf7c0, 0xffe4, 0xffed,
0xffec, 0xf767, 0xffe3, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe1, 0xffc1, 0xffe1, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe1, 0xffe0, 0xf7a0, 0xffe1, 0xffe0, 0xffe1, 0xffe6, 0xf747, 0xff2b, 0xff2c, 0xf72b, 0xf709, 0xff89, 0xff88, 0xf747, 0xffa9, 0xf72a, 0xacc4, 0xac66, 0xde2a, 0xffa4, 0xffe0, 0xffe2, 0xf7a0, 0xffe1, 0xffa3, 0xffa8, 0xff4c, 0xff11, 0xf6d3, 0xf695, 0xf676, 0xf656, 0xddb3, 0xc4ee, 0xcdcb, 0xffa8, 0xf7c2, 0xffe1, 0xf7a0, 0xffe0, 0xffc0, 0xffe0, 0xffe0, 0xffe0, 0xf7e4, 0xffee,
0xffee, 0xffca, 0xffa2, 0xffe0, 0xffc0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffc0, 0xffe0, 0xffe1, 0xffe0, 0xffe0, 0xffa0, 0xffc2, 0xff83, 0xffc4, 0xffc4, 0xffe4, 0xffe3, 0xffc2, 0xffa2, 0xffc3, 0xffa3, 0xffe5, 0xffa6, 0xff84, 0xffe2, 0xffe0, 0xffc0, 0xffe1, 0xffe1, 0xffc3, 0xf707, 0x8ba0, 0x8324, 0x82e5, 0x7ae4, 0x7ac3, 0x82c3, 0x7ac3, 0x6a21, 0x8340, 0xe6e4, 0xf7a1, 0xffe1, 0xffe0, 0xffe0, 0xffc0, 0xffe0, 0xffc0, 0xffe0, 0xf7c4, 0xffef,
0xa484, 0xff6b, 0xffe4, 0xffc0, 0xffe0, 0xffe0, 0xffc0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffc0, 0xffe0, 0xffe0, 0xffc0, 0xffe0, 0xffe0, 0xffe0, 0xffc0, 0xffe0, 0xffc0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffc0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffc0, 0xffe0, 0xffe0, 0xffc2, 0xffa8, 0xc546, 0xcd4f, 0xd552, 0xddd0, 0xe62f, 0xe5ee, 0xe60e, 0xe62e, 0xe66a, 0xf785, 0xffe3, 0xf7c0, 0xffe0, 0xffe0, 0xffc0, 0xffe0, 0xffc0, 0xffe1, 0xffc6, 0xe6cf,
0x83a5, 0xff8f, 0xf7c4, 0xffe0, 0xffe0, 0xffe0, 0xffc0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe1, 0xffe1, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe2, 0xf765, 0xf6ec, 0xac2d, 0xbcb2, 0xd591, 0xd5b0, 0xd5af, 0xf6b2, 0xe64d, 0xeeea, 0xffa5, 0xffc1, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffc0, 0xffe3, 0xf7aa, 0x7ba7,
0x3160, 0xf771, 0xf7c6, 0xffe1, 0xffe0, 0xffc0, 0xffe0, 0xffc0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe1, 0xffe1, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe1, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe2, 0xffa6, 0xcd88, 0x6a08, 0x61a9, 0x7aa6, 0x72a3, 0x7aa5, 0x6203, 0x6a62, 0xa444, 0xff85, 0xffe1, 0xffc0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xf7c1, 0xffe6, 0xef6c, 0x39a1,
0x0800, 0xad2b, 0xefa8, 0xf7e2, 0xf7c0, 0xffe0, 0xffe1, 0xffc1, 0xffe0, 0xffe0, 0xffe1, 0xffe1, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe1, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffc2, 0xff68, 0xac68, 0x69ad, 0x720f, 0xddcf, 0xff10, 0xe613, 0x722a, 0x71ed, 0xa3ed, 0xff88, 0xffe0, 0xffe0, 0xffc0, 0xffe0, 0xffe0, 0xffe0, 0xffe3, 0xf7a9, 0xa506, 0x0840,
0x0800, 0x39a0, 0xefad, 0xf7e7, 0xffe2, 0xffe0, 0xffc1, 0xffc1, 0xffe0, 0xffe0, 0xffc1, 0xffe1, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffc3, 0xff6a, 0xac6a, 0x71cf, 0x69af, 0xe610, 0xff31, 0xee35, 0x69aa, 0x69af, 0xb431, 0xff68, 0xffe0, 0xffe0, 0xffc0, 0xffe1, 0xffe0, 0xffe2, 0xffe7, 0xef4d, 0x39e0, 0x0020,
0x0000, 0x0000, 0x5ac3, 0xf7ae, 0xf7e4, 0xffe0, 0xffe1, 0xffe1, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffc3, 0xff6a, 0xac49, 0x71ce, 0x69af, 0xbc8f, 0xcd4f, 0xbc50, 0x720a, 0x69ca, 0xbcad, 0xffa7, 0xffe1, 0xffc0, 0xffe1, 0xffc0, 0xffe2, 0xf7a7, 0xffef, 0x62e3, 0x0000, 0x0020,
0x0000, 0x0000, 0x1060, 0xb5ad, 0xffec, 0xf7c5, 0xf7a3, 0xffe3, 0xffe1, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe1, 0xffe1, 0xffe0, 0xffe0, 0xffe0, 0xff82, 0xff88, 0xa465, 0x6a27, 0x6a09, 0x6a64, 0x7262, 0x8b27, 0x8b07, 0x9387, 0xde0a, 0xffa4, 0xffe0, 0xf7c0, 0xffc2, 0xffe4, 0xffc7, 0xffcf, 0xa50b, 0x1060, 0x0820, 0x0000,
0x0000, 0x0020, 0x0000, 0x0840, 0x5ae3, 0xf790, 0xf7aa, 0xf7a5, 0xffe2, 0xffe0, 0xffe1, 0xffe1, 0xffe1, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe0, 0xffe1, 0xffe1, 0xffe0, 0xffe1, 0xffe1, 0xffe1, 0xffe0, 0xffe0, 0xffe0, 0xffc1, 0xffe5, 0xde84, 0xcdc6, 0xde2a, 0xd609, 0xde29, 0xf70c, 0xf6ea, 0xf729, 0xffe8, 0xffc1, 0xffe1, 0xffe4, 0xf7c6, 0xf789, 0xef4e, 0x5ac3, 0x18a0, 0x0000, 0x0000, 0x0001,
0x0020, 0x0000, 0x0000, 0x0000, 0x0000, 0x3180, 0xad48, 0xf78c, 0xf7a8, 0xf7c6, 0xffc5, 0xffc5, 0xffc4, 0xffc4, 0xffc3, 0xffc3, 0xffe3, 0xffc4, 0xffc4, 0xffc4, 0xffc4, 0xffc4, 0xffc4, 0xffc4, 0xffc4, 0xffc4, 0xffc4, 0xffc4, 0xffc4, 0xffc4, 0xffc4, 0xffc4, 0xffe3, 0xffe3, 0xffe3, 0xffe3, 0xffe3, 0xffe3, 0xffe3, 0xffe3, 0xffe3, 0xffe3, 0xffe3, 0xffe3, 0xffe3, 0xffe3, 0xffe3, 0xffe3, 0xffc4, 0xffc4, 0xffc4, 0xffc4, 0xffc4, 0xffc4, 0xffc4, 0xffc4, 0xffc4, 0xffc4, 0xffc4, 0xffc4, 0xffc4, 0xffc4, 0xffc4, 0xffc4, 0xffc4, 0xffc4, 0xffc4, 0xffc4, 0xffc4, 0xffc4, 0xffc4, 0xffc4, 0xffc4, 0xffe5, 0xf7a5, 0xffc7, 0xffc8, 0xf768, 0xffaa, 0xff8a, 0xff89, 0xffa8, 0xffc7, 0xf785, 0xffc4, 0xffe6, 0xf7ca, 0xef6c, 0xad49, 0x41c0, 0x0000, 0x0000, 0x0020, 0x0000, 0x0001,
0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0800, 0x3980, 0x83c5, 0xe70f, 0xffef, 0xffed, 0xffed, 0xffed, 0xffec, 0xffec, 0xffed, 0xffed, 0xffed, 0xffed, 0xffed, 0xffed, 0xffed, 0xffed, 0xffed, 0xffed, 0xffed, 0xffed, 0xffed, 0xffed, 0xffed, 0xffed, 0xffed, 0xffed, 0xffed, 0xffed, 0xffed, 0xffed, 0xffed, 0xffed, 0xffed, 0xffed, 0xffed, 0xffed, 0xffed, 0xffed, 0xffed, 0xffed, 0xffed, 0xffed, 0xffed, 0xffed, 0xffed, 0xffed, 0xffed, 0xffed, 0xffed, 0xffed, 0xffed, 0xffed, 0xffed, 0xffed, 0xffed, 0xffec, 0xffec, 0xffec, 0xffec, 0xffec, 0xffec, 0xffec, 0xffed, 0xffed, 0xffed, 0xffed, 0xffed, 0xffec, 0xffec, 0xffeb, 0xffec, 0xffec, 0xffed, 0xffed, 0xffed, 0xffed, 0xffed, 0xe72c, 0x83c5, 0x3980, 0x0800, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000
  
 };