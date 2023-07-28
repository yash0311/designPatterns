/**
 * @file logger.hpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-07-28
 * 
 * @copyright Copyright (c) 2023
 * To create a singleton class we follow steps
 * 1 - make construction private, so that no instance can be created by the users.
 * 2 - make static function eg- getInstace() through which users can get objects
 * 3 - create static loggerInstance which helps in creating the logger instance and returns if already created.
 * 4 - mutex to make the logic of creating/getting getInstance thread safe.
 */
#ifndef logger_h
#define logger_h
#include<bits/stdc++.h>
#include<mutex>
using namespace std;

class Logger
{   
    private:
        static int count;
        static Logger *loggerInstance;
        static mutex mtx;
        Logger(/* args */);

    public:
        static Logger* getInstance();
        void log(string message);
};

#endif logger_h