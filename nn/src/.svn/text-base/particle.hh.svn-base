#ifndef _PARTICLE_
#define _PARTICLE_

#include <stdlib.h>
#include <vector>
#include "nn.hh"


/* set individuality and sociality */
#define iWeight  2.0 /* hunt factor */
#define iMin  0.0 /* low  stochastic weight factor */
#define iMax  1.0 /* high stochastic weight factor */
#define sWeight  2.0 /* follow factor */
#define sMin  0.0 /* low  stochastic weight factor */
#define sMax  1.0 /* high stochastic weight factor */

double random(double min, double max);
double constrict(double delta, double deltaMin, double deltaMax);

template<class InputType, class OutputType>
class Particle
{
public:
  Particle(unsigned dimension, NN<InputType> *nn, 
	   double borneinf, double bornesup, double objective) : 
    _dimension(dimension), _nn(nn), _borneinf(borneinf),
    _bornesup(bornesup), _objective(objective)
  {
    _bestFitness = 100.0;
    _deltaMin = -100.0;
    _deltaMax = 100.0;

    for (unsigned i = 0; i < dimension; ++i)
      _nextPosition.push_back(random(_borneinf, _bornesup));
    for (unsigned i = 0; i < dimension; ++i)
      _currentPosition.push_back(0.0);
    for (unsigned i = 0; i < dimension; ++i)
      _bestFitnessPosition.push_back(0.0);

    for (unsigned i = 0; i < _dimension; ++i)
      _v.push_back(random(_deltaMin, _deltaMax));
  }

  bool	walk(double error)
  {
    for (unsigned i = 0; i < _dimension; ++i)
      _currentPosition[i] = _nextPosition[i];

    double fitness = error;
    if (fitness <= _objective)
      {
	_bestFitness = fitness;
	_bestFitnessPosition = _currentPosition;
			
	return true;
      }

    if (fitness < _bestFitness)
      {
	_bestFitness = fitness;
	_bestFitnessPosition = _currentPosition;
      }

    Particle *bestNeighbors = _neighbors[0];
    fitness = _neighbors[0]->_bestFitness;
    for (unsigned i = 1; i < _neighbors.size(); ++i)
      {
	if (fitness > _neighbors[i]->_bestFitness)
	  {
	    fitness = _neighbors[i]->_bestFitness;
	    bestNeighbors = _neighbors[i];
	  }
      }

    for (unsigned i = 0; i < _dimension; ++i)
      {
	double iFactor = iWeight * random(iMin, iMax);
	double sFactor = sWeight * random(sMin, sMax);
	double hunt = _bestFitnessPosition[i] - _currentPosition[i];
	double follow = bestNeighbors->_bestFitnessPosition[i] 
	  - _currentPosition[i];
	double delta = (iFactor * hunt) + (sFactor * follow);
	delta += _v[i];
	_v[i] = constrict(delta, _deltaMin, _deltaMax);
	_nextPosition[i] = _currentPosition[i] + _v[i];
      }

    /*
    if (_deltaMin < -0.5)
      _deltaMin *= 0.999;
    if (_deltaMax > 0.5)
      _deltaMax *= 0.999;
    */

    return false;
  }

  inline double	z()
  {
    return _nn->activate(_currentPosition);
  }

  std::vector<double>	_currentPosition;
  std::vector<double>	_nextPosition;
  std::vector<double>	_v;

  double		_bestFitness;
  std::vector<double>	_bestFitnessPosition;

  std::vector<Particle *>	_neighbors;

  unsigned			_dimension;
  NN<InputType>			*_nn;
  double			_borneinf;
  double			_bornesup;
  double			_objective;

  double			_deltaMin;
  double			_deltaMax;
};


#endif /* _PARTICLE_ */
