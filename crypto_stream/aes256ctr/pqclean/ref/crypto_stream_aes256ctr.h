#ifndef CRYPTO_STREAM_AES256CTR_H
#define CRYPTO_STREAM_AES256CTR_H

#include <stddef.h>
#include <stdint.h>

#include "aes.h"

#define crypto_stream_aes256ctr CRYPTO_NAMESPACE(crypto_stream_aes256ctr)
int crypto_stream_aes256ctr(
    uint8_t *out,
    size_t outlen,
    const uint8_t nonce[AESCTR_NONCEBYTES],
    const uint8_t key[AES256_KEYBYTES]);

#endif
