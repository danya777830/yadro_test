#include "club_data.h"

#include <iostream>

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

MyTime ClubData::get_begin_time() const {
    return begin_time_;
}

MyTime ClubData::get_end_time() const {
    return end_time_;
}

int ClubData::size() const {
    return clients_.size() + client_queue_.size() + table_manager_.size();
}

int ClubData::delete_client(const std::string &client_name, const MyTime &time) {
    client_queue_.delete_client(client_name);
    clients_.erase(client_name);
    return table_manager_.delete_client(client_name, time);
}

int ClubData::get_count_table() const {
    return table_manager_.get_count_table();
};

int ClubData::get_queue_size() const{
    return client_queue_.size();
}

void ClubData::add_client(const std::string &client_name) {
    clients_.insert(client_name);
}

void ClubData::add_to_queue(const std::string &client_name) {
    if (clients_.find(client_name) != clients_.end()) {
        clients_.erase(client_name);
    } else {
        return;
    }

    client_queue_.add_client(client_name);
}

std::string ClubData::get_client_from_queue() {
    return client_queue_.get_client();
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

bool ClubData::is_empty_table() const {
    return table_manager_.is_empty_table();
}

std::vector<std::pair<int, MyTime>> ClubData::get_profit() const {
    return table_manager_.get_profit();
}

std::string ClubData::get_client() const {
    if (clients_.size() != 0) {
        return *clients_.begin();
    }
    if (client_queue_.size() != 0) {
        return client_queue_.get_client();
    }
    if (table_manager_.size() != 0) {
        return table_manager_.get_client();
    }
}