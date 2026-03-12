#include "../../mos6502.hpp"

static void cmp(mos6502& cpu, types::byte memory) {
  cpu.set_flag(C, cpu.Y >= memory);
  cpu.set_flag(Z, cpu.Y == memory);
  cpu.set_flag(N, (cpu.Y - memory) & 0x80);
}

INSTRUCTION(CPY, IMMEDIATE) {
  cmp(*this, fetch<IMMEDIATE>());
}

INSTRUCTION(CPY, ZERO_PAGE) {
  cmp(*this, fetch<ZERO_PAGE>());
}

INSTRUCTION(CPY, ABSOLUTE) {
  cmp(*this, fetch<ABSOLUTE>());
}
