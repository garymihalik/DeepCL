#include <iostream>
using namespace std;

#include "FileHelper.h"
#include "test/myasserts.h"

int main( int argc, char *argv[] ) {
    int N = 100000;
    float *somefloats = new float[N];
    for( int i = 0; i < N; i++ ) {
        somefloats[i] = i * 5.0 / 3.0;
    }
    FileHelper::writeBinary("foo.dat", reinterpret_cast<unsigned char*>(somefloats), N * sizeof(float) );
    float *newfloats = new float[N];
    int bytesread = 0;
    unsigned char *dataread = FileHelper::readBinary("foo.dat", &bytesread );
    for( int i = 0; i < N; i++ ) {
        newfloats[i] = reinterpret_cast<float*>(dataread)[i];
    }
    delete[] dataread;
    for( int i = 0; i < N; i++ ) {
        assertEquals( somefloats[i], newfloats[i], 0.0001 );
    }  
    return 0;
}

