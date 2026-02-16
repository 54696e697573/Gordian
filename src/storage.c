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
