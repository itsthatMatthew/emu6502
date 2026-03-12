#include "../../mos6502.hpp"

static void inc(mos6502& cpu, types::word address) {
  types::byte result = ++cpu.m_memory[address];
  cpu.set_flag(Z, result == 0);
  cpu.set_flag(N, result & 0x80);
}

INSTRUCTION(INC, ZERO_PAGE) {
  inc(*this, fetch<ZERO_PAGE>());
}

INSTRUCTION(INC, ZERO_PAGE_X) {
  inc(*this, fetch<ZERO_PAGE_X>());
}

INSTRUCTION(INC, ABSOLUTE) {
  inc(*this, fetch<ABSOLUTE>());
}

INSTRUCTION(INC, ABSOLUTE_X) {
  inc(*this, fetch<ABSOLUTE_X>());
}
