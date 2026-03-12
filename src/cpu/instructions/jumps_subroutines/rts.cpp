#include "../../mos6502.hpp"

INSTRUCTION(RTS, IMPLIED) {
  PC = pop_stack() + (pop_stack() << 8) + 1;
}
