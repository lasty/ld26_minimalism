#ifndef __LD26_TILEMAP_H
#define __LD26_TILEMAP_H

#include <fstream>
using std::ifstream;

#include <string>
using std::string;

#include <vector>
using std::vector;

//holds one level's data
class Level
{
	public:
	Level(const string &datastr, const string &heightstr);

	int width = 0;
	int height = 0;

	vector<int> data;

	int Get(int x, int y);
};


//very quick and dirty json parser, to parse Tiled map files
class JsonMap
{
	public:

	JsonMap() = default;
	JsonMap(ifstream &in);

	void Load(ifstream &in);

	vector<Level> levels;
};

#endif
