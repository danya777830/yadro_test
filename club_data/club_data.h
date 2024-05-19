#pragma once

#include "table_manager.h"
#include "client_queue.h"
#include "my_time.h"

#include <string>

class ClubData {
private:
    TableManager table_manager_;
    ClientQueue client_queue_;
    MyTime end_time_;
    MyTime begin_time_;

public:
    ClubData() = default;
    ClubData(int, int);

    bool is_client_inside(const std::string&) const;
    void delete_user(const std::string&);
};