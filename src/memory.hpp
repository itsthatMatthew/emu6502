#include "types.hpp"

struct i_memory {
  virtual types::byte read(types::address address) const = 0;
  virtual types::byte& ref(types::address address) = 0;
  virtual void write(types::address address, types::byte value) = 0;
  
  types::byte operator[](types::address address) const { return read(address); }
  types::byte& operator[](types::address address) { return ref(address); }
};
