// We need this header file to use FLASH as storage with PROGMEM directive:
#include <pgmspace.h>

// Icon width and height
const uint16_t windWidth = 56;
const uint16_t windHeight = 15;

const unsigned short  wind[840] PROGMEM={
0x0000, 0x0000, 0x0841, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0861, 0x4208, 0x6b6d, 0x8410, 0x7bcf, 0x5acb, 0x2124, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0020, 0x0000, 0x0000, 0x18e3, 0x5acb, 0x738e, 0x7bcf, 0x7bcf, 0x630c, 0x39c7, 0x0020, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
0x0000, 0x0000, 0x0000, 0x0000, 0x0020, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0841, 0x8410, 0xef7d, 0xffff, 0xb5b6, 0xa514, 0xa514, 0xdedb, 0xffff, 0xce59, 0x39e7, 0x0000, 0x0841, 0x0000, 0x0000, 0x0020, 0x6b4d, 0xd6ba, 0xffff, 0xc638, 0xa534, 0x9cf3, 0xa514, 0xbdf7, 0xef7d, 0xef7d, 0x94b2, 0x2124, 0x0000, 0x0000, 0x0000,
0x0000, 0x0841, 0x0000, 0x0000, 0x0020, 0x0000, 0x0020, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xbdd7, 0xffdf, 0x9cd3, 0x0841, 0x0000, 0x0000, 0x0020, 0x0000, 0x39e7, 0xdefb, 0xf7be, 0x39e7, 0x0000, 0x0020, 0x18e3, 0xce79, 0xffdf, 0x8410, 0x18e3, 0x0000, 0x0000, 0x0000, 0x0000, 0x0020, 0x0020, 0x52aa, 0xe71c, 0xf7be, 0x5acb, 0x0861, 0x0000,
0x0000, 0x0000, 0x0841, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x2945, 0xce59, 0xbdd7, 0x0000, 0x0000, 0x0000, 0x0020, 0x0000, 0x0020, 0x0000, 0x52aa, 0xffff, 0xb596, 0x0000, 0x0000, 0xce79, 0xffff, 0x4a69, 0x0020, 0x0000, 0x0000, 0x0000, 0x0000, 0x0020, 0x0000, 0x0000, 0x0000, 0x0841, 0xd6ba, 0xffff, 0x31a6, 0x0020,
0x0000, 0x0020, 0x0000, 0x0000, 0x0020, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0020, 0x8410, 0xffff, 0x9cd3, 0x0000, 0x2965, 0xe73c, 0xb5b6, 0x0000, 0x0000, 0x0841, 0x0000, 0x0000, 0x0841, 0x0000, 0x0000, 0x0000, 0x0020, 0x0020, 0x630c, 0xffff, 0x94b2, 0x0000,
0x0000, 0x0841, 0x0000, 0x0000, 0x0000, 0x0000, 0x0020, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0020, 0x0020, 0x0000, 0x0020, 0x0000, 0x0000, 0x0000, 0x0861, 0x39e7, 0x9cf3, 0xffff, 0xd69a, 0x0861, 0x0000, 0x0000, 0x0000, 0x0000, 0x0020, 0x0000, 0x0000, 0x0020, 0x0000, 0x0000, 0x0000, 0x0020, 0x0000, 0x0000, 0x0000, 0x6b4d, 0xffff, 0x8c71, 0x0020,
0x0000, 0x0000, 0x0020, 0x0000, 0x0020, 0x0000, 0x2104, 0xffff, 0xffdf, 0xffdf, 0xffdf, 0xffdf, 0xffdf, 0xffdf, 0xffdf, 0xffdf, 0xffdf, 0xffdf, 0xffdf, 0xffdf, 0xffdf, 0xffdf, 0xffdf, 0xffdf, 0xf79e, 0xffdf, 0xffdf, 0xf79e, 0xffff, 0xffdf, 0xffdf, 0xffff, 0xf7be, 0xbdf7, 0x6b4d, 0x0020, 0x0000, 0x0020, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0841, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x2945, 0xef5d, 0xef5d, 0x2965, 0x0000,
0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0020, 0x0020, 0x18e3, 0x2104, 0x2104, 0x2104, 0x2104, 0x2104, 0x2104, 0x2104, 0x2104, 0x2104, 0x2104, 0x2104, 0x2104, 0x2104, 0x2104, 0x2104, 0x2104, 0x2104, 0x18e3, 0x2104, 0x18e3, 0x2124, 0x18e3, 0x2104, 0x18c3, 0x0000, 0x0000, 0x0000, 0x0020, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x2104, 0x8410, 0xf7be, 0xdefb, 0x39e7, 0x0000, 0x0000,
0x18c3, 0xc618, 0xc638, 0xce59, 0xc638, 0xc638, 0xc638, 0xc638, 0xc638, 0xc638, 0xc638, 0xc638, 0xc618, 0xce59, 0xc638, 0xc638, 0xc638, 0xc638, 0xc638, 0xc638, 0xc638, 0xc638, 0xc638, 0xc638, 0xc638, 0xc638, 0xc638, 0xc638, 0xc638, 0xc638, 0xc638, 0xc638, 0xc618, 0xce59, 0xc618, 0xc638, 0xc638, 0xce59, 0xbdf7, 0xc638, 0xce59, 0xc638, 0xc638, 0xc638, 0xc618, 0xc638, 0xc638, 0xce79, 0xef5d, 0xffdf, 0xce79, 0x632c, 0x1082, 0x0000, 0x0000, 0x0000,
0x0841, 0x5acb, 0x528a, 0x528a, 0x528a, 0x528a, 0x528a, 0x52aa, 0x52aa, 0x4a69, 0x5acb, 0x528a, 0x4a69, 0x528a, 0x4a69, 0x52aa, 0x528a, 0x528a, 0x528a, 0x528a, 0x528a, 0x528a, 0x528a, 0x528a, 0x528a, 0x528a, 0x528a, 0x528a, 0x528a, 0x528a, 0x528a, 0x528a, 0x5acb, 0x4a69, 0x52aa, 0x4a69, 0x528a, 0x528a, 0x5acb, 0x4a69, 0x528a, 0x528a, 0x4a69, 0x52aa, 0x4a69, 0x52aa, 0x528a, 0x4a69, 0x3186, 0x1082, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
0x0000, 0x0020, 0x0000, 0x0000, 0x0020, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x18e3, 0x9492, 0x94b2, 0x9492, 0x8c71, 0x8c71, 0x8c71, 0x8c71, 0x8c71, 0x8c71, 0x8c71, 0x8c71, 0x8c71, 0x8c71, 0x8c71, 0x8c71, 0x8c71, 0x8c71, 0x8c71, 0x8c71, 0x8c71, 0x8c71, 0x8c71, 0x94b2, 0x8c51, 0x94b2, 0x8c51, 0x9492, 0x8c71, 0x8430, 0x528a, 0x0841, 0x0000, 0x0000, 0x0020, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
0x0020, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0020, 0x18c3, 0x8410, 0x8410, 0x8430, 0x8c51, 0x8c51, 0x8c51, 0x8c51, 0x8c51, 0x8c51, 0x8c51, 0x8c51, 0x8c51, 0x8c51, 0x8c51, 0x8c51, 0x8c51, 0x8c51, 0x8c51, 0x8c51, 0x8c71, 0x8430, 0x8430, 0x8430, 0x8430, 0x8c71, 0x8410, 0x8c51, 0x8c71, 0x9cd3, 0xf7be, 0xe71c, 0x2124, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0020, 0x0000, 0x0020, 0x0000, 0x0000, 0x0020, 0x0000, 0x0020, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0020, 0x1082, 0x5acb, 0x4228, 0x0000, 0x0000, 0x0000, 0x5aeb, 0xffff, 0xa534, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0020, 0x0000, 0x0000, 0x0000, 0x0020,
0x0000, 0x0020, 0x0000, 0x0020, 0x0000, 0x0000, 0x0000, 0x0020, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0020, 0x0000, 0x0000, 0x0000, 0x0841, 0xce79, 0xffff, 0x7bef, 0x4228, 0x630c, 0xce59, 0xffff, 0x52aa, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
0x0000, 0x0000, 0x0000, 0x0020, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0841, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x10a2, 0x738e, 0xb5b6, 0xd69a, 0xce59, 0x94b2, 0x2965, 0x0000, 0x0020, 0x0020, 0x0000, 0x0000, 0x0000, 0x0020, 0x0020, 0x0000, 0x0000, 0x0000, 0x0020  
  };