// Copyright (C) 2026  Tinius Treider (timmytreider@outlook.com)

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU Affero General Public License as published
// by the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Affero General Public License for more details.

// You should have received a copy of the GNU Affero General Public License
// along with this program.  If not, see <https://www.gnu.org/licenses/>.



#include "gordian.h"
#include <stddef.h>



#ifndef PRIVATE_H
#define PRIVATE_H

// Storage

extern const int DATATYPE_SIZE[];

double index_void_pointer_double(void * pointer, enum datatype type, size_t index);
long index_void_pointer_long(void * pointer, enum datatype type, size_t index);
void increment_void_pointer(void * pointer, enum datatype type, size_t index);

// Processing



// Utility

long clamp_long(long value, long min, long max);

#endif

