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
  memory[0x00] = 0xA9;
  memory[0x01] = 0x10;
  memory[0x02] = 0x69;
  memory[0x03] = 0x01;
  memory[0x04] = 0x85;
  memory[0x05] = 0x0F;
  
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