#include "opencv2/opencv.hpp"
#include <Label.h>

#include <limits>


using namespace cv;

RNG rng(12345);

int main( int argc, char** argv )
{
  VideoCapture cap( 0 ); // open the default camera
  if( !cap.isOpened( ) ) return( -1 );

  Mat output;
  Mat initial_frame;
  cap >> initial_frame;
  cvtColor( initial_frame, initial_frame, COLOR_BGR2GRAY );

  while( true )
  {
    Mat grad;
    int scale = 3;
    int delta = 0;
    int ddepth = CV_16S;
    std::vector< std::vector< Point > > contours;

    Mat frame;
    Mat original;
    cap >> original; // get a new frame from camera
    cvtColor( original, frame, COLOR_BGR2GRAY );
    output = frame - initial_frame;
    for ( int i = 1; i < 11; i = i + 2 )
      GaussianBlur( output, output, Size( i, i ), 0, 0 );
    // Canny( output,  output, 100, 150 );
    addWeighted(output, 1, output, -0.5, 0, output);
    imshow("gaussian", output);
    threshold( output, output, 10, 255, THRESH_BINARY );
    findContours( output, contours, CV_RETR_EXTERNAL, CV_CHAIN_APPROX_NONE );
    std::vector<std::vector<Point> > contours_poly( contours.size() );
    std::vector<Rect> boundRect( contours.size() );
    std::vector<Point2f>center( contours.size() );
    std::vector<float>radius( contours.size() );

    for( int i = 0; i < contours.size(); i++ )
     {
       approxPolyDP( Mat(contours[i]), contours_poly[i], 3, true );
       boundRect[i] = boundingRect( Mat(contours_poly[i]) );
     }

     /// Draw polygonal contour + bonding rects + circles
    for( int i = 0; i< contours.size(); i++ )
       {
         Scalar color = Scalar( 0, 255, 0 );
         drawContours( original, contours_poly, i, color, 3, 8, std::vector<Vec4i>(), 0, Point() );
         rectangle( original, boundRect[i].tl(), boundRect[i].br(), color, 2, 8, 0 );
       }

    Mat mask = Mat::zeros( output.size(), CV_8UC1 );
    std::vector<double> areas(contours.size());
    for(int i = 0; i < contours.size(); i++)
      areas[i] = contourArea( Mat( contours[i] ) );
    double max;
    Point maxPosition;
    minMaxLoc( Mat( areas ), 0, &max, 0, &maxPosition );
    drawContours( mask, contours, maxPosition.y, Scalar( 1 ), CV_FILLED );
    Mat crop( frame.rows, frame.cols, CV_8UC3 );

    crop.setTo(Scalar(0,255,0));

    frame.copyTo( crop, mask );

    normalize( mask.clone(), mask, 0.0, 255.0, CV_MINMAX, CV_8UC1 );

    imshow("original", frame);
    imshow("mask", mask);
    imshow("cropped", crop);
    imshow( "Composite", original );

    //  imshow( "output", output );
    initial_frame = frame;
    if( waitKey( 30 ) == 27 ) break;
  } // elihw
  return( 0 );
}
