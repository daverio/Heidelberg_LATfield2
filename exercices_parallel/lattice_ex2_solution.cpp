/*! file gettingStarted.cpp
    Created by David Daverio.

    A simple example of LATfield2 usage.
 */


#include "LATfield2.hpp"
using namespace LATfield2;


int main(int argc, char **argv)
{

    //-------- Initilization of the parallel object ---------
    int n,m;

    for (int i=1 ; i < argc ; i++ ){
		if ( argv[i][0] != '-' )
			continue;
		switch(argv[i][1]) {
			case 'n':
				n = atoi(argv[++i]);
				break;
			case 'm':
				m =  atoi(argv[++i]);
				break;
		}
	}

    parallel.initialize(n,m);

    COUT << "Parallel grid size: ("<<parallel.grid_size()[0]<<","<<parallel.grid_size()[1]<<"). "<<endl;



    //------------   Declaration of a Lattice   --------------
    int dim = 3;
    int latSize[3] = {25,57,32};
    int halo = 1;
    Lattice lat(dim,latSize,halo);

    COUT << "Lattice size: ("<< lat.size(0)<<","<< lat.size(1)<<","<< lat.size(2)<<");"<<endl;
    cout << "Local lattice size: ("<< lat.sizeLocal(0)<<","<< lat.sizeLocal(1)<<","<< lat.sizeLocal(2)<<"); ";

}
