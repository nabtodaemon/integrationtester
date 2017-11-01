#include <stdio.h>
#include "unabto/unabto_common_main.h"
#include "unabto/unabto_app.h"
#include "unabto_integrationtester_config.h"

#include "unabto_aes_test.h"
#include "unabto_sha256_test.h"
#include "unabto_aes_cbc_test.h"
#include "unabto_aes128_sha256_test.h"
#include "unabto_hmac_sha256_test.h"

int main(int argc, char** argv) {
    bool r;

    NABTO_LOG_INFO(("Testing sha256 implementation"));
    r = sha256_test();
    if (!r) {
        NABTO_LOG_INFO(("sha256 test failed"));
    }

    NABTO_LOG_INFO(("Testing hmac_sha256"));
    r = hmac_sha256_test();
    if (!r) {
        NABTO_LOG_INFO(("hmac sha256 tests failed"));
    }

    NABTO_LOG_INFO(("Testing AES implementation"));
    r = aes_test();
    if (!r) {
        NABTO_LOG_INFO(("AES test failed"));
    }

    NABTO_LOG_INFO(("Testing AES cbc encrypt/decrypt"));
    r = aes_cbc_test();
    if (!r) {
        NABTO_LOG_INFO(("AES_CBC encrypt/decrypt failed"));
    }

    int i;
    NABTO_LOG_INFO(("testing unabto timings"));

    i = sha256_timing_test();
    NABTO_LOG_INFO(("%i 131bytes sha256 hashes in one second.", i));

    i = integrity_verify_timing();
    NABTO_LOG_INFO(("%i integrity checks in one second.", i));

    i = aes_timing_test();
    NABTO_LOG_INFO(("%i aes blocks en/decryptiong in one second.", i));

    i = aes_cbc_timing_test();
    NABTO_LOG_INFO(("%i aes_cbc en/decryptions in one second.", i));

    exit(r?0:1);
}

application_event_result application_event(application_request* request, unabto_query_request* read_buffer, unabto_query_response* write_buffer) {
    return AER_REQ_INV_QUERY_ID;
}

