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
#include <stdint.h>
#include <stddef.h>



int G_POINTS_PER_BUCKET = 4;

int gordianTimeToFrequency(struct data * data, struct data * buffer) {
    const int data_count = data->count;
    const int buffer_count = buffer->count;

    if (buffer_count < data_count / G_POINTS_PER_BUCKET) return 1;

    const int bucket_offset = (int)data->minimum;
    for (int index = 0; index < data_count; index++) {
        size_t bucket = (size_t)clamp_long(
            index_void_pointer_long(data->array, data->type, index) / G_POINTS_PER_BUCKET - bucket_offset,
            0,
            buffer_count - 1
        );

        increment_void_pointer(buffer->array, buffer->type, bucket);
    }

    buffer->domain = G_FREQUENCY;

    return 0;
}
int gordianFrequencyToTime(struct data * data, struct data * buffer) {
    //WIP

    return 0;
}

