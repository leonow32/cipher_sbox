#ifndef SBOX_COMMANDS_H_
#define SBOX_COMMANDS_H_

#include "../uCosmos/uCosmos.h"
#include "sbox.h"

namespace sbox {
	void encrypt_cmd(int argc, char * argv[]);
	void decrypt_cmd(int argc, char * argv[]);
}

#endif
