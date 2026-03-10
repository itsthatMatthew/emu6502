#include "../../mos6502.hpp"

INSTRUCTION(BRK, IMPLIED) {
  const types::word address = PC + 2;
  const types::byte low = address & 0xFF;
  const types::byte high = (address >> 8) & 0xFF;
  const processor_status flags = SR | 0b00110000;

  push_stack(high);
  push_stack(low);
  push_stack(flags);

  PC = m_memory[IRQ_LB] + (m_memory[IRQ_HB] << 8);
}
