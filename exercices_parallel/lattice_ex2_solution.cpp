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
    //-----------------------   end   ------------------------


    //------------   Declaration of a Lattice   --------------

    Lattice lat(3,64,1);

    COUT << "Lattice size: ("<< lat.size(0)<<","<< lat.size(1)<<","<< lat.size(2)<<");"<<endl;
    cout << "Process ranks: "<< parallel.rank()<<",("<< parallel.grid_rank()[0]<<","<<parallel.grid_rank()[1]<< "); ";
    cout << "Local lattice size: ("<< lat.sizeLocal(0)<<","<< lat.sizeLocal(1)<<","<< lat.sizeLocal(2)<<"); ";
    cout << "Coordinate of the first local point: (0,"<< lat.coordSkip()[1] <<","<< lat.coordSkip()[0] <<")."<<endl;
    //-----------------------   end   ------------------------


    //-----------   Declaration of the Fields   --------------
    Field<Real> rho(lat);


    Field<Real> phi;
    phi.initialize(lat);
    phi.alloc();

    Field<Real> gradRho(lat,3);
    //-----------------------   end   ------------------------

    //--------------   Operations on Fields   ----------------
    Site x(lat);

    for(x.first();x.test();x.next())
    {
        phi(x) = sin(2 * M_PI * x.coord(0) / lat.size(0));
    }

    phi.updateHalo();

    double dx = 0.5;
    for(x.first();x.test();x.next())
    {

        gradPhi(x,0) = (phi(x+0)-phi(x-0))/(dx*2.0);
        gradPhi(x,1) = (phi(x+1)-phi(x-1))/(dx*2.0);
        gradPhi(x,2) = (phi(x+2)-phi(x-2))/(dx*2.0);
    }
    //-----------------------   end   ------------------------


}
