set -e
set -x

mkdir build
pushd build
cmake ..
cmake --build .
popd
