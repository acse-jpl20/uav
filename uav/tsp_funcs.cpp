//#include "Circuit.h"
//#include "genetic_algorithm.h"
#include "tsp_funcs.h"

//tsp_funcs::tsp_funcs();
//tsp_funcs::~tsp_funcs();
//extern vector<drone*> drones_v (number_of_drones);
//clustering obj1;
//clustering* obj1;
std::vector<address_metadata> test_route = set_dummy_route(5);

/*******************************************************************************
The route is iterated overand the euclidean distances between one pointand 
the next(i.e route[i], route[i - 1]) are calculatedand summed.The reciprocal 
of the summed fitness value is then returned.The reciprocal is returned as the 
genetic algorithm selection method is more likely to choose a chromosome with 
a larger fitness value.We are optimising for a small route length, hence we 
return the reciprocal.
*******************************************************************************/
double fitness(Circuit& circ1)
{
	size_t rt_length = circ1.route.size();
	double f = 0;
	for (int i = 1; i < rt_length; i++)
		f += std::sqrt(util::length(circ1.route[i], circ1.route[i - 1]));
	return  1.0 / f;
}

std::vector<address_metadata> set_dummy_route(int rt_length)
{
	std::vector<address_metadata> obj(rt_length);
	for (int i = 0; i < rt_length; i++)
	{
		obj[i].x_coord = 1 + rand() % 100;
		obj[i].y_coord = 1 + rand() % 100;
		obj[i].num = i;
	}
	return obj;
}

/**************************************************************************
The route is iterated over, if the num attribute of the location matches 
that of the test route then the fitness value is incremented by 1.
***************************************************************************/
double test_fitness(Circuit& circ)
{
	int rt_length = circ.route.size();
	double f = 0;
	for (int i = 1; i < rt_length - 1; i++)
		if (circ.route[i].num == test_route[i].num)
		{
			f++;
		}
	return f;
}
/**********************************************************
The new, old and temporary generations are all initialised.
**********************************************************/
void initialise_circuit_v(std::vector<Circuit>& gen1, std::vector<Circuit>& gen2, std::vector<Circuit>& temp_gen, 
	std::vector<address_metadata>& obj1, int gen_size)
{
	for (int i = 0; i < gen_size + 1; i++) 
	{
		gen1[i] = Circuit(obj1, false);
		gen2[i] = Circuit(obj1, true);
	}
	for (int i = 0; i < 2; i++)
		temp_gen[i] = Circuit(obj1, true);
}

/*****************************************************************************
The truck route is modelled on the travelling salesman problem.Therefore, 
except for the depot, a location cannot occur more than once in the route 
path.This function checks for any repeating locationand returns false if a 
location occurs more than onceand returns true if the routes only visit each 
location once.
*****************************************************************************/
bool check_truck_route_validity(Circuit& obj1) 
{
	int rt_size = obj1.route.size();
	for (int ic1 = 0; ic1 < rt_size; ic1++)
	{
		for (int ic2 = ic1 + 1; ic2 < rt_size; ic2++)
			if (obj1.route[ic1].num == obj1.route[ic2].num)
			{
				return false;
			}
	}
	return true;
}

/**********************************************************************************************
This is used when the ordered crossover function is used as the crossover function 
itself prevents repeating locations in the route.Therefore, to use check_truck_route_validity
would be redundant.
**********************************************************************************************/
bool check_validity_dummy(Circuit& obj1)
{
	return true;
}