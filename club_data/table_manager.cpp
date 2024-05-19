#include "table_manager.h"

TableManager::TableManager(int table_count, int price) {
    clients_ = std::unordered_map<std::string, int>();
    is_table_emty_ = std::vector<bool>(table_count, false);
    when_is_empty_ = std::vector<MyTime>(table_count);
}

bool TableManager::is_client_inside(const std::string& client_name) const {
    return clients_.find(client_name) != clients_.end();
}