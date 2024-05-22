#include "event.h"

class ClientArrived : public Event {
private:
    std::string client_name_;

public:
    ClientArrived(MyTime time, EventType::Type type, std::string client_name) : Event(time, type) {
        client_name_ = client_name;
    }
    virtual void start(ClubData&);
    virtual std::string to_str() const;
};