#ifndef __POINT_H_
#define __POINT_H_

#include <vector>

#define DllExport   __declspec( dllexport )

class Point
{
public:
	Point(int x, int y, int z)
	{
		_x = x;
		_y = y;
		_z = z;
	}

	Point(int x, int y, int z, unsigned id)
	{
		_x = x;
		_y = y;
		_z = z;

		_id = id;
	}

	int _x;
	int _y;
	int _z;

	unsigned _id;
};

std::vector<Point>	&recuitSimule(std::vector<Point> &path, 
				      double tempLimit, 
				      double initialTemp);
void showPath(std::vector<Point> &path);
double	energy(std::vector<Point>	&path);
void rs(char *pathFile, double tempLimit, double initialTemp, double ratio = -0.1);

#endif
