#include <string>
#include <sstream>
#include <stdexcept>

using namespace std;

int parseHex(char *hexString) {
    istringstream is(hexString);
    int result;
    if (is >> std::hex >> result && is.eof())
        return result;
    else
        throw runtime_error("Hex number format error");
}