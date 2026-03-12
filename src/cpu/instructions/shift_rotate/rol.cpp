#include "../../mos6502.hpp"

static void rol(mos6502& cpu, types::byte& value) {
  const bool carry = value & 0x80;
  value <<= 1;
  value |= cpu.get_flag(C);
  cpu.set_flag(C, carry);
  cpu.set_flag(Z, value == 0);
  cpu.set_flag(N, value & 0x80);
}

INSTRUCTION(ROL, ACCUMULATOR) {
  rol(*this, AC);
}

INSTRUCTION(ROL, ZERO_PAGE) {
  rol(*this, m_memory[fetch_next_byte()]);
}

INSTRUCTION(ROL, ZERO_PAGE_X) {
  rol(*this, m_memory[(fetch_next_byte() + X) % 256]);
}

INSTRUCTION(ROL, ABSOLUTE) {
  rol(*this, m_memory[fetch_next_address()]);
}

INSTRUCTION(ROL, ABSOLUTE_X) {
  rol(*this, m_memory[fetch_next_address() + X]);
}
