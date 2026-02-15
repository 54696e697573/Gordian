#include "gordian.h"

enum domain {
    time,
    frequency
};
struct data {
    void * data;
    int size;
    long count;
    float minimum;
    float maximum;
    enum domain domain;
};
