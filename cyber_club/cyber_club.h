#include "reader.h"
#include "writer.h"

#include "club_data.h"

class CyberClub {
private:
    ClubData club_data_;
    
    std::pair<MyTime, MyTime> time_;

    CyberClub(const CyberClub&) = delete;
    CyberClub &operator=(const CyberClub&) = delete;

    CyberClub();
public:
    static CyberClub &get_club();

    void start();
};