// catching memory allocation failure with exceptions

#include <iostream>
#include <new>
#include <cstdlib>
using namespace std;

int main() {

    double *ptr[ 50 ];
   
    try {   
        for ( int i = 0; i < 50; i++ ) {
            ptr[ i ] = new double[ 5000000 ];
            cout << "Allocated 5000000 doubles in ptr[ " << i << " ]\n";
            //system("PAUSE"); // uncoment for DevC++
        }
    }
    catch ( bad_alloc e ) {
        cout << "Exception occurred: "<<e.what()<< endl;
       

    }
    return 0;
}
