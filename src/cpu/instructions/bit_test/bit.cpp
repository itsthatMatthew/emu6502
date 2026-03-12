#include "../../mos6502.hpp"

static void set_flags(mos6502& cpu, types::byte memory) {
  cpu.set_flag(Z, (cpu.AC & memory) == 0);
  cpu.set_flag(V, memory & V);
  cpu.set_flag(N, memory & N);
}

INSTRUCTION(BIT, ZERO_PAGE) {
  set_flags(*this, fetch<ZERO_PAGE>());
}

INSTRUCTION(BIT, ABSOLUTE) {
  set_flags(*this, fetch<ABSOLUTE>());
}
