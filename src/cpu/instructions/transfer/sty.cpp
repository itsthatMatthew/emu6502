#include "../../mos6502.hpp"

INSTRUCTION(STY, ZERO_PAGE) {
  store<ZERO_PAGE>(Y);
}

INSTRUCTION(STY, ZERO_PAGE_X) {
  store<ZERO_PAGE_X>(Y);
}

INSTRUCTION(STY, ABSOLUTE) {
  store<ABSOLUTE>(Y);
}
