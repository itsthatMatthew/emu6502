#include "../mos6502.hpp"

INSTRUCTION(JMP, ABSOLUTE) {
  PC = fetch_next_address();
}

INSTRUCTION(JMP, INDIRECT) { 
  const types::word pointer_low = fetch_next_byte();
  const types::word pointer_high = fetch_next_byte();
  const types::word low = m_memory[(pointer_high << 8) + pointer_low];
  const types::word high = m_memory[(pointer_high << 8) + (pointer_low + 1) % 256];
  PC = (high << 8) + low;
 }
