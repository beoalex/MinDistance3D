// ----------------------------------------------------------------------------------------------------
// Confidential and proprietary source code of BEOALEX.
// This source code may not be used, reproduced or disclosed in any manner without permission.
// Copyright (c) 2025, BEOALEX. All rights reserved.
// https://github.com/beoalex
// ----------------------------------------------------------------------------------------------------

#include "Test.hpp"

// ----------------------------------------------------------------------------------------------------

int main()
{
    Test test;

    test.parallel();
    test.perpendicular();
    test.skewed();
    test.intersecting();
    test.coincident();
    test.touching();

    return ((test.failCount() == 0) ? 0 : 1);
}

// ----------------------------------------------------------------------------------------------------
