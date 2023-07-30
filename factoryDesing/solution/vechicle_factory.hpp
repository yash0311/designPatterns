#ifndef vechicle_factory_hpp
#define vechicle_factory_hpp

#include "vehicle.hpp"

class Vehicle_factory{
    public:
        static Vehicle *assignVehicle(string vechicleType);
};

#endif