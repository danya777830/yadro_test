#pragma once

#include "table_manager.h"
#include "client_queue.h"
#include "my_time.h"

#include <string>
#include <unordered_set>

class ClubData {
private:
    TableManager table_manager_;
    ClientQueue client_queue_;
    std::unordered_set<std::string> clients_;
    MyTime end_time_;
    MyTime begin_time_;

public:
    ClubData() = default;
    ClubData(int, const MyTime&, const MyTime&, int);

    bool is_client_inside(const std::string&) const;
    int delete_client(const std::string&, const MyTime&);

    MyTime get_begin_time() const;
    MyTime get_end_time() const;

    int size() const;
    int get_count_table() const;
    int get_queue_size() const;
    std::string get_client_from_queue();

    void add_client(const std::string&);
    void add_to_queue(const std::string&);
    void client_sit(const std::string&, int, const MyTime&);

    bool is_table_occupied(int) const;
    bool is_open(const MyTime&) const;
    bool is_empty_table() const;

    std::vector<std::pair<int, MyTime>> get_profit() const;
    std::string get_client() const;
};