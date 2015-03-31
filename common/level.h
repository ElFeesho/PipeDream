#ifndef __LEVEL_H__
#define __LEVEL_H__

#include <iostream>
#include <sstream>
#include <algorithm>
#include <iterator>
#include <string>
#include <vector>
#include <fstream>

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

using namespace std;

class Level
{
public:
	Level(string levelName) : level(levelName) {
		fstream levelFile = fstream("resources/"+levelName);
		if(levelFile.is_open())
		{
			string bgTileStr;
			getline(levelFile, bgTileStr);

			string fgTileStr;
			getline(levelFile, fgTileStr);

			vector<string> bgTileStrings = split(bgTileStr, ',');
			for_each(bgTileStrings.begin(), bgTileStrings.end(), [&](string result){
				bgTiles.push_back(atoi(result.c_str()));
			});

			vector<string> fgTileStrings = split(fgTileStr, ',');
			for_each(fgTileStrings.begin(), fgTileStrings.end(), [&](string result){
				fgTiles.push_back(atoi(result.c_str()));
			});

			cout << "BGTILES: " << bgTiles.size() << " FGTILES: " << fgTiles.size() << endl;
		}


	}

	~Level() {}

	string getLevelName() { return level; }

	vector<int> getBgTiles() {
		return bgTiles;
	}

	vector<int> getFgTiles() {
		return fgTiles;
	}
private:
	string level;

	vector<int> bgTiles;
	vector<int> fgTiles;
};

#endif
