// https://open.kattis.com/problems/a1paper
#include <iostream>
#include <string>
#include <cmath>
#include <iomanip> // for std::setprecision

// paperLongSidePower(2) = −3/4 
double paperLongSidePower(int n) {
	return -(0.25 + 0.5 * (n - 1));
}


int main(int argc, char const *argv[])
{
    int n;
    std::cin >> n;

    // init array. e.g. sheets[30 - 1] is the number of A30 paper
    long sheets[30];
	sheets[0] = 0;
    for (int i = 1; i < n; ++i)
    {
        std::cin >> sheets[i];
    } 

    int currA = 1; // start with A1
    long currReq = 1; // we want an A1 finally
    double tapeLen = 0;
    while (currA <= n) {
    	if (sheets[currA-1] >= currReq) {
    		std::cout << std::setprecision(12) << tapeLen << std::endl;
    		return 0;
    	} else {
    		int deficit = currReq - sheets[currA-1];
    		currA++;
    		tapeLen += deficit * std::pow(2, paperLongSidePower(currA));
    		currReq = deficit * 2;
    	}
    }

    std::cout << "impossible" << std::endl;

    return 0;
}