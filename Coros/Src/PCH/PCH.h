#pragma once

#ifdef COROS_BUILD_DEBUG
    #define COROS_DEBUG 
#else if COROS_BUILD_RELEASE
    #define COROS_RELEASE
#endif

#include <iostream>
#include <assert.h>

#include <vector>

#include <random>
#include <unordered_map>

#include "Logs.h"

