#ifndef SBOX_H_
#define SBOX_H_
#if COMPONENT_CIPHER_SBOX

#include "../uCosmos/uCosmos.h"
#include "../_config/sbox_config.h"

namespace sbox {
	void encrypt(uint8_t * ciphertext, const uint8_t * plaintext,  size_t length);
	void decrypt(uint8_t * plaintext,  const uint8_t * ciphertext, size_t length);
}

#endif
#endif
