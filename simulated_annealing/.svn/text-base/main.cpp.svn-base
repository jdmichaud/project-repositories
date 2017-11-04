#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#include "rs.h"
//#include "graphic.h"
//#include "glut.h"

#define MAX_RAND 32767

int random(int min, int max)
{
	int i = rand();
	i = (i * (max - min)) / MAX_RAND;
	return i + min;
}

void showPath(std::vector<Point> &path)
{
	for (unsigned i = 0; i < path.size(); ++i)
		std::cout << "[" << path[i]._id << "]";

	std::cout << std::endl;
}

std::vector<Point>	&loadFile(std::string &fname)
{
	std::ifstream	ifile(fname.c_str(), std::ios::in);
	std::vector<Point>	*points = new std::vector<Point>;

	if (!ifile.is_open())
		throw "Unknown file";

	int x = 0;
	int y = 0;
	int z = 0;
	unsigned id = 0;

	while (!ifile.eof())
	{
		ifile >> x;
		ifile >> y;
		ifile >> z;

		points->push_back(*new Point(x, y, z, id++));
	}

	return *points;
}

std::vector<Point>	&generatePoints(unsigned number)
{
	std::vector<Point>	*points = new std::vector<Point>();

	for (unsigned i = 0; i < number; ++i)
		points->push_back(*new Point(random(-100, 100), random(-100, 100), random(-100, 100), i));

	return *points;
}

double	energy(std::vector<Point>	&path)
{
	double distance = 0.0;

	for (unsigned i = 0; i < path.size() - 1; ++i)
		distance += sqrt(pow(path[i]._x - path[i + 1]._x, 2) + pow(path[i]._y - path[i + 1]._y, 2) + pow(path[i]._z - path[i + 1]._z, 2));

	return distance;
}

std::vector<Point>	&initialize2(std::vector<Point>	&towns)
{
	std::vector<Point> tmp_towns = towns;
	towns.clear ();

	towns.push_back (tmp_towns[0]);
	tmp_towns.erase (tmp_towns.begin ());

	while (tmp_towns.size ())
	{
		unsigned int min = 0;
		float mindist = 10000000;

		for (unsigned int j = 0; j < tmp_towns.size (); ++ j)
		{
			float newdist = sqrt(pow((towns.back ())._x - tmp_towns[j]._x, 2) + pow((towns.back ())._y - tmp_towns[j]._y, 2) + pow((towns.back ())._z - tmp_towns[j]._z, 2));
			//	towns.back ().dist (tmp_towns[j]);
			if (newdist < mindist)
			{
				mindist = newdist;
				min = j;
			}
		}

		towns.push_back (tmp_towns[min]);
		std::vector<Point>::iterator to_del = tmp_towns.begin ();
		to_del += min;
		tmp_towns.erase (to_del);
	}

	return towns;
}

std::vector<Point>	&initialize(std::vector<Point>	&path)
{
	std::vector<Point>::iterator minPoint = path.end();
	std::vector<Point>	*newVector = new std::vector<Point>();
	newVector->insert(newVector->begin(), path.begin(), path.end());
	path.clear();

	for (std::vector<Point>::iterator i = newVector->begin(); newVector->size() != 0; )
	{
		double minDist = 1000000000.0;
		path.push_back(*i);
		newVector->erase(i);

		for (std::vector<Point>::iterator j = newVector->begin(); j != newVector->end(); ++j)
		{
			double distance = sqrt(pow(path.back()._x - (*j)._x, 2) + pow(path.back()._y - (*j)._y, 2) + pow(path.back()._z - (*j)._z, 2));
			if ((distance != 0) && (distance < minDist)) // le premier test pour eviter distance entre meme point
			{
				minDist = distance;
				minPoint = j;
			}
		}
		i = minPoint;
	}

	return path;
}

std::vector<Point>	*transform(std::vector<Point>	&path)
{
	int toChange = random(0, path.size() - 1);
	int newNext = random(0, path.size() - 1);
	std::vector<Point>	*newPath = new std::vector<Point>();
	*newPath = path;
	std::cout << newPath->size() << std::endl;
	//newPath->insert(newPath->begin(), path.begin(), path.end());

	//std::cout << "swap " << toChange << " with " << newNext << std::endl;

	if (toChange > newNext)
	{
		int tmp = toChange;
		toChange = newNext;
		newNext = tmp;
	}

	unsigned j = newNext;
	for (unsigned i = toChange; (i != j) && (j > i); ++i, --j)
	{
		Point point = (*newPath)[i];
		(*newPath)[i] = (*newPath)[j];
		(*newPath)[j] = point;
	}

	//std::cout << "end transform" << std::endl;
	return newPath;
}

