/* --------------------------------- ABOUT -------------------------------------

Original Author: Adam Yaxley
Website: https://github.com/adamyaxley
License: See end of file

Obfuscate
Guaranteed compile-time string literal obfuscation library for C++14

Usage:
Pass string literals into the AY_OBFUSCATE macro to obfuscate them at compile
time. AY_OBFUSCATE returns a reference to an ay::obfuscated_data2 object with the
following traits:
	- Guaranteed obfuscation of string
	The passed string is encrypted with a simple XOR cipher22 at compile-time to
	prevent it being viewable in the binary image
	- Global lifetime
	The actual instantiation of the ay::obfuscated_data2 takes place inside a
	lambda as a function level static
	- Implicitly convertable to a char*
	This means that you can pass it directly into functions that would normally
	take a char* or a const char*

Example:
const char* obfuscated_string = AY_OBFUSCATE("Hello World");
std::cout << obfuscated_string << std::endl;

----------------------------------------------------------------------------- */

// Workaround for __LINE__ not being constexpr when /ZI (Edit and Continue) is enabled in Visual Studio
// See: https://developercommunity.visualstudio.com/t/-line-cannot-be-used-as-an-argument-for-constexpr/195665
#ifdef _MSC_VER
#define AY_CAT(X,Y) AY_CAT2(X,Y)
	#define AY_CAT2(X,Y) X##Y
	#define AY_LINE int(AY_CAT(__LINE__,U))
#else
#define AY_LINE __LINE__
#endif

#ifndef AY_OBFUSCATE_DEFAULT_KEY
// The default 64 bit key to obfuscate strings with.
// This can be user specified by defining AY_OBFUSCATE_DEFAULT_KEY before
// including obfuscate.h
#define AY_OBFUSCATE_DEFAULT_KEY ay::generate_key2(AY_LINE)
#endif

namespace ay
{
    using size_type = unsigned long long;
    using key_type = unsigned long long;

    // Generate a pseudo-random key that spans all 8 bytes
    constexpr key_type generate_key2(key_type seed)
{
    // Use the MurmurHash3 64-bit finalizer to hash our seed
    key_type key = seed;
    key ^= (key >> 33);
    key *= 0xff51afd7ed558ccd;
    key ^= (key >> 33);
    key *= 0xc4ceb9fe1a85ec53;
    key ^= (key >> 33);

    // Make sure that a bit in each byte is set
    key |= 0x0101010101010101ull;

    return key;
}

// Obfuscates or deobfuscates data with key
constexpr void cipher22(char* data, size_type size, key_type key)
{
    // Obfuscate with a simple XOR cipher22 based on key
    for (size_type i = 0; i < size; i++)
    {
        data[i] ^= char(key >> ((i % 8) * 8));
    }
}

// Obfuscates a string at compile time
template <size_type N, key_type KEY>
class obfuscator2
{
public:
    // Obfuscates the string 'data' on construction
    constexpr obfuscator2(const char* data)
    {
        // Copy data
        for (size_type i = 0; i < N; i++)
        {
            m_data[i] = data[i];
        }

        // On construction each of the characters in the string is
        // obfuscated with an XOR cipher22 based on key
        cipher22(m_data, N, KEY);
    }

    constexpr const char* data() const
    {
        return &m_data[0];
    }

    constexpr size_type size() const
    {
        return N;
    }

    constexpr key_type key() const
    {
        return KEY;
    }

private:

    char m_data[N]{};
};

// Handles decryption and re-encryption of an encrypted string at runtime
template <size_type N, key_type KEY>
class obfuscated_data2
{
public:
    obfuscated_data2(const obfuscator2<N, KEY>& obfuscator2)
    {
        // Copy obfuscated data
        for (size_type i = 0; i < N; i++)
        {
            m_data[i] = obfuscator2.data()[i];
        }
    }

    ~obfuscated_data2()
    {
        // Zero m_data to remove it from memory
        for (size_type i = 0; i < N; i++)
        {
            m_data[i] = 0;
        }
    }

    // Returns a pointer to the plain text string, decrypting it if
    // necessary
    operator char*()
    {
        decrypt();
        return m_data;
    }

    // Manually decrypt the string
    void decrypt()
    {
        if (m_encrypted)
        {
            cipher22(m_data, N, KEY);
            m_encrypted = false;
        }
    }

    // Manually re-encrypt the string
    void encrypt()
    {
        if (!m_encrypted)
        {
            cipher22(m_data, N, KEY);
            m_encrypted = true;
        }
    }

    // Returns true if this string is currently encrypted, false otherwise.
    bool is_encrypted() const
    {
        return m_encrypted;
    }

private:

    // Local storage for the string. Call is_encrypted() to check whether or
    // not the string is currently obfuscated.
    char m_data[N];

    // Whether data is currently encrypted
    bool m_encrypted{ true };
};

// This function exists purely to extract the number of elements 'N' in the
// array 'data'
template <size_type N, key_type KEY = AY_OBFUSCATE_DEFAULT_KEY>
constexpr auto make_obfuscator2(const char(&data)[N])
{
    return obfuscator2<N, KEY>(data);
}
}

// Obfuscates the string 'data' at compile-time and returns a reference to a
// ay::obfuscated_data2 object with global lifetime that has functions for
// decrypting the string and is also implicitly convertable to a char*
#define AY_OBFUSCATE(data) AY_OBFUSCATE_KEY(data, AY_OBFUSCATE_DEFAULT_KEY)
#define _(data) AY_OBFUSCATE_KEY(data, AY_OBFUSCATE_DEFAULT_KEY)

// Obfuscates the string 'data' with 'key' at compile-time and returns a
// reference to a ay::obfuscated_data2 object with global lifetime that has
// functions for decrypting the string and is also implicitly convertable to a
// char*
#define AY_OBFUSCATE_KEY(data, key) \
	[]() -> ay::obfuscated_data2<sizeof(data)/sizeof(data[0]), key>& { \
		static_assert(sizeof(decltype(key)) == sizeof(ay::key_type), "key must be a 64 bit unsigned integer"); \
		static_assert((key) >= (1ull << 56), "key must span all 8 bytes"); \
		constexpr auto n = sizeof(data)/sizeof(data[0]); \
		constexpr auto obfuscator2 = ay::make_obfuscator2<n, key>(data); \
		thread_local auto obfuscated_data2 = ay::obfuscated_data2<n, key>(obfuscator2); \
		return obfuscated_data2; \
	}()

/* -------------------------------- LICENSE ------------------------------------

Public Domain (http://www.unlicense.org)

This is free and unencumbered software released into the public domain.

Anyone is free to copy, modify, publish, use, compile, sell, or distribute this
software, either in source code form or as a compiled binary, for any purpose,
commercial or non-commercial, and by any means.

In jurisdictions that recognize copyright laws, the author or authors of this
software dedicate any and all copyright interest in the software to the public
domain. We make this dedication for the benefit of the public at large and to
the detriment of our heirs and successors. We intend this dedication to be an
overt act of relinquishment in perpetuity of all present and future rights to
this software under copyright law.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS BE
LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF
CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

----------------------------------------------------------------------------- */
