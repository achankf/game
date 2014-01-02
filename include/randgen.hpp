#ifndef _randgen_hpp_
#define _randgen_hpp_

#include <random>

template <class T>
class RandGen {
	typedef std::default_random_engine RandEngine;
	typedef std::uniform_int_distribution<T> RandDistribution;

	RandEngine rand_gen;
	RandDistribution rand_dist;

public:
	RandGen() : rand_gen(std::random_device()()) {}
	T next() {
		return rand_dist(rand_gen);
	}
};
#endif
