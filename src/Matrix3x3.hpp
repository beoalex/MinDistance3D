// ----------------------------------------------------------------------------------------------------
// Confidential and proprietary source code of BEOALEX.
// This source code may not be used, reproduced or disclosed in any manner without permission.
// Copyright (c) 2025, BEOALEX. All rights reserved.
// https://github.com/beoalex
// ----------------------------------------------------------------------------------------------------

#pragma once

#include "Vector3D.hpp"

// ----------------------------------------------------------------------------------------------------

class Matrix3x3
{
public:
    static inline double determinant(const Vector3D& vec0, const Vector3D& vec1, const Vector3D& vec2)
    {
        return (  vec0[0] * (vec1[1] * vec2[2] - vec1[2] * vec2[1])
                - vec0[1] * (vec1[0] * vec2[2] - vec1[2] * vec2[0])
                + vec0[2] * (vec1[0] * vec2[1] - vec1[1] * vec2[0]));
    }
};

// ----------------------------------------------------------------------------------------------------
