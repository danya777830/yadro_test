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

public:
    static Reader &GetReader(const std::string&);

    int read_int();
    std::pair<MyTime, MyTime> read_time();
    std::unique_ptr<Event::Event> read_event();
};