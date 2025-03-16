// ----------------------------------------------------------------------------------------------------
// Confidential and proprietary source code of BEOALEX.
// This source code may not be used, reproduced or disclosed in any manner without permission.
// Copyright (c) 2025, BEOALEX. All rights reserved.
// https://github.com/beoalex
// ----------------------------------------------------------------------------------------------------

#pragma once

#include <cmath>

// ----------------------------------------------------------------------------------------------------

namespace Utils
{
    inline bool isZero(double value)
    {
        constexpr double epsilon = 1e-6;
        return (std::fabs(value) < epsilon);
    }
}

// ----------------------------------------------------------------------------------------------------
