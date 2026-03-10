#include "types.hpp"

struct i_memory {
  virtual types::byte read(types::word address) const = 0;
  virtual types::byte& ref(types::word address) = 0;
  virtual void write(types::word address, types::byte value) = 0;
  
  types::byte operator[](types::word address) const { return read(address); }
  types::byte& operator[](types::word address) { return ref(address); }
};
