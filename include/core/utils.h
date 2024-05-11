// By: Landon Prince (5/10/2024)

#ifndef PIXALYZE_UTILS_H
#define PIXALYZE_UTILS_H

#include <algorithm>
#include <string>
#include <filesystem>
#include <fstream>
#include <opencv2/opencv.hpp>

/**
 * Transform a std::string to all lowercase characters
 * @param s input string to transform
 * @return std::string with lowercase characters
 */
inline std::string strLower(std::string s) {
    std::transform(
            s.begin(), s.end(), s.begin(),
            [](unsigned char c) { return std::tolower(c); }
    );
    return s;
}

inline bool isSupported(const std::string &filename) {
    const std::set<std::string> supportedExtensions = {
            ".jpg", ".jpeg", ".png", ".bmp", ".tif", ".tiff", ".webp", ".jp2"
    };
    std::string extension = std::filesystem::path(filename).extension().string();
    std::transform(extension.begin(), extension.end(), extension.begin(),
                   [](unsigned char c) { return std::tolower(c); });
    return supportedExtensions.find(extension) != supportedExtensions.end();
}

#endif //PIXALYZE_UTILS_H
