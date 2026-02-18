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



#ifndef GORDIAN_H
#define GORDIAN_H

#define VERSION "0.1.0"

// Storage

enum datatype {
    G_SHORT,
    G_INT,
    G_LONG,
    G_FLOAT,
    G_DOUBLE
};
enum domain {
    G_TIME,
    G_FREQUENCY
};
struct data {
    void * array;
    enum datatype type;
    int size;
    long count;
    float minimum;
    float maximum;
    enum domain domain;
};

struct data * gordianCreateData(long count, enum datatype type, enum domain domain);
void gordianFreeData(struct data * data);

// Processing

int gordianTimeToFrequency(struct data * data, struct data * buffer);
int gordianFrequencyToTime(struct data * data, struct data * buffer);

#endif
