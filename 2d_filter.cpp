#include "opencv2/imgproc.hpp"
#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"

using namespace cv;

int main ( int argc, char** argv ){
    Mat src, dst, kernel;
    Point anchor;
    double delta;
    int kernel_size, ddepth;
    const char* window_name = "Filtro 2D";

    src = imread( "img/flavio.jpg", IMREAD_COLOR ); 
    anchor = Point( -1, -1 );
    delta = 0;
    ddepth = -1;
    int ind = 0;
    for(;;){
        char c = (char)waitKey(500);
        if( c == 27 ){ 
            break;
        }
        kernel_size = 3 + 2*( ind%5 );  
        kernel = Mat::ones( kernel_size, kernel_size, CV_32F )/ (float)(kernel_size*kernel_size);
        filter2D(src, dst, ddepth , kernel, anchor, delta, BORDER_DEFAULT );
        imshow( window_name, dst );
        ind++;
    }
    
    return 0;
}