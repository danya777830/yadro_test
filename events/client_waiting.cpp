#include "client_waiting.h"
#include "writer.h"
#include "error.h"
#include "client_left.h"

void ClientWaiting::start(ClubData &club_data) {
    Writer &writer = Writer::get_writer();

    if (club_data.is_empty_table()) {
        writer.write_event(Error(get_time(), "ICanWaitNoLonger"));
        return;
    }

    if (club_data.get_queue_size() > club_data.get_count_table()) {
        std::unique_ptr<Event> event = std::unique_ptr<Event>(new ClientLeft(get_time(), EventType::OutgoingEventСlientLeft, client_name_));
        writer.write_event(*event);
        event->start(club_data);
        return;
    }

    club_data.add_to_queue(client_name_);
}

std::string ClientWaiting::to_str() const {
    return get_time().to_str() + " " + std::to_string(get_type()) + " " + client_name_;
}