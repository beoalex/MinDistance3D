// ----------------------------------------------------------------------------------------------------

#pragma once

#include "Point3D.hpp"

// ----------------------------------------------------------------------------------------------------

class Segment3D
{
public:
    Segment3D() = default;
    explicit Segment3D(const Point3D& ptStart, const Point3D& ptEnd);

    const Point3D& getStart() const;
    const Point3D& getEnd() const;

private:
    const Point3D m_ptStart{};
    const Point3D m_ptEnd{};
};

// ----------------------------------------------------------------------------------------------------

inline Segment3D::Segment3D(const Point3D& ptStart, const Point3D& ptEnd)
    : m_ptStart(ptStart), m_ptEnd(ptEnd)
{
}

inline const Point3D& Segment3D::getStart() const
{
    return m_ptStart;
}

inline const Point3D& Segment3D::getEnd() const
{
    return m_ptEnd;
}

// ----------------------------------------------------------------------------------------------------
