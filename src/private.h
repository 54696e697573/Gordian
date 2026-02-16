#ifndef PRIVATE_H
#define PRIVATE_H

// Storage

const int G_DATATYPE_SIZE[7] = {
    sizeof(char),
    sizeof(short),
    sizeof(int),
    sizeof(long),
    sizeof(long long),
    sizeof(float),
    sizeof(double)
};

// Processing

extern int G_POINTS_PER_BUCKET;

#endif
