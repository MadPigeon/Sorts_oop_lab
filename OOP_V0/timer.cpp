// Windows time query

#include <windows.h>

inline long long gettimeus()
{
    static LARGE_INTEGER ClockPerSecond = { 0 };
    if( ClockPerSecond.QuadPart == 0 ) QueryPerformanceFrequency( &ClockPerSecond );
    LARGE_INTEGER li;
    QueryPerformanceCounter( &li );
    return li.QuadPart * 1000000LL / ClockPerSecond.QuadPart;
}
