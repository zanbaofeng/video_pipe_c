
This code is derived from(modified some codes) `paddle_ocr` project: https://github.com/PaddlePaddle/PaddleOCR/tree/release/2.6/deploy/cpp_infer 

## how to install paddle_inference sdk (downloaded from official web or compiled from source code)?

1. Copy all `*.h` header files from `paddle_inference` directory to `/usr/local/include` (keep package name as the name of subdirectory)
2. Copy all `*.so/*.a` library files from `paddle_inference` directory to `/usr/local/lib` directly.

## how to build paddle_ocr?

1. `cd ./build`, and run `sh ./build.sh`.
2. It will generate a `*.so` library named `libpaddle_ocr.so`.
3. Or include source code directly, no `.so` library needed.

## How to debug `paddle_ocr`?

Make sure you have build paddle_ocr correctly

1. Change model paths to your specific values in `./main/main.cpp`.
2. Select ./main/main.cpp file and click `Run` button in vscode, choose one launch item at the top of window(`paddle_ocr`).
