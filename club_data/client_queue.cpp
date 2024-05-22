#include "client_queue.h"

bool ClientQueue::is_client_inside(const std::string &client_name) const {
    return clients_.find(client_name) != clients_.end();
}

void ClientQueue::delete_client(const std::string &client_name) {
    auto client = clients_.find(client_name);
    if (client == clients_.end()) {
        return;
    }

    auto next = client->second->next;
    if (next) {
        next->previous = client->second->previous;
    }
    else {
        last_ = client->second->previous;
    }

    auto previous = client->second->previous;
    if (previous) {
        previous->next = client->second->next;
    }
    else {
        first_ = client->second->next;
    }

    clients_.erase(client_name);
}