// By: Landon Prince (5/10/2024)

#ifndef PIXALYZE_IMAGE_MANAGER_H
#define PIXALYZE_IMAGE_MANAGER_H

#include <opencv2/opencv.hpp>

class ImageManager {
public:
    // default constructor for now
    ImageManager() = default;
    ~ImageManager() = default;
    ImageManager(const ImageManager&) = delete;
    ImageManager& operator=(const ImageManager&) = delete;

    /**
     * Loads an image into the ImageManager
     * @param filePath file path of image
     */
    void loadImage(const std::string& filePath);

    /**
     * Displays the load image in a new window
     */
    void showImage() const;

    /**
     * Prints properties of loaded image
     */
    void printInfo() const;

    /**
     * Transform a loaded color image to grayscale
     */
    void toGray();

    /**
     * Transform a loaded grayscale image to color
     */
    void toColor();

    /**
     * Saves loaded image to output file
     */
    void saveImage() const;

    /**
     * Converts loaded image to ASCII art and saves to text file
     */
    void saveASCII() const;

    /**
     * Highlights all edges in loaded image
     */
    void findEdges();

    /**
     * Blurs a loaded image
     */
    void blurImage();

    /**
     * Smoothes a loaded image
     * @param intensity intensity of smoothing (1-3)
     */
    void smoothImage(int intensity);

    /**
     * adds text to a loaded image
     * @param text the text to add
     * @param color the color of the text
     * @param fontSize the size of the text
     */
    void addText(const std::string& text, const std::string& color, double fontSize);

    /**
     * Highlights and counts all contours in loaded image
     */
    void findContours();

    /**
     * resets modifications made to loaded image
     */
    void resetImage();

    void createHistogram() const;

    void detectFaces();

private:
    cv::Mat image;
    std::string imagePath;
    std::string imageName;
};

#endif //PIXALYZE_IMAGE_MANAGER_H
