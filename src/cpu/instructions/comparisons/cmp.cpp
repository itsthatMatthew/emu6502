#include "../../mos6502.hpp"

static void cmp(mos6502& cpu, types::byte memory) {
  cpu.set_flag(C, cpu.AC >= memory);
  cpu.set_flag(Z, cpu.AC == memory);
  cpu.set_flag(N, (cpu.AC - memory) & 0x80);
}

INSTRUCTION(CMP, IMMEDIATE) {
  cmp(*this, fetch<IMMEDIATE>());
}

INSTRUCTION(CMP, ZERO_PAGE) {
  cmp(*this, fetch<ZERO_PAGE>());
}

INSTRUCTION(CMP, ZERO_PAGE_X) {
  cmp(*this, fetch<ZERO_PAGE_X>());
}

INSTRUCTION(CMP, ABSOLUTE) {
  cmp(*this, fetch<ABSOLUTE>());
}

INSTRUCTION(CMP, ABSOLUTE_X) {
  cmp(*this, fetch<ABSOLUTE_X>());
}

INSTRUCTION(CMP, ABSOLUTE_Y) {
  cmp(*this, fetch<ABSOLUTE_Y>());
}

INSTRUCTION(CMP, INDIRECT_X) {
  cmp(*this, fetch<INDIRECT_X>());
}

INSTRUCTION(CMP, INDIRECT_Y) {
  cmp(*this, fetch<INDIRECT_Y>());
}
