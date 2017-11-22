#include "Label.h"

void Label::BFS(
  Mat input, Mat& output, int rows, int cols, int mode, int max_threshold
  )
{
  // Labeled image data with small regions
  char aux[ rows ][ cols ];
  // Initialize
  for(int i = 0; i < rows; i++)
    for(int j = 0; j < cols; j++) aux[ i ][ j ] = -1; // rof

  // Direction vectors
  std::vector< int > dx;
  std::vector< int > dy;

  if( mode == 4 )
  {
    dx = { +1, 0, -1, 0 };
    dy = { 0, +1, 0, -1 };
  }
  else
  {
    dx = { +1, 0, -1, 0, -1, +1, +1, -1 };
    dy = { 0, +1, 0, -1, +1, +1, -1, -1 };
  } // fi

  BFSQueue queue;
  uchar* pointer;

  TRegions regions;

  std::random_device rd;
  std::mt19937 gen( rd( ) );
  std::uniform_int_distribution< > dis( -1, 256 );
  TColorMap color_map;

  int label = 1;
  int r, g, b;

  for( int i = 0; i < rows; ++i )
  {
    pointer = input.ptr< uchar >( i );
    for( int j = 0; j < cols; ++j )
    {
      r = 0; g = 255; b = 0;
      if( aux[ i ][ j ] == -1 && ( int ) pointer[ j ] == max_threshold )
      {
        aux[ i ][ j ] = label;
        Pixel pixel;
        pixel.SetCoordinates( j, i );
        queue.push( pixel );
        output.at< Vec3b >( i, j )[ 0 ] = ( uchar ) r;
        output.at< Vec3b >( i, j )[ 1 ] = ( uchar ) g;
        output.at< Vec3b >( i, j )[ 2 ] = ( uchar ) b;
        while ( !queue.empty( ) )
        {
          Pixel current_pixel = queue.front( );
          queue.pop( );
          for( int direction = 0; direction < mode; ++direction )
          {
            int current_x = current_pixel.GetX( ) + dx[ direction ];
            int current_y = current_pixel.GetY( ) + dy[ direction ];
            if( current_x < 0 || current_x == cols ) continue; // Out of bounds
            if( current_y < 0 || current_y == rows ) continue; // Out of bounds
            int current_color = ( int ) input.at< uchar >( current_y, current_x );
            std::cout << "current_color: " << std::to_string( current_color ) << '\n';
            std::cout << "max_threshold: " << std::to_string( current_color ) << '\n';
            if( aux[ current_y ][ current_x ] == -1 &&
              current_color == max_threshold
              )
            {
              aux[ current_y ][ current_x ] = label;
              Pixel neighbor_pixel;
              neighbor_pixel.SetCoordinates( current_x, current_y );
              queue.push( neighbor_pixel );
              output.at< Vec3b >( current_y, current_x )[ 0 ] = ( uchar ) r;
              output.at< Vec3b >( current_y, current_x )[ 1 ] = ( uchar ) g;
              output.at< Vec3b >( current_y, current_x )[ 2 ] = ( uchar ) b;
            } else {
              aux[ current_y ][ current_x ] = 0; // fi
              output.at< Vec3b >( current_y, current_x )[ 0 ] = ( uchar ) 0;
              output.at< Vec3b >( current_y, current_x )[ 1 ] = ( uchar ) 0;
              output.at< Vec3b >( current_y, current_x )[ 2 ] = ( uchar ) 0;
            }
          } // rof
        } // elihw
        label++;
      } else {
        aux[ i ][ j ] = 0;// fi
        output.at< Vec3b >( i, j )[ 0 ] = ( uchar ) 0;
        output.at< Vec3b >( i, j )[ 1 ] = ( uchar ) 0;
        output.at< Vec3b >( i, j )[ 2 ] = ( uchar ) 0;
      }
    } // rof
  } // rof

  // int max_region = 0;
  // for(
  //   TRegions::iterator regionIt = regions.begin( ); regionIt != regions.end( );
  //   ++regionIt
  // ) if( max_region < regionIt->second ) max_region = regionIt->second;
  //
  //
  // color_map.insert( "000" );
  // for(
  //   TRegions::iterator regionIt = regions.begin( ); regionIt != regions.end( );
  //   ++regionIt
  //   )
  // {
  //   int r, g, b;
  //   if( regionIt->second.size( ) < ( max_region * 0.15 ) )
  //   {
  //
  //     r = 0; g = 0; b = 0;
  //   }
  //   else
  //   {
  //     bool new_color = false;
  //     while( !new_color )
  //     {
  //       r = dis( gen ); g = dis( gen ); b = dis( gen );
  //       std::string color_signature =
  //         std::to_string( r ) + std::to_string( g ) + std::to_string( b );
  //       if( color_map.find( color_signature ) == color_map.end( ) )
  //       {
  //           color_map.insert( color_signature );
  //           new_color = true;
  //       }
  //     } // elihw
  //   } // fi
  //   for( TPixel pixel : ( regionIt->second ) ) {
  //     int pixel_x = std::get< 0 >( pixel );
  //     int pixel_y = std::get< 1 >( pixel );
  //     output.at< Vec3b >( pixel_y, pixel_x )[ 0 ] = ( uchar ) r;
  //     output.at< Vec3b >( pixel_y, pixel_x )[ 1 ] = ( uchar ) g;
  //     output.at< Vec3b >( pixel_y, pixel_x )[ 2 ] = ( uchar ) b;
  //   } // rof
  // } // rof
}

Pixel::Pixel( )
{
}

Pixel::~Pixel( )
{
}

void Pixel::SetCoordinates( int x, int y )
{
  m_X = x;
  m_Y = y;
}

int Pixel::GetX( )
{
  return m_X;
}

int Pixel::GetY( )
{
  return m_Y;
}
