#pragma once

#include "my_time.h"
#include "club_data.h"

#include <string>

namespace EventType {
enum Type {
    ClientArrived = 1,
    ClientSat = 2,
    ClientWaiting = 3,
    СlientLeft = 4,
    OutgoingEventСlientLeft = 11,
    OutgoingEventClientSat = 12,
};
};

class Event{
private:
    const Type type_;
    const MyTime time_;

public:
    Event(MyTime time, Type type): time_(time), type_(type) {};

    MyTime get_time() const;
    Type get_type() const;

    virtual void start(ClubData&) = 0;
    virtual std::string to_str() const = 0;
};