#include "../../mos6502.hpp"

static void asl(mos6502& cpu, types::byte& value) {
  cpu.set_flag(C, value & 0x80);
  value <<= 1;
  cpu.set_flag(Z, value == 0);
  cpu.set_flag(N, 0);
}

INSTRUCTION(ASL, ACCUMULATOR) {
  asl(*this, AC);
}

INSTRUCTION(ASL, ZERO_PAGE) {
  asl(*this, m_memory[fetch_next_byte()]);
}

INSTRUCTION(ASL, ZERO_PAGE_X) {
  asl(*this, m_memory[(fetch_next_byte() + X) % 256]);
}

INSTRUCTION(ASL, ABSOLUTE) {
  asl(*this, m_memory[fetch_next_address()]);
}

INSTRUCTION(ASL, ABSOLUTE_X) {
  asl(*this, m_memory[fetch_next_address() + X]);
}
