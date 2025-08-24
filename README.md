# 📷 ImageProcessor

A simple C++ project for loading, processing, and saving images.  
The project is structured with a clean separation of headers (`include/`), source files (`src/`), input images (`images/`), and processed output (`output/`).

---

## 📂 Project Structure

```cpp_image_processor/
 │── CMakeLists.txt
 │── include/
 │    └── image_processor.hpp
 │── src/
 │    ├── main.cpp
 │    └── image_processor.cpp
 │── images/
 │    └── (raw input images here)
 │── output/
 │    └── (processed images saved here)
```

---

## ⚙️ Build Instructions

### Prerequisites
- CMake ≥ 3.28
- C++17 or later
- [OpenCV](https://opencv.org/) (required for image processing)

### Steps
```bash
# Clone the repo
git clone https://github.com/MahmoudMostafaTayee/ImageProcessor
cd cpp_image_processor

# Create a build directory
mkdir build && cd build

# Configure
cmake ..

# Build
cmake --build .
