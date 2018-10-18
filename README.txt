Calculated values for Pi:
    10- 2.92
   100- 3.1156
 1,000- 3.13916
10,000- 3.14136

Evaluated Complexity:
I expect the program to run on about the order of n^2.
This is due to our nested for loops each running n times;
we end up performing n^2 calculations. I am assuming (hoping)
that the time to calculate hypot does not vary greatly base on
input, in which case we can dismiss it as a constant run time calculation.

Measured run times:
    10- 0.013 s
   100- 0.013 s
 1,000- 0.048 s
10,000- 3.534 s

These values somewhat match what I expected based on my evaluated complexity.
We see that 10,000 takes about one hundred times as long as 1,000, which is 
expected based on the complexity, as it is 10 times greater, and therefore should
take 10^2 = 100 times as long. We don't see this in the case of the smaller values;
however, where we see an increase of less than 1ms and then an increase of about a
multiple of 4. This is likely due to the program having some base calculation time,
perhaps in system calls, and the limited accuracy of the timing report-- perhaps if
we could see microseconds, we could more easily identify the run time as a function
n^2 + base time.

Running at compile time:

Measured run times and pi estimates:
    10- 0.013 s; pi = 2.92
   100- 0.014 s; pi = 3.1156
 1,000- 0.016 s; pi = 3.13916
 
The speed is roughly constant, and the values are the same. This is because when the function
Is run at compile time, it is also calculated then, so it doesn't need to be calculated when the
program is run. For this reason, the compiling time takes significantly longer than before (noticeable
especially in the case of npoints = 1,000). The returned values are identical since the function is essentially
unchanged and still computes the same as it did before.

My code for the constexpr version of the function is below; I had difficulty getting it to work with the
current division of a header and two function files as my regular program uses, so I condensed it into a single
file and compiled it as it appears below. 

#include <cmath>
#include <iostream>

constexpr double gridpi2(unsigned npoints);

constexpr double gridpi2(unsigned npoints)
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

int main() 
{
    const double piest = gridpi2(10);
    std::cout << piest<< "\n";
    return 0;
}