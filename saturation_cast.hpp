#include <boost/numeric/conversion/cast.hpp> 
#include <iostream> 
#include <algorithm>

template<typename Target, typename Source>
Target saturation_cast(Source src) 
{
    try 
    {
        return boost::numeric_cast<Target>(src);
    }
    catch (boost::numeric::negative_overflow &e) 
    {
        return std::numeric_limits<Target>::min();
    }
    catch (boost::numeric::positive_overflow &e) 
    {
        return std::numeric_limits<Target>::max();
    }
    catch(boost::numeric::bad_numeric_cast& e)
    {
        if (src > 0)
        {
            return std::numeric_limits<Target>::max();
        }
        else
        {
            return std::numeric_limits<Target>::min();
        }

    }
}
