#include "event.h"

class ClientSat : public Event {
private:
    std::string client_name_;
    int table_nomber_;

public:
    ClientSat(MyTime time, EventType::Type type, std::string client_name, int table_nomber) : Event(time, type) {
        client_name_ = client_name;
        table_nomber_ = table_nomber;
    }
    virtual void start(ClubData&);
    virtual std::string to_str() const;
};