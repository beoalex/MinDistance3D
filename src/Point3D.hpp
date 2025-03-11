// ----------------------------------------------------------------------------------------------------

#pragma once

// ----------------------------------------------------------------------------------------------------

class Point3D
{
public:
    Point3D() = default;
    explicit Point3D(double x, double y, double z);

    double getX() const;
    double getY() const;
    double getZ() const;

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

inline double Point3D::getX() const
{
    return m_x;
}

inline double Point3D::getY() const
{
    return m_y;
}

inline double Point3D::getZ() const
{
    return m_z;
}

// ----------------------------------------------------------------------------------------------------
