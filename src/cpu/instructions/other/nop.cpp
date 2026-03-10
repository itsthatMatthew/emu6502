#include "../../mos6502.hpp"

INSTRUCTION(NOP, IMPLIED) {
  PC++;
}
