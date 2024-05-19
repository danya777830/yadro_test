#include "table_manager.hpp"
#include "client_queue.hpp"

class ClubData {
private:
    TableManager table_manager_;
    ClientQueue client_queue_;

public:
    void delete_user(const std::string& client_name);
};