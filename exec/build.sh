#!/bin/sh
cd ../;
PATHDIR="./build"
if [ -e $PATHDIR ]; then
    echo "continue"
#ifのあとにはコードをかかないといけない
else
    echo "make $PATHDIR"
    mkdir $PATHDIR
fi

cd ./build/;
cmake ../;
echo $"------compile-------"
make;
cd ../;
cd ./exec
echo $"---programresult----"
# ./PathTest ;
