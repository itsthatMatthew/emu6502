#include "../../mos6502.hpp"

INSTRUCTION(JSR, ABSOLUTE) {
  push_stack((PC >> 8) & 0xFF);
  push_stack(PC & 0xFF);
  PC = fetch_next_address();
}
