#include "../../mos6502.hpp"

INSTRUCTION(BRK, IMPLIED) {
  (void)fetch_next_byte();
  push_stack((PC >> 8)& 0xFF);
  push_stack(PC & 0xFF);
  push_stack(SR | 0b00110000);
  PC = m_memory[IRQ_LB] + (m_memory[IRQ_HB] << 8);
}
