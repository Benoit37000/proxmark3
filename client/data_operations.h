#ifndef DATA_OPERATIONS_H
#define DATA_OPERATIONS_H

#include <string.h>
#include <stdint.h>

// Max graph trace len: 40000 (bigbuf) * 8 (at 1 bit per sample)
#define MAX_GRAPH_TRACE_LEN (40000 * 8 )

extern int GraphBuffer[MAX_GRAPH_TRACE_LEN];
extern int GraphTraceLen;
extern int s_Buff[MAX_GRAPH_TRACE_LEN];


int autoCorr(const int* in, int *out, size_t len, int window);
int directionalThreshold(const int* in, int *out, size_t len, int8_t up, int8_t down);
#endif // DATA_OPERATIONS_H
