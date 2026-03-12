#include "../../mos6502.hpp"

static void eor(mos6502& cpu, types::byte memory) {
  cpu.AC ^= memory;
  cpu.set_flag(Z, cpu.AC == 0);
  cpu.set_flag(N, cpu.AC & 0x80);
}

INSTRUCTION(EOR, IMMEDIATE) {
  eor(*this, fetch<IMMEDIATE>());
}

INSTRUCTION(EOR, ZERO_PAGE) {
  eor(*this, fetch<ZERO_PAGE>());
}

INSTRUCTION(EOR, ZERO_PAGE_X) {
  eor(*this, fetch<ZERO_PAGE_X>());
}

INSTRUCTION(EOR, ABSOLUTE) {
  eor(*this, fetch<ABSOLUTE>());
}

INSTRUCTION(EOR, ABSOLUTE_X) {
  eor(*this, fetch<ABSOLUTE_X>());
}

INSTRUCTION(EOR, ABSOLUTE_Y) {
  eor(*this, fetch<ABSOLUTE_Y>());
}

INSTRUCTION(EOR, INDIRECT_X) {
  eor(*this, fetch<INDIRECT_X>());
}

INSTRUCTION(EOR, INDIRECT_Y) {
  eor(*this, fetch<INDIRECT_Y>());
}
