#ifndef _randgen_h_
#define _randgen_h_

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
