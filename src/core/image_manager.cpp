// By: Landon Prince (5/10/2024)

#include "core/image_manager.h"
#include <opencv2/highgui/highgui.hpp>
#include <filesystem>
#include <fstream>

void ImageManager::loadImage(const std::string& filePath) {
    imagePath = filePath;
    try {
        image = cv::imread(filePath, cv::IMREAD_UNCHANGED);
    } catch (std::exception &e) {
        std::cout << "failed to load image: " << e.what() << std::endl;
    }
    if (image.empty()) {
        std::cout << "failed to load image" << std::endl;
    } else {
        std::cout << "image successfully loaded" << std::endl;
    }
    size_t pos = imagePath.find_last_of("\\/");
    if (pos != std::string::npos) {
        imageName = imagePath.substr(pos + 1);
    }
}

void ImageManager::showImage() const {
    if (image.empty()) {
        throw std::logic_error("no image loaded");
    }
    else {
        std::cout << "opening " << imageName << std::endl;
        cv::imshow(imagePath, image);
        cv::waitKey(0);
    }
}

void ImageManager::printInfo() const {
    if (image.empty()) {
        throw std::logic_error("no image loaded");
    }
    else {
        std::cout << "Size: " << image.size() << std::endl;
        std::cout << "Rows: " << image.rows << ", Cols: " << image.cols << std::endl;
        std::cout << "Type: " << image.type() << std::endl;
        std::cout << "Depth: " << image.depth() << std::endl;
        std::cout << "Channels: " <<  image.channels() << std::endl;
        std::cout << "Step: " << image.step << " bytes" << std::endl;
        std::cout << "Element Size: " << image.elemSize() << " bytes" << std::endl;
        std::cout << "Total Elements: " << image.total() << std::endl;
    }
}

void ImageManager::toGray() {
    if (image.empty()) {
        throw std::logic_error("no image loaded");
    }
    else if (image.channels() == 1) {
        throw std::logic_error("image is already in grayscale");
    }
    else {
        cv::cvtColor(image, image, cv::COLOR_BGR2GRAY);
        std::cout << "converted " + imageName << " to grayscale" << std::endl;
    }
}

void ImageManager::toColor() {
    if (image.empty()) {
        throw std::logic_error("no image loaded");
    }
    else if (image.channels() == 3) {
        throw std::logic_error("image is already in color");
    }
    else {
        cv::cvtColor(image, image, cv::COLOR_GRAY2BGR);
        std::cout << "converted " + imageName << " to color" << std::endl;
    }
}

void ImageManager::findEdges() {
    if (image.empty()) {
        throw std::logic_error("no image loaded");
    }
    if (image.channels() != 1) {
        cv::cvtColor(image, image, cv::COLOR_BGR2GRAY);
    }
    cv::Canny(image, image, 50, 150, 3);
    std::cout << "edge detection successful" << std::endl;
}

void ImageManager::saveASCII() const {
    if (image.empty()) {
        throw std::logic_error("no image loaded");
    }
    if (image.channels() != 1) {
        cv::cvtColor(image, image, cv::COLOR_BGR2GRAY);
    }
    const char *levels = "@%#*+=-:. ";
    size_t scale = 255 / (strlen(levels) - 1);
    std::string ascii;

    for (int i = 0; i < image.rows; i++) {
        for (int j = 0; j < image.cols; j++) {
            auto brightness = image.at<uchar>(i, j);
            char ascii_char = levels[brightness / scale];
            ascii += ascii_char;
        }
        ascii += '\n';
    }
    if (!ascii.empty()) {
        std::ofstream file("ascii_" + imageName + ".txt");
        if (file.is_open()) {
            file << ascii;
            file.close();
            std::cout << "ASCII art has been saved to ascii_" << imageName
            << ".txt" << std::endl;
        } else {
            throw std::logic_error("failed to convert image to ASCII");
        }

    }
}

void ImageManager::saveImage() const {
    if (image.empty()) {
        throw std::logic_error("no image loaded");
    }
    std::string outFile = "pix_" + imageName;
    if (cv::imwrite(outFile, image)) {
        std::cout << "image saved to " + outFile << std::endl;
    }
    else {
        throw std::logic_error("failed to save image");
    }
}

void ImageManager::blurImage() {
    if (image.empty()) {
        throw std::logic_error("no image loaded");
    }
    cv::GaussianBlur(image, image, cv::Size(27, 27), 25);
    std::cout << "image successfully blurred" << std::endl;
}

void ImageManager::smoothImage(int intensity) {
    if (image.empty()) {
        throw std::logic_error("no image loaded");
    }
    if (intensity == 1) {
        cv::GaussianBlur(image, image, cv::Size(5, 5), 3);
        std::cout << "image successfully smoothed (intensity 1)" << std::endl;
    }
    else if (intensity == 2) {
        cv::GaussianBlur(image, image, cv::Size(7, 7), 5);
        std::cout << "image successfully smoothed (intensity 2)" << std::endl;
    }
    else if (intensity == 3) {
        cv::GaussianBlur(image, image, cv::Size(9, 9), 7);
        std::cout << "image successfully smoothed (intensity 3)" << std::endl;
    }
}