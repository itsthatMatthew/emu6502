#pragma once
#include <cstdint>

namespace types {
  using byte = uint8_t;
  using address = uint16_t;
  
  namespace literals {
    constexpr byte operator ""_b(unsigned long long value) {
      return static_cast<byte>(value);
    }
    constexpr byte operator ""_byte(unsigned long long value) {
      return static_cast<byte>(value);
    }
    constexpr byte operator ""_immediate(unsigned long long value) {
      return static_cast<byte>(value);
    }
    
    constexpr address operator ""_a(unsigned long long value) {
      return static_cast<address>(value);
    }
    constexpr address operator ""_address(unsigned long long value) {
      return static_cast<address>(value);
    }
    constexpr address operator ""_absolute(unsigned long long value) {
      return static_cast<address>(value);
    }
  }
}
