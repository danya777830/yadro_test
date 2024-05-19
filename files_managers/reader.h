#pragma once

#include "event.h"
#include "time.h"

#include <memory>
#include <string>
#include <fstream>
#include <exception>

class InputException : public std::exception {
    
};

class Reader {
private:
    std::ifstream stream_;

    Reader() = default;
    Reader(const Reader &other) = delete;
    Reader &operator=(const Reader &other) = delete;
    Reader (const std::string &file_name);

public:
    static Reader &GetReader(const std::string &file_name);


    int read_int();
    std::pair<MyTime, MyTime> read_time();
    std::unique_ptr<Event::Event> read_event();
};