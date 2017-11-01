# integrationtester

Tool to test AES & SHA crypto modules on Unix like platform

Generic cyrpto module:
---------------------

mkdir build

cd build

cmake ..

make

openssl_armv4 crypto module:
---------------------------

mkdir build

cd build

cmake -DCMAKE_BUILD_TYPE=Release -DUNABTO_CRYPTO_MODULE=openssl_armv4 ..

make


