#include "../mos6502.hpp"

INSTRUCTION(BRK, IMPLIED) {
  const types::byte low = fetch_next();
  const types::byte high = fetch_next();
  const processor_status flags = P | 0b00110000;

  m_memory[S++] = high;
  m_memory[S++] = low;
  m_memory[S++] = flags;

  PC = 0xFFFE;
}
