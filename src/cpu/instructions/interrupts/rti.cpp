#include "../../mos6502.hpp"

INSTRUCTION(RTI, IMPLIED) {
  SR = pop_stack();
  PC = pop_stack() + (pop_stack() << 8);
}
