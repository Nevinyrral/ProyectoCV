#include "opencv2/opencv.hpp"
#include <Label.h>

using namespace cv;

int main( int argc, char** argv )
{
  VideoCapture cap( 0 ); // open the default camera
  if( !cap.isOpened( ) ) return( -1 );

  Mat output;
  namedWindow( "output", 1 );

  while( true )
  {
    Mat frame;
    cap >> frame; // get a new frame from camera
    cvtColor( frame, output, COLOR_BGR2GRAY );
    int rows = output.rows;
    int cols = output.cols;
    adaptiveThreshold( output, output, 255,
      ADAPTIVE_THRESH_GAUSSIAN_C, THRESH_BINARY, 11, 2);
    Label::BFS( output, output, rows, cols, 4, 255);
    // Canny( output, output, 0, 30, 3 );
    imshow( "output", output );
    if( waitKey( 30 ) >= 0 ) break;
  } // elihw
  return( 0 );
}
