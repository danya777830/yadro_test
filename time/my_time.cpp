#include "my_time.h"
#include "my_exception.h"

int MyTime::to_min() const {
    int it = ((hour_[0] - '0') * 10 + (hour_[1] - '0')) * 60;
    it += (minutes_[0] - '0') * 10 + minutes_[1] - '0';
    return it;
}

MyTime::MyTime(const std::string &str) {
    if (str.size() != 5 || str[2] != ':') {
        throw WrongFormatException();
    }
    for (int i = 0; i < str.size(); ++i) {
        if (i == 2) {
            continue;
        }
        if (str[i] < '0' || str[i] > '9') {
            throw WrongFormatException();
        }
    }
    int hour = (str[0] - '0') * 10 + str[1] - '0';
    int minutes = (str[3] - '0') * 10 + str[4] - '0';

    if (hour > 24 || minutes > 60) {
        throw WrongFormatException();
    }
    hour_ = str[0];
    hour_ += str[1];
    minutes_ = str[3];
    minutes_ += str[4];
}

std::string MyTime::to_str() const {
    return hour_ + ":" + minutes_;
}

bool MyTime::operator<(const MyTime &b) const{
    return to_min() < b.to_min();
}