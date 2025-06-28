#pragma once

#include <string>

namespace InputUtils {

    void flushStdin(void);

    std::string safeGetLine(const std::string&);
    int safeGetInt(const std::string&);
    int safeGetIntegerInRange(const std::string&, int, int );
    float safeGetFloat(const std::string&);
}
