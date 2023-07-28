#include<bits/stdc++.h>
#include "logger.hpp"
using namespace std;

Logger::Logger() {
    count++;
    cout<<"instance created, count value = "<<count<<endl;
}

void Logger::log(string message) {
    cout<<message<<endl;
}

Logger *Logger::getInstance() {
    // mutex to make the logic thread safe.
    mtx.lock();
    if(loggerInstance == nullptr) {
        loggerInstance = new Logger();
    }
    mtx.unlock();
    return loggerInstance;
}

int Logger::count = 0;
Logger *Logger::loggerInstance = nullptr;
mutex Logger::mtx;