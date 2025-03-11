// ----------------------------------------------------------------------------------------------------

#include <cmath>
#include <algorithm>

#include "Utils.hpp"
#include "Vector3D.hpp"
#include "Segment3D.hpp"
#include "MinDistance.hpp"

// ----------------------------------------------------------------------------------------------------

//
// The shortest distance between two 3D line segments is given by the minimum distance between
// any two points on the segments. This can be found by solving a system of equations that minimizes
// the squared distance between points on the segments.
// 
// Given two line segments:
// 
// 1. Segment 1:
//    P1 + t * d1, where "P1" is the starting point, "d1 = P2 - P1" is the direction vector,
//    and "t" is the parameter ranging from 0 to 1.
//
// 2. Segment 2:
//    Q1 + u * d2, where "Q1" is the starting point, "d2 = Q2 - Q1" is the direction vector,
//    and "u" is the parameter ranging from 0 to 1.
// 
// The squared distance function is:
// 
//   D ^ 2 = (||(P1 + t * d1) - (Q1 + u * d2)||) ^ 2
// 
// Minimizing this function leads to a system of two linear equations in two unknowns "t" and "u".
//
double getMinDistance(const Segment3D& seg1, const Segment3D& seg2)
{
    // Direction vectors of the segments
    const Vector3D vecDir1(seg1.getStart(), seg1.getEnd());
    const Vector3D vecDir2(seg2.getStart(), seg2.getEnd());

    // Vector between starting points
    const Vector3D vecStartPts(seg1.getStart(), seg2.getStart());

    // Dot products
    const double a = vecDir1.squaredNorm();
    const double b = vecDir1.dotProduct(vecDir2);
    const double c = vecDir2.squaredNorm();
    const double d = vecDir1.dotProduct(vecStartPts);
    const double e = vecDir2.dotProduct(vecStartPts);

    // Denominator of the parameter equations
    const double denom = a * c - b * b;

    // Unknowns of equations
    double t{};
    double u{};

    // If segments are nearly parallel, choose "t" as 0 and compute "u" from projection
    if (Utils::isZero(denom))
    {
        t = 0.0;
        u = std::clamp(e / c, 0.0, 1.0);
    }
    else
    {
        t = std::clamp((b * e - c * d) / denom, 0.0, 1.0);
        u = std::clamp((a * e - b * d) / denom, 0.0, 1.0);
    }

    // Closest points on segments
    const auto vecClosest1 = vecDir1 * t + seg1.getStart();
    const auto vecClosest2 = vecDir2 * u + seg2.getStart();

    // Euclidean distance between the closest points
    const Vector3D vecDistance(vecClosest1, vecClosest2);
    const double result = std::sqrt(vecDistance.squaredNorm());

    return result;
}

// ----------------------------------------------------------------------------------------------------
