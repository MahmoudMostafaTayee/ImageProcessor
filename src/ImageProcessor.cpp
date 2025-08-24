#include "ImageProcessor.hpp"
#include <filesystem>
#include <future>
#include <opencv2/highgui.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/opencv.hpp>
#include <string>
#include <vector>

ImageProcessor::ImageProcessor(const std::string &inputDir,
                               const std::string &outputDir)
    : inputDir(inputDir), outputDir(outputDir) {}

std::vector<std::string>
ImageProcessor::getImagePaths(const std::string &path) {
  std::vector<std::string> imagePaths{};

  for (const auto &entry : std::filesystem::directory_iterator(inputDir)) {
    if (entry.is_regular_file()) {
      imagePaths.emplace_back(entry.path().string());
    }
  }
  return imagePaths;
}

void ImageProcessor::getEdgesForImage(const std::string &imagePath,
                                      bool preview, bool save) {
  cv::Mat image = cv::imread(imagePath);
  if (image.empty())
    return;

  cv::Mat gray, blurred, edges;
  cv::cvtColor(image, gray, cv::COLOR_BGR2GRAY);
  cv::GaussianBlur(gray, blurred, {5, 5}, 1.5);
  cv::Canny(blurred, edges, 50, 150);

  if (preview) {
    cv::imshow("Edges of the image", edges);
    cv::waitKey(0);
  }

  if (save) {
    std::string filename = std::filesystem::path(imagePath).filename().string();
    std::string outputFilePath = outputDir + "/processed_" + filename;
    cv::imwrite(outputFilePath, edges);
  }
}

void ImageProcessor::processImages(int numOfThreads) {
  std::vector<std::string> paths = getImagePaths(inputDir);
  std::vector<std::future<void>> futures;
  for (const auto &path : paths) {
    futures.emplace_back(
        std::async([this, path]() { getEdgesForImage(path); }));
  }

  for (auto &future : futures) {
    future.get();
  }
}
