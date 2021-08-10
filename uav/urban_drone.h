#pragma once
#include "drone.h"
class urban_drone :
    public drone
{
public:
   /* double power_consumption() override;
    double time_to_charge() override;
    void set_h_velocity_drone(double m_h_v) override
    void set_v_velocity_drone(double m_v_v) override;
    void set_battery_time() override;
    void set_payload_capacity() override;*/
    const double max_flight_time = 30;
    vector<address_metadata>* depots; 
    vector<address_metadata>* charging_ports;
    virtual bool energy_flight_constraint(double L);
    double cost_of_drone; //Currency GBP
private:
    double x_coord, y_coord;
};

