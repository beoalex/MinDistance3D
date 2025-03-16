// ----------------------------------------------------------------------------------------------------
// Confidential and proprietary source code of BEOALEX.
// This source code may not be used, reproduced or disclosed in any manner without permission.
// Copyright (c) 2025, BEOALEX. All rights reserved.
// https://github.com/beoalex
// ----------------------------------------------------------------------------------------------------

#pragma once

#include <array>

// ----------------------------------------------------------------------------------------------------

class Point3D
{
public:
    Point3D() = default;
    explicit Point3D(double x, double y, double z);
    explicit Point3D(const std::array<double, 3>& coords);

    double x() const;
    double y() const;
    double z() const;

private:
    const double m_x{};
    const double m_y{};
    const double m_z{};
};

// ----------------------------------------------------------------------------------------------------

inline Point3D::Point3D(double x, double y, double z)
    : m_x(x), m_y(y), m_z(z)
{
}

inline Point3D::Point3D(const std::array<double, 3>& coords)
    : m_x(coords[0]), m_y(coords[1]), m_z(coords[2])
{
}

inline double Point3D::x() const
{
    return m_x;
}

inline double Point3D::y() const
{
    return m_y;
}

inline double Point3D::z() const
{
    return m_z;
}

// ----------------------------------------------------------------------------------------------------
