#include "../mos6502.hpp"

INSTRUCTION(STA, ZERO_PAGE) {
  const types::byte memory = fetch_next();
  m_memory[memory] = A;
}
INSTRUCTION(STA, ZERO_PAGE_X) { throw "Not yet implemented operation"; }
INSTRUCTION(STA, ABSOLUTE) { throw "Not yet implemented operation"; }
INSTRUCTION(STA, ABSOLUTE_X) { throw "Not yet implemented operation"; }
INSTRUCTION(STA, ABSOLUTE_Y) { throw "Not yet implemented operation"; }
INSTRUCTION(STA, INDIRECT_X) { throw "Not yet implemented operation"; }
INSTRUCTION(STA, INDIRECT_Y) { throw "Not yet implemented operation"; }
