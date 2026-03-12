#include "../../mos6502.hpp"

INSTRUCTION(CLC, IMPLIED) {
  set_flag(C, false);
}

INSTRUCTION(CLD, IMPLIED) {
  set_flag(D, false);
}

INSTRUCTION(CLI, IMPLIED) {
  set_flag(I, false);
}

INSTRUCTION(CLV, IMPLIED) {
  set_flag(V, false);
}

INSTRUCTION(SEC, IMPLIED) {
  set_flag(C, true);
}

INSTRUCTION(SED, IMPLIED) {
  set_flag(D, true);
}

INSTRUCTION(SEI, IMPLIED) {
  set_flag(I, true);
}
