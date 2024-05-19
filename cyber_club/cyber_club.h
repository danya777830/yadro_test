#include "reader.h"
#include "writer.h"

#include "club_data.h"

class CyberClub {
private:
    Reader &reader_;
    Writer &writer_;
    ClubData club_data_;
    
    std::pair<MyTime, MyTime> time_;

public:
    CyberClub (Reader &reader, Writer &writer) : reader_(reader), writer_(writer) {
        auto table_count = reader.read_int();
        auto time = reader.read_time();
        auto price = reader.read_int();

        club_data_ = ClubData(table_count, price);
    }
    void start();
};