#include "table_manager.h"

TableManager::TableManager(int table_count, int price) {
    clients_ = std::unordered_map<std::string, int>();
    is_table_occupied_ = std::vector<bool>(table_count, false);
    when_is_empty_ = std::vector<MyTime>(table_count);
    money_at_table_ = std::vector<int>(table_count);
}

bool TableManager::is_client_inside(const std::string& client_name) const {
    return clients_.find(client_name) != clients_.end();
}

void TableManager::delete_client(const std::string &client_name) {

}

void TableManager::client_sit(const std::string &client_name, int table_count, const MyTime &time) {
    if (clients_.find(client_name) != clients_.end()) {
        delete_client(client_name);
    }

    clients_[client_name] = table_count;
    is_table_occupied_[table_count] = true;
    when_is_empty_[table_count] = time;
}

bool TableManager::is_table_occupied(int table_nomber) const{
    return is_table_occupied_[table_nomber];
}