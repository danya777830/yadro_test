#pragma once

#include <string>
#include <unordered_map>
#include <memory>

class ClientQueue{
private:
    struct QueueLink {
        std::string client_name;
        QueueLink *next;
        QueueLink *previous;
    };

    QueueLink *first_ = nullptr;
    QueueLink *last_ = nullptr;

    std::unordered_map<std::string, std::unique_ptr<QueueLink>> clients_;

public:
    bool is_client_inside(const std::string&) const;
    void delete_client(const std::string&);
};