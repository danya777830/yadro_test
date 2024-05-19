#include "cyber_club.h"
#include "reader.h"
#include "writer.h"
#include "my_exception.h"

const std::string OUTPUT_FILE = "out.txt";
const std::string INPUT_FILE = "in.txt";

int main(int argc, char *argv[]) {
    std::string file_name;
    if (argc > 1) {
        file_name = std::string(argv[1]);
    }
    else {
        file_name = INPUT_FILE;
    }

    Reader &reader = Reader::GetReader(file_name);
    Writer &writer = Writer::GetWriter(OUTPUT_FILE);
    CyberClub cyber_club(reader, writer);

    cyber_club.start();
}