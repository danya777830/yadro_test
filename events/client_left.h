#include "event.h"

class ClientLeft : public Event {
private:
    std::string client_name_;

public:
    ClientLeft(MyTime time, EventType::Type type, std::string client_name) : Event(time, type) {
        client_name_ = client_name;
    }
    virtual void start(ClubData&);
};