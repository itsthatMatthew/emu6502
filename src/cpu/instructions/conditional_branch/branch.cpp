#include "../../mos6502.hpp"

static void branch(mos6502& cpu, bool condition) {
  const types::byte offset = cpu.fetch_next_byte();
  const types::word ptr = cpu.PC + ((offset & 0x80) ? (offset | 0xFF00) : offset);
  if (condition) {
    cpu.PC = ptr;
  }
}

INSTRUCTION(BCC, RELATIVE) {
  branch(*this, !get_flag(C));
}

INSTRUCTION(BCS, RELATIVE) {
  branch(*this, get_flag(C));
}

INSTRUCTION(BEQ, RELATIVE) {
  branch(*this, get_flag(Z));
}

INSTRUCTION(BMI, RELATIVE) {
  branch(*this, get_flag(N));
}

INSTRUCTION(BNE, RELATIVE) {
  branch(*this, !get_flag(Z));
}

INSTRUCTION(BPL, RELATIVE) {
  branch(*this, !get_flag(N));
}

INSTRUCTION(BVC, RELATIVE) {
  branch(*this, !get_flag(V));
}

INSTRUCTION(BVS, RELATIVE) {
  branch(*this, get_flag(V));
}
