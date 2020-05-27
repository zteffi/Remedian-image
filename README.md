# Remedian image
## Header-only C++ library for per-pixel image median approximation using [Remedian algorithm](https://www.researchgate.net/publication/247974442_The_Remedian_A_Robust_Averaging_Method_for_Large_Data_Sets).
Project also includes sample application for computing remedian of a video file.

## Dependencies
* **[OpenCV](https://github.com/opencv/opencv/)** building with FFMPEG support is recommended for sample application 
* **[CMake](https://cmake.org/)** for building the sample application

## TODO
* Add configurable handling for median of even sample
* Support for multithreaded computation