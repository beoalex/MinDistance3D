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
double getMinDistance(const Segment3D& seg1, const Segment3D& seg2)
{
    // Some constants
    constexpr double Zero = 0.0;

    // Calculate denominator
    const Vector3D A(seg1.getStart(), seg1.getEnd());
    const Vector3D B(seg2.getStart(), seg2.getEnd());
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
        const double d0 = _A.dot(Vector3D(seg1.getStart(), seg2.getStart()));
        const double d1 = _A.dot(Vector3D(seg1.getStart(), seg2.getEnd()));

        // Is segment B before A?
        if (d0 <= Zero && d1 <= Zero)
        {
            if (std::fabs(d0) < std::fabs(d1))
            {
                return Vector3D(seg2.getStart(), seg1.getStart()).norm();
            }

            return Vector3D(seg2.getEnd(), seg1.getStart()).norm();
        }
        // Is segment B after A?
        else if (d0 >= magA && d1 >= magA)
        {
            if (std::fabs(d0) < std::fabs(d1))
            {
                return Vector3D(seg2.getStart(), seg1.getEnd()).norm();
            }

            return Vector3D(seg2.getEnd(), seg1.getEnd()).norm();
        }

        // Segments overlap, return distance between parallel segments
        return (_A * d0 + seg1.getStart() - seg2.getStart()).norm();
    }

    // Lines criss-cross - calculate the projected closest points
    const Vector3D t(seg1.getStart(), seg2.getStart());
    const double detA = Matrix3x3::determinant(t, _B, cross);
    const double detB = Matrix3x3::determinant(t, _A, cross);

    const double t0 = detA / denom;
    const double t1 = detB / denom;

    // Projected closest points on segments
    Vector3D pA = _A * t0 + seg1.getStart();
    Vector3D pB = _B * t1 + seg2.getStart();

    // Clamp projections
    {
        if (t0 < Zero)
        {
            pA = seg1.getStart();
        }
        else if (t0 > magA)
        {
            pA = seg1.getEnd();
        }

        if (t1 < Zero)
        {
            pB = seg2.getStart();
        }
        else if (t1 > magB)
        {
            pB = seg2.getEnd();
        }

        // Clamp projection A
        if (t0 < Zero || t0 > magA)
        {
            double dot = _B.dot(pA - seg2.getStart());

            if (dot < Zero)
            {
                dot = Zero;
            }
            else if (dot > magB)
            {
                dot = magB;
            }

            pB = _B * dot + seg2.getStart();
        }

        // Clamp projection B
        if (t1 < Zero || t1 > magB)
        {
            double dot = _A.dot(pB - seg1.getStart());

            if (dot < Zero)
            {
                dot = Zero;
            }
            else if (dot > magA)
            {
                dot = magA;
            }

            pA = _A * dot + seg1.getStart();
        }
    }

    return (pA - pB).norm();
}

// ----------------------------------------------------------------------------------------------------
