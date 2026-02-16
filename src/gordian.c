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

struct data gordianTimeToFrequecy(struct data data) {
    //
}
struct data gordianFrequencyToTime(struct data data) {
    //
}
