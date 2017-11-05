## OpenCV Examples

<br>

Primeiramente, tenha a biblioteca OpenCV C++ instalada em seu Linux. Caso não tenha, recomendo que utilize o tutorial do [CodeBind](http://www.codebind.com/cpp-tutorial/install-opencv-ubuntu-cpp/) como referência.

Terminado este passo, utilize o comando a seguir para compilar um arquivo:

```
g++ example.cpp -o output `pkg-config --cflags --libs opencv`
```

E depois execute-o através do comando:

```
./output
```
