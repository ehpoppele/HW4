#include "pi.hpp" //Header includes cmath so that we can use hypot

double gridpi(unsigned npoints)
{
    double p_inside = 0; //we only increase this by incremenets of 1; but we need them to be doubles for the division we do on them later
    for(unsigned i=0; i<npoints; i++ ) {//start at zero (origin), go up to npoints-1 to have a total of npoints along one side. This can be considered our x coord
        for(unsigned j=0; j<npoints; j++ ) {//Same as above for j; effectively now checking all our y coords
            double dist = (std::hypot(i, j)); //This will accurately calculate distance even with unsigned int inputs (no improper rounding)
            if (dist <= npoints-1) { //Given that we are dealing with a grid that ranges from 0 to npoints-1, we are considering our radius to be npoints-1. This is more accurate than just npoints, even though using that does return the suggested value of 3.14938 at 500 points.
                p_inside++;
            }
        }
    } 
    double pi = (p_inside/(npoints*npoints)) * 4; //Then we do points inside / total points, times 4 to get the value of pi.
    return pi;
}