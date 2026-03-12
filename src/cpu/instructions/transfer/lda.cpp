#include "../../mos6502.hpp"

static void lda(mos6502& cpu, types::byte memory) {
  cpu.AC = memory;
  cpu.set_flag(Z, cpu.AC == 0);
  cpu.set_flag(N, cpu.AC & 0x80);
}

INSTRUCTION(LDA, IMMEDIATE) {
  lda(*this, fetch<IMMEDIATE>());
}

INSTRUCTION(LDA, ZERO_PAGE) {
  lda(*this, fetch<ZERO_PAGE>());
}

INSTRUCTION(LDA, ZERO_PAGE_X) {
  lda(*this, fetch<ZERO_PAGE_X>());
}

INSTRUCTION(LDA, ABSOLUTE) {
  lda(*this, fetch<ABSOLUTE>());
}

INSTRUCTION(LDA, ABSOLUTE_X) {
  lda(*this, fetch<ABSOLUTE_X>());
}

INSTRUCTION(LDA, ABSOLUTE_Y) {
  lda(*this, fetch<ABSOLUTE_Y>());
}

INSTRUCTION(LDA, INDIRECT_X) {
  lda(*this, fetch<INDIRECT_X>());
}

INSTRUCTION(LDA, INDIRECT_Y) {
  lda(*this, fetch<INDIRECT_Y>());
}
