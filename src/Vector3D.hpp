// ----------------------------------------------------------------------------------------------------

#pragma once

#include "Point3D.hpp"

// ----------------------------------------------------------------------------------------------------

class Vector3D
{
public:
    Vector3D() = default;
    explicit Vector3D(double x, double y, double z);
    explicit Vector3D(const Point3D& ptStart, const Point3D& ptEnd);
    explicit Vector3D(const Vector3D& vecStart, const Vector3D& vecEnd);

    double getX() const;
    double getY() const;
    double getZ() const;

    Vector3D operator*(double scalar) const;
    Vector3D operator+(const Point3D& point) const;

    double dotProduct(const Vector3D& vector) const;
    double squaredNorm() const;

private:
    const double m_x{};
    const double m_y{};
    const double m_z{};
};

// ----------------------------------------------------------------------------------------------------

inline Vector3D::Vector3D(double x, double y, double z)
    : m_x(x), m_y(y), m_z(z)
{
}

inline Vector3D::Vector3D(const Point3D& ptStart, const Point3D& ptEnd)
    : m_x(ptEnd.getX() - ptStart.getX()),
      m_y(ptEnd.getY() - ptStart.getY()),
      m_z(ptEnd.getZ() - ptStart.getZ())
{
}

inline Vector3D::Vector3D(const Vector3D& vecStart, const Vector3D& vecEnd)
    : m_x(vecEnd.getX() - vecStart.getX()),
      m_y(vecEnd.getY() - vecStart.getY()),
      m_z(vecEnd.getZ() - vecStart.getZ())
{
}

inline double Vector3D::getX() const
{
    return m_x;
}

inline double Vector3D::getY() const
{
    return m_y;
}

inline double Vector3D::getZ() const
{
    return m_z;
}

inline Vector3D Vector3D::operator*(double scalar) const
{
    return Vector3D(
        m_x * scalar,
        m_y * scalar,
        m_z * scalar);
}

inline Vector3D Vector3D::operator+(const Point3D& point) const
{
    return Vector3D(
        this->m_x + point.getX(),
        this->m_y + point.getY(),
        this->m_z + point.getZ());
}

inline double Vector3D::dotProduct(const Vector3D& vector) const
{
    return (  this->m_x * vector.m_x
            + this->m_y * vector.m_y
            + this->m_z * vector.m_z);
}

inline double Vector3D::squaredNorm() const
{
    return dotProduct(*this);
}

// ----------------------------------------------------------------------------------------------------
