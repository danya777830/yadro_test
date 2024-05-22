#include "client_queue.h"

int ClientQueue::size() const {
    return clients_.size();
}

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

void ClientQueue::add_client(const std::string &client_name) {
    QueueLink *link = new QueueLink{};
    link->client_name = client_name;

    link -> previous = last_;
    link -> next = nullptr;
    if (!first_) {
        first_ = link;
    }
    clients_[client_name] = std::unique_ptr<QueueLink>(link);
}

std::string ClientQueue::get_client() const {
    return first_->client_name;
}