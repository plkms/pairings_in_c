/*
 * test_aes.c
 *
 *  Created on: May 21, 2013
 *      Author: thomas
 */

#include "aes/aes.h"
#include "types.h"
#include <string.h>

/*int main(void) {

	byte key[16] = { 0x2b, 0x7e, 0x15, 0x16, 0x28, 0xae, 0xd2, 0xa6, 0xab, 0xf7,
			0x15, 0x88, 0x09, 0xcf, 0x4f, 0x3c };
	byte orig[16] = { 0x32, 0x43, 0xf6, 0xa8, 0x88, 0x5a, 0x30, 0x8d, 0x31,
			0x31, 0x98, 0xa2, 0xe0, 0x37, 0x07, 0x34 };

	byte decode[16] = { 0x32, 0x43, 0xf6, 0xa8, 0x88, 0x5a, 0x30, 0x8d, 0x31,
			0x31, 0x98, 0xa2, 0xe0, 0x37, 0x07, 0x34 };

	aes128_ctx_t ctx;
	aes128_init(key, &ctx);

	aes128_enc(decode, &ctx);

	aes128_dec(decode, &ctx);

	assert_bytearr_equal(orig, decode, 16, "aes enc-dec");

	return 0;
}*/


int main(void) {
	byte var_code[48];

	{
		static const byte var_key[] = {0x08, 0x97, 0xE6, 0xCC, 0xB3, 0x12, 0x01, 0x29, 0x9B, 0x83, 0xD6, 0xEF, 0xFB, 0x0A, 0xC1, 0xE3};
		static const byte var_data[] = {0x09, 0xCD, 0x24, 0x94, 0x4E, 0x71, 0x35, 0x7B, 0xF6, 0x0A, 0x05, 0x59, 0xCD, 0x71, 0x8C, 0xD6};
		static const byte var_expected[] = {0x0B, 0x9C, 0x83, 0xB3, 0x84, 0x5B, 0x34, 0x60, 0xD4, 0xC4, 0x06, 0x3A, 0xF4, 0x2D, 0xFC, 0x21};
		memcpy(var_code, var_data, 16);
		aes128_cbc_encrypt(var_code, var_key, 16);
		assert_bytearr_equal(var_expected, var_code, 16, "aes128_enc 24 encode");
	}
	{
		static const byte var_key[] = {0x7E, 0x1C, 0x27, 0xB5, 0x3A, 0xE2, 0x35, 0xCC, 0xD7, 0x43, 0x82, 0x10, 0x01, 0xE2, 0x2D, 0xE6};
		static const byte var_data[] = {0x4A, 0xF0, 0x23, 0xC0, 0x80, 0x12, 0xD5, 0x1C, 0x0D, 0x5B, 0x30, 0xFE, 0x56, 0x25, 0x2E, 0xC0, 0xBE, 0x42, 0x6F, 0xBB, 0x05, 0xB5, 0x68, 0x3B, 0x89, 0xAA, 0x63, 0xA6, 0x31, 0x1C, 0x66, 0xF3, 0x4D, 0xDD, 0x6C, 0x9B, 0x33, 0x5A, 0x1A, 0x4D, 0x31, 0xE2, 0x3B, 0x46, 0xE7, 0x97, 0x13, 0x98};
		static const byte var_expected[] = {0xD0, 0xA1, 0x30, 0xAF, 0x0B, 0x8B, 0xBE, 0x69, 0x8E, 0x93, 0xF8, 0x9F, 0x89, 0x25, 0xCB, 0x46, 0x22, 0xED, 0x1B, 0x68, 0xA8, 0x36, 0x48, 0x1A, 0x94, 0xD9, 0x7B, 0xA0, 0x6E, 0x21, 0x4D, 0x07, 0xB7, 0x4B, 0xFD, 0x21, 0x23, 0x17, 0x7A, 0x84, 0x08, 0xF6, 0xA4, 0x7B, 0xDB, 0x2E, 0xF6, 0x72};
		memcpy(var_code, var_data, 48);
		aes128_cbc_encrypt(var_code, var_key, 48);
		assert_bytearr_equal(var_expected, var_code, 48, "aes128_enc 25 encode");
	}
	{
		static const byte var_key[] = {0x86, 0x5F, 0x3A, 0xBE, 0xD9, 0x9D, 0x7B, 0x38, 0xF4, 0x69, 0x26, 0x5C, 0x3B, 0x15, 0xEB, 0x55};
		static const byte var_data[] = {0x3E, 0x41, 0x7E, 0xD8, 0x4F, 0xCF, 0x94, 0x95, 0x1E, 0x51, 0x5C, 0x42, 0x25, 0x1B, 0x2C, 0xCA, 0x0C, 0x44, 0xE8, 0x0D, 0xDE, 0x77, 0x73, 0xB1, 0xEC, 0x5E, 0x7F, 0x5B, 0xD5, 0x41, 0xD6, 0x43, 0xF9, 0x07, 0xC3, 0xA7, 0x5E, 0x63, 0xB0, 0x43, 0x63, 0x18, 0x9F, 0xF7, 0xF6, 0x25, 0x79, 0x01};
		static const byte var_expected[] = {0xC8, 0xF8, 0x38, 0x7B, 0xDF, 0xDC, 0x8E, 0xE2, 0xF1, 0x02, 0x2E, 0x7C, 0x7A, 0xD7, 0x12, 0xBF, 0x30, 0xB0, 0x3E, 0xC9, 0x75, 0x0B, 0x7E, 0x4C, 0xBC, 0x9D, 0x71, 0xFE, 0x1C, 0x8E, 0x7C, 0xEC, 0x59, 0xD1, 0x01, 0x35, 0x8B, 0x4B, 0x6F, 0x2A, 0x98, 0x5B, 0x1B, 0x0E, 0x21, 0x1E, 0x58, 0x1A};
		memcpy(var_code, var_data, 48);
		aes128_cbc_encrypt(var_code, var_key, 48);
		assert_bytearr_equal(var_expected, var_code, 48, "aes128_enc 26 encode");
	}
	{
		static const byte var_key[] = {0x78, 0xB7, 0xBD, 0x75, 0x1F, 0x0F, 0xBB, 0xF1, 0x5D, 0xCF, 0x27, 0xF3, 0x37, 0xCC, 0xF9, 0xE2};
		static const byte var_data[] = {0x93, 0xFE, 0x0F, 0x0C, 0x0C, 0xA3, 0x32, 0x10, 0xE4, 0x0E, 0xCB, 0xDE, 0x06, 0x39, 0x4C, 0xEE, 0x67, 0xC1, 0x89, 0xE5, 0x0D, 0xD9, 0x72, 0x0C, 0xC2, 0xF8, 0x91, 0x90, 0x9E, 0x40, 0xC8, 0x30, 0xD2, 0x45, 0x43, 0xC3, 0xAD, 0x76, 0xFD, 0xF9, 0x58, 0x68, 0x3F, 0x78, 0x44, 0xD3, 0xAC, 0xCB};
		static const byte var_expected[] = {0xCB, 0x88, 0xD7, 0xE6, 0xAB, 0x45, 0x4D, 0x25, 0x5E, 0x35, 0x69, 0x07, 0xBF, 0x6B, 0x3D, 0x3D, 0xBC, 0xF3, 0x54, 0x00, 0x08, 0xBD, 0x06, 0x94, 0xE5, 0x87, 0x9C, 0x7B, 0xC3, 0x88, 0x77, 0x76, 0x1B, 0x8A, 0x30, 0x4F, 0xF3, 0x83, 0xE9, 0x44, 0xCB, 0x5F, 0xFF, 0x30, 0xAA, 0x0D, 0x31, 0x39};
		memcpy(var_code, var_data, 48);
		aes128_cbc_encrypt(var_code, var_key, 48);
		assert_bytearr_equal(var_expected, var_code, 48, "aes128_enc 27 encode");
	}
	{
		static const byte var_key[] = {0x6A, 0xC4, 0xB9, 0x3D, 0xFD, 0x3C, 0xCF, 0x3E, 0xAE, 0xEE, 0x30, 0x2D, 0xCC, 0x49, 0xD5, 0x39};
		static const byte var_data[] = {0xB0, 0x94, 0x6F, 0x57, 0xB7, 0x72, 0x39, 0xC1, 0xCB, 0xFB, 0x4A, 0xF7, 0x62, 0x76, 0xD8, 0xBA, 0x85, 0x68, 0xE6, 0x6E, 0xA5, 0x6C, 0xC7, 0x27, 0x47, 0xC9, 0x6D, 0xB0, 0x86, 0x7D, 0x01, 0xF5, 0xDC, 0x4A, 0x3D, 0x50, 0x43, 0xB8, 0x49, 0x32, 0x1E, 0xDA, 0xB5, 0x3D, 0x58, 0xBB, 0x0E, 0x38};
		static const byte var_expected[] = {0xB5, 0x97, 0xB7, 0x21, 0xD8, 0xA9, 0x17, 0x79, 0x0D, 0x48, 0x14, 0xCE, 0xDD, 0xAD, 0x8A, 0x74, 0xA7, 0x73, 0xDC, 0x5E, 0x67, 0x30, 0x21, 0xE8, 0x71, 0x38, 0x91, 0x45, 0xA0, 0x06, 0xD2, 0x5A, 0x96, 0x6B, 0x72, 0x3D, 0xAC, 0x8E, 0x47, 0xEA, 0xF1, 0x2C, 0x76, 0xCA, 0x36, 0x69, 0x22, 0xAC};
		memcpy(var_code, var_data, 48);
		aes128_cbc_encrypt(var_code, var_key, 48);
		assert_bytearr_equal(var_expected, var_code, 48, "aes128_enc 28 encode");
	}
	{
		static const byte var_key[] = {0xB0, 0x55, 0x23, 0x75, 0xA3, 0xCC, 0x96, 0x58, 0xC6, 0x23, 0xA4, 0x10, 0x15, 0x39, 0xA3, 0xC6};
		static const byte var_data[] = {0x38, 0x53, 0x6B, 0x07, 0x90, 0x65, 0x2B, 0x3A, 0x82, 0x34, 0x77, 0xFD, 0xE1, 0x76, 0x1B, 0x60, 0x59, 0xBE, 0x9B, 0xB6, 0xF6, 0xEC, 0xD2, 0xEF, 0xF8, 0xEA, 0xBF, 0x2E, 0xC6, 0x8D, 0x3E, 0x28, 0x5C, 0xD6, 0x99, 0x56, 0x80, 0x96, 0x22, 0x90, 0x01, 0x93, 0xD1, 0xDB, 0xFC, 0xED, 0x50, 0x7A};
		static const byte var_expected[] = {0xCD, 0x66, 0x4A, 0x56, 0x0A, 0x2C, 0xFA, 0xD3, 0xB0, 0xB5, 0x23, 0xB5, 0x37, 0x2F, 0xAC, 0x89, 0x84, 0x00, 0xBF, 0x1D, 0x2B, 0x3C, 0xB5, 0xBC, 0x86, 0x5B, 0xDC, 0xCE, 0x72, 0x0C, 0x72, 0x65, 0xE7, 0xD8, 0xD6, 0x9D, 0x88, 0xAE, 0x86, 0xF0, 0xC3, 0x70, 0xFF, 0xEB, 0xE2, 0x8D, 0xA5, 0xEC};
		memcpy(var_code, var_data, 48);
		aes128_cbc_encrypt(var_code, var_key, 48);
		assert_bytearr_equal(var_expected, var_code, 48, "aes128_enc 29 encode");
	}
	{
		static const byte var_key[] = {0xE0, 0xB9, 0x45, 0xF4, 0x83, 0x11, 0x18, 0xA7, 0xC0, 0x7B, 0x56, 0x81, 0x6A, 0x3D, 0x9E, 0x31};
		static const byte var_data[] = {0x12, 0xBD, 0xC8, 0x2F, 0x1A, 0xF5, 0xD6, 0x9A, 0xF5, 0x5A, 0x4F, 0xDE, 0x6C, 0x1A, 0xE4, 0x3E, 0x1A, 0x6F, 0xB6, 0x4A, 0x91, 0x4A, 0x8E, 0xF9, 0x93, 0x11, 0x55, 0xA5, 0xD7, 0xC6, 0x5F, 0xC8, 0xD8, 0x02, 0x34, 0x35, 0x06, 0xDA, 0x41, 0x19, 0x8F, 0xA5, 0x59, 0x3F, 0x39, 0xFF, 0xDC, 0x9D};
		static const byte var_expected[] = {0x51, 0xFE, 0x83, 0x9B, 0xC3, 0x9D, 0x70, 0xED, 0x84, 0x66, 0xDC, 0x09, 0x22, 0x52, 0x89, 0x76, 0x6B, 0x98, 0xA2, 0x30, 0xAB, 0x21, 0x39, 0xA8, 0x62, 0x05, 0x9E, 0xE4, 0x3E, 0x0F, 0x30, 0x50, 0x7F, 0x2D, 0x93, 0xDD, 0x28, 0xE7, 0xEE, 0xE3, 0x8E, 0xF3, 0x3D, 0x8C, 0x45, 0xAE, 0x68, 0xF2};
		memcpy(var_code, var_data, 48);
		aes128_cbc_encrypt(var_code, var_key, 48);
		assert_bytearr_equal(var_expected, var_code, 48, "aes128_enc 30 encode");
	}
	{
		static const byte var_key[] = {0xCF, 0x0E, 0x61, 0xB8, 0x4D, 0x1D, 0xC9, 0xCF, 0xFA, 0x84, 0x9E, 0xD3, 0x64, 0x82, 0x44, 0x0B};
		static const byte var_data[] = {0x61, 0xD8, 0x77, 0x90, 0x14, 0xFD, 0x0F, 0x02, 0x51, 0x66, 0x63, 0x05, 0x2D, 0x0D, 0x0D, 0x5F, 0x3C, 0x9E, 0xCA, 0x3D, 0x47, 0xBC, 0xC3, 0x6B, 0x13, 0x5A, 0x32, 0x0C, 0x71, 0xCE, 0xD9, 0x26, 0x14, 0x96, 0x26, 0x9C, 0xB5, 0xB5, 0x58, 0xFE, 0x94, 0xE1, 0xE2, 0x5C, 0x58, 0x97, 0xBD, 0xCF};
		static const byte var_expected[] = {0x59, 0x93, 0x6F, 0x00, 0x4F, 0xE1, 0x81, 0xEA, 0xB8, 0x34, 0x33, 0x42, 0xE3, 0x8A, 0xCB, 0x88, 0xC1, 0xC3, 0xF7, 0xD9, 0xC3, 0xFF, 0x35, 0x64, 0x5E, 0xAF, 0x45, 0xC0, 0x76, 0xD4, 0xBF, 0x63, 0x63, 0x65, 0xB8, 0xF1, 0x41, 0x6A, 0xAA, 0xD6, 0x68, 0x87, 0x31, 0x64, 0xFE, 0x62, 0x11, 0x36};
		memcpy(var_code, var_data, 48);
		aes128_cbc_encrypt(var_code, var_key, 48);
		assert_bytearr_equal(var_expected, var_code, 48, "aes128_enc 31 encode");
	}
	{
		static const byte var_key[] = {0x92, 0x91, 0x7C, 0xF3, 0xF3, 0xCF, 0xFB, 0x25, 0x11, 0x1F, 0xB7, 0x80, 0xDD, 0x4B, 0x4A, 0x21};
		static const byte var_data[] = {0x8B, 0x7E, 0x3A, 0x6E, 0x80, 0xCB, 0xCC, 0xDE, 0x03, 0x73, 0x93, 0xC2, 0x8D, 0x57, 0x08, 0xD7, 0x75, 0x36, 0xC0, 0x60, 0x2A, 0xCF, 0xEC, 0xEA, 0xB8, 0x1A, 0x82, 0x69, 0x8E, 0x2A, 0x6A, 0x53, 0x16, 0x51, 0x0D, 0xF5, 0xAF, 0xD6, 0xBE, 0x6C, 0x1E, 0xA4, 0xB9, 0x80, 0xE2, 0x02, 0x0C, 0x36};
		static const byte var_expected[] = {0x34, 0x50, 0x73, 0xE6, 0xC8, 0x98, 0x21, 0xBF, 0xD8, 0xEE, 0x7F, 0xA2, 0x3C, 0xB4, 0xAA, 0x39, 0x71, 0x91, 0x73, 0x13, 0x90, 0x75, 0x7B, 0x07, 0xE4, 0xF5, 0xD3, 0x25, 0x10, 0xB1, 0x2E, 0x96, 0xD8, 0x3A, 0x10, 0x0B, 0xA7, 0xE4, 0xDF, 0x32, 0x5E, 0xF7, 0x59, 0xAE, 0x86, 0x0D, 0xB2, 0x81};
		memcpy(var_code, var_data, 48);
		aes128_cbc_encrypt(var_code, var_key, 48);
		assert_bytearr_equal(var_expected, var_code, 48, "aes128_enc 32 encode");
	}
	{
		static const byte var_key[] = {0x7D, 0xEE, 0x6C, 0xF5, 0xA6, 0xE7, 0x6D, 0x4E, 0xE1, 0x4A, 0x76, 0xF9, 0xED, 0x85, 0x50, 0x35};
		static const byte var_data[] = {0x36, 0xAC, 0xBF, 0x23, 0x9F, 0x30, 0xA7, 0x02, 0xB9, 0x92, 0x63, 0xDF, 0x34, 0xEE, 0x6E, 0x6D, 0xB8, 0x39, 0x53, 0xC8, 0x89, 0x76, 0xB4, 0x78, 0xFC, 0xB2, 0x54, 0x96, 0x67, 0xD1, 0x0F, 0xDD, 0x22, 0x40, 0x3A, 0x9E, 0x54, 0x74, 0x05, 0x6A, 0x7A, 0xA7, 0xDF, 0xAC, 0xA1, 0xC2, 0xE1, 0xBD};
		static const byte var_expected[] = {0xB5, 0xB6, 0xCF, 0xF8, 0x36, 0x97, 0x0E, 0x41, 0x21, 0x36, 0xB4, 0x97, 0xA1, 0xE8, 0xA6, 0xE5, 0x26, 0x05, 0x85, 0x24, 0x30, 0x64, 0x50, 0xCC, 0x7C, 0x7D, 0xF7, 0x37, 0xC3, 0xF6, 0xC7, 0xD3, 0x17, 0xC6, 0xFB, 0xBF, 0xB2, 0x13, 0xEF, 0x53, 0x25, 0xBC, 0xA5, 0x0E, 0x6C, 0x3F, 0x3D, 0x91};
		memcpy(var_code, var_data, 48);
		aes128_cbc_encrypt(var_code, var_key, 48);
		assert_bytearr_equal(var_expected, var_code, 48, "aes128_enc 33 encode");
	}
	{
		static const byte var_key[] = {0x26, 0x91, 0x0E, 0xA3, 0xD6, 0x10, 0xFD, 0x26, 0x89, 0xFA, 0x57, 0xD4, 0xED, 0x54, 0x5F, 0x0E};
		static const byte var_data[] = {0x45, 0xD1, 0x32, 0x70, 0xF2, 0x8E, 0xC1, 0x96, 0x5E, 0x9C, 0xE3, 0x70, 0x0C, 0x42, 0x94, 0xFD, 0x3C, 0x11, 0x48, 0xF3, 0xF7, 0x1B, 0x1D, 0x78, 0x9E, 0x5B, 0x35, 0xF5, 0x74, 0xB9, 0x47, 0x02, 0xBD, 0x0A, 0xDF, 0x9D, 0x45, 0x60, 0x6E, 0xFA, 0x34, 0xD3, 0x1D, 0xB2, 0x9C, 0x1B, 0xCE, 0x88};
		static const byte var_expected[] = {0xF7, 0xD4, 0xD6, 0x5D, 0xD1, 0x4E, 0x6D, 0x6E, 0xD7, 0x2F, 0xA2, 0xD4, 0xA2, 0x0F, 0x9F, 0x02, 0x02, 0x6B, 0x26, 0x5B, 0x3A, 0xAB, 0x1A, 0x44, 0x5C, 0xA3, 0x82, 0x1C, 0x9E, 0xC8, 0x48, 0x1E, 0x78, 0x2C, 0xB3, 0x29, 0xA5, 0x93, 0xB1, 0x79, 0x71, 0x07, 0x42, 0x05, 0xD1, 0x88, 0xEF, 0x5F};
		memcpy(var_code, var_data, 48);
		aes128_cbc_encrypt(var_code, var_key, 48);
		assert_bytearr_equal(var_expected, var_code, 48, "aes128_enc 34 encode");
	}
	{
		static const byte var_key[] = {0x62, 0xF4, 0xB3, 0x70, 0x36, 0xF6, 0x7E, 0x43, 0x64, 0xE1, 0xDC, 0xD3, 0x76, 0xA5, 0x24, 0x1E};
		static const byte var_data[] = {0xDE, 0x20, 0x3F, 0xC8, 0x3A, 0xEB, 0x0F, 0x54, 0x20, 0xFC, 0x2A, 0x33, 0x3D, 0xD0, 0x1D, 0x68, 0x75, 0xDD, 0x53, 0x26, 0x43, 0xAF, 0x4A, 0x47, 0x9A, 0xF6, 0x92, 0x37, 0x70, 0x69, 0x8D, 0xA9, 0xAD, 0x43, 0x2A, 0xB2, 0x64, 0x16, 0x47, 0x13, 0x1A, 0x0C, 0x2A, 0xF1, 0x1D, 0xA7, 0xCF, 0xE2};
		static const byte var_expected[] = {0x8B, 0x5F, 0xC3, 0xAC, 0xEC, 0x96, 0xB2, 0x46, 0x88, 0xC6, 0x0A, 0x6A, 0x31, 0xA2, 0xB0, 0x58, 0xD6, 0x1E, 0x6A, 0x3A, 0xF4, 0x2A, 0x4A, 0x1B, 0x19, 0x54, 0x8F, 0x2E, 0x79, 0xCE, 0x5B, 0xA8, 0x90, 0x5E, 0x6B, 0xFF, 0xC7, 0x74, 0x0D, 0xDA, 0x73, 0x5E, 0x88, 0xF1, 0xD0, 0x2B, 0x34, 0x67};
		memcpy(var_code, var_data, 48);
		aes128_cbc_encrypt(var_code, var_key, 48);
		assert_bytearr_equal(var_expected, var_code, 48, "aes128_enc 35 encode");
	}
	{
		static const byte var_key[] = {0x46, 0xF2, 0xC7, 0x14, 0xB4, 0x50, 0xBD, 0x90, 0x11, 0x44, 0x3D, 0x82, 0x62, 0xBC, 0xF6, 0x32};
		static const byte var_data[] = {0x66, 0xE1, 0x86, 0x2E, 0x78, 0xFC, 0x04, 0xA0, 0x6D, 0x83, 0x68, 0xFB, 0x30, 0xB2, 0x9E, 0x18, 0x18, 0xC6, 0xB8, 0xD2, 0x80, 0xB6, 0xF0, 0x1F, 0x2E, 0xDF, 0xFC, 0x8E, 0x52, 0x88, 0x1F, 0xBB, 0xF7, 0xB8, 0x58, 0xE3, 0xD1, 0xCC, 0x27, 0x1A, 0x38, 0x04, 0xE1, 0xF0, 0xAD, 0xE2, 0xD1, 0xE9};
		static const byte var_expected[] = {0xD2, 0xB0, 0x8E, 0x87, 0x26, 0x86, 0x8A, 0x94, 0xD0, 0x09, 0x21, 0x34, 0x4E, 0x2B, 0xB8, 0x13, 0xBB, 0xE2, 0xD4, 0xBA, 0x21, 0x94, 0x1D, 0xF2, 0x42, 0x3B, 0x9C, 0x9E, 0x7E, 0x19, 0x78, 0x41, 0xB6, 0xBC, 0xD9, 0xCD, 0xB7, 0xA9, 0x98, 0x26, 0x24, 0x37, 0xB0, 0x0C, 0x69, 0x8D, 0x99, 0x2A};
		memcpy(var_code, var_data, 48);
		aes128_cbc_encrypt(var_code, var_key, 48);
		assert_bytearr_equal(var_expected, var_code, 48, "aes128_enc 36 encode");
	}
	{
		static const byte var_key[] = {0x26, 0x14, 0xA4, 0x67, 0x84, 0xF7, 0x95, 0xEE, 0x6B, 0xC8, 0x6F, 0x5F, 0xC9, 0xC6, 0x9A, 0xEF};
		static const byte var_data[] = {0x82, 0xBC, 0x8E, 0x58, 0xED, 0x3B, 0xA3, 0x6E, 0xF0, 0x38, 0x86, 0x0D, 0x8F, 0x2D, 0x37, 0x69, 0x1B, 0x4A, 0x96, 0x1C, 0xFE, 0x5D, 0x64, 0x2F, 0xD5, 0xB9, 0x33, 0xE7, 0x54, 0x6D, 0x08, 0xB5, 0xDF, 0xC3, 0xBA, 0xFC, 0xED, 0x83, 0x16, 0xF2, 0xDC, 0x0A, 0x94, 0x36, 0x16, 0xC0, 0xAE, 0x4F};
		static const byte var_expected[] = {0xBE, 0x79, 0x60, 0x55, 0x86, 0x2A, 0xA6, 0x00, 0x8B, 0x67, 0xFD, 0x91, 0xF1, 0x8A, 0x0E, 0xDF, 0xDA, 0x94, 0x57, 0x04, 0x29, 0xED, 0xEB, 0x20, 0xAC, 0x73, 0xF4, 0xF5, 0x90, 0xC2, 0x42, 0x80, 0x91, 0x84, 0xF6, 0x48, 0x52, 0x07, 0xD6, 0x06, 0xAE, 0xBC, 0x15, 0xBC, 0xEA, 0x1C, 0xC3, 0x83};
		memcpy(var_code, var_data, 48);
		aes128_cbc_encrypt(var_code, var_key, 48);
		assert_bytearr_equal(var_expected, var_code, 48, "aes128_enc 37 encode");
	}
	{
		static const byte var_key[] = {0x97, 0xE2, 0x9A, 0x25, 0x15, 0xF0, 0x3E, 0xD2, 0x8F, 0x45, 0x84, 0xDE, 0x04, 0x6A, 0xCF, 0x01};
		static const byte var_data[] = {0x17, 0x0F, 0x1D, 0x25, 0x19, 0xF5, 0xF1, 0x0A, 0x98, 0x28, 0x61, 0x62, 0x43, 0x44, 0x38, 0x6D, 0xB1, 0x8F, 0xED, 0xD5, 0x4E, 0x88, 0x52, 0x17, 0x4E, 0x44, 0x0E, 0x06, 0xEF, 0xAF, 0x6A, 0x92, 0xEA, 0x98, 0xAD, 0x91, 0x5A, 0x16, 0x8E, 0xD7, 0x93, 0xDC, 0x6A, 0x0D, 0x5F, 0x35, 0xB4, 0xDF};
		static const byte var_expected[] = {0xAA, 0x18, 0x2F, 0x70, 0x37, 0x6B, 0xAE, 0x43, 0x4E, 0x7D, 0x9E, 0x9B, 0x7A, 0x41, 0xE3, 0xD4, 0x09, 0xF0, 0xD7, 0x0F, 0x50, 0x69, 0x99, 0x12, 0xA0, 0x02, 0x02, 0x0F, 0xED, 0x3F, 0x1E, 0xC9, 0x91, 0x82, 0x27, 0xFC, 0xB5, 0x61, 0x53, 0x4A, 0xEF, 0x45, 0x7B, 0xF0, 0xB9, 0x23, 0x0D, 0x07};
		memcpy(var_code, var_data, 48);
		aes128_cbc_encrypt(var_code, var_key, 48);
		assert_bytearr_equal(var_expected, var_code, 48, "aes128_enc 38 encode");
	}
	{
		static const byte var_key[] = {0x70, 0x35, 0x36, 0x88, 0x18, 0x7E, 0xAE, 0x41, 0xDC, 0x93, 0x52, 0xAF, 0xAD, 0x53, 0x9B, 0x50};
		static const byte var_data[] = {0x4A, 0x39, 0x0D, 0xA9, 0xBF, 0x55, 0xD6, 0x26, 0x90, 0x33, 0x95, 0x2B, 0x74, 0x44, 0xCB, 0xEB, 0x51, 0xB4, 0x59, 0x83, 0x42, 0xDE, 0x19, 0x48, 0x96, 0x25, 0x32, 0xAE, 0xDB, 0xB7, 0x11, 0x5F, 0xDE, 0x97, 0x88, 0x73, 0xF8, 0x48, 0x69, 0x8C, 0x29, 0x73, 0xD9, 0x29, 0xD2, 0xCC, 0xAD, 0xB0};
		static const byte var_expected[] = {0xE8, 0x49, 0x4F, 0xA0, 0x60, 0x9E, 0xD4, 0x4A, 0x90, 0x23, 0xB2, 0xDD, 0xDC, 0xAD, 0x5A, 0x26, 0x9A, 0xEB, 0x94, 0xC1, 0x6F, 0xC7, 0x87, 0x80, 0xFE, 0x60, 0x7E, 0x44, 0x47, 0xC1, 0x15, 0xB1, 0x15, 0x18, 0x24, 0x33, 0xED, 0xE5, 0x1B, 0xB0, 0x53, 0xDD, 0xAB, 0xDB, 0x1B, 0x1B, 0xB2, 0xA9};
		memcpy(var_code, var_data, 48);
		aes128_cbc_encrypt(var_code, var_key, 48);
		assert_bytearr_equal(var_expected, var_code, 48, "aes128_enc 39 encode");
	}
	{
		static const byte var_key[] = {0xC4, 0x83, 0xA9, 0xEB, 0x7F, 0x33, 0x27, 0xB9, 0xEE, 0x5C, 0x7D, 0x11, 0x9B, 0xC9, 0x5F, 0x9B};
		static const byte var_data[] = {0x80, 0xEE, 0x96, 0x57, 0xDE, 0x7D, 0x50, 0xD3, 0x47, 0xE0, 0xDC, 0x21, 0x8C, 0x58, 0x9D, 0x93, 0xAF, 0x1C, 0x7C, 0x3F, 0xE9, 0xDE, 0xC8, 0xE5, 0xE9, 0xBD, 0xA0, 0x21, 0x12, 0x4D, 0x46, 0x10, 0xC0, 0x9B, 0x7E, 0xBD, 0xE9, 0xDA, 0xB1, 0x94, 0xAB, 0xD5, 0x29, 0x56, 0xF9, 0x34, 0x72, 0x2C};
		static const byte var_expected[] = {0x57, 0x5C, 0xDC, 0xAA, 0xAF, 0x50, 0xE4, 0x9D, 0x51, 0x65, 0x3B, 0x90, 0x13, 0x44, 0xEA, 0x69, 0x30, 0xB9, 0xE3, 0xC6, 0x1C, 0x4C, 0xAC, 0xB5, 0xCB, 0xFD, 0x9F, 0xA2, 0xAA, 0xCC, 0x35, 0xC2, 0x8F, 0x97, 0xAE, 0x8E, 0x8C, 0xA8, 0x1F, 0x67, 0x15, 0x47, 0x23, 0x56, 0x0E, 0x6D, 0x96, 0x54};
		memcpy(var_code, var_data, 48);
		aes128_cbc_encrypt(var_code, var_key, 48);
		assert_bytearr_equal(var_expected, var_code, 48, "aes128_enc 40 encode");
	}
	{
		static const byte var_key[] = {0xE9, 0x33, 0x78, 0xF5, 0x7B, 0x00, 0xE8, 0xCB, 0xA1, 0xEB, 0xC8, 0x2D, 0xE9, 0x39, 0xAF, 0x42};
		static const byte var_data[] = {0x5E, 0x85, 0x09, 0x0B, 0xB8, 0x8F, 0x1C, 0x42, 0x69, 0x2A, 0x05, 0x6B, 0x33, 0x17, 0x8F, 0xB0};
		static const byte var_expected[] = {0xF8, 0xCF, 0x47, 0x31, 0xDC, 0x2F, 0x59, 0xF8, 0x06, 0xE4, 0x72, 0xAC, 0x72, 0xE9, 0xB3, 0x13};
		memcpy(var_code, var_data, 16);
		aes128_cbc_decrypt(var_code, var_key, 16);
		assert_bytearr_equal(var_expected, var_code, 16, "aes128_dec 41 decode");
	}
	{
		static const byte var_key[] = {0xC0, 0xC4, 0x1C, 0x92, 0x96, 0xEF, 0xBF, 0x28, 0xC4, 0xF6, 0x17, 0xA1, 0xCD, 0x27, 0xE7, 0x7B};
		static const byte var_data[] = {0xD3, 0x4A, 0x73, 0xDB, 0x8D, 0x95, 0x53, 0x85, 0x68, 0xE8, 0x19, 0x95, 0x9B, 0xD0, 0xF4, 0x55, 0x74, 0xEB, 0x4F, 0xF1, 0x7D, 0x43, 0x00, 0x91, 0x13, 0xFC, 0xC5, 0xB2, 0xF0, 0xCA, 0xE7, 0x33, 0xC9, 0x47, 0xFB, 0xF2, 0xCE, 0xBF, 0xB7, 0x71, 0xE3, 0x52, 0x75, 0x24, 0x53, 0x13, 0x68, 0xEC};
		static const byte var_expected[] = {0xCA, 0xB5, 0x83, 0xC2, 0x32, 0xDD, 0x0A, 0xF5, 0x09, 0x3C, 0xE3, 0x81, 0x3C, 0xED, 0xD8, 0x04, 0xB2, 0x47, 0x5B, 0x3E, 0xA7, 0x90, 0xD6, 0xA7, 0x7E, 0x25, 0x13, 0xC6, 0x6C, 0x1B, 0xE0, 0x71, 0xD4, 0xC3, 0x91, 0x39, 0xD8, 0xAE, 0x7A, 0x00, 0xEE, 0x23, 0xA2, 0xB4, 0xAE, 0xC6, 0x65, 0x26};
		memcpy(var_code, var_data, 48);
		aes128_cbc_decrypt(var_code, var_key, 48);
		assert_bytearr_equal(var_expected, var_code, 48, "aes128_dec 42 decode");
	}
	{
		static const byte var_key[] = {0xB9, 0x8F, 0xFE, 0x8F, 0xD9, 0x6B, 0xF7, 0x6A, 0xE4, 0x12, 0x47, 0xC5, 0x85, 0x80, 0xC5, 0x86};
		static const byte var_data[] = {0x9E, 0x66, 0xC4, 0x30, 0x86, 0x5C, 0xB3, 0xA5, 0xEA, 0x3C, 0x8D, 0x67, 0xC2, 0x46, 0xDB, 0xF6, 0x39, 0xDF, 0x16, 0x59, 0x35, 0xD9, 0x47, 0x2D, 0xA1, 0x8B, 0xD0, 0x31, 0x47, 0xEB, 0x91, 0x30, 0xE6, 0xC2, 0xEC, 0xAC, 0xE1, 0x64, 0xC9, 0x24, 0xE2, 0xAF, 0x4A, 0xDF, 0x14, 0x6C, 0x8E, 0xE3};
		static const byte var_expected[] = {0xF5, 0x14, 0x6C, 0x91, 0x0A, 0xC5, 0x29, 0x9A, 0x57, 0x14, 0x40, 0x8A, 0xE4, 0x49, 0x33, 0x9F, 0xEB, 0x3A, 0x5A, 0x92, 0xF0, 0xF0, 0xAD, 0xCB, 0x1D, 0x76, 0x34, 0x2A, 0x2D, 0x07, 0xFC, 0x48, 0xE3, 0x44, 0x39, 0xE0, 0xC4, 0x74, 0xF7, 0xED, 0x99, 0xD7, 0xA1, 0x76, 0xD4, 0x83, 0xDF, 0x6A};
		memcpy(var_code, var_data, 48);
		aes128_cbc_decrypt(var_code, var_key, 48);
		assert_bytearr_equal(var_expected, var_code, 48, "aes128_dec 43 decode");
	}
	{
		static const byte var_key[] = {0x10, 0x98, 0x67, 0xD8, 0x82, 0xB5, 0xE9, 0x52, 0x47, 0x7E, 0xD7, 0xCE, 0xF3, 0x9F, 0x45, 0xE3};
		static const byte var_data[] = {0xE6, 0x1B, 0x07, 0x44, 0xB3, 0x3D, 0x2A, 0x65, 0x01, 0xE2, 0x52, 0x22, 0xB8, 0x12, 0x97, 0x9D, 0x4E, 0x23, 0x2E, 0xBD, 0x95, 0x2C, 0x7B, 0x0B, 0xE8, 0xA8, 0x62, 0xF9, 0xC9, 0xE1, 0x82, 0xEA, 0x1A, 0x17, 0x60, 0x0C, 0xF2, 0x07, 0xF0, 0xC5, 0xD3, 0x7C, 0x08, 0x9B, 0xE0, 0x5C, 0xC2, 0x96};
		static const byte var_expected[] = {0x69, 0xC8, 0x2F, 0x3D, 0xE6, 0x69, 0x46, 0xA8, 0xB6, 0x49, 0x47, 0xBB, 0xD0, 0x96, 0xEF, 0xF1, 0x38, 0x30, 0x1D, 0x4B, 0x1E, 0x14, 0x75, 0x36, 0x66, 0xE6, 0xCC, 0x27, 0x1C, 0x87, 0xB5, 0x3E, 0x10, 0x3D, 0x89, 0xC1, 0xF2, 0x60, 0xA4, 0xB2, 0xB9, 0xE9, 0x7F, 0xBB, 0xCC, 0x04, 0x90, 0xBC};
		memcpy(var_code, var_data, 48);
		aes128_cbc_decrypt(var_code, var_key, 48);
		assert_bytearr_equal(var_expected, var_code, 48, "aes128_dec 44 decode");
	}
	{
		static const byte var_key[] = {0x79, 0x7F, 0x5D, 0x45, 0xA4, 0x44, 0x21, 0xCD, 0x29, 0x9E, 0x49, 0x4A, 0x0F, 0x6F, 0x43, 0xF9};
		static const byte var_data[] = {0xAF, 0x52, 0xB9, 0x94, 0x38, 0x81, 0x64, 0x65, 0xB8, 0x33, 0xFF, 0x80, 0x04, 0x14, 0x03, 0x95, 0x08, 0xFB, 0xE7, 0x81, 0xCD, 0x46, 0x7B, 0x93, 0xC5, 0x43, 0xBB, 0x69, 0x8E, 0x5D, 0xC3, 0xAD, 0x09, 0x48, 0x64, 0x57, 0x42, 0x74, 0xF2, 0x18, 0x63, 0xAA, 0xDB, 0x0B, 0x5F, 0xCD, 0xDD, 0x02};
		static const byte var_expected[] = {0xBC, 0xB7, 0xD3, 0x54, 0x7E, 0x9D, 0x42, 0x69, 0x8F, 0xE1, 0xEC, 0x0B, 0x57, 0x62, 0x72, 0xB1, 0x6E, 0x8C, 0x04, 0x02, 0xEC, 0x44, 0x1B, 0x32, 0x38, 0x1C, 0x2E, 0xB5, 0xD6, 0x3E, 0xFF, 0x29, 0x40, 0xD6, 0x0E, 0x58, 0xFD, 0xB8, 0xFC, 0xB3, 0x6A, 0xB8, 0x97, 0x40, 0x5D, 0x60, 0x17, 0x03};
		memcpy(var_code, var_data, 48);
		aes128_cbc_decrypt(var_code, var_key, 48);
		assert_bytearr_equal(var_expected, var_code, 48, "aes128_dec 45 decode");
	}
	{
		static const byte var_key[] = {0xE9, 0xBE, 0x95, 0x63, 0x90, 0xB7, 0x6A, 0xC5, 0x08, 0xA1, 0xA5, 0xA4, 0x13, 0x07, 0x3B, 0xD0};
		static const byte var_data[] = {0x3F, 0xFE, 0xE6, 0x7F, 0x73, 0xB9, 0xA4, 0x1A, 0x5C, 0xAB, 0xD9, 0xE2, 0x70, 0x1E, 0x85, 0x3E, 0xFC, 0x28, 0x32, 0x27, 0x4F, 0xDF, 0xB1, 0x71, 0x54, 0xFD, 0xD8, 0x00, 0xEF, 0x05, 0x3A, 0x91, 0x9A, 0x8C, 0x94, 0xFC, 0x52, 0xC7, 0x54, 0xDA, 0x7F, 0xAE, 0x72, 0x39, 0x7B, 0xE1, 0x97, 0x67};
		static const byte var_expected[] = {0x07, 0x52, 0xB9, 0x4B, 0x01, 0x0B, 0xCC, 0xFD, 0x77, 0xE4, 0xB0, 0xD9, 0xF7, 0x6E, 0x40, 0x39, 0x02, 0x74, 0x95, 0x7B, 0xEF, 0xC2, 0x09, 0x34, 0xE7, 0x6E, 0x0A, 0x9E, 0x49, 0x15, 0xA6, 0x5F, 0x8E, 0xBE, 0x83, 0x19, 0x13, 0xAB, 0xD2, 0xB3, 0x92, 0xE3, 0xA7, 0xE1, 0xE7, 0xEB, 0x50, 0xE4};
		memcpy(var_code, var_data, 48);
		aes128_cbc_decrypt(var_code, var_key, 48);
		assert_bytearr_equal(var_expected, var_code, 48, "aes128_dec 46 decode");
	}
	{
		static const byte var_key[] = {0x95, 0xF6, 0x19, 0x07, 0xD5, 0xE2, 0xAA, 0xD0, 0x9F, 0x4E, 0x00, 0x8E, 0x78, 0x41, 0xB5, 0x14};
		static const byte var_data[] = {0x1A, 0x6D, 0xC3, 0xD8, 0x07, 0xD3, 0xEA, 0x42, 0x7B, 0xAF, 0xDE, 0xDE, 0x06, 0x8A, 0xB3, 0x77, 0xFE, 0x3E, 0x74, 0x0F, 0xCC, 0x6B, 0x99, 0xBF, 0xF3, 0xF7, 0xC8, 0x9A, 0x86, 0x0A, 0x1A, 0x67, 0xF1, 0x9E, 0x8B, 0x07, 0xE2, 0x80, 0x51, 0xAE, 0x54, 0x54, 0x69, 0xC3, 0x5C, 0x89, 0x4C, 0x06};
		static const byte var_expected[] = {0x9B, 0x14, 0x14, 0x20, 0xF1, 0xBF, 0x49, 0xCA, 0x68, 0xCC, 0x49, 0x37, 0x86, 0x8B, 0xFF, 0xCD, 0x9D, 0xD0, 0x96, 0x95, 0x47, 0xA9, 0x56, 0xF1, 0x6B, 0xFF, 0xDA, 0x17, 0x91, 0xB8, 0x0E, 0xF9, 0x13, 0x77, 0xF7, 0x80, 0x23, 0x13, 0x6D, 0x0F, 0x3D, 0xFA, 0xC1, 0x7E, 0xC1, 0x57, 0xB0, 0x59};
		memcpy(var_code, var_data, 48);
		aes128_cbc_decrypt(var_code, var_key, 48);
		assert_bytearr_equal(var_expected, var_code, 48, "aes128_dec 47 decode");
	}
	{
		static const byte var_key[] = {0xF2, 0x3D, 0xA0, 0x91, 0x45, 0xE1, 0x58, 0x38, 0xED, 0xD7, 0xD3, 0x46, 0xF6, 0x47, 0xF8, 0x91};
		static const byte var_data[] = {0x05, 0x99, 0x36, 0x1A, 0xD5, 0x24, 0xFF, 0xB4, 0xE2, 0x63, 0xD5, 0x1B, 0x0D, 0xC3, 0x7E, 0xF4, 0x24, 0xEE, 0xA1, 0xFA, 0x35, 0x30, 0x69, 0x9E, 0x3F, 0xA7, 0x49, 0xA3, 0x2B, 0xB3, 0x15, 0xE6, 0x72, 0x0C, 0xCB, 0xD8, 0xF5, 0x92, 0x36, 0x00, 0x50, 0x8C, 0x48, 0x58, 0x6C, 0x11, 0xC8, 0x61};
		static const byte var_expected[] = {0x89, 0xDB, 0x32, 0xD8, 0xB3, 0xD0, 0x29, 0xB4, 0xCE, 0x9B, 0x91, 0x17, 0x60, 0x2B, 0xD3, 0x1F, 0x94, 0xE4, 0x6A, 0xB8, 0x08, 0x2A, 0xFF, 0x68, 0xA7, 0xBD, 0x87, 0xC0, 0xC5, 0xF2, 0xB9, 0x2D, 0x54, 0x08, 0x4D, 0x48, 0x46, 0xE1, 0x85, 0x03, 0x81, 0x57, 0x5C, 0x91, 0x96, 0xBE, 0x7B, 0x17};
		memcpy(var_code, var_data, 48);
		aes128_cbc_decrypt(var_code, var_key, 48);
		assert_bytearr_equal(var_expected, var_code, 48, "aes128_dec 48 decode");
	}
	{
		static const byte var_key[] = {0xB6, 0x73, 0x97, 0xBF, 0xF2, 0x23, 0x9C, 0x18, 0x2F, 0xA7, 0x2C, 0x35, 0x88, 0x24, 0xFC, 0xB8};
		static const byte var_data[] = {0x06, 0x77, 0x5E, 0x56, 0xFC, 0x7F, 0x61, 0x48, 0x9D, 0x79, 0x79, 0x99, 0x10, 0xDA, 0xDE, 0xB6, 0xC2, 0x56, 0x81, 0xAA, 0xBA, 0x4E, 0xE5, 0x14, 0x15, 0xA0, 0xC1, 0x35, 0xF7, 0xEF, 0x54, 0xC4, 0xC4, 0x85, 0x16, 0xE6, 0xCA, 0x71, 0x26, 0xB3, 0x1E, 0x3C, 0x1A, 0x2C, 0x53, 0xB2, 0x16, 0x48};
		static const byte var_expected[] = {0x03, 0x80, 0x01, 0x1F, 0xCB, 0xFD, 0x76, 0x7F, 0x05, 0x8D, 0x86, 0xFD, 0xEF, 0xF0, 0xF2, 0x6B, 0x39, 0x17, 0x21, 0x6A, 0x15, 0xED, 0x1E, 0x9F, 0x80, 0xB1, 0xAB, 0x79, 0x57, 0x1F, 0xD6, 0x43, 0xFE, 0xF8, 0x47, 0x8D, 0x51, 0xB8, 0x8E, 0xB5, 0x22, 0xDC, 0xED, 0x47, 0x4F, 0xF2, 0x82, 0xAF};
		memcpy(var_code, var_data, 48);
		aes128_cbc_decrypt(var_code, var_key, 48);
		assert_bytearr_equal(var_expected, var_code, 48, "aes128_dec 49 decode");
	}
	{
		static const byte var_key[] = {0xD5, 0x8D, 0xE7, 0x10, 0x2C, 0x82, 0x0E, 0x82, 0xE1, 0x2F, 0xAA, 0x5E, 0x65, 0x51, 0xA3, 0x0D};
		static const byte var_data[] = {0x62, 0x47, 0x04, 0x49, 0xDF, 0x3F, 0x1C, 0xD7, 0xFA, 0xFE, 0xB8, 0xD7, 0xD6, 0x13, 0x05, 0x0D, 0x6E, 0x58, 0x25, 0x65, 0xCC, 0xD7, 0x52, 0x41, 0x92, 0x68, 0x8A, 0x68, 0x43, 0xE9, 0x2F, 0xBD, 0xCA, 0x2E, 0x43, 0x88, 0xE3, 0x23, 0x3D, 0xC5, 0xAD, 0x0E, 0x91, 0x7B, 0xFB, 0x20, 0x58, 0x2F};
		static const byte var_expected[] = {0xCB, 0xF3, 0x06, 0xA1, 0xED, 0x05, 0x06, 0xF3, 0xD9, 0xA2, 0xA4, 0xBD, 0x8B, 0xCF, 0xBB, 0x65, 0xC6, 0x4A, 0x2C, 0xC8, 0xF4, 0x38, 0x48, 0x49, 0x7A, 0x9A, 0x26, 0xA0, 0xCB, 0x37, 0x69, 0xB9, 0xEB, 0x7C, 0xA3, 0xA8, 0xB6, 0x81, 0x3A, 0xF0, 0xCA, 0x2D, 0x0D, 0x83, 0xD1, 0x4C, 0xF4, 0x5C};
		memcpy(var_code, var_data, 48);
		aes128_cbc_decrypt(var_code, var_key, 48);
		assert_bytearr_equal(var_expected, var_code, 48, "aes128_dec 50 decode");
	}
	{
		static const byte var_key[] = {0x84, 0xE9, 0x65, 0x22, 0x83, 0x49, 0x22, 0xD0, 0xC0, 0xBE, 0x53, 0xA4, 0x07, 0x49, 0x37, 0x93};
		static const byte var_data[] = {0x9D, 0xE5, 0x05, 0x32, 0x1F, 0x5A, 0x7B, 0x9A, 0x86, 0x2F, 0x06, 0x89, 0x6A, 0x79, 0x11, 0xBF, 0xFD, 0xE1, 0x9B, 0x4A, 0x1E, 0xDA, 0x8F, 0x30, 0x13, 0x48, 0x8F, 0x40, 0xA9, 0x8F, 0xAD, 0xBA, 0xAB, 0xEE, 0x7A, 0x1B, 0x01, 0x52, 0x19, 0x46, 0x28, 0x44, 0xC4, 0x68, 0x8D, 0x1E, 0x97, 0xAE};
		static const byte var_expected[] = {0xD3, 0x18, 0xA4, 0xB1, 0x34, 0xD7, 0x9D, 0x73, 0x23, 0x66, 0x37, 0x61, 0xF5, 0x63, 0x7B, 0xD2, 0x2F, 0xCD, 0x80, 0x16, 0x65, 0xF4, 0x48, 0xE3, 0x88, 0xA1, 0x8D, 0x60, 0x55, 0x3B, 0xB1, 0xFA, 0x68, 0xC9, 0xEB, 0x40, 0x3C, 0xB6, 0x9C, 0xFE, 0xF0, 0x5A, 0x39, 0xAE, 0x0C, 0x32, 0x8B, 0x0E};
		memcpy(var_code, var_data, 48);
		aes128_cbc_decrypt(var_code, var_key, 48);
		assert_bytearr_equal(var_expected, var_code, 48, "aes128_dec 51 decode");
	}
	{
		static const byte var_key[] = {0x38, 0x9B, 0xFD, 0x8C, 0xCA, 0x4D, 0x2C, 0xA5, 0xC9, 0x49, 0x41, 0xDD, 0x26, 0x16, 0x29, 0x91};
		static const byte var_data[] = {0x7C, 0x18, 0xB3, 0x5C, 0x9C, 0x6E, 0xA7, 0x63, 0x0D, 0x44, 0xBD, 0xBC, 0x13, 0x68, 0x4C, 0x55, 0x84, 0x41, 0xD0, 0xB2, 0x9E, 0x72, 0x4F, 0xEB, 0x34, 0x17, 0x40, 0x0A, 0x01, 0x2C, 0xC6, 0x9B, 0xCA, 0xBF, 0xF3, 0xF6, 0x25, 0x57, 0xC9, 0x41, 0xFE, 0x81, 0x7F, 0xBE, 0x71, 0x08, 0xA5, 0x1B};
		static const byte var_expected[] = {0x51, 0x28, 0x21, 0xB8, 0x9F, 0xD4, 0x16, 0x7F, 0x77, 0x8D, 0x9E, 0xD2, 0x8F, 0x2C, 0x09, 0xFC, 0x8F, 0x6A, 0x9B, 0x3F, 0xC3, 0xAC, 0x79, 0x0B, 0xD0, 0x91, 0xEA, 0x6D, 0x42, 0x0E, 0x0F, 0x29, 0x0A, 0x15, 0xAD, 0x39, 0xEE, 0xAE, 0x7C, 0x26, 0x73, 0xC4, 0xF3, 0xCE, 0xC9, 0xC9, 0xE7, 0x31};
		memcpy(var_code, var_data, 48);
		aes128_cbc_decrypt(var_code, var_key, 48);
		assert_bytearr_equal(var_expected, var_code, 48, "aes128_dec 52 decode");
	}
	{
		static const byte var_key[] = {0xA6, 0xBE, 0x8B, 0x1F, 0x12, 0xF9, 0x11, 0x3D, 0x3A, 0x40, 0x18, 0x2D, 0xBD, 0xE3, 0x15, 0x49};
		static const byte var_data[] = {0x05, 0xE2, 0x1E, 0x79, 0x77, 0xD7, 0x24, 0x71, 0x9C, 0x42, 0x9E, 0xAE, 0x5C, 0x21, 0xE4, 0x9F, 0x58, 0x74, 0xA1, 0x08, 0x80, 0xDC, 0x79, 0x8A, 0xD3, 0x0F, 0xD8, 0x14, 0x64, 0xEF, 0x69, 0x50, 0xCE, 0xFF, 0x1A, 0x01, 0x90, 0x50, 0x1C, 0x81, 0xDB, 0xA2, 0x26, 0x67, 0x50, 0x68, 0xF9, 0x96};
		static const byte var_expected[] = {0x4A, 0x08, 0x53, 0xCA, 0xEB, 0x23, 0x6A, 0xD0, 0x68, 0x43, 0x6B, 0x5D, 0x12, 0x47, 0xF6, 0xF7, 0x53, 0x63, 0x68, 0xFC, 0x19, 0x16, 0xE2, 0x86, 0x5D, 0xFB, 0x77, 0x6F, 0x22, 0x49, 0x63, 0x2D, 0xD2, 0x7B, 0xC5, 0x86, 0x02, 0x47, 0x8A, 0x61, 0x40, 0x47, 0x45, 0x0D, 0xB7, 0xCC, 0x55, 0x56};
		memcpy(var_code, var_data, 48);
		aes128_cbc_decrypt(var_code, var_key, 48);
		assert_bytearr_equal(var_expected, var_code, 48, "aes128_dec 53 decode");
	}
	{
		static const byte var_key[] = {0xC4, 0xC6, 0x6F, 0x88, 0xAA, 0x5B, 0x9B, 0x07, 0x8F, 0x5A, 0x5C, 0x33, 0x03, 0x8D, 0x0F, 0x77};
		static const byte var_data[] = {0x7C, 0xCF, 0x64, 0x2C, 0x12, 0xB9, 0x36, 0xE2, 0x81, 0xCE, 0x5A, 0xA8, 0x0C, 0x5B, 0x2E, 0xE9, 0x0D, 0x77, 0x2C, 0xD7, 0x33, 0x81, 0xB0, 0x63, 0x0E, 0x9D, 0xF8, 0x0C, 0x2B, 0x83, 0x4B, 0x44, 0x9A, 0xBF, 0x34, 0xE5, 0xC3, 0x2D, 0x57, 0x40, 0xAC, 0x86, 0x2D, 0xA4, 0x14, 0x84, 0x95, 0x0E};
		static const byte var_expected[] = {0xB8, 0x38, 0x8F, 0xBF, 0x56, 0x3C, 0xBD, 0x6C, 0xAD, 0xC4, 0x50, 0x02, 0x71, 0xE2, 0x78, 0xFD, 0x34, 0x0D, 0x20, 0x79, 0x78, 0x04, 0xC1, 0x72, 0x5D, 0x24, 0x1B, 0x17, 0xB0, 0x12, 0x12, 0x4A, 0xA8, 0xF0, 0x99, 0x1B, 0xCE, 0x23, 0x11, 0xF3, 0x1C, 0xFD, 0x23, 0xEE, 0x19, 0x69, 0xDD, 0x1A};
		memcpy(var_code, var_data, 48);
		aes128_cbc_decrypt(var_code, var_key, 48);
		assert_bytearr_equal(var_expected, var_code, 48, "aes128_dec 54 decode");
	}
	{
		static const byte var_key[] = {0xC6, 0xCD, 0xCF, 0xC3, 0x24, 0x3C, 0x69, 0xBB, 0x85, 0x6A, 0x94, 0xF0, 0x72, 0x2D, 0x29, 0xB5};
		static const byte var_data[] = {0x66, 0x49, 0xE2, 0x7C, 0x0D, 0x12, 0x26, 0x09, 0x49, 0xF8, 0x37, 0xA2, 0x2E, 0xCF, 0x6D, 0x7B, 0x78, 0x95, 0x4A, 0xFE, 0x69, 0x08, 0xF6, 0x9E, 0x40, 0x2B, 0x98, 0x73, 0xF0, 0x98, 0x6E, 0x51, 0x54, 0x13, 0x6F, 0x2F, 0x7F, 0xC0, 0x4D, 0x3D, 0x9E, 0xE2, 0x23, 0x53, 0xE5, 0xED, 0xEB, 0x00};
		static const byte var_expected[] = {0xBE, 0xB8, 0x03, 0x77, 0x40, 0x60, 0xBA, 0x28, 0x4D, 0x6F, 0xEC, 0x95, 0x9C, 0x60, 0xDB, 0xD4, 0xBA, 0x93, 0xAA, 0xEB, 0x91, 0x0D, 0x5E, 0x73, 0x4F, 0x77, 0xF8, 0xED, 0x9A, 0x89, 0x9C, 0xCB, 0x14, 0x2B, 0x00, 0x59, 0xCB, 0x0C, 0xA2, 0xC2, 0xAA, 0x68, 0x11, 0xBD, 0x3D, 0xA3, 0x1F, 0x71};
		memcpy(var_code, var_data, 48);
		aes128_cbc_decrypt(var_code, var_key, 48);
		assert_bytearr_equal(var_expected, var_code, 48, "aes128_dec 55 decode");
	}
	{
		static const byte var_key[] = {0x21, 0xE5, 0x90, 0xE3, 0x52, 0x27, 0x8F, 0x52, 0x1A, 0x2B, 0x43, 0x7E, 0xC3, 0xB0, 0x47, 0x1B};
		static const byte var_data[] = {0x8A, 0xE3, 0x63, 0xFF, 0x4A, 0xCB, 0x6C, 0x1D, 0xC0, 0x0D, 0xC4, 0x8F, 0x09, 0xCC, 0x1B, 0x63, 0xB0, 0xBA, 0x43, 0x43, 0x13, 0x68, 0x7A, 0xC6, 0x06, 0xF8, 0x44, 0xEE, 0x8B, 0x7A, 0x7A, 0xB3, 0x61, 0x62, 0x69, 0xD4, 0xC4, 0xCC, 0xDF, 0xBD, 0x1E, 0x11, 0x55, 0xCD, 0x2D, 0x14, 0xCC, 0x08};
		static const byte var_expected[] = {0x71, 0xB9, 0xB6, 0x0F, 0xE2, 0xB7, 0xD3, 0x54, 0x21, 0x25, 0xF1, 0x5A, 0x4E, 0xA1, 0x25, 0x0E, 0xCC, 0x9C, 0x5F, 0x5C, 0xF2, 0x88, 0xB4, 0x4F, 0xEC, 0x9E, 0x9C, 0x55, 0x45, 0xCB, 0x3E, 0xDD, 0x57, 0x18, 0x82, 0x4F, 0x37, 0xA1, 0x01, 0xBF, 0xBC, 0x87, 0xE6, 0x16, 0xB8, 0x49, 0x94, 0xF6};
		memcpy(var_code, var_data, 48);
		aes128_cbc_decrypt(var_code, var_key, 48);
		assert_bytearr_equal(var_expected, var_code, 48, "aes128_dec 56 decode");
	}
	{
		static const byte var_key[] = {0x8A, 0x65, 0x03, 0x06, 0x44, 0x80, 0xD1, 0xA1, 0x8A, 0x10, 0xB4, 0xF6, 0xEE, 0x62, 0x36, 0xB4};
		static const byte var_data[] = {0xEA, 0xAC, 0x46, 0xEA, 0xE9, 0xC7, 0xC4, 0x0E, 0xF4, 0x69, 0xA0, 0x85, 0x28, 0xC4, 0xB5, 0x96, 0x08, 0xC1, 0xB4, 0xB2, 0x61, 0xF4, 0x8A, 0x21, 0x3F, 0xE2, 0xBB, 0x6D, 0x15, 0x9A, 0xD0, 0xB4, 0x66, 0xB7, 0x2F, 0xE9, 0xD5, 0x18, 0xDA, 0x6F, 0xD9, 0xE1, 0xFB, 0x2E, 0x95, 0xD1, 0x51, 0x7B};
		static const byte var_expected[] = {0xA0, 0x87, 0xAA, 0xD4, 0xF4, 0xC7, 0xE7, 0xDD, 0x7E, 0x39, 0x92, 0x3F, 0x39, 0x45, 0xBE, 0xA5, 0x9D, 0x6B, 0xAA, 0x4D, 0x04, 0x6A, 0x69, 0xDF, 0x1F, 0xD3, 0x26, 0x4D, 0x9D, 0x9D, 0xF8, 0x30, 0xEB, 0x02, 0xAC, 0x99, 0x19, 0xCE, 0x4B, 0x5D, 0x26, 0x7F, 0x80, 0x32, 0x83, 0x6E, 0xBE, 0x00};
		memcpy(var_code, var_data, 48);
		aes128_cbc_decrypt(var_code, var_key, 48);
		assert_bytearr_equal(var_expected, var_code, 48, "aes128_dec 57 decode");
	}

}
