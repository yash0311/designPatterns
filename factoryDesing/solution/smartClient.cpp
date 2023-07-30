#include<bits/stdc++.h>
#include "vechicle_factory.hpp"
#include "vehicle.hpp"
using namespace std;

int main() {
    string vehicleType;
    cin>>vehicleType;
    Vehicle *v = Vehicle_factory::assignVehicle(vehicleType);
    if(v != nullptr) {
        v->created_vehicle();
    }
    return 0;
}