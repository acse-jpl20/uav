#include "genetic_algorithm.h"

void set_GA_params(GA_param_list& lst)
{
	lst.generation_size = 5;
	lst.max_generation = 3;
	lst.crossover_prob = 0.5;
	lst.max_iterations = 30;
	lst.mutation_prob = 0.1;
	lst.seed = std::chrono::system_clock::now().time_since_epoch().count();
	lst.tolerance = 1.0e-3;
}
void run_truck_tandem_drone()
{
	cout << "Running truck & tandem drone method\n";
	read_data tets("postal_data.txt");
	tets.fill_data();
	clustering cl(tets);
	cl.run_K_means(false);
	GA_param_list f;
	set_GA_params(f);
	genetic_algorithm vb(f, cl);
	vb.run_algorithm_genetic(10);
}

void run_charging_port_tandem_drone()
{
	cout << "Running drone & charging ports method\n";
	read_data tets("postal_data.txt");
	tets.fill_data();
}