#include "event.h"

MyTime Event::get_time() const {
    return time_;
}

EventType::Type Event::get_type() const {
    return type_;
}