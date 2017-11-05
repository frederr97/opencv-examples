#include "opencv2/imgproc.hpp"
#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"

using namespace cv;
Mat src, dilation_dst;

int dilation_elem = 0;
int dilation_size = 0;

int const max_elem = 2;
int const max_kernel_size = 21;

void Dilation( int, void* );

int main( int, char** argv ){
	src = imread( "img/mineirao.jpg", IMREAD_COLOR );
	if( src.empty() )
		{ return -1; }
	namedWindow( "Dilatação", WINDOW_AUTOSIZE );
	createTrackbar( "Elemento:\n 0 - Reta \n 1 - X \n 2 - Elipse", "Dilatação",
		&dilation_elem, max_elem,
		Dilation );
	createTrackbar( "Kernel size:\n 2n +1", "Dilatação",
		&dilation_size, max_kernel_size,
		Dilation );
	Dilation( 0, 0 );
	waitKey(0);
	return 0;
}

void Dilation( int, void* ){
	int dilation_type = 0;
	if( dilation_elem == 0 ){ dilation_type = MORPH_RECT; }
	else if( dilation_elem == 1 ){ dilation_type = MORPH_CROSS; }
	else if( dilation_elem == 2) { dilation_type = MORPH_ELLIPSE; }
	Mat element = getStructuringElement( dilation_type,
		Size( 2*dilation_size + 1, 2*dilation_size+1 ),
		Point( dilation_size, dilation_size ) );
	dilate( src, dilation_dst, element );
	imshow( "Dilatação", dilation_dst );
}