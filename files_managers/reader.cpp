#include "reader.h"
#include "my_exception.h"
#include "client_arrived.h"
#include "client_waiting.h"
#include "client_left.h"
#include "client_sat.h"

#include <iostream>

std::vector<std::string> Reader::split(const std::string &str) const {
    std::vector<std::string> it{""};
    for (size_t i = 0; i < str.size(); ++i) {
        if (str[i] == ' ') {
            it.push_back("");
            continue;
        }
        it.back() += str[i];
    }
    return it;
}

int Reader::str_to_int(const std::string &str) const {
    if (str.size() == 0) {
        throw WrongFormatException();
    }
    int it = 0;
    for (size_t i = 0; i < str.size(); ++i) {
        if (str[i] < '0' || str[i] > '9') {
            throw WrongFormatException();
        }
        it = i * 10 + str[i] - '0';
    }
    return it;
}

bool Reader::is_name_valid(const std::string &str) const {
    for (size_t i = 0; i < str.size(); ++i) {
        if (!(islower(str[i]) || isdigit(str[i]) || str[i] == '_' || str[i] == '-')) {
            return false;
        }
    }
    return true;
}

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

    return str_to_int(str);
}

std::pair<MyTime, MyTime> Reader::read_time() {
    std::string str;
    std::getline(stream_, str);

    auto strs = split(str);
    if (strs.size() != 2) {
        throw WrongFormatException();
    }
    return {MyTime(strs[0]), MyTime(strs[1])};
}

std::unique_ptr<Event> Reader::read_event() {
    std::string str;
    std::getline(stream_, str);
    if (str == "") {
        throw EndFile();
    }

    auto strs = split(str);
    if (strs.size() < 2) {
        throw WrongFormatException();
    }

    EventType::Type type = static_cast<EventType::Type>(str_to_int(strs[1]));
    MyTime time(strs[0]);

    switch(type) {
        case EventType::ClientArrived:
            if (strs.size() != 3 || !is_name_valid(strs[2])) {
                throw WrongFormatException();
            }
            return std::unique_ptr<Event>(new ClientArrived(time, type, strs[2]));
        case EventType::ClientWaiting:
            if (strs.size() != 3 || !is_name_valid(strs[2])) {
                throw WrongFormatException();
            }
            return std::unique_ptr<Event>(new ClientWaiting(time, type, strs[2]));
        case EventType::ClientSat:
            if (strs.size() != 4 || !is_name_valid(strs[2])) {
                throw WrongFormatException();
            }
            return std::unique_ptr<Event>(new ClientSat(time, type, strs[2], str_to_int(strs[3])));
        case EventType::СlientLeft:
            if (strs.size() != 3 || !is_name_valid(strs[2])) {
                throw WrongFormatException();
            }
            return std::unique_ptr<Event>(new ClientLeft(time, type, strs[2]));
        case EventType::OutgoingEventСlientLeft:
        case EventType::OutgoingEventClientSat:
        case EventType::Error:
            throw WrongFormatException();
    }
    throw EndFile();
}