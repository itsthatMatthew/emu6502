#include "../../mos6502.hpp"

static void cmp(mos6502& cpu, types::byte memory) {
  cpu.set_flag(C, cpu.X >= memory);
  cpu.set_flag(Z, cpu.X == memory);
  cpu.set_flag(N, (cpu.X - memory) & 0x80);
}

INSTRUCTION(CPX, IMMEDIATE) {
  cmp(*this, fetch<IMMEDIATE>());
}

INSTRUCTION(CPX, ZERO_PAGE) {
  cmp(*this, fetch<ZERO_PAGE>());
}

INSTRUCTION(CPX, ABSOLUTE) {
  cmp(*this, fetch<ABSOLUTE>());
}
