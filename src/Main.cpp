// ----------------------------------------------------------------------------------------------------

#include <iostream>

#include "Point3D.hpp"
#include "Segment3D.hpp"
#include "MinDistance.hpp"

// ----------------------------------------------------------------------------------------------------

int main()
{
    const Segment3D seg1(Point3D(0.0, 0.0, 0.0), Point3D(10.0, 0.0, 0.0));
    const Segment3D seg2(Point3D(5.0, 5.0, 5.0), Point3D(5.0, -5.0, 10.0));

    const double distance = getMinDistance(seg1, seg2);
    std::cout << "Minimum Distance: " << distance << std::endl;

    return 0;
}

// ----------------------------------------------------------------------------------------------------
