#include "mos6502.hpp"

types::byte mos6502::fetch_next_byte() {
  return m_memory[PC++];
}
types::word mos6502::fetch_next_address() {
  const types::word low = fetch_next_byte();
  const types::word high = fetch_next_byte();
  return (high << 8) + low;
}

template<> types::byte mos6502::fetch<IMMEDIATE>() {
  return fetch_next_byte();
}
template<> types::byte mos6502::fetch<ZERO_PAGE>() {
  const types::byte zp_ptr = fetch_next_byte();
  return m_memory[zp_ptr];
}
template<> types::byte mos6502::fetch<ZERO_PAGE_X>() {
  const types::byte zp_ptr = fetch_next_byte();
  return m_memory[(zp_ptr + X) % 256];
}
template<> types::byte mos6502::fetch<ZERO_PAGE_Y>() {
  const types::byte zp_ptr = fetch_next_byte();
  return m_memory[(zp_ptr + Y) % 256];
}
template<> types::byte mos6502::fetch<ABSOLUTE>() {
  const types::word abs_ptr = fetch_next_address();
  return m_memory[abs_ptr];
}
template<> types::byte mos6502::fetch<ABSOLUTE_X>() {
  const types::word abs_ptr = fetch_next_address();
  return m_memory[abs_ptr + X];
}
template<> types::byte mos6502::fetch<ABSOLUTE_Y>() {
  const types::word abs_ptr = fetch_next_address();
  return m_memory[abs_ptr + Y];
}
template<> types::byte mos6502::fetch<INDIRECT_X>() {
  const types::byte zp_ptr = fetch_next_byte() + X;
  const types::word ptr = (m_memory[zp_ptr + 1] << 8) + m_memory[zp_ptr];
  return m_memory[ptr];
}
template<> types::byte mos6502::fetch<INDIRECT_Y>() {
  const types::byte zp_ptr = fetch_next_byte();
  const types::word ptr = (m_memory[zp_ptr + 1] << 8) + m_memory[zp_ptr] + Y;
  return m_memory[ptr];
}
