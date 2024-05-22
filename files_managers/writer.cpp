#include "writer.h"

Writer::Writer(const std::string &file_name) {
    stream_ = std::ofstream(file_name, std::ios::binary);
}

Writer &Writer::get_writer(const std::string &file_name) {
    static Writer result = Writer(file_name);
    return result;
}

Writer &Writer::get_writer() {
    return get_writer("");
}

void Writer::write_int(int el) {
    stream_ << el << "\n";
}

void Writer::write_time(const std::pair<MyTime, MyTime> &time) {
    stream_ << time.first.to_str() << " " << time.second.to_str() << "\n";
}

void Writer::write_event(const Event &event) {
    stream_ << event.to_str() << "\n";
}