// We need this header file to use FLASH as storage with PROGMEM directive:
#include <pgmspace.h>

// Icon width and height
const uint16_t dustWidth = 53;
const uint16_t dustHeight = 53;

const unsigned short  dust[2809] PROGMEM={
0x0800, 0x0000, 0x0000, 0x0000, 0x0000, 0x0020, 0x0020, 0x0000, 0x0000, 0x0000, 0x0000, 0x0020, 0x0020, 0x0020, 0x0820, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0001, 0x0002, 0x0002, 0x0001, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0020, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0860, 0x3164, 0x5268, 0x738c, 0x83ee, 0x8c2f, 0x83ef, 0x738d, 0x5aaa, 0x3165, 0x0840, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0841, 0x0000, 0x0000, 0x0000, 0x0001, 0x0022, 0x0000, 0x0000, 0x0020, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
0x0000, 0x0000, 0x0000, 0x0001, 0x0001, 0x0000, 0x0000, 0x0000, 0x0820, 0x0000, 0x0000, 0x0000, 0x0000, 0x0001, 0x0001, 0x0001, 0x0021, 0x0020, 0x1904, 0x73ae, 0xce58, 0xf77c, 0xffbc, 0xfffc, 0xfffb, 0xfffb, 0xfffb, 0xfffa, 0xfffb, 0xfffc, 0xfffc, 0xf7bc, 0xc616, 0x73ce, 0x2966, 0x0000, 0x0000, 0x0020, 0x0000, 0x0800, 0x1000, 0x0000, 0x0000, 0x0000, 0x0020, 0x0000, 0x0000, 0x0820, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0800, 0x0000, 0x0000, 0x0000, 0x0821, 0x0000, 0x0001, 0x0001, 0x0001, 0x0042, 0x4aaa, 0xb5f6, 0xfffe, 0xfffd, 0xffbb, 0xff9a, 0xff37, 0xee93, 0xf692, 0xee71, 0xee71, 0xee71, 0xe672, 0xeeb3, 0xf715, 0xff77, 0xfffa, 0xfffc, 0xffde, 0xce58, 0x52a9, 0x0020, 0x0000, 0x0000, 0x0000, 0x0000, 0x0020, 0x0020, 0x0020, 0x0020, 0x0861, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
0x0001, 0x0001, 0x0000, 0x0000, 0x0000, 0x0000, 0x0800, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0822, 0x0001, 0x4208, 0xd658, 0xffbb, 0xffda, 0xff56, 0xee72, 0xe62f, 0xee2e, 0xee2d, 0xf64d, 0xf62d, 0xf62c, 0xf62c, 0xf64d, 0xf60c, 0xedeb, 0xe5eb, 0xedec, 0xeded, 0xe5ef, 0xfef6, 0xffdb, 0xfffd, 0xce78, 0x52aa, 0x0020, 0x0020, 0x0020, 0x0020, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
0x0001, 0x0001, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0001, 0x0000, 0x0000, 0x0000, 0x0020, 0x0841, 0xad14, 0xfffd, 0xffda, 0xfed4, 0xfe71, 0xedee, 0xe5ed, 0xf62e, 0xee2d, 0xee0c, 0xee2c, 0xee0c, 0xee0c, 0xee0c, 0xedec, 0xedec, 0xf62c, 0xf60c, 0xedeb, 0xf5ab, 0xfe0e, 0xe5ef, 0xddd0, 0xee94, 0xfffb, 0xfffd, 0xb5b4, 0x1923, 0x0020, 0x0020, 0x0000, 0x0000, 0x0821, 0x0000, 0x0841, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
0x0001, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x39c5, 0xf75b, 0xfffb, 0xfed4, 0xedee, 0xed8b, 0xedab, 0xf5cc, 0xf5ee, 0xf62f, 0xf671, 0xf6d3, 0xff35, 0xff56, 0xff76, 0xff76, 0xff56, 0xff55, 0xff34, 0xf6d2, 0xee50, 0xedee, 0xedac, 0xe5ac, 0xdd8b, 0xe5ac, 0xe5ef, 0xf6b3, 0xfffb, 0xef5b, 0x4a8a, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0001, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0020, 0x632a, 0xffbb, 0xffda, 0xee72, 0xe5ad, 0xedcc, 0xf5ec, 0xf5ec, 0xf62e, 0xfeb2, 0xff34, 0xff36, 0xff78, 0xff78, 0xff79, 0xf779, 0xf779, 0xff99, 0xff79, 0xff58, 0xff58, 0xff77, 0xff55, 0xfef2, 0xf66f, 0xe5ed, 0xe58b, 0xe56b, 0xedac, 0xedef, 0xff9a, 0xffbd, 0x738e, 0x0021, 0x0000, 0x0000, 0x0801, 0x0001, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0001, 0x0000, 0x0020, 0x0020, 0x6b6b, 0xfffd, 0xff78, 0xe60f, 0xe5ac, 0xedab, 0xedcd, 0xee51, 0xf6d4, 0xff56, 0xff77, 0xff57, 0xff57, 0xff58, 0xff78, 0xff78, 0xff78, 0xff58, 0xff59, 0xff59, 0xff39, 0xff39, 0xff38, 0xff36, 0xff55, 0xff55, 0xff14, 0xf650, 0xed8b, 0xed49, 0xed6a, 0xed8d, 0xff17, 0xffde, 0x83f0, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0020, 0x0000, 0x0000, 0x0000,
0x0800, 0x0000, 0x0000, 0x0000, 0x0001, 0x0021, 0x0000, 0x0020, 0x5aea, 0xfffd, 0xff79, 0xdd8e, 0xe5ab, 0xedaa, 0xedcc, 0xf691, 0xf6f5, 0xff37, 0xff78, 0xff57, 0xff37, 0xff37, 0xff57, 0xff37, 0xff37, 0xff37, 0xff38, 0xff38, 0xff38, 0xff38, 0xff18, 0xff18, 0xff37, 0xff36, 0xff36, 0xff36, 0xff14, 0xfe91, 0xfdcc, 0xed29, 0xed2a, 0xe54c, 0xff18, 0xffdd, 0x6b4d, 0x0021, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
0x0000, 0x0000, 0x0820, 0x0000, 0x0000, 0x0020, 0x0020, 0x3a07, 0xffbd, 0xff59, 0xe58e, 0xed8b, 0xed69, 0xf5cc, 0xf671, 0xff15, 0xff36, 0xff56, 0xff36, 0xff35, 0xff15, 0xff35, 0xff36, 0xff36, 0xff16, 0xff16, 0xff17, 0xff17, 0xf717, 0xf716, 0xf736, 0xf716, 0xf716, 0xff16, 0xff36, 0xff35, 0xff36, 0xff36, 0xfe93, 0xf5cf, 0xed2a, 0xf58b, 0xdd2c, 0xff16, 0xfffd, 0x4a69, 0x0000, 0x0020, 0x0020, 0x0000, 0x0020, 0x0020, 0x0000,
0x0020, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x10c2, 0xe71b, 0xffbc, 0xdd70, 0xed4b, 0xf56a, 0xf56a, 0xfe90, 0xff35, 0xfef5, 0xf6f4, 0xff14, 0xff14, 0xfef4, 0xff14, 0xff14, 0xff14, 0xfef4, 0xfef5, 0xfef5, 0xfef5, 0xff15, 0xf714, 0xf714, 0xf714, 0xf714, 0xf6f5, 0xff16, 0xff15, 0xfed4, 0xf6d5, 0xf716, 0xfef5, 0xfe93, 0xf58b, 0xed29, 0xe549, 0xdd8d, 0xff9a, 0xf7bd, 0x2124, 0x0020, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
0x0000, 0x0000, 0x0821, 0x0001, 0x0000, 0x0020, 0xb573, 0xfffc, 0xe5d1, 0xe52c, 0xf549, 0xfd8a, 0xfe70, 0xfe92, 0xfed3, 0xf6f3, 0xfed3, 0xfed3, 0xfed3, 0xfed3, 0xfed3, 0xfed3, 0xfed3, 0xfed3, 0xfed2, 0xfed2, 0xfed2, 0xfed2, 0xfed2, 0xfed2, 0xfed2, 0xf6d3, 0xf6d3, 0xf6d3, 0xfeb3, 0xfe93, 0xfed3, 0xfef3, 0xfef3, 0xfeb1, 0xfe90, 0xed8b, 0xed6a, 0xd50a, 0xd590, 0xffbb, 0xc637, 0x0020, 0x0020, 0x0000, 0x0000, 0x0000, 0x0020,
0x0000, 0x0000, 0x0001, 0x0001, 0x0040, 0x4a47, 0xfffc, 0xf694, 0xe54c, 0xed4a, 0xf549, 0xfdcc, 0xfe71, 0xfeb2, 0xf6d2, 0xf6b1, 0xfeb2, 0xfeb2, 0xfeb2, 0xfeb2, 0xfeb2, 0xfeb2, 0xfeb2, 0xfeb1, 0xfeb0, 0xfeb0, 0xfeb0, 0xfeb0, 0xfeb0, 0xfeb0, 0xfeb1, 0xfeb1, 0xf6b1, 0xf6b1, 0xfe91, 0xfe91, 0xfeb1, 0xfeb1, 0xf6b1, 0xf6b0, 0xfe90, 0xfe4e, 0xe529, 0xe54a, 0xdd4c, 0xee53, 0xfffd, 0x5aeb, 0x0000, 0x0020, 0x0020, 0x0000, 0x0000,
0x0800, 0x0000, 0x0000, 0x0020, 0x0000, 0xde78, 0xff99, 0xdd4d, 0xed4a, 0xed49, 0xf5ab, 0xfe4e, 0xf66f, 0xf68f, 0xee6f, 0xfed0, 0xf690, 0xf690, 0xf690, 0xf690, 0xf690, 0xf690, 0xf690, 0xfe90, 0xf690, 0xf690, 0xf690, 0xf68f, 0xf68f, 0xf68f, 0xf68f, 0xf68f, 0xfe6f, 0xfe8f, 0xf68e, 0xf68e, 0xf66e, 0xf66e, 0xf68f, 0xf6af, 0xf68f, 0xfe6f, 0xf56a, 0xf509, 0xe4e9, 0xdd2c, 0xff59, 0xef5b, 0x1081, 0x0000, 0x0000, 0x0000, 0x0000,
0x0800, 0x0000, 0x0021, 0x0020, 0x5aeb, 0xffdc, 0xf631, 0xe50a, 0xed28, 0xed48, 0xf5eb, 0xfe8e, 0xf66e, 0xf66e, 0xfeaf, 0xf62d, 0xf66e, 0xf66e, 0xf66e, 0xf66e, 0xf66e, 0xf66d, 0xf64d, 0xf64d, 0xf64d, 0xf64e, 0xf64e, 0xf64e, 0xf66e, 0xf64e, 0xf64d, 0xf64d, 0xfe4d, 0xfe6d, 0xf66d, 0xf66c, 0xf66d, 0xf66d, 0xf66e, 0xee4e, 0xf64e, 0xfe4e, 0xfe0c, 0xf529, 0xece7, 0xdcc9, 0xe5f1, 0xffbb, 0x734c, 0x0020, 0x0000, 0x0020, 0x0000,
0x0001, 0x0000, 0x0000, 0x0000, 0xce77, 0xff99, 0xdd6c, 0xe508, 0xed28, 0xed48, 0xfe4b, 0xfe4c, 0xf60d, 0xfe2d, 0xfe4c, 0xf60b, 0xfe4c, 0xfe4d, 0xf62c, 0xf60b, 0xfe4c, 0xf62b, 0xf5ea, 0xfe4b, 0xfe2b, 0xf60b, 0xf60b, 0xfe2c, 0xf62c, 0xfe2c, 0xfe4c, 0xf62c, 0xf62b, 0xf64c, 0xf64c, 0xf60b, 0xfe2c, 0xfe2c, 0xf62d, 0xf62e, 0xfe0d, 0xfdeb, 0xfe0b, 0xf589, 0xed07, 0xdce8, 0xcd0c, 0xff38, 0xeed8, 0x0820, 0x0001, 0x0000, 0x0000,
0x0001, 0x0000, 0x0000, 0x3185, 0xffbc, 0xeeb4, 0xd4e9, 0xed48, 0xed28, 0xf589, 0xf5e9, 0xf60a, 0xfe0c, 0xedab, 0xfe6d, 0xf5eb, 0xee0c, 0xf62d, 0xf62c, 0xfe4c, 0xf62b, 0xf5eb, 0xfe2b, 0xfe0a, 0xfe2b, 0xfe0a, 0xf60a, 0xfe0b, 0xf5ea, 0xf5ca, 0xf5eb, 0xf60b, 0xf62c, 0xee0b, 0xf62d, 0xf62d, 0xedca, 0xf5eb, 0xf62d, 0xedec, 0xfe0b, 0xfdea, 0xfdea, 0xf588, 0xed27, 0xe508, 0xd4ca, 0xee12, 0xffdc, 0x4a28, 0x0001, 0x0021, 0x0000,
0x0000, 0x0000, 0x0021, 0x83ef, 0xff9b, 0xdd50, 0xdceb, 0xed09, 0xed29, 0xf5cb, 0xf5ca, 0xf5c9, 0xfe0b, 0xfdeb, 0xe5ab, 0xf64e, 0xc50a, 0x9ba5, 0x9343, 0x8b01, 0x9b83, 0xd529, 0xedeb, 0xf60b, 0xedca, 0xf60a, 0xf60b, 0xf5ea, 0xf60b, 0xfe4c, 0xf62b, 0xe58a, 0xa383, 0x9322, 0x8ae3, 0x9b85, 0xc4c8, 0xe5cb, 0xee2b, 0xee0a, 0xf5c9, 0xfdc9, 0xfda9, 0xf569, 0xf528, 0xf508, 0xe488, 0xdcec, 0xff7a, 0xa4d2, 0x0001, 0x0001, 0x0000,
0x0000, 0x0000, 0x0000, 0xd658, 0xfeb7, 0xdcac, 0xeceb, 0xece9, 0xed2a, 0xed6a, 0xfe0b, 0xf5c9, 0xf5aa, 0xf5cb, 0xb466, 0x8322, 0x8b44, 0x9365, 0x9364, 0x9ba4, 0x9ba4, 0xbc87, 0xf60c, 0xf62c, 0xedea, 0xf60b, 0xf60a, 0xedca, 0xedca, 0xf60a, 0xedc9, 0xd507, 0xabc4, 0xa3a5, 0x9b86, 0x9b85, 0x9323, 0x82e0, 0xa403, 0xe5ea, 0xeda9, 0xfdc9, 0xf589, 0xfd6a, 0xf528, 0xf4e8, 0xec88, 0xdc8a, 0xf696, 0xe6fa, 0x0041, 0x0001, 0x0000,
0x0000, 0x0020, 0x0841, 0xff9c, 0xfe73, 0xe4c9, 0xeca8, 0xf509, 0xfd4a, 0xf56a, 0xed88, 0xedca, 0xd509, 0x9363, 0x8b43, 0x9384, 0x9b85, 0x9364, 0xa3e6, 0xac06, 0xc4c8, 0xedec, 0xedeb, 0xedca, 0xf5ca, 0xedc9, 0xf5c9, 0xfe0a, 0xf5ea, 0xf5e9, 0xfe2a, 0xfe4c, 0xc508, 0xa406, 0xa385, 0xaba6, 0xaba5, 0xa3a5, 0x9385, 0x8302, 0xccc8, 0xedaa, 0xf5aa, 0xf569, 0xf507, 0xf4e7, 0xeca8, 0xdc8a, 0xee34, 0xfffe, 0x1904, 0x0001, 0x0000,
0x0000, 0x0000, 0x39a7, 0xffdd, 0xe5af, 0xdc88, 0xece8, 0xfd09, 0xf4e8, 0xf528, 0xed68, 0xeda9, 0x9343, 0x9364, 0x9bc5, 0x9be5, 0x9ba4, 0xcd0a, 0xedcd, 0xfe4e, 0xfe4d, 0xedeb, 0xf60b, 0xf5ea, 0xf5ea, 0xf5a9, 0xf5a9, 0xf5c9, 0xf5a9, 0xf5a8, 0xf5a9, 0xf5ca, 0xee2c, 0xf68e, 0xf62e, 0xccc9, 0xaba5, 0xa385, 0x9bc6, 0x9bc6, 0x9343, 0xcce9, 0xed8a, 0xf569, 0xf507, 0xf508, 0xeca8, 0xd46a, 0xcd30, 0xffbd, 0x4aab, 0x0021, 0x0000,
0x0000, 0x0000, 0x6b6e, 0xf79d, 0xcd91, 0xcceb, 0xe4c8, 0xed07, 0xf528, 0xfd89, 0xf548, 0xe528, 0x8ae1, 0xa3e6, 0x9be5, 0xcd29, 0xfe6e, 0xf60c, 0xf5ec, 0xedaa, 0xedca, 0xf5ea, 0xeda9, 0xeda9, 0xf5a9, 0xf5a9, 0xf5a9, 0xf5a9, 0xf5a9, 0xfdea, 0xfdca, 0xed89, 0xeda9, 0xedca, 0xedcb, 0xf60d, 0xfe4e, 0xdd4a, 0xac06, 0x9ba4, 0x9364, 0xc4c9, 0xe56a, 0xed69, 0xf527, 0xf507, 0xe468, 0xd48b, 0xcd30, 0xf73b, 0x8430, 0x0021, 0x0000,
0x0800, 0x0000, 0x7c30, 0xef9d, 0xe6d9, 0xd5b2, 0xbc28, 0xe4e8, 0xed28, 0xed28, 0xfd28, 0xfd69, 0xe56a, 0xe5cc, 0xf66e, 0xee0c, 0xedca, 0xed89, 0xeda9, 0xf5ca, 0xf5a9, 0xf589, 0xf5a9, 0xf5a9, 0xfda9, 0xf588, 0xf589, 0xfda9, 0xf589, 0xf569, 0xf589, 0xfda9, 0xf589, 0xf589, 0xedaa, 0xed8a, 0xedaa, 0xf60c, 0xfe4d, 0xee0d, 0xd54b, 0xe5ac, 0xedab, 0xed69, 0xed28, 0xdcc9, 0xc42a, 0xd4ef, 0xfeb7, 0xf71a, 0x94b3, 0x0021, 0x0000,
0x0000, 0x0000, 0x94f2, 0xdf1b, 0xe75d, 0xef3c, 0xe656, 0xbc8c, 0xccaa, 0xe4e9, 0xfd48, 0xf547, 0xed89, 0xedaa, 0xed8a, 0xf5aa, 0xf589, 0xfd88, 0xfd88, 0xf588, 0xfd88, 0xfd88, 0xfd88, 0xfd68, 0xfd68, 0xfd68, 0xfd69, 0xfd69, 0xfd69, 0xfd69, 0xfd69, 0xfd69, 0xf569, 0xfd89, 0xf569, 0xfd89, 0xf589, 0xf5a9, 0xed89, 0xed89, 0xed89, 0xed89, 0xf5a9, 0xe549, 0xccc9, 0xbc8c, 0xee57, 0xfedb, 0xfef9, 0xe698, 0xb596, 0x0000, 0x0000,
0x0040, 0x0020, 0x9cf2, 0xef7c, 0xdefb, 0xef1c, 0xf71b, 0xff1a, 0xd570, 0xc48a, 0xe4e9, 0xf549, 0xed69, 0xf58a, 0xed4a, 0xed6b, 0xed4a, 0xed4a, 0xed4a, 0xed4a, 0xed4a, 0xed4a, 0xed4a, 0xed4a, 0xed6a, 0xed6a, 0xed6b, 0xed6b, 0xed6b, 0xed6b, 0xed4b, 0xed6b, 0xed6b, 0xed4a, 0xed4a, 0xf56a, 0xed69, 0xe548, 0xf589, 0xf5a9, 0xf58a, 0xf56a, 0xdce9, 0xc4aa, 0xcd90, 0xf719, 0xeefb, 0xf6fb, 0xf6b8, 0xeed9, 0xad75, 0x0021, 0x0000,
0x0000, 0x0000, 0xa4d3, 0xeeda, 0xbcf1, 0xee35, 0xff1a, 0xef1b, 0xf75b, 0xe6d7, 0xbcad, 0xcc8a, 0xed0a, 0xf52a, 0xf58c, 0xccaa, 0xc48b, 0xbc8c, 0xbc8c, 0xbc8c, 0xbc8c, 0xbc8c, 0xbc8c, 0xbc8c, 0xbc8b, 0xbc8b, 0xb48b, 0xb48c, 0xb48c, 0xb48c, 0xb48c, 0xb48b, 0xbc8b, 0xbc8b, 0xbc8a, 0xbc49, 0xc4c9, 0xd509, 0xed48, 0xf528, 0xed0a, 0xe4ec, 0xc48e, 0xeeb9, 0xef3c, 0xef5c, 0xff5a, 0xe655, 0xb48e, 0xe677, 0xad75, 0x0041, 0x0000,
0x0841, 0x0000, 0x9451, 0xff1b, 0xc46d, 0xc42b, 0xcd11, 0xff1a, 0xf77c, 0xef5b, 0xff7b, 0xddb2, 0xc429, 0xdcaa, 0xd4cb, 0xedb0, 0xffdb, 0xffdc, 0xffdc, 0xffdc, 0xffdc, 0xffdc, 0xffdc, 0xffdc, 0xfffc, 0xfffc, 0xfffc, 0xfffc, 0xfffc, 0xfffc, 0xfffc, 0xfffc, 0xffdb, 0xffbb, 0xfffc, 0xfffb, 0xff98, 0xee10, 0xd4a8, 0xed4b, 0xcc6b, 0xe593, 0xff5c, 0xff1d, 0xf75d, 0xf71a, 0xc4ee, 0xabe9, 0xac2c, 0xf6d8, 0xad55, 0x0000, 0x0000,
0x0801, 0x0000, 0x738e, 0xff5a, 0xd4cd, 0xd46a, 0xd48b, 0xc46b, 0xee54, 0xff7b, 0xf77e, 0xffdf, 0xf718, 0xbcce, 0xbbea, 0xe592, 0xffbd, 0xffde, 0xffde, 0xffde, 0xffde, 0xffde, 0xffde, 0xffde, 0xffde, 0xffde, 0xffde, 0xfffe, 0xfffe, 0xfffe, 0xfffe, 0xfffe, 0xfffe, 0xffff, 0xffff, 0xffdf, 0xfffe, 0xff38, 0xb44a, 0xc4cd, 0xff19, 0xffbd, 0xff5d, 0xff1b, 0xf655, 0xbc2a, 0xd448, 0xd469, 0xcccd, 0xfef9, 0x9471, 0x0000, 0x0000,
0x0800, 0x0821, 0x5acb, 0xf719, 0xdd0e, 0xd428, 0xe468, 0xe4ca, 0xcccb, 0xcd4f, 0xff3b, 0xffbe, 0xfffe, 0xfffc, 0xd551, 0xe5d4, 0xffbe, 0xf7df, 0xf7df, 0xf7df, 0xf7df, 0xf7df, 0xf7df, 0xffdf, 0xffdf, 0xffdf, 0xffdf, 0xffdf, 0xffdf, 0xffdf, 0xffdf, 0xffdf, 0xf7df, 0xf7df, 0xf7df, 0xf7ff, 0xffff, 0xef1b, 0xbd11, 0xffdb, 0xfffe, 0xff7c, 0xff3a, 0xd530, 0xc409, 0xecca, 0xec67, 0xdc27, 0xc48c, 0xf6f8, 0x736d, 0x0000, 0x0020,
0x0020, 0x0000, 0x2185, 0xf75b, 0xe570, 0xd448, 0xec88, 0xec87, 0xecc8, 0xe50b, 0xd4ed, 0xee55, 0xffdd, 0xfffe, 0xe698, 0xde57, 0xffbd, 0xefde, 0xf7be, 0xf7be, 0xf7df, 0xf7df, 0xf7df, 0xf7bf, 0xf7df, 0xf7df, 0xf7df, 0xf7df, 0xffbf, 0xffdf, 0xffdf, 0xffdf, 0xffdf, 0xffff, 0xffdf, 0xff9f, 0xf7bf, 0xef3d, 0xcdf6, 0xffdd, 0xffbc, 0xf675, 0xccab, 0xd4a9, 0xe50a, 0xece9, 0xec67, 0xdc28, 0xdd0e, 0xff5a, 0x4a08, 0x0000, 0x0000,
0x0040, 0x0020, 0x0041, 0xef1b, 0xe5d2, 0xd449, 0xe447, 0xf486, 0xf4c8, 0xf4e9, 0xecea, 0xd4cc, 0xcdb1, 0xffbb, 0xf6f9, 0xd616, 0xf7bd, 0xefbe, 0xefbe, 0xefde, 0xefde, 0xefde, 0xf7df, 0xf7df, 0xf7be, 0xf7be, 0xf7bf, 0xf7bf, 0xf7bf, 0xf7bf, 0xffbf, 0xffbf, 0xff9e, 0xff9e, 0xff7d, 0xff9e, 0xffdf, 0xe6fb, 0xd616, 0xff7a, 0xd530, 0xc449, 0xe4a9, 0xf529, 0xed09, 0xecc8, 0xe426, 0xd408, 0xe5b1, 0xff3a, 0x1061, 0x0000, 0x0000,
0x0020, 0x0000, 0x0001, 0xad35, 0xf696, 0xc46a, 0xdc67, 0xec66, 0xf4c8, 0xf4c8, 0xece8, 0xf56a, 0xd4c9, 0xcccc, 0xe572, 0xe5f6, 0xff7d, 0xefbe, 0xef9e, 0xefbe, 0xefbe, 0xefbe, 0xefbe, 0xefbe, 0xefbe, 0xefbe, 0xf7be, 0xf7be, 0xf7be, 0xf7be, 0xf7be, 0xffbe, 0xff9e, 0xff9e, 0xff9d, 0xf77d, 0xffde, 0xeefa, 0xbcce, 0xc44a, 0xdc8a, 0xece9, 0xfd08, 0xf4e7, 0xf509, 0xe488, 0xe428, 0xcc2a, 0xee77, 0xbdb6, 0x0020, 0x0000, 0x0000,
0x0020, 0x0000, 0x0022, 0x62ec, 0xeeb8, 0xdd91, 0xbc08, 0xcc27, 0xd428, 0xdcaa, 0xe4e9, 0xed4a, 0xed6a, 0xdceb, 0xc44d, 0xd533, 0xff7d, 0xf79e, 0xef9e, 0xef9e, 0xef9e, 0xef9e, 0xef9e, 0xefbe, 0xef9e, 0xef9d, 0xf79d, 0xf79e, 0xf79e, 0xf79e, 0xf79e, 0xf79e, 0xf77e, 0xf77d, 0xf79e, 0xf7be, 0xf7bd, 0xe6b7, 0xabea, 0xd48b, 0xed0b, 0xecca, 0xecc9, 0xe4c9, 0xcc69, 0xbc08, 0xbba8, 0xccae, 0xeed9, 0x738e, 0x0020, 0x0000, 0x0000,
0x0040, 0x0000, 0x0001, 0x1083, 0xef1c, 0xe6b8, 0xf6d8, 0xe635, 0xdd92, 0xd550, 0xc4cc, 0xb46a, 0xc4ca, 0xcccc, 0xb42c, 0xd593, 0xf77c, 0xef7d, 0xef7d, 0xef7e, 0xef7e, 0xef7e, 0xef7e, 0xef7e, 0xef7e, 0xef7e, 0xef7e, 0xef9e, 0xef9e, 0xef9e, 0xef9e, 0xef9e, 0xefbf, 0xe7bf, 0xe77e, 0xe77d, 0xf79d, 0xeeb8, 0x9b89, 0xc44b, 0xb40a, 0xb3ea, 0xbc6c, 0xc4ce, 0xc531, 0xe677, 0xff1a, 0xd637, 0xef3c, 0x2945, 0x0000, 0x0000, 0x0000,
0x0000, 0x0000, 0x0001, 0x0000, 0xa514, 0xd69a, 0xe71b, 0xef1b, 0xf6fa, 0xfefa, 0xff7a, 0xff59, 0xff17, 0xf6d6, 0xddd3, 0xd5d4, 0xf75c, 0xef7d, 0xef7d, 0xef7d, 0xef5e, 0xef7e, 0xef7e, 0xef5e, 0xef5e, 0xef7e, 0xef7e, 0xef7e, 0xef7e, 0xef7e, 0xef7e, 0xe79f, 0xdf7e, 0xe7bf, 0xefbf, 0xef7d, 0xef3c, 0xe6b9, 0xbcf1, 0xfe97, 0xff7a, 0xff39, 0xff39, 0xff5a, 0xef1a, 0xe6fb, 0xdedb, 0xdedb, 0xb596, 0x0000, 0x0000, 0x0000, 0x0000,
0x0000, 0x0020, 0x0000, 0x0000, 0x3185, 0xe73c, 0xd659, 0xeefc, 0xf73d, 0xf71c, 0xf73c, 0xff7c, 0xf77c, 0xffdd, 0xf6d9, 0xcdd5, 0xf75c, 0xef5d, 0xef5d, 0xef5e, 0xef5e, 0xef5e, 0xef5e, 0xef5e, 0xef5e, 0xef5e, 0xef5e, 0xef5e, 0xef5e, 0xef5e, 0xef5e, 0xef5e, 0xe79f, 0xe75e, 0xef3d, 0xf77e, 0xf77e, 0xdedb, 0xce18, 0xffff, 0xffde, 0xffdd, 0xff3a, 0xff19, 0xf75b, 0xef3b, 0xce37, 0xe71b, 0x4228, 0x0000, 0x0000, 0x0000, 0x0000,
0x0000, 0x0000, 0x0000, 0x0000, 0x0020, 0x9cf3, 0xe6db, 0xbd34, 0xb4b3, 0xcd34, 0xdd94, 0xee36, 0xf6f8, 0xff5a, 0xee97, 0xde17, 0xf73d, 0xef5d, 0xef5d, 0xef5d, 0xef5e, 0xef5e, 0xef5e, 0xef5e, 0xef5e, 0xef5e, 0xef5e, 0xef5e, 0xef5e, 0xef5e, 0xef5e, 0xef5e, 0xe77e, 0xe75e, 0xef3d, 0xf73d, 0xef3e, 0xde9b, 0xd617, 0xffbc, 0xff19, 0xee55, 0xe5d2, 0xd571, 0xb4d0, 0xacf2, 0xdeb9, 0xb595, 0x0000, 0x0020, 0x0000, 0x0000, 0x0000,
0x0000, 0x0000, 0x0021, 0x0000, 0x0000, 0x2103, 0xde99, 0xddd6, 0xbbcc, 0xcbeb, 0xd409, 0xcbe7, 0xc3e7, 0xbc08, 0xabeb, 0xc532, 0xf73c, 0xef5e, 0xef5e, 0xef5e, 0xef5d, 0xef5d, 0xef5e, 0xe75e, 0xe75e, 0xe75d, 0xe77d, 0xe77d, 0xe77d, 0xe77d, 0xe77d, 0xe77d, 0xe75d, 0xe75e, 0xef5e, 0xef5e, 0xf75d, 0xe657, 0xabca, 0xbbe8, 0xd48a, 0xcc28, 0xdc49, 0xd429, 0xbc2c, 0xddb4, 0xeedb, 0x2965, 0x0000, 0x0020, 0x0000, 0x0000, 0x0000,
0x0000, 0x0000, 0x0000, 0x0001, 0x0000, 0x0000, 0x734c, 0xf6d9, 0xe511, 0xd3c9, 0xe3e7, 0xec26, 0xf486, 0xecc9, 0xc42b, 0xd553, 0xef3c, 0xe75e, 0xef5e, 0xef5d, 0xef5d, 0xef5d, 0xef5d, 0xef5d, 0xe75d, 0xe75d, 0xe75d, 0xe77d, 0xe77c, 0xe77c, 0xe77c, 0xe77c, 0xe77d, 0xef5d, 0xe73e, 0xe73d, 0xf73c, 0xf676, 0xbbc7, 0xf509, 0xeca7, 0xf4a8, 0xe427, 0xd429, 0xd4ef, 0xf6b9, 0x83ae, 0x0821, 0x0000, 0x0000, 0x0000, 0x0020, 0x0000,
0x0000, 0x0020, 0x0000, 0x0001, 0x0001, 0x0000, 0x0841, 0xad14, 0xee99, 0xcccf, 0xd3e7, 0xe405, 0xec66, 0xdc47, 0xd46c, 0xcd32, 0xef1b, 0xe75e, 0xef7e, 0xef5d, 0xef3d, 0xef5d, 0xef5d, 0xef3d, 0xef3d, 0xef3d, 0xef3d, 0xef5d, 0xef5d, 0xe75c, 0xe75c, 0xe75c, 0xef5c, 0xe73c, 0xef3d, 0xef5d, 0xef1b, 0xee76, 0xbbe8, 0xecc8, 0xf486, 0xe446, 0xd449, 0xccae, 0xe679, 0xbd97, 0x0801, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0021, 0x0000, 0x10a3, 0xce38, 0xe657, 0xccac, 0xcbe6, 0xdc05, 0xe447, 0xdc4a, 0xbbcb, 0xee77, 0xde78, 0xde57, 0xe677, 0xe677, 0xe677, 0xe657, 0xe677, 0xe678, 0xe678, 0xe678, 0xe678, 0xe678, 0xe677, 0xe657, 0xe677, 0xe656, 0xee97, 0xe657, 0xe657, 0xee77, 0xbc4c, 0xd428, 0xec67, 0xe467, 0xcc07, 0xc48c, 0xee56, 0xd67a, 0x1905, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
0x0000, 0x0000, 0x0000, 0x0020, 0x0000, 0x0000, 0x0020, 0x0000, 0x1924, 0xd698, 0xe676, 0xc4cd, 0xcc08, 0xdbc7, 0xe3c7, 0xd366, 0xa2c5, 0x9ac5, 0x9ac5, 0x9ae5, 0x9ac4, 0x92a4, 0x9ac4, 0x9b05, 0x92e5, 0x92e5, 0x92e5, 0x92c6, 0x9ac6, 0x9aa5, 0xa2a5, 0xa2a5, 0x9ac5, 0x92c5, 0x9b06, 0x9ac6, 0xa2c5, 0xbb66, 0xe427, 0xe447, 0xc408, 0xc4ad, 0xe656, 0xe6b9, 0x3185, 0x0000, 0x0840, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
0x0000, 0x0000, 0x0000, 0x0000, 0x0820, 0x0000, 0x0820, 0x0021, 0x0000, 0x1923, 0xce78, 0xde76, 0xccad, 0xd409, 0xe3e7, 0xe3c6, 0xe408, 0xe429, 0xe449, 0xec48, 0xec88, 0xeca8, 0xe4a8, 0xdc67, 0xdca8, 0xdca9, 0xdca9, 0xe489, 0xe489, 0xec6a, 0xec69, 0xec69, 0xec89, 0xe468, 0xe469, 0xe449, 0xe428, 0xe429, 0xe449, 0xcbe8, 0xccef, 0xe677, 0xde78, 0x3185, 0x0000, 0x0020, 0x0000, 0x0020, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
0x0800, 0x0800, 0x0000, 0x0000, 0x0020, 0x0000, 0x0000, 0x0000, 0x0000, 0x0020, 0x1103, 0xb5b5, 0xeed8, 0xcd51, 0xc40a, 0xd3e8, 0xdbc8, 0xebe8, 0xec07, 0xec06, 0xec46, 0xf486, 0xf4e7, 0xece7, 0xe4e7, 0xe4e7, 0xe4e8, 0xe4e8, 0xece8, 0xecc8, 0xf4a8, 0xf4a8, 0xec87, 0xec87, 0xf466, 0xec46, 0xdc27, 0xd429, 0xcc2b, 0xd531, 0xe678, 0xc5d7, 0x2104, 0x0000, 0x0000, 0x0041, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
0x0000, 0x0000, 0x0020, 0x0020, 0x0000, 0x0000, 0x0000, 0x0820, 0x0000, 0x0000, 0x0000, 0x0881, 0x842f, 0xeef9, 0xe655, 0xd4ee, 0xcbe9, 0xd3c8, 0xdbe8, 0xec28, 0xec47, 0xec46, 0xec65, 0xec86, 0xeca6, 0xecc6, 0xe4c7, 0xe4c7, 0xe4a7, 0xeca6, 0xec86, 0xec86, 0xec87, 0xdc06, 0xe426, 0xe468, 0xc409, 0xd4ef, 0xddb3, 0xf6d9, 0x9c92, 0x1083, 0x0000, 0x0000, 0x0000, 0x0000, 0x0021, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
0x0022, 0x0000, 0x0000, 0x0020, 0x0000, 0x0020, 0x0000, 0x0000, 0x0821, 0x0000, 0x0800, 0x0000, 0x0000, 0x4a48, 0xbdd5, 0xe6b8, 0xddd3, 0xccef, 0xbc2a, 0xbbe8, 0xcbe7, 0xdc07, 0xe406, 0xe406, 0xec07, 0xec27, 0xe427, 0xe427, 0xe426, 0xe426, 0xe426, 0xdc26, 0xcba7, 0xd42a, 0xc42b, 0xbc6d, 0xd5f5, 0xde99, 0xd637, 0x5269, 0x0820, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0021, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
0x0001, 0x0021, 0x0000, 0x0000, 0x0020, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0800, 0x0000, 0x0000, 0x0000, 0x0861, 0x632b, 0xd677, 0xde97, 0xe655, 0xdd71, 0xccad, 0xcc2a, 0xcbe9, 0xcbc9, 0xd3e9, 0xd3e9, 0xcbe9, 0xcbe8, 0xcbe8, 0xcc08, 0xcc08, 0xcc09, 0xd4ad, 0xdd51, 0xddf5, 0xeeda, 0xce79, 0x6b8e, 0x0862, 0x0000, 0x0000, 0x0000, 0x0000, 0x0020, 0x0000, 0x0020, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0840, 0x5269, 0xad33, 0xe699, 0xeed9, 0xe657, 0xddd5, 0xddb4, 0xcd32, 0xcd52, 0xcd52, 0xc531, 0xcd52, 0xd5b3, 0xde14, 0xe635, 0xeeb9, 0xe6b9, 0xb554, 0x5aca, 0x1082, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0020, 0x18c3, 0x4a49, 0x8c10, 0xbd75, 0xce38, 0xef1b, 0xeefb, 0xe6da, 0xe6fb, 0xe6fb, 0xd679, 0xb575, 0x9491, 0x5289, 0x2104, 0x0000, 0x0000, 0x0020, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0820, 0x0840, 0x0820, 0x0820, 0x1882, 0x20e3, 0x20c2, 0x1061, 0x0820, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0021, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0820, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0020, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0020, 0x0000, 0x0000, 0x0020, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000
};
