// By: Landon Prince (5/10/2024)

#include "core\utils.h"
#include "core/image_manager.h"
#include <opencv2/highgui/highgui.hpp>
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
        Utils::addSeparator();
        std::cout << "\033[1;32m" << "Image successfully loaded" <<
        "\033[0m" << std::endl;
        Utils::addSeparator();
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
        Utils::addSeparator();
        std::cout << "\033[1;32m" << "Opening " << imageName << "\033[0m" << std::endl;
        Utils::addSeparator();
        cv::imshow(imagePath, image);
        cv::waitKey(0);
    }
}

void ImageManager::printInfo() const {
    if (image.empty()) {
        throw std::logic_error("no image loaded");
    }
    else {
        Utils::addSeparator();
        std::cout << "Size: " << image.size() << std::endl;
        std::cout << "Rows: " << image.rows << ", Cols: " << image.cols << std::endl;
        std::cout << "Type: " << image.type() << std::endl;
        std::cout << "Depth: " << image.depth() << std::endl;
        std::cout << "Channels: " <<  image.channels() << std::endl;
        std::cout << "Step: " << image.step << " bytes" << std::endl;
        std::cout << "Element Size: " << image.elemSize() << " bytes" << std::endl;
        std::cout << "Total Elements: " << image.total() << std::endl;
        Utils::addSeparator();
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
        Utils::addSeparator();
        std::cout << "\033[1;32m" << "Converted " + imageName <<
        " to grayscale" << "\033[0m" << std::endl;
        Utils::addSeparator();
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
        Utils::addSeparator();
        std::cout << "\033[1;32m" << "Converted " + imageName << " to color"
        << "\033[0m" << std::endl;
        Utils::addSeparator();
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
    Utils::addSeparator();
    std::cout << "\033[1;32m" << "Edge detection successful" << "\033[0m" << std::endl;
    Utils::addSeparator();
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
            Utils::addSeparator();
            std::cout << "\033[1;32m" << "ASCII art has been saved to ascii_" << imageName
            << ".txt" << "\033[0m" << std::endl;
            Utils::addSeparator();
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
        Utils::addSeparator();
        std::cout << "\033[1;32m" << "Image saved to " + outFile << "\033[0m" << std::endl;
        Utils::addSeparator();
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
    Utils::addSeparator();
    std::cout << "\033[1;32m" << "Image successfully blurred" << "\033[0m" << std::endl;
    Utils::addSeparator();
}

void ImageManager::smoothImage(int intensity) {
    if (image.empty()) {
        throw std::logic_error("no image loaded");
    }
    Utils::addSeparator();
    if (intensity == 1) {
        cv::GaussianBlur(image, image, cv::Size(5, 5), 3);
        std::cout << "\033[1;32m" << "Image successfully smoothed (intensity 1)" << "\033[0m"
        << std::endl;
    }
    else if (intensity == 2) {
        cv::GaussianBlur(image, image, cv::Size(7, 7), 5);
        std::cout << "\033[1;32m" << "Image successfully smoothed (intensity 2)" << "\033[0m"
        << std::endl;
    }
    else if (intensity == 3) {
        cv::GaussianBlur(image, image, cv::Size(9, 9), 7);
        std::cout << "\033[1;32m" << "Image successfully smoothed (intensity 3)" << "\033[0m"
        << std::endl;
    }
    Utils::addSeparator();
}

void ImageManager::addText(const std::string& text, const std::string& color, double fontSize) {
    if (image.empty()) {
        throw std::logic_error("no image loaded");
    }
    cv::Scalar colorScalar = Utils::getColorScalar(color);
    int fontFace = cv::FONT_HERSHEY_SIMPLEX;
    double fontScale = fontSize / 10.0;
    int thickness = 2;
    int baseline = 0;
    cv::Point textOrg(10, image.rows - baseline - 10);
    cv::putText(image, text, textOrg, fontFace, fontScale, colorScalar, thickness);

    Utils::addSeparator();
    std::cout << "\033[1;32m" << "Successfully added text to image" << "\033[0m" << std::endl;
    Utils::addSeparator();
}

void ImageManager::findContours() {
    if (image.empty()) {
        throw std::logic_error("no image loaded");
    }
    if (image.channels() != 1) {
        cv::cvtColor(image, image, cv::COLOR_BGR2GRAY);
    }
    cv::Canny(image, image, 50, 150, 3);
    std::vector<std::vector<cv::Point>> contours;
    cv::findContours(image, contours, cv::RETR_EXTERNAL, cv::CHAIN_APPROX_SIMPLE);

    Utils::addSeparator();
    std::cout << "\033[1;32m" << "Successfully detected " << contours.size() <<
              " contours" << "\033[0m" << std::endl;
    Utils::addSeparator();
}

void ImageManager::resetImage() {
    if (image.empty()) {
        throw std::logic_error("no image loaded");
    }
    image = cv::imread(imagePath, cv::IMREAD_UNCHANGED);
    Utils::addSeparator();
    std::cout << "\033[1;32m" << imageName << " successfully reset" << "\033[0m" << std::endl;
    Utils::addSeparator();
}

void ImageManager::createHistogram() const {
    if (image.empty()) {
        throw std::logic_error("no image loaded");
    }
    cv::Mat grayImage;
    if (image.channels() != 1) {
        cv::cvtColor(image, grayImage, cv::COLOR_BGR2GRAY);
    } else {
        grayImage = image.clone(); // Make a copy if image is already grayscale
    }

    cv::Mat hist;
    int histSize = 256;
    float range[] = {0, 256};
    const float* histRange = {range};
    cv::calcHist(&grayImage, 1, nullptr, cv::Mat(),
                 hist, 1, &histSize, &histRange);

    int histWidth = 512;
    int histHeight = 400;
    int binWidth = cvRound((double) histWidth / histSize);
    cv::Mat histImage(histHeight, histWidth, CV_8UC3,
                      cv::Scalar(0, 0, 0));
    cv::normalize(hist, hist, 0, histImage.rows,
                  cv::NORM_MINMAX, -1, cv::Mat());

    for (int i = 1; i < histSize; i++) {
        cv::line(histImage, cv::Point(binWidth * (i - 1),
                                      histHeight - cvRound(hist.at<float>(i - 1))),
                 cv::Point(binWidth * (i), histHeight - cvRound(hist.at<float>(i))),
                 cv::Scalar(255, 255, 255), 2, 8, 0);
    }
    Utils::addSeparator();
    std::cout << "\033[1;32m" << "Opening histogram"<< "\033[0m" << std::endl;
    Utils::addSeparator();
    cv::imshow("Histogram_" + imageName, histImage);
    cv::waitKey(0);
}

void ImageManager::detectFaces() {
    if (image.empty()) {
            throw std::logic_error("no image loaded");
    }
    if (image.channels() != 1) {
        cv::cvtColor(image, image, cv::COLOR_BGR2GRAY);
    }
    cv::CascadeClassifier haar_cascade;
    haar_cascade.load("haar_face.xml");
    if (haar_cascade.empty()) {
        throw std::runtime_error("failed to load haar cascade");
    }

    std::vector<cv::Rect> faces_rect;
    haar_cascade.detectMultiScale(image, faces_rect);

    for (const auto& rect : faces_rect) {
        cv::rectangle(image, rect, cv::Scalar(255, 0, 0), 2);
    }
    std::cout << "Number of faces detected: " << faces_rect.size() << std::endl;

};
