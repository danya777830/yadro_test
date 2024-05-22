#include "club_data.h"

ClubData::ClubData(int table_count, const MyTime &begin_time, const MyTime &end_time, int price) {
    end_time_ = end_time;
    begin_time_ = begin_time;
    table_manager_ = TableManager(table_count, price);
    client_queue_ = ClientQueue();
    clients_ = std::unordered_set<std::string>();
}

bool ClubData::is_client_inside(const std::string& client_name) const {
    return table_manager_.is_client_inside(client_name) ||
           client_queue_.is_client_inside(client_name) ||
           clients_.find(client_name) != clients_.end();
}

void ClubData::delete_client(const std::string &client_name) {
    table_manager_.delete_client(client_name);
    client_queue_.delete_client(client_name);
    clients_.erase(client_name);
}

void ClubData::add_client(const std::string &client_name) {
    clients_.insert(client_name);
}

void ClubData::client_sit(const std::string &client_name, int table_count, const MyTime &time) {
    if (!is_client_inside(client_name)) {
        return;
    }

    clients_.erase(client_name);
    client_queue_.delete_client(client_name);
    table_manager_.client_sit(client_name, table_count, time);
}

bool ClubData::is_table_occupied(int table_nomber) const{
    return table_manager_.is_table_occupied(table_nomber);
}

bool ClubData::is_open(const MyTime& time) const {
    return !(time < begin_time_ || end_time_ < time);
}