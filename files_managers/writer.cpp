#include "writer.h"

Writer::Writer(const std::string &file_name) {
    stream_ = std::ofstream(file_name, std::ios::binary);
}

Writer &Writer::GetWriter(const std::string &file_name) {
    static Writer result = Writer(file_name);
    return result;
}

void Writer::write_int(int el) {
    stream_ << el << "\n";
}

void Writer::write_time(const std::pair<MyTime, MyTime> &time) {
    stream_ << time.first.to_str() << " " << time.second.to_str() << "\n";
}