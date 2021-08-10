#pragma once

#include "driver_code.h"

vector<drone*> drones_v;

double total_cost_rural(int num_of_drones, double drone_price, double truck_distance, double tot_drone_distance, double elec_price, double fuel_price)
{
	double total_drone_cost = num_of_drones * drone_price;
	double total_fuel_cost = truck_distance * fuel_price;
	double total_elec_cost = tot_drone_distance * elec_price;
	return total_drone_cost + total_fuel_cost + total_elec_cost;
}
double total_cost_urban()
{
	return;
}
void setup_drones(int number_of_drones, string type)
{
	drones_v.resize(number_of_drones);
	if (type == "urban" || "Urban") {
		for (int i = 0; i < number_of_drones; i++) {
			drones_v[i] = new urban_drone();
		}
	}
	else if (type == "rural" || "Rural") {
		for (int i = 0; i < number_of_drones; i++) {
			drones_v[i] = new rural_drone();
		}
	}
	else
		cout << "Incorrect drone type entered\n";
}
void drone_operation(vector<drone>& drone_v)
{
	for (i : )
}
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
int drone_clusters(int k, int part_size, vector<unique_ptr<address_metadata>>& cl_data, vector<address_metadata>& opt_route, double max_payload_cap,
					double max_dist)
{
	int cnt, cnt2, temp_num_of_addresses_distance = 0, temp_num_of_addresses_mass = 0;
	double sum_d, sum_m;
	int number_of_addresses = 0;
	vector<double> total_dist_v(part_size + 2); 
	vector<double> cluster_mass_v(part_size + 1);
	for (int i = 0; i < k; i++) {
		for (int j = 0; j < cl_data[i].size(); j++) {
			cnt = 0;
			sum_m = 0;
			sum_d = 0;
			total_dist_v[cnt] =  utility::length(opt_route[i], cl_data[i][j]); // cool
			for (int k = j; k < j + part_size; k++) {
				total_dist_v[cnt] = utility::length(cl_data[i][k], cl_data[i][k + 1]);
				cnt++;
			}
			total_dist_v[cnt] = utility::length(cl_data[i][part_size + j], opt_route[i]);
			cnt = 0;
			for (int k = j; k < j + part_size + 1; k++) {
				cluster_mass_v[cnt] = cl_data[i][k + 1].parcel_mass;
				cnt++;
			}
			temp_num_of_addresses_distance = part_size + 1;
			sum_d += std::accumulate(total_dist_v.begin(), total_dist_v.end(), 0.);
			sum_m += std::accumulate(cluster_mass_v.begin(), cluster_mass_v.end(), 0.);
			cnt = part_size;
			while (sum_m > max_payload_cap) {
				//auto it2 = max_element(cluster_mass_v.begin(), cluster_mass_v.end());
				sum_m -= cluster_mass_v[cnt];
				cnt--;  //*max_element(cluster_mass_v.begin(), cluster_mass_v.end());
				temp_num_of_addresses_mass -= 1;
			}
			if (temp_num_of_addresses_mass != 1) {
				cnt = part_size + 1;
				while (sum_d > max_dist) {
					sum_d -= total_dist_v[cnt];
					cnt--;
					sum_d -= total_dist_v[cnt];
					sum_d += utility::length(cl_data[][], opt_route[i]);
					cnt--;
					temp_num_of_addresses_distance -= 1;

				}
			}
		
			int lowest_num = min(temp_num_of_addresses_distance, temp_num_of_addresses_mass);
			for (int k = j; k < lowest_num + j; k++) {
				cl_data[i][k].visited = true;
			}
			number_of_addresses += lowest_num;
			j += lowest_num;
		}
	}

}
double run_truck_tandem_drone(string drone_type)
{
	cout << "Running truck & tandem drone method\n";
	read_data tets("postal_data.txt");
	tets.fill_data();
	if (drone_type == "urban" || "Urban") urban_drone temp_drone();
	else if (drone_type == "rural" || "Rural") rural_drone temp_drone();
	clustering cl(tets);
	cl.run_K_means();
	GA_param_list f;
	set_GA_params(f);
	genetic_algorithm<Circuit, address_metadata> vb(f, cl);
	result Result = vb.run_algorithm_genetic(10, &fitness, &initialise_circuit_v, &check_truck_route_validity);
	Result.circuit_vector;
	int no_of_drones_req = drone_clusters(cl.k, 2, cl.cluster_regions, cl.centroids, temp_drone., temp_drone.);
	setup_drones(no_of_drones_req, "rural");
	return total_cost_rural(no_of_drones_req, temp_drone., Result.optimal_performance, , );

	
}

void run_charging_port_tandem_drone()
{
	cout << "Running drone & charging ports method\n";
	read_data tets("postal_data.txt");
	tets.fill_data();
}