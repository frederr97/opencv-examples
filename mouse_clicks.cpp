#include "opencv2/highgui/highgui.hpp"
#include <iostream>

using namespace std;
using namespace cv;

void CallBackFunc(int event, int x, int y, int flags, void* userdata){
    
    if  ( event == EVENT_LBUTTONDOWN ){
          cout << "Left button of the mouse is clicked - position (" << x << ", " << y << ")" << endl;
          MyEllipse();
    }
    
    else if  ( event == EVENT_RBUTTONDOWN ){
          cout << "Right button of the mouse is clicked - position (" << x << ", " << y << ")" << endl;
    }
    
    else if  ( event == EVENT_MBUTTONDOWN ){
          cout << "Middle button of the mouse is clicked - position (" << x << ", " << y << ")" << endl;
    }
    
    else if ( event == EVENT_MOUSEMOVE ){
          cout << "Mouse move over the window - position (" << x << ", " << y << ")" << endl;
    }
}


int main(int argc, char** argv){
    
    Mat img = imread("img/mineirao.jpg");

    namedWindow("Imagem", 1);
    setMouseCallback("Imagem", CallBackFunc, NULL);

    imshow("Imagem", img);

    waitKey(0);

    return 0;

}


void MyEllipse( Mat img, double angle ){
    int thickness = 2;
    int lineType = 8;

    ellipse( img, Point( w/2.0, w/2.0 ), Size( w/4.0, w/16.0 ), angle, 0, 360, Scalar( 255, 0, 0 ), thickness, lineType );
}