#include "client_arrived.h"
#include "writer.h"

void ClientArrived::start(ClubData &club_data) {
    Writer &writer = Writer::get_writer();

    if (!club_data.is_client_inside(client_name_)) {
        
    }

    club_data.add_client(client_name_);
}

std::string ClientArrived::to_str() const {
    return "1";
}