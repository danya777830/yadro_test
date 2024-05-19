#include "cyber_club.h"
#include "reader.h"
#include "writer.h"

int main(int argc, char *argv[]) {
    std::string file_name = argv[1];

    Reader &reader = Reader::GetReader(file_name);
    Writer writer;
    CyberClub cyber_club(reader, writer);

    cyber_club.start();
}