#include "intersection.h"

intersection::intersection(){}
intersection::~intersection(){}


double intersection::run_truck_tandem_drone(std::string drone_type)
{
	int all_distances, all_masses, number_of_addresses, number_of_drones;
	std::tuple  <int, int, int, int>f;
	f = std::make_tuple(all_distances, all_masses, number_of_addresses, number_of_drones);
	std::cout << "Running truck & tandem drone method with drone type " << drone_type << "\n";
	int additional_adr = 2;
	double max_flight_distance = 150;// in metres
	double max_pay_load = 12;// in kg
	rural_drone arcadian_drone(max_pay_load, max_flight_distance);
	read_data rd("postal_data.txt");
	rd.fill_data();
	clustering cl(rd, max_flight_distance);
	cl.run_clustering();
	cl.add_depot();
	GA_param_list set_params;
	set_GA_params(set_params);
	genetic_algorithm<Circuit, address_metadata> tsp_ga(set_params, cl.centroids);
	result Result = tsp_ga.run_algorithm_genetic(&fitness, &initialise_circuit_v, &check_truck_route_validity);
	f = arcadian_drone.drone_multi_delivery(cl.k, additional_adr, cl.cluster_regions, Result.circuit_vector, max_pay_load, max_flight_distance);
	//arcadian_drone.drone_multi_delivery(cl.k, additional_adr, cl.cluster_regions,  Result.circuit_vector, )
	std:: cout << std::get<0>(f) << "\n";	
	std::cout << std::get<1>(f) << "\n";
	std::cout << std::get<2>(f) << "\n";
	std::cout << std::get<3>(f) << "\n";
	std::tuple<double, int> g;

	g = arcadian_drone.singular_flight(cl.k, cl.cluster_regions, Result.circuit_vector);
	std:: cout << std::get<0>(g) << "\n";	
	std::cout << std::get<1>(g) << "\n";
	return 0;

	//truck t1(no_of_drones_req);
	




	return 0.0;
}

double intersection::comparison()
{
	return 1;
}
void intersection::do_tests()
{
	run_tests();
}

void intersection::run_charging_port_tandem_drone(std::string drone_type)
{
	std::cout << "Running drone & charging stations method with drone type " << drone_type << "\n";

}
