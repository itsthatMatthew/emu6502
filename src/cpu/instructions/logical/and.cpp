#include "../../mos6502.hpp"

static void and_a(mos6502& cpu, types::byte memory) {
  cpu.AC &= memory;
  cpu.set_flag(Z, cpu.AC == 0);
  cpu.set_flag(N, cpu.AC & 0x80);
}

INSTRUCTION(AND, IMMEDIATE) {
  and_a(*this, fetch<IMMEDIATE>());
}

INSTRUCTION(AND, ZERO_PAGE) {
  and_a(*this, fetch<ZERO_PAGE>());
}

INSTRUCTION(AND, ZERO_PAGE_X) {
  and_a(*this, fetch<ZERO_PAGE_X>());
}

INSTRUCTION(AND, ABSOLUTE) {
  and_a(*this, fetch<ABSOLUTE>());
}

INSTRUCTION(AND, ABSOLUTE_X) {
  and_a(*this, fetch<ABSOLUTE_X>());
}

INSTRUCTION(AND, ABSOLUTE_Y) {
  and_a(*this, fetch<ABSOLUTE_Y>());
}

INSTRUCTION(AND, INDIRECT_X) {
  and_a(*this, fetch<INDIRECT_X>());
}

INSTRUCTION(AND, INDIRECT_Y) {
  and_a(*this, fetch<INDIRECT_Y>());
}
