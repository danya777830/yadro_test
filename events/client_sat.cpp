#include "client_sat.h"
#include "writer.h"
#include "error.h"

void ClientSat::start(ClubData &club_data) {
    Writer &writer = Writer::get_writer();

    if (!club_data.is_client_inside(client_name_)) {
        writer.write_event(Error(get_time(), "ClientUnknown"));
        return;
    }
    if (club_data.is_table_occupied(table_nomber_)) {
        writer.write_event(Error(get_time(), "PlacelsBusy"));
        return;
    }

    club_data.client_sit(client_name_, table_nomber_, get_time());
}

std::string ClientSat::to_str() const {
    return get_time().to_str() + " " + std::to_string(get_type()) + " " + client_name_ + " " + std::to_string(table_nomber_);
}