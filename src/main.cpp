#include "cpu/mos6502.hpp"

#include <cstdio>
#include <array>
#include <algorithm>

int main() {
  using namespace types;

  constexpr size_t MEMSIZE = 16;
  struct : i_memory {
    std::array<byte, MEMSIZE> m = {0};
    byte read(address a) const override {
      return m[a];
    }
    byte& ref(address a) override {
      return m[a];
    }
    void write(address a, byte v) override {
      m[a] = v;
    }
  } memory;
  mos6502 cpu(memory);
  
  auto printstuff = [&]() {
    static size_t cycle = 1;
    printf("\n%lu. cycle", cycle++);

    printf("[[CPU]]\n");
    printf("  A  [0x%0X]\n", cpu.A);
    printf("  X  [0x%0X]\n", cpu.X);
    printf("  Y  [0x%0X]\n", cpu.Y);
    printf("  S  [0x%0X]\n", cpu.S);
    printf("  PC [0x%0X]\n", cpu.PC);
    printf("  P  [0x%0X]\n", cpu.P);
    
    printf("[[STACK]]\n");
    constexpr int stack_eps = 3;
    for (int idx = std::max<int>(0, cpu.S - stack_eps); idx <= std::min<int>(MEMSIZE, cpu.S + stack_eps); idx++) {
      if (idx == cpu.S) printf ("> "); else printf("  ");
      printf("[0x%02X] 0x%02X\n", idx, memory[idx]);
    }

    printf("[[PROGRAM]]\n");
    constexpr int program_eps = 5;
    for (int idx = std::max<int>(0, cpu.PC - program_eps); idx <= std::min<int>(MEMSIZE, cpu.PC + program_eps); idx++) {
      if (idx == cpu.PC) printf ("> "); else printf("  ");
      printf("[0x%02X] 0x%02X\n", idx, memory[idx]);
    }
  };
  
  
  printf("Setting up MOS6502...\n");
  cpu.registers = {0, 0, 0, 0, 0, 0};

  printf("Setting up memory...\n");
  memory[0x00] = 0xA9; // LDA #$10 ; Load 16 to the accumulator
  memory[0x01] = 0x10; // 
  memory[0x02] = 0x69; // ADC #$01 ; Add 1 to the accumulator
  memory[0x03] = 0x01; //
  memory[0x04] = 0x85; // STA $07  ; Store the accumulator's value at memory
  memory[0x05] = 0x07; //          ; location 0x07 (observe on 4.c. when ran)
  memory[0x06] = 0x00; // BRK ; causes a memory exception for now, hence stops
  
  printf("Setup finished, starting execution...\n\n");
  printstuff();

  try {
    cpu.execute(printstuff);
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