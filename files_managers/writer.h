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
    static Writer &get_writer(const std::string&);
    static Writer &get_writer();

    void write_int(int);
    void write_time(const std::pair<MyTime, MyTime> &time);
    void write_event(const Event&);
};