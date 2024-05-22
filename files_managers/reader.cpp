#include "reader.h"
#include "my_exception.h"

#include "client_arrived.h"

Reader::Reader(const std::string &file_name) {
    stream_ = std::ifstream(file_name, std::ios::binary);
}

Reader &Reader::get_reader(const std::string &file_name) {
    static Reader result = Reader(file_name);
    return result;
}

Reader &Reader::get_reader() {
    return get_reader("");
}

int Reader::read_int() {
    std::string str;
    std::getline(stream_, str);

    int it = 0;
    for (size_t i = 0; i < str.size(); ++i) {
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
    for (size_t i = 0; i < str.size(); ++i) {
        if (str[i] == ' ' && !f) {
            f = true;
            continue;
        }
        if (f) {
            b += str[i];
        }
        else {
            a += str[i];
        }
    }
    return {MyTime(a), MyTime(b)};
}

std::unique_ptr<Event> Reader::read_event() {
    std::string str;
    std::getline(stream_, str);
    if (str == "") {
        throw EndFile();
    }

    int cnt_space = 0;
    std::string time;
    int nomber;
    size_t i = 0;
    for (; i < str.size(); ++i) {
        if (str[i] == ' ') {
            ++cnt_space;
            if (cnt_space > 1) {
                break;
            }
            continue;
        }
        if (cnt_space == 0) {
            time += str[i];
        }
        else {
            nomber = nomber * 10 + str[i] - '0';
        }
    }
    EventType::Type type = static_cast<EventType::Type>(nomber);
    MyTime time(time);
    switch(type) {
        case EventType::ClientArrived:
            std::string name;
            for (size_t i = 0; i < str.size(); ++i) {
                if (!(islower(str[i]) || isdigit(str[i]) || str[i] == '_' || str[i] == '-')) {
                    throw WrongFormatException();
                }
                name += str[i];
            }
            return std::unique_ptr<Event>(new ClientArrived(time, type, name));
    }
    throw EndFile();
}