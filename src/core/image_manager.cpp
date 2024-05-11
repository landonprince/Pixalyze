// By: Landon Prince (5/10/2024)

#include "core/image_manager.h"

void ImageManager::loadImage(const std::string& filePath) {
    try {
        image = cv::imread(filePath);
    } catch (std::exception& e) {
        std::cout << "failed to load image: " << e.what() << std::endl;
    }
    if (image.empty()) {
        std::cout << "failed to load image" << std::endl;
    }
    else {
        std::cout << "image successfully loaded" << std::endl;
    }
}
