// ----------------------------------------------------------------------------------------------------

#pragma once

#include <cmath>
#include <iostream>

#include "Point3D.hpp"
#include "Segment3D.hpp"
#include "MinDistance.hpp"

// ----------------------------------------------------------------------------------------------------

class Test
{
public:
    // Tests
    void parallel();
    void perpendicular();
    void skewed();
    void intersecting();
    void coincident();
    void touching();

    // Diagnostics
    std::uint32_t failCount() const;

private:
    std::uint32_t m_failCount = 0;

    void runOne(
        const std::array<double, 3>& segA_first,
        const std::array<double, 3>& segA_second,
        const std::array<double, 3>& segB_first,
        const std::array<double, 3>& segB_second,
        double expected,
        const char* testName);
};

// ----------------------------------------------------------------------------------------------------

inline void Test::parallel()
{
    runOne({ 0, 0, 0 }, { 10, 0, 0 }, { 0, 5, 0 }, { 10, 5, 0 }, 5.0, __func__);
}

inline void Test::perpendicular()
{
    runOne({ 0, 0, 0 }, { 10, 0, 0 }, { 5, -5, 1 }, { 5, 5, 1 }, 1.0, __func__);
}

inline void Test::skewed()
{
    runOne({ 0, 0, 0 }, { 10, 0, 0 }, { 5, 5, 5 }, { 5, -5, 10 }, 6.708, __func__);
}

inline void Test::intersecting()
{
    runOne({ 0, 0, 0 }, { 10, 0, 0 }, { 5, 0, -5 }, { 5, 0, 5 }, 0.0, __func__);
}

inline void Test::coincident()
{
    runOne({ 0, 0, 0 }, { 10, 0, 0 }, { 5, 0, 0 }, { 10, 0, 0 }, 0.0, __func__);
}

inline void Test::touching()
{
    runOne({ 0, 0, 0 }, { 5, 0, 0 }, { 5, 0, 0 }, { 10, 0, 0 }, 0.0, __func__);
}

inline std::uint32_t Test::failCount() const
{
    return m_failCount;
}

inline void Test::runOne(
    const std::array<double, 3>& segA_first,
    const std::array<double, 3>& segA_second,
    const std::array<double, 3>& segB_first,
    const std::array<double, 3>& segB_second,
    double expected,
    const char* testName)
{
    const Segment3D segA{ Point3D(segA_first), Point3D(segA_second) };
    const Segment3D segB{ Point3D(segB_first), Point3D(segB_second) };
    const double actual = getMinDistance(segA, segB);
    constexpr double epsilon = 1e-3;
    const bool fail = !(std::fabs(actual - expected) < epsilon);

    if (fail)
    {
        ++m_failCount;
        std::cout << "TEST FAILED: " << testName << std::endl;
    }
}

// ----------------------------------------------------------------------------------------------------
