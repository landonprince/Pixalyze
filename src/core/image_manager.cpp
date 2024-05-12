// By: Landon Prince (5/10/2024)

#include "core/image_manager.h"
#include <opencv2/highgui/highgui.hpp>

void ImageManager::loadImage(const std::string& filePath) {
    imagePath = filePath;
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

void ImageManager::showImage() const {
    if (image.empty()) {
        throw std::logic_error("no image loaded");
    }
    else {
        std::cout << "opening " << imagePath << std::endl;
        cv::imshow(imagePath, image);
        cv::waitKey(0);
    }
}
