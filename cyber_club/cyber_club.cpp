#include "cyber_club.h"
#include "event.h"

#include <memory>

void CyberClub::start() {
    writer_.write_int(1);
    writer_.write_int(2);
    return;
    while(true) {
        try {
            auto event = reader_.read_event();
            event->start(club_data_);
        } catch (...) {
            return;
        }
    }
}