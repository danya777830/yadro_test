#include "error.h"

void Error::start(ClubData& club_data) {}

std::string Error::to_str() const {
    return get_time().to_str() + " " + error_name_;
}