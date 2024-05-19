#include "club_data.h"

ClubData::ClubData(int table_count, int price_data) {

}

bool ClubData::is_client_inside(const std::string& client_name) const {
    return table_manager_.is_client_inside(client_name) ||
           client_queue_.is_client_inside(client_name);
}