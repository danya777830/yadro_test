#pragma once

#include "event.h"
#include "time.h"

#include <memory>
#include <string>
#include <fstream>


class Writer {
    std::ofstream stream_;

    Writer() = default;
    Writer(const Writer&) = delete;
    Writer &operator=(const Writer&) = delete;
    Writer (const std::string&);

public:
    static Writer &GetWriter(const std::string&);

    void write_int(int);
    void write_time(const std::pair<MyTime, MyTime> &time);
    std::unique_ptr<Event::Event> write_event();
};