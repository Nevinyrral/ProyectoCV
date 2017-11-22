#include <stdio.h>
#include <opencv2/opencv.hpp>
#include <cstdlib>
#include <queue>
#include <iostream>
#include <vector>
#include <set>
#include <random>

using namespace cv;

class Pixel
{
  public:
    void   SetCoordinates( int x, int y );
    void   SetData( uchar& data );
    int    GetX( );
    int    GetY( );
    Pixel( );
    ~Pixel( );

  private:
    int    m_X;
    int    m_Y;
}; // ssalc

class Label
{
  public:
    typedef std::vector< int > TRegions;
    typedef std::queue< Pixel > BFSQueue;
    typedef std::set< std::string > TColorMap;
  public:
    static void BFS(
      Mat input, Mat& output, int rows, int cols, int mode, int max_threshold
      );
}; // ssalc
