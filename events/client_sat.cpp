#include "client_sat.h"
#include "writer.h"

void ClientSat::start(ClubData &club_data) {
    Writer &writer = Writer::get_writer();

    if (!club_data.is_client_inside(client_name_)) {
        
    }
    if (!club_data.is_table_occupied(table_nomber_)) {

    }

    club_data.client_sit(client_name_, table_nomber_, get_time());
}

std::string ClientSat::to_str() const {
    return "1";
}