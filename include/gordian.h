#ifndef GORDIAN_H
#define GORDIAN_H

#define VERSION "0.1.0"

// Storage

enum datatype {
    G_CHAR,
    G_SHORT,
    G_INT,
    G_LONG,
    G_LONG_LONG,
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
