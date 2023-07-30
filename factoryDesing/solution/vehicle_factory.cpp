#include<bits/stdc++.h>
#include "vechicle_factory.hpp"
#include "car.hpp"
#include "bike.hpp"

Vehicle *Vehicle_factory::assignVehicle(string vechicleType) {
     if(vechicleType == "car") {
        return new Car();
    } else if(vechicleType == "bike") {
        return new Bike();
    } else {
        cout<<"input error"<<endl;
        return nullptr;
    }
}