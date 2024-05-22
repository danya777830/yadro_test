#pragma once

#include <string>

class MyTime {
private:
    std::string hour_;
    std::string minutes_;
    
    int to_min() const;
    static MyTime from_min_to_time(int);

public:
    MyTime(const std::string&);
    MyTime();

    bool operator<(const MyTime&) const;
    MyTime operator+(const MyTime&) const;
    MyTime operator-(const MyTime&) const;
    int not_full_hours() const;

    std::string to_str() const;
};