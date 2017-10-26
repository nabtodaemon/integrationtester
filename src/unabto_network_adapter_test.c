#include <unabto/unabto_external_environment.h>
#include <unabto/unabto_logging.h>

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
