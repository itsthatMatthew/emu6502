#include "../../mos6502.hpp"

static void lsr(mos6502& cpu, types::byte& value) {
  cpu.set_flag(C, value & 1);
  value >>= 1;
  cpu.set_flag(Z, value == 0);
  cpu.set_flag(N, 0);
}

INSTRUCTION(LSR, ACCUMULATOR) {
  lsr(*this, AC);
}

INSTRUCTION(LSR, ZERO_PAGE) {
  lsr(*this, m_memory[fetch_next_byte()]);
}

INSTRUCTION(LSR, ZERO_PAGE_X) {
  lsr(*this, m_memory[(fetch_next_byte() + X) % 256]);
}

INSTRUCTION(LSR, ABSOLUTE) {
  lsr(*this, m_memory[fetch_next_address()]);
}

INSTRUCTION(LSR, ABSOLUTE_X) {
  lsr(*this, m_memory[fetch_next_address() + X]);
}