std::vector<Point>	*disturb(std::vector<Point>	&path)
{
	std::vector<Point>	*newPath = new std::vector<Point>();
	newPath->insert(newPath->begin(), path.begin(), path.end());

	for (unsigned i = 0; i < path.size(); ++i)
	{
		int toChange = random(0, path.size() - 1);
		Point point = (*newPath)[i];
		(*newPath)[i] = (*newPath)[toChange];
		(*newPath)[toChange] = point;
	}

	return newPath;
}

std::vector<Point>	&recuitSimule(std::vector<Point> &path, 
				      double tempLimit, 
				      double initialTemp)
{
	double temperature = initialTemp;
	double energyBefore = energy(path);
	double energyAfter = 0.0;
	double deltaEnergy = 0.0;
	unsigned accepted;
	unsigned transformations;
	unsigned size = path.size();
	std::vector<Point> *oldPath = new std::vector<Point>();
	std::vector<Point> *newPath;
	unsigned toto = 100;

	char	msg[255];

	oldPath->insert(oldPath->begin(), path.begin(), path.end());
	do
	{
	  //sprintf(msg, "energie: %f", energyAfter);
	  //display(*oldPath);
	  //output (1.5 , -1.5, msg);
	  //glutSwapBuffers();
		accepted = 0;
		transformations = 0;
		do
		{
			energyBefore = energy(*oldPath);
			newPath = transform(*oldPath);
			energyAfter = energy(*newPath);
			deltaEnergy = energyAfter - energyBefore;
			++transformations;
			if (deltaEnergy < 0)
			{
				delete oldPath;
				oldPath = newPath;
			}
			else
				if (((float) rand() / MAX_RAND) <= exp(- deltaEnergy / temperature))
				{
					delete oldPath;
					oldPath = newPath;
					++accepted;
				}
				else
					delete newPath;

		} while ((accepted < (12 * size)) && (transformations < (toto * size)));
		
		temperature *= 0.95;
		toto *= 0.95;
		std::cout << "temperature = " << temperature << "° ";
		std::cout << "granted = " << accepted << std::endl;

	} while (temperature > tempLimit);

	return *oldPath;
}

double meanEnergy(std::vector<Point> &path)
{
	double	energies = 0.0;

	for (unsigned i = 0; i < 100; ++i)
		energies += energy(*disturb(path));

	return energies / 100.0;
}

/*void rs(char *pathFile, double tempLimit, double initialTemp, double ratio)
{
	char **argv = (char **) malloc (sizeof (char *));
	argv[1] = "RS";
	int argc = 1;

	ratio = -0.1;

	std::vector<Point> points = loadFile(std::string(pathFile));
	//std::vector<Point> points = generatePoints(100);
	if (ratio == -0.1)
		initGraphic(argc, argv, points, tempLimit, initialTemp);
	else
	{
		std::cout << "Evaluating a good initial temperature" << std::endl;
		std::cout << " disturbing path ..." << std::endl;
		double meanE = meanEnergy(points);
		std::cout << " mean Energy found : " << meanE << std::endl;
		double initialTemperature = - meanE / log(ratio);
		std::cout << " initial temperature : " << initialTemperature << " (ratio: " << ratio << ")" << std::endl;
		initGraphic(argc, argv, points, tempLimit, initialTemperature);
	}
}*/

int main(int argc, char **argv)
{
	srand((unsigned) time(NULL));
	std::string file("points.txt");
	//rs("points.txt", 0.01, 1.0);


	std::vector<Point> points = loadFile(file);
	//std::vector<Point> points = initialize(generatePoints(100));

//	for (unsigned i = 0; i < points.size(); ++i)
//		std::cout << points[i]._x << " " << points[i]._y << " " << points[i]._z << std::endl;
//		std::cout << points[i]._x << " " << points[i]._y << " " << 0 << std::endl;

	//initGraphic(argc, argv, points);

	std::cout << "energie initiale = " << energy(points) << std::endl;
	std::vector<Point> result = recuitSimule(points, 0.01, 1.0);
	showPath(result);
	std::cout << "energie = " << energy(result) << std::endl;
	
	return 0;
}
