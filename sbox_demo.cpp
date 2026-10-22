#include "../_config/_config.h"
#if COMPONENT_CIPHER_SBOX
#include "sbox_demo.h"

#if PICO_RP2040 || PICO_RP2350
	#include "pico/stdlib.h"
#endif

#if SBOX_USE_DEMO_COMMANDS

namespace sbox {

// sbox_e 00000000000000000000000000000000
// sbox_d 6E0B83AE4ADCAA457D3D1E5A40CA990E

// sbox_e 00112233445566778899AABBCCDDEEFF
// sbox_d 6E1A167D0E9F883FEAA359047859524D

// sbox_e 000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000
// sbox_d 6E0B83AE4ADCAA457D3D1E5A40CA990E7A0103BFCF40C492B28E416DD341B1B8B46B5A838BD9FB9FDE7BC64828F675B8D309B2C57794652B5931F9E1801C865A291A08AFF7324D1857A0B1330950AD83120C4F59273EA530F11891FE32DE0D0215BAFDA76174F442B02D4F7680E384DB6CCA59727CAB08CC

static inline uint64_t get_time_us(void) {
	#if ESP_PLATFORM
		return uint64_t(esp_timer_get_time());
	#elif PICO_RP2040 || PICO_RP2350
		return time_us_64();
	#else
		#warning "Platform not supported"
		return 0;
	#endif
}

void encrypt_cmd(int argc, char * argv[]) {
	uint8_t plaintext[128];
	uint8_t ciphertext[128];
	size_t length;
	if(parse_hex_string(argv[1], plaintext, &length, sizeof(plaintext))) return;

	uint64_t time_1 = get_time_us();
	encrypt(ciphertext, plaintext, length);
	uint64_t time_2 = get_time_us();
	
	printf("ciphertext[%u]: ", length);

	for(uint8_t i=0; i<length; i++) {
		printf("%02X", ciphertext[i]);
	}

	printf("\nTime: %llu us\n", time_2 - time_1);
}

void decrypt_cmd(int argc, char * argv[]) {
	uint8_t plaintext[128];
	uint8_t ciphertext[128]  = {0};
	size_t length = 0;
	if(parse_hex_string(argv[1], ciphertext, &length, sizeof(ciphertext))) return;

	uint64_t time_1 = get_time_us();
	decrypt(plaintext, ciphertext, length);
	uint64_t time_2 = get_time_us();

	printf("plaintext[%u]: ", length);

	for(uint8_t i=0; i<length; i++) {
		printf("%02X", plaintext[i]);
	}

	printf("\nTime: %llu us\n", time_2 - time_1);
}

}

#endif
#endif
