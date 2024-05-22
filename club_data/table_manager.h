#pragma once

#include <vector>
#include <string>
#include <unordered_map>

#include "my_time.h"

class TableManager {
private:
    std::unordered_map<std::string, int> clients_;
    std::vector<bool> is_table_occupied_;
    std::vector<MyTime> when_is_occupied_;

    std::vector<int> money_at_table_;
    std::vector<MyTime> how_long_occupied_;

    int count_occupied_tables_;
    int count_table_;
    int price_;
public:
    TableManager(int, int);
    TableManager() = default;
    bool is_client_inside(const std::string&) const;
    int delete_client(const std::string&, const MyTime &time);
    void client_sit(const std::string&, int, const MyTime&);

    int get_count_table() const;
    std::string get_client() const;
    bool is_table_occupied(int) const;
    bool is_empty_table() const;
    int size() const;

    std::vector<std::pair<int, MyTime>> get_profit() const;
};