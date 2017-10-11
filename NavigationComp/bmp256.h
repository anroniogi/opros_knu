#pragma once

#define BYTE unsigned char
#define WORD unsigned short
#define DWORD unsigned int
#define LONG unsigned int

#pragma pack( push, packing_alignments, 1 )

struct BMP_FILE_HEAD {
	WORD bfType;
	DWORD  bfSize;
	WORD bfReserved1;
	WORD bfReserved2;
	DWORD  bfOffBits;
};

struct BMP_INFO_HEAD{
	DWORD  biSize;
	LONG  biWidth;
	LONG  biHeight;
	WORD biPlanes;
	WORD biBitCount;
	DWORD  biCompression;
	DWORD  biSizeImage;
	LONG  biXPelsPerMeter;
	LONG  biYPelsPerMeter;
	DWORD  biClrUsed;
	DWORD  biClrImportant;
};

//#if defined(_OPROS_LINUX_)
struct RGBQUAD {
	BYTE rgbBlue;
	BYTE rgbGreen;
	BYTE rgbRed;
	BYTE rgbReserved;
};
//#endif

#pragma pack( pop, packing_alignments )


extern unsigned char *ReadBmp256 (const char *fileName, int &width, int &height, unsigned char palette[256][4]);
//extern unsigned char *ReadBmp256 (const char *fileName, unsigned char palette[256][4]);
extern int WriteBmp256 (const char *fileName, int width, int height, unsigned char *image, unsigned char palette[256][4]);
extern void FreeImage (unsigned char *image);
