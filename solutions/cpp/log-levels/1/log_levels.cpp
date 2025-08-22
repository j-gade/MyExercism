#include <string>

namespace log_line {
    std::string message(std::string line) {
        // return the message
        auto start = line.find(": ");
        if (start == line.npos)
            return line;
        return line.substr(start + 2);
    }

    std::string log_level(std::string line) {
        // return the log level
        auto start = line.find('[');
        auto end = line.find(']');
        if (start == line.npos || end == line.npos)
            return "[]";
        return line.substr(start + 1, end - 1);
    }

    std::string reformat(std::string line) {
        // return the reformatted message
        auto level = " (" + log_level(line) + ')';
        auto msg = message(line);
        auto result = msg + level;
        return result;
    }
}
