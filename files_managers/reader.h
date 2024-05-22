#pragma once

#include "event.h"
#include "time.h"

#include <memory>
#include <string>
#include <fstream>

class Reader {
private:
    std::ifstream stream_;

    Reader() = default;
    Reader(const Reader&) = delete;
    Reader &operator=(const Reader&) = delete;
    Reader (const std::string&);

    std::vector<std::string> split(const std::string&) const;
    int str_to_int(const std::string&) const;
    bool is_name_valid(const std::string&) const;

public:
    static Reader &get_reader(const std::string&);
    static Reader &get_reader();

    int read_int();
    std::pair<MyTime, MyTime> read_time();
    std::unique_ptr<Event> read_event();
};