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
#include "private.h"
#include <math.h>
#include <stdlib.h>
#include <stdint.h>



struct data * gordianCreateData(long count, enum datatype type, enum domain domain) {
    const int datatype_size = G_DATATYPE_SIZE[type];

    if (count > SIZE_MAX / datatype_size) return NULL;

    struct data * allocated_struct = malloc(sizeof(struct data));
    if (!allocated_struct) return NULL;

    void * allocated_array = calloc(count, datatype_size);
    if (!allocated_array) {
        free(allocated_struct);
        return NULL;
    }

    *allocated_struct = (struct data){
        allocated_array,
        type,
        datatype_size,
        count,
        INFINITY,
        -INFINITY,
        domain
    };

    return allocated_struct;
}
void gordianFreeData(struct data * data) {
    free(data->array);
    free(data);
}
