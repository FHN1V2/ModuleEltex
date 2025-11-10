#ifndef NETWORK_H
#define NETWORK_H

#include <stdint.h>

uint32_t ip_str_to_int(const char *ip_str);
void ip_int_to_str(uint32_t ip, char *buffer);
int is_same_subnet(uint32_t ip1, uint32_t ip2, uint32_t mask);
uint32_t generate_random_ip(void);
void process_packets(const char *gateway_ip_str, const char *mask_str, int N);

#endif
