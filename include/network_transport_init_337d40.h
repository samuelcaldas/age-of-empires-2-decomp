#ifndef NETWORK_TRANSPORT_INIT_337D40_H
#define NETWORK_TRANSPORT_INIT_337D40_H
struct TransportSema { int count, max_count, init_count, wait_threads, attr, option; };
struct TransportAddress { unsigned char len, family; unsigned short port; unsigned int node[2]; unsigned char tail[4]; };
struct TransportThread { int status; void (*entry)(); void *stack; int stack_size; void *gp; int priority; };
extern "C" {
int func_00337D40(void);
}
#endif
