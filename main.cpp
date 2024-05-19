#include "cyber_club/cyber_club.h"
#include "files_managers/reader.h"
#include "files_managers/writer.h"

int main(int argc, char *argv[]) {
    Reader reader();
    Writer writer();
    CyberClub cyber_club(reader, writer);

    cyber_club.start();
}