#include "cyber_club.h"
#include "event.h"
#include "my_exception.h"
#include "client_left.h"

#include <memory>

CyberClub::CyberClub() {
    Reader &reader = Reader::get_reader();
    Writer &writer = Writer::get_writer();
    auto table_count = reader.read_int();
    auto time = reader.read_time();
    auto price = reader.read_int();

    club_data_ = ClubData(table_count, time.first, time.second, price);
}

CyberClub &CyberClub::get_club() {
    static CyberClub club = CyberClub();
    return club;
}

void CyberClub::start() {
    Reader &reader = Reader::get_reader();
    Writer &writer = Writer::get_writer();
    writer.write_time(club_data_.get_begin_time());
    while(true) {
        try {
            auto event = reader.read_event();
            writer.write_event(*event);
            event->start(club_data_);
        } catch (EndFile) {
            while(club_data_.size() != 0) {
                auto client_name = club_data_.get_client();
                std::unique_ptr<Event> event = std::unique_ptr<Event>(new ClientLeft(club_data_.get_end_time(), EventType::OutgoingEventСlientLeft, client_name));
                writer.write_event(*event);
                event->start(club_data_);
            }
            writer.write_time(club_data_.get_end_time());
            auto profit = club_data_.get_profit();
            for (size_t i = 0; i < profit.size(); ++i) {
                writer.write_profit(i + 1, profit[i]);
            }
            return;
        } catch (...) {
            return;
        }
    }
}