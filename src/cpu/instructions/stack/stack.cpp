#include "../../mos6502.hpp"

INSTRUCTION(PHA, IMPLIED) {
  push_stack(AC);
}

INSTRUCTION(PHP, IMPLIED) {
  push_stack(SR & 0b00110000);
}

INSTRUCTION(PLA, IMPLIED) {
  AC = pop_stack();
}

INSTRUCTION(PLP, IMPLIED) {
  SR = pop_stack();
}
