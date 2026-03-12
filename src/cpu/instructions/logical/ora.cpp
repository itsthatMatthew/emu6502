#include "../../mos6502.hpp"

static void ora(mos6502& cpu, types::byte memory) {
  cpu.AC |= memory;
  cpu.set_flag(Z, cpu.AC == 0);
  cpu.set_flag(N, cpu.AC & 0x80);
}

INSTRUCTION(ORA, IMMEDIATE) {
  ora(*this, fetch<IMMEDIATE>());
}

INSTRUCTION(ORA, ZERO_PAGE) {
  ora(*this, fetch<ZERO_PAGE>());
}

INSTRUCTION(ORA, ZERO_PAGE_X) {
  ora(*this, fetch<ZERO_PAGE_X>());
}

INSTRUCTION(ORA, ABSOLUTE) {
  ora(*this, fetch<ABSOLUTE>());
}

INSTRUCTION(ORA, ABSOLUTE_X) {
  ora(*this, fetch<ABSOLUTE_X>());
}

INSTRUCTION(ORA, ABSOLUTE_Y) {
  ora(*this, fetch<ABSOLUTE_Y>());
}

INSTRUCTION(ORA, INDIRECT_X) {
  ora(*this, fetch<INDIRECT_X>());
}

INSTRUCTION(ORA, INDIRECT_Y) {
  ora(*this, fetch<INDIRECT_Y>());
}
