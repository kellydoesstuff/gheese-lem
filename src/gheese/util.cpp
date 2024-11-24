#include "C:\Users\kelly\OneDrive\Desktop\gheeseLem\gheese-lem\include\gheese\util.hpp"

namespace gheese {
    int sgn(double _input) {
        if(_input > 0) return 1;
        else if (_input < 0) return -1;
        return 0;
    }
}