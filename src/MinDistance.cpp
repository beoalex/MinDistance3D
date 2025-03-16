// ----------------------------------------------------------------------------------------------------
// Confidential and proprietary source code of BEOALEX.
// This source code may not be used, reproduced or disclosed in any manner without permission.
// Copyright (c) 2025, BEOALEX. All rights reserved.
// https://github.com/beoalex
// ----------------------------------------------------------------------------------------------------

#include "Utils.hpp"
#include "Vector3D.hpp"
#include "Segment3D.hpp"
#include "Matrix3x3.hpp"
#include "MinDistance.hpp"

// ----------------------------------------------------------------------------------------------------

//
// The algorithm is taken from here (and rewritten from Python to C++):
// https://stackoverflow.com/questions/2824478/shortest-distance-between-two-line-segments
// 
// The online tests were carried out here:
// http://ambrnet.com/TrigoCalc/Line3D/Distance2Lines3D_.htm
//
double getMinDistance(const Segment3D& segA, const Segment3D& segB)
{
    // Shortcuts
    const Point3D& a0 = segA.first();
    const Point3D& a1 = segA.second();
    const Point3D& b0 = segB.first();
    const Point3D& b1 = segB.second();

    // Constants
    constexpr double Zero = 0.0;

    // Calculate denominator
    const Vector3D A(a0, a1);
    const Vector3D B(b0, b1);
    const double magA = A.norm();
    const double magB = B.norm();

    const Vector3D _A = A / magA;
    const Vector3D _B = B / magB;

    const Vector3D cross = _A.cross(_B);
    const double denom = std::pow(cross.norm(), 2.0);

    // If lines are parallel ("denom" is zero), test if lines overlap.
    // If they don't overlap, then there is a closest point solution.
    // If they do overlap, there are infinite closest positions, but there is a closest distance.
    if (Utils::isZero(denom))
    {
        const double d0 = _A.dot(Vector3D(a0, b0));
        const double d1 = _A.dot(Vector3D(a0, b1));

        // Is segment B before A?
        if (d0 <= Zero && d1 <= Zero)
        {
            if (std::fabs(d0) < std::fabs(d1))
            {
                return Vector3D(b0, a0).norm();
            }

            return Vector3D(b1, a0).norm();
        }
        // Is segment B after A?
        else if (d0 >= magA && d1 >= magA)
        {
            if (std::fabs(d0) < std::fabs(d1))
            {
                return Vector3D(b0, a1).norm();
            }

            return Vector3D(b1, a1).norm();
        }

        // Segments overlap, return distance between parallel segments
        return (_A * d0 + a0 - b0).norm();
    }

    // Lines criss-cross - calculate the projected closest points
    const Vector3D t(a0, b0);
    const double detA = Matrix3x3::determinant(t, _B, cross);
    const double detB = Matrix3x3::determinant(t, _A, cross);

    const double t0 = detA / denom;
    const double t1 = detB / denom;

    // Projected closest points on segments
    Vector3D pA = _A * t0 + a0;
    Vector3D pB = _B * t1 + b0;

    // Clamp projections
    {
        if (t0 < Zero)
        {
            pA = a0;
        }
        else if (t0 > magA)
        {
            pA = a1;
        }

        if (t1 < Zero)
        {
            pB = b0;
        }
        else if (t1 > magB)
        {
            pB = b1;
        }

        // Clamp projection A
        if (t0 < Zero || t0 > magA)
        {
            double dot = _B.dot(pA - b0);

            if (dot < Zero)
            {
                dot = Zero;
            }
            else if (dot > magB)
            {
                dot = magB;
            }

            pB = _B * dot + b0;
        }

        // Clamp projection B
        if (t1 < Zero || t1 > magB)
        {
            double dot = _A.dot(pB - a0);

            if (dot < Zero)
            {
                dot = Zero;
            }
            else if (dot > magA)
            {
                dot = magA;
            }

            pA = _A * dot + a0;
        }
    }

    return (pA - pB).norm();
}

// ----------------------------------------------------------------------------------------------------
