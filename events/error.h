#include "event.h"

#include <string>

class Error : public Event {
private:
    std::string error_name_;

public:
    Error(const MyTime &time, const std::string &error_name) : Event(time, EventType::Error) {
        error_name_ = error_name;
    }
    virtual void start(ClubData&);
    virtual std::string to_str() const;
};