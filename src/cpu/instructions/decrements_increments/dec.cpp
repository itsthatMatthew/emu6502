#include "../../mos6502.hpp"

static void dec(mos6502& cpu, types::word address) {
  types::byte result = --cpu.m_memory[address];
  cpu.set_flag(Z, result == 0);
  cpu.set_flag(N, result & 0x80);
}

INSTRUCTION(DEC, ZERO_PAGE) {
  dec(*this, fetch<ZERO_PAGE>());
}

INSTRUCTION(DEC, ZERO_PAGE_X) {
  dec(*this, fetch<ZERO_PAGE_X>());
}

INSTRUCTION(DEC, ABSOLUTE) {
  dec(*this, fetch<ABSOLUTE>());
}

INSTRUCTION(DEC, ABSOLUTE_X) {
  dec(*this, fetch<ABSOLUTE_X>());
}
