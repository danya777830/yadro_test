#pragma once

#include <vector>
#include <string>
#include <unordered_map>

#include "my_time.h"

class TableManager {
private:
    std::unordered_map<std::string, int> clients_;
    std::vector<bool> is_table_occupied_;
    std::vector<MyTime> when_is_empty_;

    std::vector<int> money_at_table_;
public:
    TableManager(int, int);
    TableManager() = default;
    bool is_client_inside(const std::string&) const;
    void delete_client(const std::string&);
    void client_sit(const std::string&, int, const MyTime&);

    bool is_table_occupied(int) const;
};