#include "opencv2/imgproc.hpp"
#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"

using namespace cv;
Mat src, dst;

int morph_elem = 0;
int morph_size = 0;
int morph_operator = 0;
int const max_operator = 4;
int const max_elem = 2;
int const max_kernel_size = 21;
const char* window_name = "Tranformações Morfológicas";
void Morphology_Operations( int, void* );

int main( int argc, char** argv ){
  	src = imread("img/flavio.jpg", IMREAD_COLOR); 
  	if( src.empty() ){ 
  		return -1; 
  	}
  	namedWindow( window_name, WINDOW_AUTOSIZE ); 
  	createTrackbar("Operador:\n 0 - Abertura\n 1 - Fechamento  \n 2 - Gradiente\n 3 - Top Hat \n 4: Black Hat", window_name, &morph_operator, max_operator, Morphology_Operations );
  	createTrackbar( "Elemento:\n 0 - Reta\n 1 - X \n 2 - Elipse", window_name,
        &morph_elem, max_elem,
        Morphology_Operations );
  	createTrackbar( "Kernel size:\n 2n +1", window_name,
        &morph_size, max_kernel_size,
        Morphology_Operations );
  	Morphology_Operations( 0, 0 );
  	waitKey(0);
  	return 0;
}

void Morphology_Operations( int, void* ){
  	int operation = morph_operator + 2;
  	Mat element = getStructuringElement( morph_elem, Size( 2*morph_size + 1, 2*morph_size+1 ), Point( morph_size, morph_size ) );
  	morphologyEx( src, dst, operation, element );
  	imshow( window_name, dst );
}