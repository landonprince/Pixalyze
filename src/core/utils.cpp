// By: Landon Prince (5/10/2024)

#include "core/utils.h"
#include <string>
#include <filesystem>
#include <opencv2/opencv.hpp>

std::string Utils::strLower(std::string s) {
    std::transform(
            s.begin(), s.end(), s.begin(),
            [](unsigned char c) { return std::tolower(c); }
    );
    return s;
}

bool Utils::isSupported(const std::string &filename) {
    const std::set<std::string> supportedExtensions = {
            ".jpg", ".jpeg", ".png", ".bmp", ".tif", ".tiff", ".webp", ".jp2"
    };
    std::string extension = std::filesystem::path(filename).extension().string();
    std::transform(extension.begin(), extension.end(), extension.begin(),
                   [](unsigned char c) { return std::tolower(c); });
    return supportedExtensions.find(extension) != supportedExtensions.end();
}

cv::Scalar Utils::getColorScalar(const std::string& colorName) {
    auto it = colorMap.find(colorName);
    if (it != colorMap.end()) {
        return it->second;
    } else {
        throw std::invalid_argument("Color not found");
    }
}

const std::map<std::string, cv::Scalar>& Utils::getColorMap() {
    return colorMap;
}

const std::map<std::string, cv::Scalar> Utils::colorMap = {
        {"black", cv::Scalar(0, 0, 0)},
        {"white", cv::Scalar(255, 255, 255)},
        {"red", cv::Scalar(0, 0, 255)},
        {"green", cv::Scalar(0, 255, 0)},
        {"blue", cv::Scalar(255, 0, 0)},
        {"yellow", cv::Scalar(0, 255, 255)},
        {"cyan", cv::Scalar(255, 255, 0)},
        {"magenta", cv::Scalar(255, 0, 255)},
        {"gray", cv::Scalar(128, 128, 128)},
        {"dark Red", cv::Scalar(0, 0, 139)},
        {"dark Green", cv::Scalar(0, 100, 0)},
        {"dark Blue", cv::Scalar(139, 0, 0)},
        {"orange", cv::Scalar(0, 165, 255)},
        {"pink", cv::Scalar(203, 192, 255)},
        {"purple", cv::Scalar(128, 0, 128)},
        {"brown", cv::Scalar(42, 42, 165)},
        {"light gray", cv::Scalar(211, 211, 211)},
        {"dark gray", cv::Scalar(169, 169, 169)}
};

