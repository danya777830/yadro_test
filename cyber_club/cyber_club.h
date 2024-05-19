#include "reader.h"
#include "writer.h"

class CyberClub {
private:
    Reader &reader_;
    Writer &writer_;
    ClubData club_data_;
    
    std::pair<MyTime, MyTime> time_;

public:
    CyberClub (Reader &reader, Writer &writer) : reader_(reader), writer_(writer){

    }
    void start();

    
};