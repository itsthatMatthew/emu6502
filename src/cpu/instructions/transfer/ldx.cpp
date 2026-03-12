#include "../../mos6502.hpp"

static void ldx(mos6502& cpu, types::byte memory) {
  cpu.X = memory;
  cpu.set_flag(Z, cpu.X == 0);
  cpu.set_flag(N, cpu.X & 0x80);
}

INSTRUCTION(LDX, IMMEDIATE) {
  ldx(*this, fetch<IMMEDIATE>());
}

INSTRUCTION(LDX, ZERO_PAGE) {
  ldx(*this, fetch<ZERO_PAGE>());
}

INSTRUCTION(LDX, ZERO_PAGE_Y) {
  ldx(*this, fetch<ZERO_PAGE_Y>());
}

INSTRUCTION(LDX, ABSOLUTE) {
  ldx(*this, fetch<ABSOLUTE>());
}

INSTRUCTION(LDX, ABSOLUTE_Y) {
  ldx(*this, fetch<ABSOLUTE_Y>());
}
