#include "table_manager.h"
#include "client_queue.h"

#include <string>

class ClubData {
private:
    TableManager table_manager_;
    ClientQueue client_queue_;

public:
    void delete_user(const std::string& client_name);
};