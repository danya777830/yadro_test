#pragma once

#include <vector>
#include <string>
#include <unordered_map>

#include "my_time.h"

class TableManager {
private:
    std::unordered_map<std::string, int> clients_;
    std::vector<bool> is_table_emty_;
    std::vector<MyTime> when_is_empty_;

public:
    TableManager(int, int);
    TableManager() = default;
    bool is_client_inside(const std::string&) const;
};