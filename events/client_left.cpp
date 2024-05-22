#include "client_left.h"
#include "my_exception.h"

void ClientLeft::start(ClubData &club_data) {
    if (!club_data.is_client_inside(client_name_)) {
        throw ClientUnknown();
    }

    club_data.delete_client(client_name_);
}