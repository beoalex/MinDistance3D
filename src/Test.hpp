// ----------------------------------------------------------------------------------------------------
// Confidential and proprietary source code of BEOALEX.
// This source code may not be used, reproduced or disclosed in any manner without permission.
// Copyright (c) 2025, BEOALEX. All rights reserved.
// https://github.com/beoalex
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
    void parallel()
    {
        runOne({ 0, 0, 0 }, { 10, 0, 0 }, { 0, 5, 0 }, { 10, 5, 0 }, 5.0, __func__);
    }

    void perpendicular()
    {
        runOne({ 0, 0, 0 }, { 10, 0, 0 }, { 5, -5, 1 }, { 5, 5, 1 }, 1.0, __func__);
    }

    void skewed()
    {
        runOne({ 0, 0, 0 }, { 10, 0, 0 }, { 5, 5, 5 }, { 5, -5, 10 }, 6.708, __func__);
    }

    void intersecting()
    {
        runOne({ 0, 0, 0 }, { 10, 0, 0 }, { 5, 0, -5 }, { 5, 0, 5 }, 0.0, __func__);
    }

    void coincident()
    {
        runOne({ 0, 0, 0 }, { 10, 0, 0 }, { 5, 0, 0 }, { 10, 0, 0 }, 0.0, __func__);
    }

    void touching()
    {
        runOne({ 0, 0, 0 }, { 5, 0, 0 }, { 5, 0, 0 }, { 10, 0, 0 }, 0.0, __func__);
    }

    std::uint32_t failCount() const;

private:
    using Coords = std::array<double, 3>;

    std::uint32_t m_failCount = 0;

    void runOne(
        const Coords& segA_first, const Coords& segA_second,
        const Coords& segB_first, const Coords& segB_second,
        double expected, const char* testName);
};

// ----------------------------------------------------------------------------------------------------

inline std::uint32_t Test::failCount() const
{
    return m_failCount;
}

inline void Test::runOne(
    const Coords& segA_first, const Coords& segA_second,
    const Coords& segB_first, const Coords& segB_second,
    double expected, const char* testName)
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
