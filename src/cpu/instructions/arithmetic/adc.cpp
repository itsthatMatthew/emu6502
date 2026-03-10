#include "../../mos6502.hpp"

static void set_flags(mos6502& cpu, types::byte memory, types::word result) {
  cpu.set_flag(C, result > 0xFF);
  cpu.set_flag(Z, result == 0);
  cpu.set_flag(V, (result ^ cpu.AC) & (result ^ memory) & 0x80);
  cpu.set_flag(N, result & 0x80);
}

static void adc(mos6502& cpu, types::byte memory) {
  const types::word result = cpu.AC + memory + cpu.get_flag(C);
  set_flags(cpu, memory, result);
  cpu.AC = result & 0xFF;
}

INSTRUCTION(ADC, IMMEDIATE) {
  adc(*this, fetch<IMMEDIATE>());
}

INSTRUCTION(ADC, ZERO_PAGE) {
  adc(*this, fetch<ZERO_PAGE>());
}

INSTRUCTION(ADC, ZERO_PAGE_X) {
  adc(*this, fetch<ZERO_PAGE_X>());
}

INSTRUCTION(ADC, ABSOLUTE) {
  adc(*this, fetch<ABSOLUTE>());
}

INSTRUCTION(ADC, ABSOLUTE_X) {
  adc(*this, fetch<ABSOLUTE_X>());
}

INSTRUCTION(ADC, ABSOLUTE_Y) {
  adc(*this, fetch<ABSOLUTE_Y>());
}

INSTRUCTION(ADC, INDIRECT_X) {
  adc(*this, fetch<INDIRECT_X>());
}

INSTRUCTION(ADC, INDIRECT_Y) {
  adc(*this, fetch<INDIRECT_Y>());
}
