// By: Landon Prince (5/10/2024)

#ifndef PIXALYZE_UTILS_H
#define PIXALYZE_UTILS_H

#include <algorithm>
#include <string>
#include <filesystem>
#include <fstream>
#include <opencv2/opencv.hpp>

class Utils final {
public:
    Utils() = delete;
    ~Utils() = delete;
    Utils(const Utils&) = delete;
    Utils& operator=(const Utils&) = delete;

    /**
     * Transform a std::string to all lowercase characters
     * @param s input string to transform
     * @return std::string with lowercase characters
     */
    static std::string strLower(std::string s);

    /**
     * Determines if a file has a supported extension type
     * @param filename name of file with extension
     * @return true if supported, false otherwise
     */
    static bool isSupported(const std::string &filename);

    /**
     * Gets associated scalar from colorMap given color name
     * @param colorName name of color to get scalar of
     * @return cv::Scalar object of color
     */
    static cv::Scalar getColorScalar(const std::string& colorName);

    /**
     * Gets associated scalar from colorMap given color name
     * @param colorName name of color to get scalar of
     * @return cv::Scalar object of color
     */
    static const std::map<std::string, cv::Scalar>& getColorMap();

    /**
     * Enables customized console output
     */
    static void enableVirtualTerminalProcessing();

    /**
     * prints a line to separate console output
     */
    static void addSeparator();

private:
    static const std::map<std::string, cv::Scalar> colorMap;
};

#endif //PIXALYZE_UTILS_H
