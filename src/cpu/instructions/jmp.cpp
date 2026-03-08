#include "../mos6502.hpp"

INSTRUCTION(JMP, ABSOLUTE) {
  const types::address memory = fetch_next() + (fetch_next() << 8);
  PC = memory;
}

INSTRUCTION(JMP, INDIRECT) { throw "Not yet implemented operation"; }
