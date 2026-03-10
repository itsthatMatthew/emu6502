#include "../mos6502.hpp"

INSTRUCTION(LDA, IMMEDIATE) {
  const types::byte result = fetch_next_byte();
  set_flag(Z, result == 0);
  set_flag(N, result & 0x80);
  AC = result;
}

INSTRUCTION(LDA, ZERO_PAGE) { throw "Not yet implemented operation"; }
INSTRUCTION(LDA, ZERO_PAGE_X) { throw "Not yet implemented operation"; }
INSTRUCTION(LDA, ABSOLUTE) { throw "Not yet implemented operation"; }
INSTRUCTION(LDA, ABSOLUTE_X) { throw "Not yet implemented operation"; }
INSTRUCTION(LDA, ABSOLUTE_Y) { throw "Not yet implemented operation"; }
INSTRUCTION(LDA, INDIRECT_X) { throw "Not yet implemented operation"; }
INSTRUCTION(LDA, INDIRECT_Y) { throw "Not yet implemented operation"; }
