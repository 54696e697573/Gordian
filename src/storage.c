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
#include <stddef.h>



const int DATATYPE_SIZE[] = {
    sizeof(short),
    sizeof(int),
    sizeof(long),
    sizeof(float),
    sizeof(double)
};

double index_void_pointer_double(void * pointer, enum datatype type, size_t index) {
    void * new_pointer = (char*)pointer + index * DATATYPE_SIZE[type];
    switch (type) {
        case G_SHORT:
            return (double)(*(short*)new_pointer);
        case G_INT:
            return (double)(*(int*)new_pointer);
        case G_LONG:
            return (double)(*(long*)new_pointer);
        case G_FLOAT:
            return (double)(*(float*)new_pointer);
        case G_DOUBLE:
            return *(double*)new_pointer;
     }
};
long index_void_pointer_long(void * pointer, enum datatype type, size_t index) {
    void * new_pointer = (char*)pointer + index * DATATYPE_SIZE[type];
    switch (type) {
        case G_SHORT:
            return (long)(*(short*)new_pointer);
        case G_INT:
            return (long)(*(int*)new_pointer);
        case G_LONG:
            return *(long*)new_pointer;
        case G_FLOAT:
            return (long)(*(float*)new_pointer);
        case G_DOUBLE:
            return (long)(*(double*)new_pointer);
     }
}
void increment_void_pointer(void * pointer, enum datatype type, size_t index) {
    void * new_pointer = (char*)pointer + index * DATATYPE_SIZE[type];
    switch (type) {
        case G_SHORT:
            (*(short*)new_pointer)++;
        case G_INT:
            (*(int*)new_pointer)++;
        case G_LONG:
            (*(long*)new_pointer)++;
        case G_FLOAT:
            (*(float*)new_pointer)++;
        case G_DOUBLE:
            (*(double*)new_pointer)++;
     }
}

struct data * gordianCreateData(long count, enum datatype type, enum domain domain) {
    const int datatype_size = DATATYPE_SIZE[type];

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

