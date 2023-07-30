/**
 * @file client.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-07-28
 * 
 * @copyright Copyright (c) 2023
 * we have tried to understand the actual problem with the below client.
 * Let's say in future if we want to add more class which inherit vehicle
 * for eg - truck, we will have to ask client to change its code, include "truck.hpp"
 * also will have to ask them to change the logic as well which they would not want.
 * Hence to mitigate this issue we will try to implement factory desing.
 * We will implement smartClient.cpp and also vehicle_factory which will contain
 * the logic of assignment of vechicle and thus client and product can be de-coupled.
 * 
 * first to run and understand, use commands
 * g++ -c car.cpp bike.cpp
 * ar ru vehicle_library.a car.o bike.o
 * g++ -o client client.cpp vehicle_library.a
 */
#include<bits/stdc++.h>
#include "car.hpp"
#include "bike.hpp"
using namespace std;

int main() {

    string vechicleType;
    cin>>vechicleType;
    Vehicle *vehicle;
    if(vechicleType == "car") {
        vehicle = new Car();
    } else if(vechicleType == "bike") {
        vehicle = new Bike();
    } else {
        cout<<"input error"<<endl;
        return 0;
    }
    vehicle->created_vehicle();
    return 0;
}