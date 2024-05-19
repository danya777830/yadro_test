#include "my_time.h"
#include "my_exception.h"

MyTime::MyTime(const std::string &str) {
    if (str.size() == 5 || str[2] != ':') {
        throw WrongFormatException();
    }
    for (int i = 0; i < str.size(); ++i) {
        if (i == 2) {
            continue;
        }
        if (str[i] < '0' || str[i] > 9) {
            throw WrongFormatException();
        }
    }
    int hour = str[0] * 10 + str[1];
    int minutes = str[3] * 10 + str[4];

    if (hour > 24 || minutes > 64) {
        throw WrongFormatException();
    }
    hour_ = str[0] + str[1];
    minutes_ = str[3] + str[4];
}

std::string MyTime::to_str() const {
    return hour_ + ":" + minutes_;
}