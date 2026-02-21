// copyright (c) 2026  tinius treider (timmytreider@outlook.com)

// this program is free software: you can redistribute it and/or modify
// it under the terms of the gnu affero general public license as published
// by the free software foundation, either version 3 of the license, or
// (at your option) any later version.

// this program is distributed in the hope that it will be useful,
// but without any warranty; without even the implied warranty of
// merchantability or fitness for a particular purpose.  see the
// gnu affero general public license for more details.

// you should have received a copy of the gnu affero general public license
// along with this program.  if not, see <https://www.gnu.org/licenses/>.



#include "private.h"



long clamp_long(long value, long min, long max) {
    if (value < min) {
        return min;
    } else if (value > max) {
        return max;
    }
    return value;
}

