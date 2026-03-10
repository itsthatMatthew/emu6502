#include "mos6502.hpp"

template<> void mos6502::store<ZERO_PAGE>(types::byte data) {
  const types::byte zp_ptr = fetch_next_byte();
  m_memory[zp_ptr] = data;
}
template<> void mos6502::store<ZERO_PAGE_X>(types::byte data) {
  const types::byte zp_ptr = fetch_next_byte();
  m_memory[(zp_ptr + X) % 256] = data;
}
template<> void mos6502::store<ZERO_PAGE_Y>(types::byte data) {
  const types::byte zp_ptr = fetch_next_byte();
  m_memory[(zp_ptr + Y) % 256] = data;
}
template<> void mos6502::store<ABSOLUTE>(types::byte data) {
  const types::word abs_ptr = fetch_next_address();
  m_memory[abs_ptr] = data;
}
template<> void mos6502::store<ABSOLUTE_X>(types::byte data) {
  const types::word abs_ptr = fetch_next_address();
  m_memory[abs_ptr + X] = data;
}
template<> void mos6502::store<ABSOLUTE_Y>(types::byte data) {
  const types::word abs_ptr = fetch_next_address();
  m_memory[abs_ptr + Y] = data;
}
template<> void mos6502::store<INDIRECT_X>(types::byte data) {
  const types::byte zp_ptr = fetch_next_byte() + X;
  const types::word ptr = (m_memory[zp_ptr + 1] << 8) + m_memory[zp_ptr];
  m_memory[ptr] = data;
}
template<> void mos6502::store<INDIRECT_Y>(types::byte data) {
  const types::byte zp_ptr = fetch_next_byte();
  const types::word ptr = (m_memory[zp_ptr + 1] << 8) + m_memory[zp_ptr] + Y;
  m_memory[ptr] = data;
}
