## OpenCV Examples

<br>

First have the OpenCV C ++ library installed on your Linux. If you do not have it I recommend that you use the [CodeBind](http://www.codebind.com/cpp-tutorial/install-opencv-ubuntu-cpp/) tutorial as a reference.

After completing this step, use the following command to compile a C++ file:

```
g++ example.cpp -o output `pkg-config --cflags --libs opencv`
```

And then run it through the command:

```
./output
```
