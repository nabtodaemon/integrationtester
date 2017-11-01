#include <unabto/unabto_external_environment.h>
#include <unabto/unabto_util.h>
#include <unabto/unabto_logging.h>


//*** DNS adapter ***

void nabto_dns_resolve(const char* id) {
    return;
}

nabto_dns_status_t nabto_dns_is_resolved(const char *id, uint32_t* v4addrs) {
    return NABTO_DNS_ERROR;
}

//*** Network adapter ***

bool nabto_init_socket(uint32_t localAddr, uint16_t* localPort, nabto_socket_t* sock) {
    return false;
}

void nabto_close_socket(nabto_socket_t* sock) {
    return;
}

ssize_t nabto_read(nabto_socket_t sock, uint8_t* buf, size_t len, uint32_t* addr, uint16_t* port) {
    return 0;
}

ssize_t nabto_write(nabto_socket_t sock, const uint8_t* buf, size_t len, uint32_t addr, uint16_t port) {
    return 0;
}

//*** Random adapter ***

void nabto_random(uint8_t* buf, size_t len) {
   return;
}

