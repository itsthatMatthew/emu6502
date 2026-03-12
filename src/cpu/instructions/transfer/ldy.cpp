#include "../../mos6502.hpp"

static void ldy(mos6502& cpu, types::byte memory) {
  cpu.Y = memory;
  cpu.set_flag(Z, cpu.Y == 0);
  cpu.set_flag(N, cpu.Y & 0x80);
}

INSTRUCTION(LDY, IMMEDIATE) {
  ldy(*this, fetch<IMMEDIATE>());
}

INSTRUCTION(LDY, ZERO_PAGE) {
  ldy(*this, fetch<ZERO_PAGE>());
}

INSTRUCTION(LDY, ZERO_PAGE_X) {
  ldy(*this, fetch<ZERO_PAGE_X>());
}

INSTRUCTION(LDY, ABSOLUTE) {
  ldy(*this, fetch<ABSOLUTE>());
}

INSTRUCTION(LDY, ABSOLUTE_X) {
  ldy(*this, fetch<ABSOLUTE_X>());
}

