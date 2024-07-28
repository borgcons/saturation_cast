#include "saturation_cast.hpp"

#include <iostream>
#include <algorithm>

int main()
{
    unsigned long unsignedLongMax = std::numeric_limits<unsigned long>::max();

    try
    { 
        std::cout << "Test 1 Saturation cast: ";
        unsigned short s = saturation_cast<int>(unsignedLongMax);
        std::cout << " Saturation unsigned short value " << s << " from " << unsignedLongMax << std::endl;  
    }
    catch(...)
    {
        std::cout << " Should never happen" << std::endl;
    }

    return 0;
}
