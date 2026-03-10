#include "cpu/mos6502.hpp"

#include <cstdio>
#include <array>
#include <algorithm>

int main() {
  using namespace types;

  constexpr size_t MEMSIZE = 0xFFFF + 1; // 0xFFFF should be a valid address
  struct : i_memory {
    std::array<byte, MEMSIZE> m = {0};
    byte read(word a) const override {
      return m.at(a);
    }
    byte& ref(word a) override {
      return m.at(a);
    }
    void write(word a, byte v) override {
      m.at(a) = v;
    }
  } memory;

  printf("Setting up memory...\n");
  memory[0xE000] = 0xA9; // LDA #$10 ; Load 16 to the accumulator
  memory[0xE001] = 0x10; // 
  memory[0xE002] = 0x69; // ADC #$01 ; Add 1 to the accumulator
  memory[0xE003] = 0x01; //
  memory[0xE004] = 0x8D; // STA $E00A ; Store the accumulator's value at memory
  memory[0xE005] = 0x0A; //           ; location 0xE00A
  memory[0xE006] = 0xE0; //
  memory[0xE007] = 0x4C; // JMP $E002 ; jump back to adding 1 to the accumulator
  memory[0xE008] = 0x02; //
  memory[0xE009] = 0xE0; //

  memory[mos6502::RES_LB] = 0x00; // Reset vector set to address 0xE000
  memory[mos6502::RES_HB] = 0xE0;
  memory[mos6502::IRQ_LB] = 0x00; // Interrupt vector as well (for now)
  memory[mos6502::IRQ_HB] = 0xE0; // Could be triggered by BRK (0x00)
  
  printf("Setting up MOS6502...\n");
  mos6502 cpu(memory);
  
  auto simple_debugger = [&]() {
    static size_t cycle = 1;
    printf("\n%lu. cycle\n", cycle++);

    printf("[[CPU]]\n");
    printf("  AC [0x%02X]\n", cpu.AC);
    printf("  X  [0x%02X]\n", cpu.X);
    printf("  Y  [0x%02X]\n", cpu.Y);
    printf("  SP [0x%02X]\n", cpu.SP);
    printf("  PC [0x%04X]\n", cpu.PC);
    printf("  SR [0x%02X]\n", cpu.SR);
    
    printf("[[STACK]]\n");
    constexpr int stack_eps = 3;
    for (int idx = std::max<int>(0, cpu.SP - stack_eps); idx <= std::min<int>(255, cpu.SP + stack_eps); idx++) {
      if (idx == cpu.SP) printf ("> "); else printf("  ");
      printf("[0x%04X] 0x%02X\n", idx + (0x01 << 8), memory[idx + (0x01 << 8)]);
    }

    printf("[[PROGRAM]]\n");
    constexpr int program_eps = 5;
    for (int idx = std::max<int>(0, cpu.PC - program_eps); idx <= std::min<int>(MEMSIZE - 1, cpu.PC + program_eps); idx++) {
      if (idx == cpu.PC) printf ("> "); else printf("  ");
      printf("[0x%04X] 0x%02X\n", idx, memory[idx]);
    }

    getchar();
  };

  printf("Setup finished, starting execution...\n\n");
  simple_debugger();

  try {
    cpu.execute(simple_debugger);
  }
  catch (const std::exception& e) {
    printf("%s\n", e.what());
  }
  catch(const char* str) {
    printf("%s\n", str);
  }
  catch(...) {
    printf("Unknown error occoured.\n");
  }

  return 0;
}