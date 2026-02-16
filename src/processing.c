#include "gordian.h"
#include <stdint.h>



int G_POINTS_PER_BUCKET = 4;

int gordianTimeToFrequency(struct data * data, struct data * buffer) {
    const int data_count = data->count;
    const int buffer_count = buffer->count;

    if (buffer_count < data_count / G_POINTS_PER_BUCKET) return 1;

    int bucket;
    const int bucket_offset = (int)data->minimum;
    for (int index = 0; index < data_count; index++) {
        switch (data->type) {
            case G_CHAR:
                bucket = ((char*)data->array)[index] / G_POINTS_PER_BUCKET - bucket_offset;
                break;
            case G_SHORT:
                bucket = ((short*)data->array)[index] / G_POINTS_PER_BUCKET - bucket_offset;
                break;
            case G_INT:
                bucket = ((int*)data->array)[index] / G_POINTS_PER_BUCKET - bucket_offset;
                break;
            case G_LONG:
                bucket = ((long*)data->array)[index] / G_POINTS_PER_BUCKET - bucket_offset;
                break;
            case G_LONG_LONG:
                bucket = ((long long*)data->array)[index] / G_POINTS_PER_BUCKET - bucket_offset;
                break;
            case G_FLOAT:
                bucket = (int)((float*)data->array)[index] / G_POINTS_PER_BUCKET - bucket_offset;
                break;
            case G_DOUBLE:
                bucket = (long)((double*)data->array)[index] / G_POINTS_PER_BUCKET - bucket_offset;
                break;
            default:
                return 1;
        }
        if (bucket < 0 || bucket >=buffer_count) return 0;
        switch (buffer->type) {
            case G_CHAR:
                ((char*)buffer->array)[bucket]++;
                break;
            case G_SHORT:
                ((short*)buffer->array)[bucket]++;
                break;
            case G_INT:
                ((int*)buffer->array)[bucket]++;
                break;
            case G_LONG:
                ((long*)buffer->array)[bucket]++;
                break;
            case G_LONG_LONG:
                ((long long*)buffer->array)[bucket]++;
                break;
            case G_FLOAT:
                ((float*)buffer->array)[bucket]++;
                break;
            case G_DOUBLE:
                ((double*)buffer->array)[bucket]++;
                break;
            default:
                return 1;
        }
    }

    buffer->domain = G_FREQUENCY;

    return 0;
}
int gordianFrequencyToTime(struct data * data, struct data * buffer) {
    return 0;
}
