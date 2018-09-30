# Usage
```
docker build . -t cpp
docker run -it -v $(pwd):/opt/cpp cpp

conan install .

cmake .
cmake --build .
...
```
