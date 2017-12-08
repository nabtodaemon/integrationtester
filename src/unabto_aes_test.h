#ifndef _AES_TEST_H_
#define _AES_TEST_H_

#include "unabto/unabto_env_base.h"

#ifndef UNABTO_CRYPTO_MODULE_LIBTOMCRYPT
bool aes_test(void);
#endif

int aes_timing_test(void);

#endif
