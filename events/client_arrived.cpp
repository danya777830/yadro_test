#include "client_arrived.h"
#include "writer.h"
#include "error.h"

#include <iostream>

void ClientArrived::start(ClubData &club_data) {
    Writer &writer = Writer::get_writer();    

    if (!club_data.is_open(get_time())) {
        writer.write_event(Error(get_time(), "NotOpenYet"));
        return;
    }

    if (club_data.is_client_inside(client_name_)) {
        writer.write_event(Error(get_time(), "YouShallNotPass"));
        return;
    }

    club_data.add_client(client_name_);
}

std::string ClientArrived::to_str() const {
    return get_time().to_str() + " " + std::to_string(get_type()) + " " + client_name_;
}