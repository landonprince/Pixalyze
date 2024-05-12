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
    matSize = image.size();
    numRows = image.rows;
    numCols = image.cols;
    matType = image.type();
    depthType = image.depth();
    numChannels = image.channels();
    stepSize = image.step;
    elementSize = image.elemSize();
    totalElements = image.total();
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

void ImageManager::printInfo() const {
    if (image.empty()) {
        throw std::logic_error("no image loaded");
    }
    else {
        std::cout << "Rows: " << numRows << ", Cols: " << numCols << std::endl;
        std::cout << "Type: " << matType << std::endl;
        std::cout << "Depth: " << depthType << std::endl;
        std::cout << "Channels: " << numChannels << std::endl;
        std::cout << "Step: " << stepSize << " bytes" << std::endl;
        std::cout << "Element Size: " << elementSize << " bytes" << std::endl;
        std::cout << "Total Elements: " << totalElements << std::endl;
    }
}
