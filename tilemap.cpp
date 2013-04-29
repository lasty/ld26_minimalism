
#include "tilemap.h"

#include <stdexcept>
using std::runtime_error;

#include <sstream>
using std::stringstream;

//#include <algorithm>

#include <iostream>
using std::cout;
using std::endl;

using std::getline;

bool find(const string &s, const string &f)
{
	return s.find(f) != string::npos;
}

// get the string inbetween two positions
string GetSubstr(const string &str, size_t p1, size_t p2)
{
	return str.substr(p1+1, (p2-p1-1));
}

// parse the int in the string between the two character positions
int ParseInt(const string&str, size_t p1, size_t p2)
{
	string ss = GetSubstr(str, p1, p2);
	stringstream s;  s << ss;
	int out;
	s >> out;
	return out;
}

Level::Level(const string&datastr, const string&heightstr)
{
	if (not find(datastr, "data")) throw runtime_error("data line not found");
	if (not find(heightstr, "height")) throw runtime_error("height line not found");

	//cout << datastr << endl;
	//cout << heightstr << endl;

	size_t h1 = heightstr.find(':');	
	size_t h2 = heightstr.find(',');
	height = ParseInt(heightstr, h1, h2);

	//cout << "height = " << height << endl;

	size_t d1 = datastr.find('[');
	size_t d2 = datastr.find(',');

	size_t dlast = datastr.find(']');

	while (d1 < dlast)
	{
		int i = ParseInt(datastr, d1, d2);
		data.push_back(i);

		//cout << i << ",";

		d1 = d2;
		d2 = datastr.find(',', d2+1);
	}
	cout << endl;

	//cout << "vector size: " << data.size() << endl;

	width = data.size() / height;

	//cout << "width = " << width << endl;

	if (unsigned(width * height) != data.size())
		throw runtime_error("mismatch in elements");

}

int Level::Get(int x, int y)
{
	if (x < 0 or x >= width) throw runtime_error("x coord out of range");
	if (y < 0 or y >= height) throw runtime_error("y coord out of range");

	int index = (y * width) + x;

	return data.at(index);
}

JsonMap::JsonMap(ifstream &in)
{
	Load(in);
}


void JsonMap::Load(ifstream &in)
{
	string line;

	if (not in.good()) throw runtime_error("ifstream not valid (data file not found?)");

	while(in.good() and not in.eof())
	{
		getline(in, line);
		//cout << "line:  " << line << endl;

		if (find(line, "\"data\""))
		{
			string height;
			getline(in, height);
			
			string namestr;
			getline(in, namestr);
			if (not find(namestr, "\"name\"")) throw runtime_error("name not found");
			string name = GetSubstr(namestr, namestr.find(':')+1, namestr.find(',')-1);
			cout << "Level name = '" << name << "'" << endl;

			levels.emplace_back(line, height);
		}
	}

	if (levels.size() == 0) throw runtime_error("no maps found in json file");
}

