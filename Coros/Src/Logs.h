#pragma once

#ifdef COROS_DEBUG

#define COROS_ASSERT(x) \
    {                   \
        assert(x);      \
    }

#define COROS_PRINT(x)                         \
    {                                          \
        std::cout << "[COROS]: " << x << '\n'; \
    }

#define COROS_ERROR(x)                  \
    {                                   \
        COROS_PRINT(x);                 \
        COROS_ASSERT(false && "Error"); \
    }
#else if COROS_RELEASE
    #define COROS_ASSERT(x) {}
    #define COROS_PRINT(x) {}
    #define COROS_ERROR(x) {}
#endif