#include "../../mos6502.hpp"

static void dec(mos6502& cpu, types::byte& reg) {
  types::byte result = --reg;
  cpu.set_flag(Z, result == 0);
  cpu.set_flag(N, result & 0x80);
}

static void inc(mos6502& cpu, types::byte& reg) {
  types::byte result = ++reg;
  cpu.set_flag(Z, result == 0);
  cpu.set_flag(N, result & 0x80);
}

INSTRUCTION(DEX, IMPLIED) {
  dec(*this, X);
}

INSTRUCTION(DEY, IMPLIED) {
  dec(*this, Y);
}

INSTRUCTION(INX, IMPLIED) {
  inc(*this, X);
}

INSTRUCTION(INY, IMPLIED) {
  inc(*this, Y);
}
