#include "rural_drone.h"
//
//rural_drone::rural_drone(double maximum_battery_time, double maximum_payload_capacity, double drone_mass, double payload, double max_flight_time,
//int rotors){}
rural_drone::rural_drone(double maximum_battery_time, double maximum_payload_capacity, double drone_mass, double payload, double max_flight_time,
	int rotors) : drone(maximum_battery_time, maximum_payload_capacity, drone_mass, payload, max_flight_time, rotors){}

rural_drone::rural_drone(double payload, double max_flight_time) : drone(payload, max_flight_time) {};


//bool rural_drone::energy_flight_constraint(double L)
//{
//	/*double energy1 = power_consumption() * (L / horizontal_max_velocity);
//	double dist_to_truck = utility::length(adr, this->x_coord, this->y_coord);*/
//	return true;
//}
//




	