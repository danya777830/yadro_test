#include "cyber_club.h"
#include "event.h"

#include <memory>

CyberClub::CyberClub() {
    Reader &reader = Reader::get_reader();
    Writer &writer = Writer::get_writer();
    auto table_count = reader.read_int();
    auto time = reader.read_time();
    auto price = reader.read_int();

    club_data_ = ClubData(table_count, price);
}

CyberClub &CyberClub::get_club() {
    static CyberClub club = CyberClub();
    return club;
}

void CyberClub::start() {
    Reader &reader = Reader::get_reader();
    Writer &writer = Writer::get_writer();
    writer.write_int(1);
    writer.write_int(2);
    return;
    while(true) {
        try {
            auto event = reader.read_event();
            event->start(club_data_);
        } catch (...) {
            return;
        }
    }
}