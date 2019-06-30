# cpp rsa

a simple implementation of an rsa algorithm using c++. 

## getting started

these instructions will get you a copy of the project up and running on your local machine for development and testing purposes.

literally download & include

you can then use

```
std::string input = "hello this is a cool test";
std::string result = rsa::encrypt(input);
```

to encrypt data.

decryption works like this:

```
std::string encrypted = "Mo1BU6faf7l...+UOqPbCees="
std::string result = rsa::decrypt(input);
```

of course encryption + decryption have to use the same primes. so messages encrypted with this library will only be decrypted by this library, please feel free to change the primes to your liking/needs.

## contributing

if you have any suggestions or comments (such as an opinion from someone who actually knows cryptographics), please file an issue :)

## versioning

we dont have that since im lazy and dont do updates.

## authors

* **Robert 'BaumFX'** - *initial work* - [website](https://baumfx.xyz) - [GitHub](https://github.com/BaumFX)

## license

its like 10 lines but dont say you made it, okay?
