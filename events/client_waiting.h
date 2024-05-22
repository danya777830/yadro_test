#include "event.h"

class ClientWaiting : public Event {
private:
    std::string client_name_;

public:
    ClientWaiting(const MyTime &time, const EventType::Type &type, const std::string &client_name) : Event(time, type) {
        client_name_ = client_name;
    }
    virtual void start(ClubData&);
    virtual std::string to_str() const;
};