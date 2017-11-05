#include "opencv2/imgproc.hpp"
#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"

using namespace cv;
int threshold_value = 0;
int threshold_type = 3;
int const max_value = 255;
int const max_type = 4;
int const max_BINARY_value = 255;

Mat src, src_gray, dst;
const char* window_name = "Threshold";
const char* trackbar_type = "Tipo: \n 0 - Binário \n 1 - Binário Invertido \n 2 - Truncado \n 3 - Para Zero \n 4 - Para Zero Invertido";
const char* trackbar_value = "Value";
void Threshold_Demo( int, void* );


int main( int argc, char** argv ){
    src = imread("img/piramide.jpg", IMREAD_COLOR ); 

    cvtColor( src, src_gray, COLOR_BGR2GRAY );
    namedWindow( window_name, WINDOW_AUTOSIZE ); 
  	createTrackbar( trackbar_type,
        window_name, &threshold_type,
        max_type, Threshold_Demo ); 
  	createTrackbar( trackbar_value,
        window_name, &threshold_value,
        max_value, Threshold_Demo ); 
  	Threshold_Demo( 0, 0 ); 
  	for(;;){
      	char c = (char)waitKey( 20 );
    	if( c == 27 ){
 			break; 
 		}
    }
}


void Threshold_Demo( int, void* ){
  	threshold( src_gray, dst, threshold_value, max_BINARY_value,threshold_type );
  	imshow( window_name, dst );
}