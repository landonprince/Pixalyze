// By: Landon Prince (5/10/2024)

#ifndef PIXALYZE_UTILS_H
#define PIXALYZE_UTILS_H

#include <algorithm>
#include <string>

/**
 * Transform a std::string to all lowercase characters
 * @param s input string to transform
 * @return std::string with lowercase characters
 */
inline std::string strLower(std::string s)
{
    std::transform(
            s.begin(), s.end(), s.begin(),
            [](unsigned char c) { return std::tolower(c); }
    );
    return s;
}

#endif //PIXALYZE_UTILS_H
