#pragma once

class Bitmap
{
public:

	Bitmap();
	Bitmap(int width, int height, int format);
	~Bitmap();

	bool Load(const char* Filename);

	unsigned int GetWidth() const;
	unsigned int GetHeight() const;
	unsigned int GetPixelDepth() const;

	unsigned char* GetData() const;

	unsigned char* GetPixel(unsigned int x, unsigned int y) const;
	void  SetPixel(unsigned int x, unsigned int y, unsigned char* val);

	void Release();

private:
	void Reset();
	void Assign(const Bitmap& src);

	unsigned char* pData;

	int format;
	unsigned int Width;
	unsigned int Height;
};

