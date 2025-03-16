// ----------------------------------------------------------------------------------------------------

#pragma once

#include "Point3D.hpp"

// ----------------------------------------------------------------------------------------------------

class Segment3D
{
public:
    Segment3D() = default;
    explicit Segment3D(const Point3D& first, const Point3D& second);

    const Point3D& first() const;
    const Point3D& second() const;

private:
    const Point3D m_first{};
    const Point3D m_second{};
};

// ----------------------------------------------------------------------------------------------------

inline Segment3D::Segment3D(const Point3D& first, const Point3D& second)
    : m_first(first), m_second(second)
{
}

inline const Point3D& Segment3D::first() const
{
    return m_first;
}

inline const Point3D& Segment3D::second() const
{
    return m_second;
}

// ----------------------------------------------------------------------------------------------------
