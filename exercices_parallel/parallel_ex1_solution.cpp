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

int i = 1;
//cout<<i<<endl;
COUT<<i<<endl;

COUT << "Parallel size: "<< parallel.size()<<endl;
COUT << "Parallel grid size: ("<<parallel.grid_size()[0]<<","<<parallel.grid_size()[1]<<"). "<<endl;
cout<< "Process rank: "<< parallel.rank()<<" ; Process grid position: ("<<parallel.grid_rank()[0]<<","<<parallel.grid_rank()[1]<<"). "<<endl;

int seed =1;
srand(seed + parallel.rank());
int a=rand() % 1000;
int min,max,sum,sum_dim0;

min = a;
parallel.min(min);
max = a;
parallel.max(max);
sum = a;
parallel.sum(sum);
sum_dim0 = a;
parallel.sum(sum_dim0);

cout << "min: "<<min << ", max: "<<max << ", sum: "<<sum << "sum_dim0: "<<sum_dim0<<endl;

}
