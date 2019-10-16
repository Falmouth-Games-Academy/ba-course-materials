#include "bitmap.h"
#include <windows.h>

Bitmap::Bitmap()
{
	Reset();
}
Bitmap::~Bitmap()
{
	Release();
	Reset();
}

Bitmap::Bitmap(int width, int height, int format)
{
	Reset();

	this->format = format;
	Width = width;
	Height = height;

	int dataSize = Width*Height * (format / 8);
	pData = new unsigned char[dataSize];
}

bool Bitmap::Load(const char* filename)
{
	Release();

	HBITMAP hBMP = (HBITMAP)LoadImage(NULL, filename, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);

	if (hBMP != NULL)
	{
		BITMAP  bm;
		GetObject(hBMP, sizeof(BITMAP), &bm);

		format = bm.bmBitsPixel;
		Width = bm.bmWidth;
		Height = bm.bmHeight;

		int dataSize = Width*Height * (format / 8);
		pData = new unsigned char[dataSize];

		memcpy(pData, bm.bmBits, dataSize);

		return true;
	}
	return false;
}

unsigned int Bitmap::GetWidth() const
{
	return Width;
}

unsigned int Bitmap::GetHeight() const
{
	return Height;
}

unsigned int Bitmap::GetPixelDepth() const
{
	return format;
}

byte* Bitmap::GetData() const
{
	return pData;
}

unsigned char* Bitmap::GetPixel(unsigned int x, unsigned int y) const
{
	switch (format)
	{
	case 16:
	{
		return &pData[((y*Width) + x) * 2];
	}
	break;

	case 24:
	{
		return &pData[((y*Width) + x) * 3];
	}
	break;

	case 32:
	{
		return &pData[((y*Width) + x) * 4];
	}
	break;

	default:
		break;
	}

	return 0;
}

void  Bitmap::SetPixel(unsigned int x, unsigned int y, unsigned char* val)
{
	switch (format)
	{
	case 16:
	{
		pData[((y*Width) + x) * 2 + 0] = *val;
		pData[((y*Width) + x) * 2 + 1] = *(val + 1);
	}
	break;

	case 24:
	{
		pData[((y*Width) + x) * 3 + 0] = *val;
		pData[((y*Width) + x) * 3 + 1] = *(val + 1);
		pData[((y*Width) + x) * 3 + 2] = *(val + 2);
	}
	break;

	case 32:
	{
		pData[((y*Width) + x) * 4 + 0] = *val;
		pData[((y*Width) + x) * 4 + 1] = *(val + 1);
		pData[((y*Width) + x) * 4 + 2] = *(val + 2);
		pData[((y*Width) + x) * 4 + 3] = *(val + 3);
	}
	break;

	default:
		break;
	}
}

void Bitmap::Release()
{
	if (pData != NULL)
	{
		delete[] pData;
	}

	Reset();
}

void Bitmap::Reset()
{
	pData = NULL;
	Width = 0;
	Height = 0;
	format = 0;
}

void Bitmap::Assign(const Bitmap& src)
{
}
