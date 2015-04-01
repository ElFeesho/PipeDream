//
// Created by Christopher Sawczuk on 31/03/2015.
//

#include "pngspriteloader.h"

#include <png.h>
#include <iostream>
#include <sstream>
#include <map>

using namespace std;

static std::vector<std::string> &split(const std::string &s, char delim, std::vector<std::string> &elems) {
	std::stringstream ss(s);
	std::string item;
	while (std::getline(ss, item, delim)) {
		elems.push_back(item);
	}
	return elems;
}


static std::vector<std::string> split(const std::string &s, char delim) {
	std::vector<std::string> elems;
	split(s, delim, elems);
	return elems;
}

PngSpriteLoader::PngSpriteLoader(Gfx *gfxWrapper) : gfx(gfxWrapper)
{

}

PngSpriteLoader::~PngSpriteLoader()
{

}

map<string, Sprite*> PngSpriteLoader::loadSprites(std::string name)
{
	map<string, Sprite*> result;
	FILE *spriteFile = fopen(name.c_str(), "rb");
	if(!spriteFile)
	{
		throw "HELP!";
	}

	png_const_bytep header = new unsigned char[4];
	fread((void*)header, 1, 4, spriteFile);

	if(png_sig_cmp(header, 0, 4))
	{
		throw "NOT PNG";
	}

	png_voidp user_error_ptr;

	png_structp png_ptr = png_create_read_struct
			(PNG_LIBPNG_VER_STRING, (png_voidp)user_error_ptr,
			 [](png_structp png_struct, png_const_charp error_message){
				 // PNG ERROR OCCURRED
			 }, [](png_structp png_struct, png_const_charp error_message){
				// PNG WARNING OCCURRED
			 });
	if (!png_ptr)
	{
		throw "Failed to load png";
	}

	png_infop info_ptr = png_create_info_struct(png_ptr);
	if (!info_ptr)
	{
		png_destroy_read_struct(&png_ptr,
										(png_infopp)NULL, (png_infopp)NULL);
		throw "FAILED TO CREATE INFO PTR";
	}

	png_infop end_info = png_create_info_struct(png_ptr);
	if (!end_info)
	{
		png_destroy_read_struct(&png_ptr, &info_ptr,
										(png_infopp)NULL);
		throw "FAILED TO CREATE END INFO PTR";
	}

	png_init_io(png_ptr, spriteFile);
	png_set_sig_bytes(png_ptr, 4);

	png_read_info(png_ptr, info_ptr);

	png_textp text_ptr = NULL;
	int num_text = 0;
	int num_comments   = png_get_text(png_ptr, info_ptr,
											&text_ptr, &num_text);

	int cellWidth = 0;
	int cellHeight = 0;
	int frameDelay;
	for(int i = 0; i < num_text; i++)
	{
		string key = string(text_ptr[i].key);
		string value = string(text_ptr[i].text);
		
		if(key == "cellWidth")
		{
			cellWidth = stoi(value);
		}
		else if(key == "cellHeight")
		{
			cellHeight = stoi(value);
		}
		else if(key == "frameDelay")
		{
			frameDelay = stoi(value);
			cout << "Frame Delay: " << frameDelay << endl;
		}
		else
		{
			// Gotten a sprite definition
			vector<string> frameOffsets = split(value, '-');
			int frameOffset = stoi(frameOffsets[0]);
			int numFrames = stoi(frameOffsets[1]) - frameOffset;
			cout << "Sprite " << key << ": Frames: " << numFrames << " Offset: " << frameOffset << endl;
			result[key] = new Sprite(gfx->openImage(name), numFrames, frameOffset, cellWidth, cellHeight, frameDelay);
		}
	}

	cout << "CW: " << cellWidth << " CH: " <<cellHeight <<endl;

	png_destroy_read_struct(&png_ptr, &info_ptr, &end_info);
	png_free_data(png_ptr, info_ptr, PNG_FREE_ALL , -1);

	return result;
}

