#pragma once
#include "circuit.h"
#include "postal_region.h"
#include <cmath>
#include <random>
#include <stdio.h>
#include <algorithm>
#include <cfloat>

struct GA_param_list {
	int num_units, generation_size, max_generation;
	double crossover_prob, mutation_prob, tolerance;
	unsigned seed;
};

struct result {
	int iteration;
	std::vector<address_metadata> circuit_vector;
	double optimal_performance;
};


template <class C, class D>
class genetic_algorithm
{
public:

	genetic_algorithm(GA_param_list list, std::vector<D>& path);
	
	~genetic_algorithm();

	//void crossover_collision(vector<C>& Circuit1, vector<C>& Circuit2, vector<C>& child1, vector<C>& child2, default_random_engine& generator);
	
	void calc_fitness(double& max, std::vector<double>::iterator& max_it, double& min, double& fitness_total, std::vector<double>& fitness_v, std::vector<C>& gen);
	
	void partial_shuffle_mutation(C& circ, double mutation_prob, std::default_random_engine& generator);
	
	void rs_mutation(C& circ, double mutation_prob, std::default_random_engine& generator);
	
	void point_mutation(C& circ, double mutation_prob, std::default_random_engine& generator);
	
	bool approx_equal(double a, double b, double epsilion);
	
	void crossover_ordered(C& parent1, C& parent2, C& child1, C& child2, int a, int b);
	
	void crossover_standard(C& parent1, C& parent2, C& child1, C& child2, int a, int b);

	int selection(std::vector<double>& fitness_v, int generation_size, double fitness_total, std::default_random_engine& generator);

	result run_algorithm_genetic(std::function<double(C&)> fitness_func,
		std::function<void(std::vector<C>&, std::vector<C>&, std::vector<C>&, std::vector<D>&, int)> initialise_gen_v, std::function<bool(C&)> eval_circ);
	
	int rt_size;
	
	std::vector<D> path;
	
	std::vector<C> generation, new_generation;
	GA_param_list lista;
	
};

template class genetic_algorithm<Circuit, address_metadata>;
genetic_algorithm<Circuit, address_metadata>::genetic_algorithm(GA_param_list list, std::vector<address_metadata>& path);
void genetic_algorithm<Circuit, address_metadata>::crossover_ordered(Circuit& parent1, Circuit& parent2, Circuit& child1, Circuit& child2, int a, int b);
void genetic_algorithm<Circuit, address_metadata>::crossover_standard(Circuit& parent1, Circuit& parent2, Circuit& child1, Circuit& child2, int a, int b);
void genetic_algorithm<Circuit, address_metadata>::rs_mutation(Circuit& circ, double mutation_prob, std::default_random_engine& generator);
void genetic_algorithm<Circuit, address_metadata>::partial_shuffle_mutation(Circuit& circ, double mutation_prob, std::default_random_engine& generator);
void genetic_algorithm<Circuit, address_metadata>::point_mutation(Circuit& circ, double mutation_prob, std::default_random_engine& generator);
int  genetic_algorithm<Circuit, address_metadata>::selection(std::vector<double>& fitness_v, int generation_size, double fitness_total, std::default_random_engine& generator);
void genetic_algorithm<Circuit, address_metadata>::calc_fitness(double& max, std::vector<double>::iterator& max_it, double& min, double& fitness_total, std::vector<double>& fitness_v, std::vector<Circuit>& gen);
result genetic_algorithm<Circuit, address_metadata>::run_algorithm_genetic(std::function<double(Circuit&)> fitness_func,
	std::function<void(std::vector<Circuit>&, std::vector<Circuit>&, std::vector<Circuit>&, std::vector<address_metadata>&, int)> initialise_gen_v, std::function<bool(Circuit&)> eval_circ);