#include "opencv2/imgproc.hpp"
#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"

using namespace cv;
Mat src, erosion_dst;

int erosion_elem = 0;
int erosion_size = 0;
int const max_elem = 2;
int const max_kernel_size = 21;

void Erosion( int, void* );

int main( int, char** argv ){
	src = imread( "img/mineirao.jpg", IMREAD_COLOR );
	if( src.empty() )
		{ return -1; }
	namedWindow( "Erosão", WINDOW_AUTOSIZE );
	createTrackbar( "Elemento:\n 0 - Reta \n 1 - X \n 2 - Elipse", "Erosão",
		&erosion_elem, max_elem,
		Erosion );
	createTrackbar( "Kernel size:\n 2n +1", "Erosão",
		&erosion_size, max_kernel_size,
		Erosion );
	Erosion( 0, 0 );
	waitKey(0);
	return 0;
}


void Erosion( int, void* ){
	int erosion_type = 0;
	if( erosion_elem == 0 ){ erosion_type = MORPH_RECT; }
	else if( erosion_elem == 1 ){ erosion_type = MORPH_CROSS; }
	else if( erosion_elem == 2) { erosion_type = MORPH_ELLIPSE; }
	Mat element = getStructuringElement( erosion_type,
		Size( 2*erosion_size + 1, 2*erosion_size+1 ),
		Point( erosion_size, erosion_size ) );
	erode( src, erosion_dst, element );
	imshow( "Erosão", erosion_dst );
}