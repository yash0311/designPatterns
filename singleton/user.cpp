/**
 * @file user.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-07-28
 * 
 * @copyright Copyright (c) 2023
 * The below code is an attempt to check the functionality of singleton class Logger.
 * We run two threads which tries to get single object instance and tries to log the message.
 */
#include<bits/stdc++.h>
#include "logger.hpp"
#include<thread>
using namespace std;

void user1Logs() {
    Logger *logger1 = Logger::getInstance();
    logger1->log("1 - yes print it.");
}

void user2Logs() {
    Logger *logger2 = Logger::getInstance();
    logger2->log("2 - yes print it.");      
}

int main() {
    
    thread t1(user1Logs);
    thread t2(user2Logs);

    t1.join();
    t2.join();
    
    
    return 0;
}