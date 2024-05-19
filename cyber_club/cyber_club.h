#include "../files_managers/reader.h"
#include "../files_managers/writer.h"

class CyberClub {
private:
    Reader &reader_;
    Writer &writer_;

public:
    CyberClub(Reader &reader, Writer &writer);
    void start();

};