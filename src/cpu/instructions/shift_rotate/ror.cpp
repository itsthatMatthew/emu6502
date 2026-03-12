#include "../../mos6502.hpp"

static void ror(mos6502& cpu, types::byte& value) {
  const bool carry = value & 1;
  value >>= 1;
  value |= cpu.get_flag(C) << 7;
  cpu.set_flag(C, carry);
  cpu.set_flag(Z, value == 0);
  cpu.set_flag(N, value & 0x80);
}

INSTRUCTION(ROR, ACCUMULATOR) {
  ror(*this, AC);
}

INSTRUCTION(ROR, ZERO_PAGE) {
  ror(*this, m_memory[fetch_next_byte()]);
}

INSTRUCTION(ROR, ZERO_PAGE_X) {
  ror(*this, m_memory[(fetch_next_byte() + X) % 256]);
}

INSTRUCTION(ROR, ABSOLUTE) {
  ror(*this, m_memory[fetch_next_address()]);
}

INSTRUCTION(ROR, ABSOLUTE_X) {
  ror(*this, m_memory[fetch_next_address() + X]);
}