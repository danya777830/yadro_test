#pragma once

#include "my_time.h"
#include "club_data.h"

#include <string>

enum Type {
    ClientArrived = 1,
    ClientSat = 2,
    ClientWaiting = 3,
    СlientLeft = 4,
    OutgoingEventСlientLeft = 11,
    OutgoingEventClientSat = 12,
    Error = 13,
};

class Event{
private:
    const Type type_;
    const std::string client_name_;
    const MyTime time_;

public:
    virtual void start(ClubData&) = 0;
};