#pragma once

#include <string>

class MyTime {
private:
    std::string hour_;
    std::string minutes_;

public:
    MyTime(const std::string&);
    MyTime() = default;

    bool operator<(const MyTime&) const;

    int to_min() const;
    std::string to_str() const;
};