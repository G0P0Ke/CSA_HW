#ifndef __rnd__
#define __rnd__

#include <cstdlib>

//------------------------------------------------------------------------------
// rnd.h - содержит генератор случайных чисел в диапазоне от 10 до 110
//------------------------------------------------------------------------------

inline auto Random() {
    return rand() % 100 + 10;
}

#endif //__rnd__

