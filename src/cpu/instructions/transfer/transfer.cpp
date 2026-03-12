#include "../../mos6502.hpp"

static void set_flags(mos6502& cpu, types::byte result) {
  cpu.set_flag(Z, result == 0);
  cpu.set_flag(N, result & 0x80);
}

INSTRUCTION(TAX, IMPLIED) {
  set_flags(*this, X = AC);
}

INSTRUCTION(TAY, IMPLIED) {
  set_flags(*this, Y = AC);
}

INSTRUCTION(TSX, IMPLIED) {
  set_flags(*this, X = SP);
}

INSTRUCTION(TXA, IMPLIED) {
  set_flags(*this, AC = X);
}

INSTRUCTION(TXS, IMPLIED) {
  set_flags(*this, SP = X);
}

INSTRUCTION(TYA, IMPLIED) {
  set_flags(*this, AC = Y);
}
