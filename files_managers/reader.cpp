#include "reader.h"

Reader::Reader(const std::string &file_name) {
    stream_ = std::ifstream(file_name, std::ios::binary);
}

Reader &Reader::GetReader(const std::string &file_name) {
    static Reader result = Reader(file_name);
    return result;
}

int Reader::read_int() {
    
}

std::pair<MyTime, MyTime> Reader::read_time() {

}

std::unique_ptr<Event::Event> Reader::read_event() {

}