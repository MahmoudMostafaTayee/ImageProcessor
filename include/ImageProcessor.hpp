#pragma once
#include <string>
#include <vector>

class ImageProcessor {
public:
  ImageProcessor(const std::string &inputDir, const std::string &outputDir);
  void getEdgesForImage(const std::string &imagePath, bool preview=false, bool save=true);
  void processImages(const std::string &imagesPath, int numOfThreads = 5);

private:
  std::vector<std::string> getImagePaths(const std::string &path);
  std::string inputDir;
  std::string outputDir;
};
