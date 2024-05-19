#include "event.h"

class ClientLeft : public Event {
public:
    virtual void start(ClubData &club_dagta);
};