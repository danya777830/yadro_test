#include "client_left.h"
#include "my_exception.h"
#include "writer.h"
#include "error.h"
#include "client_sat.h"

void ClientLeft::start(ClubData &club_data) {
    Writer &writer = Writer::get_writer();

    if (!club_data.is_client_inside(client_name_)) {
        writer.write_event(Error(get_time(), "ClientUnknown"));
        return;
    }

    int table_nomber = club_data.delete_client(client_name_, get_time());
    if (table_nomber != -1 && club_data.get_queue_size() != 0) {
        auto client_name = club_data.get_client_from_queue();
        std::unique_ptr<Event> event = std::unique_ptr<Event>(new ClientSat(get_time(), EventType::OutgoingEventClientSat, client_name, table_nomber));
        writer.write_event(*event);
        event->start(club_data);
    }
}

std::string ClientLeft::to_str() const {
    return get_time().to_str() + " " + std::to_string(get_type()) + " " + client_name_;
}