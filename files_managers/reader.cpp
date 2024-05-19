#include "reader.h"
#include "my_exception.h"

Reader::Reader(const std::string &file_name) {
    stream_ = std::ifstream(file_name, std::ios::binary);
}

Reader &Reader::GetReader(const std::string &file_name) {
    static Reader result = Reader(file_name);
    return result;
}

int Reader::read_int() {
    std::string str;
    std::getline(stream_, str);

    int it = 0;
    for (int i = 0; i < str.size(); ++i) {
        if (str[i] < '0' || str[i] > '9') {
            throw WrongFormatException();
        }
        it = i * 10 + str[i] - '0';
    }
    return it;
}

std::pair<MyTime, MyTime> Reader::read_time() {
    std::string str;
    std::getline(stream_, str);

    std::string a, b;
    bool f = false;
    for (int i = 0; i < str.size(); ++i) {
        if (str[i] == ' ') {
            f = true;
        }
        if (f) {
            a += str[i];
        }
        else {
            b += str[i];
        }
    }
    return {MyTime(a), MyTime(b)};
}

std::unique_ptr<Event::Event> Reader::read_event() {

}