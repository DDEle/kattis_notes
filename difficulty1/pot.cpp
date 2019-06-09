// https://open.kattis.com/problems/pot
#include <iostream>
#include <string>
#include <cmath>

int main(int argc, char const *argv[])
{
    int n;
    long sum = 0;
    std::cin >> n;
    std::string line;

    for (int i = 0; i < n; ++i)
    {
        std::cin >> line;
        long pow = std::stoi(line.substr(line.length() - 1));
        long num = std::stoi(line.substr(0, line.length() - 1));

        sum += std::pow(num, pow);
    } 
    
    std::cout << sum << std::endl;

    return 0;
}