#include "mos6502.hpp"

mos6502::mos6502(i_memory& memory) : m_memory(memory) {
  SP = 0xFF;
  PC = RES_LB;
  JMP<ABSOLUTE>();
}

void mos6502::set_flag(processor_status_flags flag, bool condition) {
  if (condition) SR |= flag;
  else SR &= ~flag;
}
processor_status mos6502::get_flag(processor_status_flags flag) const {
  return SR & flag;
}

void mos6502::push_stack(types::byte value) {
  m_memory[STACK_PAGE + SP--] = value;
}

types::byte mos6502::pop_stack() {
  return m_memory[STACK_PAGE + ++SP];
}
