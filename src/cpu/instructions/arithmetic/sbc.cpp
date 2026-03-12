#include "../../mos6502.hpp"

static void set_flags(mos6502& cpu, types::byte memory, types::word result) {
  cpu.set_flag(C, result > 0xFF);
  cpu.set_flag(Z, result == 0);
  cpu.set_flag(V, (result ^ cpu.AC) & (result ^ ~memory) & 0x80);
  cpu.set_flag(N, result & 0x80);
}

static void sbc(mos6502& cpu, types::byte memory) {
  const types::word result = cpu.AC + ~memory + cpu.get_flag(C);
  set_flags(cpu, memory, result);
  cpu.AC = result & 0xFF;
}

INSTRUCTION(SBC, IMMEDIATE) {
  sbc(*this, fetch<IMMEDIATE>());
}

INSTRUCTION(SBC, ZERO_PAGE) {
  sbc(*this, fetch<ZERO_PAGE>());
}

INSTRUCTION(SBC, ZERO_PAGE_X) {
  sbc(*this, fetch<ZERO_PAGE_X>());
}

INSTRUCTION(SBC, ABSOLUTE) {
  sbc(*this, fetch<ABSOLUTE>());
}

INSTRUCTION(SBC, ABSOLUTE_X) {
  sbc(*this, fetch<ABSOLUTE_X>());
}

INSTRUCTION(SBC, ABSOLUTE_Y) {
  sbc(*this, fetch<ABSOLUTE_Y>());
}

INSTRUCTION(SBC, INDIRECT_X) {
  sbc(*this, fetch<INDIRECT_X>());
}

INSTRUCTION(SBC, INDIRECT_Y) {
  sbc(*this, fetch<INDIRECT_Y>());
}
