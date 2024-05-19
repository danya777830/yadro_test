#include "../events/event.hpp"

#include <memory>

class Reader {
private:

public:
    std::unique_ptr<Event::Event> read_event() {}
};