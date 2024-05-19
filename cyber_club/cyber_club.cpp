#include "cyber_club.h"
#include "event.h"

#include <memory>

void CyberClub::start() {
    while(true) {
        try {
            auto event = reader_.read_event();
            event->start(club_data_);
        } catch (...) {

        }
    }
}