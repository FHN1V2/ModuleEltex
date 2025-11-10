#include "network.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// --- Преобразование IP-адреса из строки в число ---
uint32_t ip_str_to_int(const char *ip_str) {
    unsigned int b1, b2, b3, b4;
    if (sscanf(ip_str, "%u.%u.%u.%u", &b1, &b2, &b3, &b4) != 4 ||
        b1 > 255 || b2 > 255 || b3 > 255 || b4 > 255) {
        fprintf(stderr, "Ошибка: неверный формат IP адреса %s\n", ip_str);
        exit(EXIT_FAILURE);
    }
    return (b1 << 24) | (b2 << 16) | (b3 << 8) | b4;
}

// --- Преобразование числа в IP строку ---
void ip_int_to_str(uint32_t ip, char *buffer) {
    unsigned int b1 = (ip >> 24) & 0xFF;
    unsigned int b2 = (ip >> 16) & 0xFF;
    unsigned int b3 = (ip >> 8) & 0xFF;
    unsigned int b4 = ip & 0xFF;
    sprintf(buffer, "%u.%u.%u.%u", b1, b2, b3, b4);
}

// --- Проверка, принадлежат ли IP одной подсети ---
int is_same_subnet(uint32_t ip1, uint32_t ip2, uint32_t mask) {
    return (ip1 & mask) == (ip2 & mask);
}

// --- Генерация случайного IP ---
uint32_t generate_random_ip(void) {
    uint32_t ip = 0;
    for (int i = 0; i < 4; i++) {
        ip = (ip << 8) | (rand() % 256);
    }
    return ip;
}

// --- Основная логика обработки пакетов ---
void process_packets(const char *gateway_ip_str, const char *mask_str, int N) {
    if (N <= 0) {
        fprintf(stderr, "Ошибка: количество пакетов должно быть положительным числом.\n");
        exit(EXIT_FAILURE);
    }

    srand(time(NULL));

    uint32_t gateway_ip = ip_str_to_int(gateway_ip_str);
    uint32_t subnet_mask = ip_str_to_int(mask_str);

    int same_subnet_count = 0;

    for (int i = 0; i < N; i++) {
        uint32_t random_ip = generate_random_ip();
        if (is_same_subnet(random_ip, gateway_ip, subnet_mask)) {
            same_subnet_count++;
        }
    }

    double same_percent = (same_subnet_count * 100.0) / N;
    double other_percent = 100.0 - same_percent;

    printf("Результаты обработки %d пакетов:\n", N);
    printf("В своей подсети: %d пакетов (%.2f%%)\n", same_subnet_count, same_percent);
    printf("В других сетях: %d пакетов (%.2f%%)\n", N - same_subnet_count, other_percent);
}
