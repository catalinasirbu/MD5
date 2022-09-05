#ifndef BZF_MD5_H
#define BZF_MD5_H

#include <cstring>
#include <iostream>

class MD5
{
public:

  /// @warning Must be 32bit
  typedef unsigned int size_type; 

  /// @brief Default constructor - just initailize
  MD5();

  /// @brief Overloaded constructor - compute MD5 for string and finalize it right away
  /// @param text[in] user text to be encrypted
  MD5(const std::string& text);

  /// @brief MD5 block update operation. Continues an MD5 message-digest operation, processing another message block.
  void update(const unsigned char *buf, size_type length);

  /// @brief For convenience provide a verson with signed char
  void update(const char *buf, size_type length);

  /// @brief MD5 finalization. Ends an MD5 message-digest operation, writing the message digest and zeroizing the context.
  MD5& finalize();

  /// @brief return hex representation of digest as string
  std::string hexdigest() const;

  /// @brief Initialize variables and load <a href="https://en.wikipedia.org/wiki/MD5#Implementations">magic constants</a> 
  void init();

  /// @brief Apply MD5 algo on a block
  void transform(const uint1 block[blocksize]);

  /// @brief Decodes input (unsigned char) into output (uint4). Assumes len is a multiple of 4.
  static void decode(uint4 output[], const uint1 input[], size_type len);

  /// @brief Encodes input (uint4) into output (unsigned char).\nAssumes len is a multiple of 4.
  static void encode(uint1 output[], const uint4 input[], size_type len);

  /// @brief Overload operator for ease of printing
  friend std::ostream& operator<<(std::ostream&, MD5 md5);

  /// @warning 8 bin
  typedef unsigned char uint1;

  /// @warning 32 bit
  typedef unsigned int uint4;

  bool finalized;

  enum {blocksize = 64};
  
  /// @brief Bytes that didn't fit in last 64 byte chunk
  uint1 buffer[blocksize];

  /// @brief 64bit counter for number of bits (lo, hi)
  uint4 count[2];   
  
  /// @brief Digest so far
  uint4 state[4];   
  
  /// @breif Stores result
  uint1 digest[16]; 



	/**
	*  \defgroup @name F,G,H and I functions
	*  The main MD5 algorithm operates on a 128-bit state,
	*  divided into four 32-bit words, denoted A, B, C, and D.
	*  These are initialized to certain fixed constants. The main algorithm then uses each
	*  512-bit message block in turn to modify the state. The processing of a message block consists
	*  of four similar stages, termed rounds; each round is composed of 16 similar operations based on
	*  a non-linear function F, modular addition, and left rotation.
	*  \n Low level logic operations.
	*  \n Basic MD5 functions.
	* @{*/

	/* @brief Computes a logical operation on the three parameters* /
	 @param x first member
	 @param y second member
	 @param z third member
	 @return (x or y) or (not x or y) */
	/*
	static inline uint4 F(uint4 x, uint4 y, uint4 z);

	/* @brief Computes a logical operation on the three parameters
	 @param x first member
	 @param y second member
	 @param z third member
	 @return (x or y) or (not x or y)
	*/
	static inline uint4 G(uint4 x, uint4 y, uint4 z);

	/* @brief Computes a logical operation on the three parameters
	 @param x first member
	 @param y second member
	 @param z third member
	 @return (x or y) or (not x or y)
	*/
	static inline uint4 H(uint4 x, uint4 y, uint4 z);

	/* @brief Computes a logical operation on the three parameters
	@param x first member
	@param y second member
	@param z third member
	@return (x or y) or (not x or y)
	*/
	static inline uint4 I(uint4 x, uint4 y, uint4 z);

	/// @brief Computes left roration
	/// @param x The number itself
	/// @param n How many times to rotate left
	/// @return x rotated left by n
	static inline uint4 rotate_left(uint4 x, int n);

	// FF, GG, HH, and II transformations for rounds 1, 2, 3, and 4.
	static inline void FF(uint4& a, uint4 b, uint4 c, uint4 d, uint4 x, uint4 s, uint4 ac);

	// FF, GG, HH, and II transformations for rounds 1, 2, 3, and 4.
	static inline void GG(uint4& a, uint4 b, uint4 c, uint4 d, uint4 x, uint4 s, uint4 ac);

	// FF, GG, HH, and II transformations for rounds 1, 2, 3, and 4.
	static inline void HH(uint4& a, uint4 b, uint4 c, uint4 d, uint4 x, uint4 s, uint4 ac);

	// FF, GG, HH, and II transformations for rounds 1, 2, 3, and 4.
	static inline void II(uint4& a, uint4 b, uint4 c, uint4 d, uint4 x, uint4 s, uint4 ac);

	/*\@}*/
};

/// @brief The function creates a MD5 object and returns the hash
/// @param str[in] User input
std::string md5(const std::string str);

#endif
