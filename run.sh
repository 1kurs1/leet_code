mkdir build
cd build

PROJECT_NAME="leet_code"

cmake ..
cmake --build .

clear

./$PROJECT_NAME
cd ..
rm -r build
