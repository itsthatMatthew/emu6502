#include "../mos6502.hpp"

INSTRUCTION(ADC, IMMEDIATE) {
  const types::address memory = fetch_next();
  const uint16_t result = A + memory + (P & C);
  
  A = result;
  
  set_flag(result > 0xFF, C);
  set_flag(result == 0, Z);
  set_flag((result ^ A) & (result ^ memory) & 0x80, V);
  set_flag(result & 0x80, N);
}

INSTRUCTION(ADC, ZERO_PAGE) { throw "Not yet implemented operation"; }
INSTRUCTION(ADC, ZERO_PAGE_X) { throw "Not yet implemented operation"; }
INSTRUCTION(ADC, ABSOLUTE) { throw "Not yet implemented operation"; }
INSTRUCTION(ADC, ABSOLUTE_X) { throw "Not yet implemented operation"; }
INSTRUCTION(ADC, ABSOLUTE_Y) { throw "Not yet implemented operation"; }
INSTRUCTION(ADC, INDIRECT_X) { throw "Not yet implemented operation"; }
INSTRUCTION(ADC, INDIRECT_Y) { throw "Not yet implemented operation"; }
