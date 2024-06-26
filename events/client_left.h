#include "event.h"

class ClientLeft : public Event {
private:
    std::string client_name_;

public:
    ClientLeft(const MyTime &time, EventType::Type type, const std::string &client_name) : Event(time, type) {
        client_name_ = client_name;
    }
    virtual void start(ClubData&);
    virtual std::string to_str() const;
};