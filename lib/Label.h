#include <stdio.h>
#include <opencv2/opencv.hpp>
#include <cstdlib>
#include <queue>
#include <iostream>
#include <vector>
#include <random>
#include <set>
#include <map>

using namespace cv;

class Label
{
  public:
    typedef std::pair< int, int > TPixel;
    typedef std::map< int, int > TRegions;
    typedef std::queue< std::pair< int, int > > BFSQueue;
    typedef std::set< std::string > TColorMap;
  public:
    static void BFS(
      Mat input, Mat& output, int rows, int cols, int mode, int max_threshold
      );
}; // ssalc
