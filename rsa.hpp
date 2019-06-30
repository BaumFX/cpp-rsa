#include <string>
#include <iostream>
#include <math.h>
#include <string>

/**
	namespace for encryption using a shitty rsa algorithm
*/
namespace rsa {
	//prime numbers + calculations, should probably make this dynamic or like time based or shit but who cares
	long int p = 8623;
	long int q = 1153;
	long int n = p * q;
	long int t = (p - 1) * (q - 1);
	long int e = calculate_e(t);
	long int d = calculate_d(e, t);
	
	/**
		encrypts given string
		@param input string
		@return result string
	*/
	std::string encrypt(std::string input) {
		//temp var for result (encrypted text)
		std::string result;
		
		//iterate over input and replace the characters with the encrypted characters
		for (long int i = 0; i < input.length(); i++) { result[i] = encrypt_character(input[i], e, n); }

		//return encrypted text
		return result;
	}

	/**
		decrypts given string
		@param input string
		@return result string
	*/
	std::string decrypt(std::string input) {
		//temp var for result (decrypted text)
		std::string result;
		
		//iterate over input and replace the characters with the decrypted characters
		for (long int i = 0; i < input.length(); i++) { result[i] = decrypt_character(input[i], d, n); }

		//return decrypted result
		return result;
	}

	/**
		calculates e (for encryption)
		@param input integer
		@return e integer
	*/
	long int calculate_e(long int t) { long int e; for (e = 2; e < t; e++) { if (greatest_common_divisor(e, t) == 1) { return e; } } return -1; }

	/**
		calculates greatest common divisor (for encryption)
		@param input integer 1, input integer 2
		@return greatest common divisor
	*/
	long int greatest_common_divisor(long int e, long int t) { while (e > 0) { long int temp = e; e = t % e; t = temp; } return t; }

	/**
		calculates d (for encryption)
		@param input integer
		@return d integer
	*/
	long int calculate_d(long int e, long int t) { long int k = 1; while (1) { k += t; if (k % e == 0) { return (k / e); } } }

	/**
		encrypts given character
		@param character to encrypt, factor 1, factor 2
		@return encrypted character (int)
	*/
	long int encrypt_character(long int i, long int e, long int n)
	{
		//temp vars
		long int current = i - 97;
		long int result = 1;

		//encrypt character
		for (long int j = 0; j < e; j++) { result *= current; result %= n; }

		//return encrypted character
		return result;
	}

	/**
		decrypts given character
		@param character to decrypt, factor 1, factor 2
		@return decrypted character (int)
	*/
	long int decrypt_character(long int i, long int d, long int n)
	{
		//temp vars
		long int current = i;
		long int result = 1;

		//decrypt character
		for (long int j = 0; j < d; j++) { result *= current; result %= n; }

		//return decrypted character
		return result + 97;
	}
}
