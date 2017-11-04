#ifndef _PSWARM_
#define _PSWARM_

#include <vector>
#include <string>
#include "nn.hh"
#include "neuron.hh"
#include "learn_algorithm.hh"
#include "particle.hh"

template<class InputType, class OutputType>
class Pswarm : LearnAlgo<InputType, OutputType>
{
public:
  Pswarm(const std::string& filename, 
	 Driver<InputType, OutputType> *driver,
	 NN<InputType> *nn, unsigned nlearnline,
	 double min_error, unsigned nbparticles, 
	 double borneinf, double bornesup) :
    LearnAlgo<InputType, OutputType>(filename, driver, 
				     nn, nlearnline, min_error),
    _nbparticles(nbparticles), _borneinf(borneinf), _bornesup(bornesup)
  {
    std::cout << "Learning algorithm: particle swarm" << std::endl;
    
    unsigned dim = 0;
    std::cout << "creating particules ... " << std::endl;
    for (unsigned L = 1; L < nn->get_nlayers(); ++L)
      dim += nn->get_nneurons(L - 1) * nn->get_nneurons(L);
    for (unsigned i = 0; i < nbparticles; ++i)
      _swarm.push_back(new Particle<InputType, OutputType>(dim, nn, 
							   borneinf, bornesup, 
							   min_error));
    makeNeighbors(_swarm, _swarm.size() - 1);
  }

  void makeNeighbors(std::vector<Particle<InputType, OutputType> *> &particles,
		     unsigned nbNeighbors)
  {
    std::cout << "making neighbours ... " << std::endl;
    for (unsigned i = 0; i < particles.size(); ++i)
      {
	unsigned j = 0;
	for (j = 0; ((j + i + 1) < particles.size()) 
	       && (j < nbNeighbors); ++j)
	  particles[i]->_neighbors.push_back(particles[j + i + 1]);
	
	if (j < nbNeighbors)
	  {
	    unsigned rest = nbNeighbors - j;
	    for (j = 0; j < rest; ++j)
	      particles[i]->_neighbors.push_back(particles[j]);
	  }
      }
  }	

  virtual void learn()
  {
    double	error = 0.0;
    double	best = 0.0;    
    unsigned	count = 0;
    unsigned	nomove = 0;
    unsigned	best_particle = 0;
    bool	changed = false;

    for (unsigned i = 0; 1; ++i, ++count)
      {
	if (i >= _nbparticles)
	  i = 0;
	
	OutputType desired = _driver->get_learnline(_nn->get_inputs());
	_nn->activate(_swarm[i]->_currentPosition);
	error = compute_error(desired);
	if (_swarm[i]->walk(error))
	  break;
	
	if (!best || (best > error))
	  {
	    best = error;
	    best_particle = i;
	    changed = true;
	  }
	
	if (count && !(count % 1000))
	  {
	    if (!changed)
	      ++nomove;
	    else
	      {
		changed = false;
		nomove= 0;
	      }

	    std::cout << "best error: " << best << " - ";
	    std::cout << "delta: " << _swarm[0]->_deltaMin << std::endl;
	  }
	
	if (nomove > 10)
	    break;
      }
    std::cout << "final error: " << best << std::endl;
    _nn->apply_weights(_swarm[best_particle]->_currentPosition);
  }


private:
  unsigned	_nbparticles;
  double	_borneinf;
  double	_bornesup;

  std::vector<Particle<InputType, OutputType> *>	_swarm;
};

#endif /* _PSWARM_ */
