#include "../_config/_config.h"
#if COMPONENT_CIPHER_SBOX
#include "sbox.h"

namespace sbox {

	void encrypt(uint8_t * ciphertext, const uint8_t * plaintext, size_t length) {
		for(size_t i=0; i<length; i++) {
			ciphertext[i] = key_a[plaintext[i] ^ uint8_t(i)] ^ (i ? ciphertext[i-1] : 0);
		}
	}

	void decrypt(uint8_t * plaintext, const uint8_t * ciphertext, size_t length) {
		for(size_t i=0; i<length; i++) {
			plaintext[i] = key_b[ciphertext[i] ^ (i ? ciphertext[i-1] : 0)] ^ uint8_t(i);
		}
	}

}

#endif
