// ----------------------------------------------------------------------------------------------------

#include <iostream>

#include "Utils.hpp"
#include "Point3D.hpp"
#include "Segment3D.hpp"
#include "MinDistance.hpp"

// ----------------------------------------------------------------------------------------------------

namespace Test
{
    bool nearlyEqual(double value1, double value2)
    {
        constexpr double epsilon = 1e-3;
        return (std::fabs(value1 - value2) < epsilon);
    }

    bool parallelSegments()
    {
        const Segment3D seg1(Point3D(0, 0, 0), Point3D(10, 0, 0));
        const Segment3D seg2(Point3D(0, 5, 0), Point3D(10, 5, 0));
        const double distance = getMinDistance(seg1, seg2);
        return nearlyEqual(distance, 5.0);
    }

    bool perpendicularSegments()
    {
        const Segment3D seg1(Point3D(0, 0, 0), Point3D(10, 0, 0));
        const Segment3D seg2(Point3D(5, -5, 1), Point3D(5, 5, 1));
        const double distance = getMinDistance(seg1, seg2);
        return nearlyEqual(distance, 1.0);
    }

    bool skewedSegments()
    {
        const Segment3D seg1(Point3D(0, 0, 0), Point3D(10, 0, 0));
        const Segment3D seg2(Point3D(5, 5, 5), Point3D(5, -5, 10));
        const double distance = getMinDistance(seg1, seg2);
        return nearlyEqual(distance, 6.708);
    }

    bool intersectingSegments()
    {
        const Segment3D seg1(Point3D(0, 0, 0), Point3D(10, 0, 0));
        const Segment3D seg2(Point3D(5, 0, -5), Point3D(5, 0, 5));
        const double distance = getMinDistance(seg1, seg2);
        return nearlyEqual(distance, 0.0);
    }

    bool coincidentSegments()
    {
        const Segment3D seg1(Point3D(0, 0, 0), Point3D(10, 0, 0));
        const Segment3D seg2(Point3D(5, 0, 0), Point3D(10, 0, 0));
        const double distance = getMinDistance(seg1, seg2);
        return nearlyEqual(distance, 0.0);
    }

    bool touchingAtEndpoint()
    {
        const Segment3D seg1(Point3D(0, 0, 0), Point3D(5, 0, 0));
        const Segment3D seg2(Point3D(5, 0, 0), Point3D(10, 0, 0));
        const double distance = getMinDistance(seg1, seg2);
        return nearlyEqual(distance, 0.0);
    }
}

// ----------------------------------------------------------------------------------------------------

int main()
{
    bool b1 = Test::parallelSegments();
    bool b2 = Test::perpendicularSegments();
    bool b3 = Test::skewedSegments();
    bool b4 = Test::intersectingSegments();
    bool b5 = Test::coincidentSegments();
    bool b6 = Test::touchingAtEndpoint();

    return 0;
}

// ----------------------------------------------------------------------------------------------------
