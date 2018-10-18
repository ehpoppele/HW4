#include "pi.hpp" //Includes the header file which defines the function we use and includes iostream and cmath

int main() 
{
    for(unsigned dimension : {10, 100, 1000, 10000}) {
        const double piest = gridpi(dimension);
        std::cout << piest<< "\n";
    }
    return 0;
}