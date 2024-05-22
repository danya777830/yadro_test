#include "table_manager.h"

TableManager::TableManager(int table_count, int price) {
    clients_ = std::unordered_map<std::string, int>();
    is_table_occupied_ = std::vector<bool>(table_count, false);
    when_is_occupied_ = std::vector<MyTime>(table_count);
    money_at_table_ = std::vector<int>(table_count);
    how_long_occupied_ = std::vector<MyTime>(table_count);
    count_occupied_tables_ = 0;
    price_ = price;
    count_table_ = table_count;
}

bool TableManager::is_client_inside(const std::string& client_name) const {
    return clients_.find(client_name) != clients_.end();
}

int TableManager::get_count_table() const {
    return count_table_;
}

int TableManager::delete_client(const std::string &client_name, const MyTime &time) {
    if (clients_.find(client_name) == clients_.end()) {
        return -1;
    }

    auto table_nomber = clients_[client_name];
    MyTime how_mutch = time - when_is_occupied_[table_nomber - 1];
    money_at_table_[table_nomber - 1] += price_ * how_mutch.not_full_hours();
    how_long_occupied_[table_nomber - 1] = how_long_occupied_[table_nomber - 1] + how_mutch;
    is_table_occupied_[table_nomber - 1] = false;
    clients_.erase(client_name);

    --count_occupied_tables_;
    return table_nomber;
}

void TableManager::client_sit(const std::string &client_name, int table_nomber, const MyTime &time) {
    if (clients_.find(client_name) != clients_.end()) {
        delete_client(client_name, time);
    }

    clients_[client_name] = table_nomber;
    is_table_occupied_[table_nomber - 1] = true;
    when_is_occupied_[table_nomber - 1] = time;
    ++count_occupied_tables_;
}

bool TableManager::is_table_occupied(int table_nomber) const{
    return is_table_occupied_[table_nomber - 1];
}

bool TableManager::is_empty_table() const {
    return count_occupied_tables_ < count_table_;
}

std::vector<std::pair<int, MyTime>> TableManager::get_profit() const {
    std::vector<std::pair<int, MyTime>> it;
    for (int i = 0; i < count_table_; ++i) {
        it.push_back({money_at_table_[i], how_long_occupied_[i]});
    }
    return it;
}

std::string TableManager::get_client() const{
    return clients_.begin()->first;
}

int TableManager::size() const{
    return clients_.size();
}