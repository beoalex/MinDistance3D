// ----------------------------------------------------------------------------------------------------

#pragma once

#include <cmath>
#include <stdexcept>

#include "Point3D.hpp"

// ----------------------------------------------------------------------------------------------------

class Vector3D
{
public:
    Vector3D() = default;
    explicit Vector3D(double x, double y, double z);
    explicit Vector3D(const Point3D& ptStart, const Point3D& ptEnd);
    explicit Vector3D(const Vector3D& vecStart, const Vector3D& vecEnd);

    double operator[](unsigned int index) const;

    Vector3D operator*(double scalar) const;
    Vector3D operator/(double scalar) const;

    Vector3D operator+(const Point3D& point) const;
    Vector3D operator-(const Point3D& point) const;
    Vector3D operator-(const Vector3D& vector) const;

    Vector3D& operator=(const Point3D& point);

    double dot(const Vector3D& vector) const;
    Vector3D cross(const Vector3D& vector) const;
    double norm() const;

private:
    double m_x{};
    double m_y{};
    double m_z{};
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
    : m_x(vecEnd.m_x - vecStart.m_x),
      m_y(vecEnd.m_y - vecStart.m_y),
      m_z(vecEnd.m_z - vecStart.m_z)
{
}

inline double Vector3D::operator[](unsigned int index) const
{
    switch (index)
    {
        case 0: return m_x;
        case 1: return m_y;
        case 2: return m_z;
    }

    throw std::out_of_range("Vector3D::operator[]");
}

inline Vector3D Vector3D::operator*(double scalar) const
{
    return Vector3D(
        m_x * scalar,
        m_y * scalar,
        m_z * scalar);
}

inline Vector3D Vector3D::operator/(double scalar) const
{
    return Vector3D(
        m_x / scalar,
        m_y / scalar,
        m_z / scalar);
}

inline Vector3D Vector3D::operator+(const Point3D& point) const
{
    return Vector3D(
        this->m_x + point.getX(),
        this->m_y + point.getY(),
        this->m_z + point.getZ());
}

inline Vector3D Vector3D::operator-(const Point3D& point) const
{
    return Vector3D(
        this->m_x - point.getX(),
        this->m_y - point.getY(),
        this->m_z - point.getZ());
}

inline Vector3D Vector3D::operator-(const Vector3D& vector) const
{
    return Vector3D(
        this->m_x - vector.m_x,
        this->m_y - vector.m_y,
        this->m_z - vector.m_z);
}

inline Vector3D& Vector3D::operator=(const Point3D& point)
{
    m_x = point.getX();
    m_y = point.getY();
    m_z = point.getZ();

    return *this;
}

inline double Vector3D::dot(const Vector3D& vector) const
{
    return (  this->m_x * vector.m_x
            + this->m_y * vector.m_y
            + this->m_z * vector.m_z);
}

inline Vector3D Vector3D::cross(const Vector3D& vector) const
{
    return Vector3D(
        this->m_y * vector.m_z - this->m_z * vector.m_y,
        this->m_z * vector.m_x - this->m_x * vector.m_z,
        this->m_x * vector.m_y - this->m_y * vector.m_x);
}

inline double Vector3D::norm() const
{
    return std::sqrt(dot(*this));
}

// ----------------------------------------------------------------------------------------------------
