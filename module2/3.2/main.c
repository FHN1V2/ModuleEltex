#include <stdio.h>
#include <stdlib.h>
#include "network.h"

int main(int argc, char *argv[]) {
    if (argc != 4) {
        printf("Использование: %s <gateway_ip> <subnet_mask> <N>\n", argv[0]);
        return 0;
    }

    const char *gateway_ip_str = argv[1];
    const char *mask_str = argv[2];
    int N = atoi(argv[3]);

    process_packets(gateway_ip_str, mask_str, N);

    return 0;
}
