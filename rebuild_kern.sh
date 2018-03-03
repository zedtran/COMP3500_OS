cd ~/cs161/src
./configure
cd ~/cs161/src/kern/conf
./config ASST1

cd ../compile/ASST1
make depend
make
make install
