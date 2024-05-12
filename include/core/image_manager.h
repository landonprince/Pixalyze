// By: Landon Prince (5/10/2024)

#ifndef PIXALYZE_IMAGE_MANAGER_H
#define PIXALYZE_IMAGE_MANAGER_H

#include <opencv2/opencv.hpp>

class ImageManager {
public:
    ImageManager() = default;
    ~ImageManager() = default;
    ImageManager(const ImageManager&) = delete;
    ImageManager& operator=(const ImageManager&) = delete;

    void loadImage(const std::string& filePath);
    void showImage() const;
    void printInfo() const;
private:
    cv::Mat image;
    std::string imagePath;

    cv::Size matSize; // contains width and height of mat
    int numRows; // number of rows in mat
    int numCols; // number of cols in mat
    int matType; // represents the type of mat elements
    int depthType; // represents the depth of mat elements
    int numChannels; // represents the number of channels in mat
    size_t stepSize; // number of bytes in each mat row
    size_t elementSize; // size of each mat element in bytes
    size_t totalElements; // total number of elements in mat



};

#endif //PIXALYZE_IMAGE_MANAGER_H
