/**
 * SuperFX opcodes
 *   This table based on 33953YoShI's document.
 */
struct optcode opt_table[] = {

  { "ADC R*", 0x50, 1, ALT1 },
  { "ADC #*", 0x50, 2, ALT3 },
  { "ADD R*", 0x50, 1, ALT0 },
  { "ADD #*", 0x50, 2, ALT2 },
  { "ALT1", 0x3D, 0, ALT0 },
  { "ALT2", 0x3E, 0, ALT0 },
  { "ALT3", 0x3F, 0, ALT0 },
  { "AND R*", 0x70, 1, ALT0 },
  { "AND #*", 0x70, 2, ALT2 },
  { "ASR", 0x96, 0, ALT0 },

  { "BCC x", 0x0C, 3, ALT0 },
  { "BCS x", 0x0D, 3, ALT0 },
  { "BEQ x", 0x09, 3, ALT0 },
  { "BGE x", 0x07, 3, ALT0 },
  { "BIC R*", 0x70, 1, ALT1 },
  { "BIC #*", 0x70, 2, ALT3 },
  { "BLT x", 0x06, 3, ALT0 },
  { "BMI x", 0x0B, 3, ALT0 },
  { "BNE x", 0x08, 3, ALT0 },
  { "BPL x", 0x0A, 3, ALT0 },
  { "BRA x", 0x05, 3, ALT0 },
  { "BVC x", 0x0E, 3, ALT0 },
  { "BVS x", 0x0F, 3, ALT0 },

  { "CACHE", 0x02, 0, ALT0 },
  { "CMP R*", 0x60, 1, ALT3 },
  { "COLOR", 0x4E, 0, ALT0 },
  
  { "DEC R*", 0xE0, 1, ALT0 },
  { "DIV2", 0x96, 0, ALT1 },

  { "FMULT", 0x9F, 0, ALT0 },
  { "FROM R*", 0xB0, 1, ALT0 },

  { "GETB", 0xEF, 0, ALT0 },
  { "GETBH", 0xEF, 0, ALT1 },
  { "GETBL", 0xEF, 0, ALT2 },
  { "GETBS", 0xEF, 0, ALT3 },
  { "GETC", 0xDF, 0, ALT0 },

  { "HIB", 0xC0, 0, ALT0 },

  { "IBT R*,#x", 0xA0, 4, ALT0 },
  { "INC R*", 0xD0, 1, ALT0 },
  { "IWT R*,#?", 0xF0, 5, ALT0 },

  { "JMP R*", 0x90, 1, ALT0 },

  { "LDB R*", 0x40, 1, ALT1 },
  { "LDW R*", 0x40, 1, ALT0 },
  { "LINK #*", 0x90, 2, ALT0 },
  { "LJMP R*", 0x90, 1, ALT1 },
  { "LM R*,?", 0xF0, 6, ALT1 },
  { "LMS R*,?", 0xA0, 6, ALT1 },
  { "LMULT", 0x9F, 0, ALT1 },
  { "LOB", 0x9E, 0, ALT0 },
  { "LOOP", 0x3C, 0, ALT0 },
  { "LSR", 0x03, 0, ALT0 },

  { "MERGE", 0x70, 0, ALT0 },
  { "MOVE R*,R*", 0x1020, 9, ALT0 },
  { "MOVES R*,R*", 0xb020, 9, ALT0 },
  { "MULT R*", 0x80, 1, ALT0 },
  { "MULT #*", 0x80, 2, ALT2 },

  { "NOP", 0x01, 0, ALT0 },
  { "NOT", 0x4F, 0, ALT0 },

  { "OR R*", 0xC0, 1, ALT0 },
  { "OR #*", 0xC0, 2, ALT2 },

  { "PLOT", 0x4C, 0, ALT0 },

  { "RAMB", 0xDF, 0, ALT2 },
  { "ROL", 0x04, 0, ALT0 },
  { "ROMB", 0xDF, 0, ALT3 },
  { "ROR", 0x97, 0, ALT0 },
  { "RPIX", 0x4C, 0, ALT1 },

  { "SBC R*", 0x60, 1, ALT1 },
  { "SBK", 0x90, 0, ALT0 },
  { "SEX", 0x95, 0, ALT0 },
  { "SM R*,?", 0xF0, 6, ALT2 },
  { "SMS R*,?", 0xA0, 6, ALT2 },
  { "STB R*", 0x30, 1, ALT1 },
  { "STOP", 0x00, 0, ALT0 },
  { "STW R*", 0x30, 1, ALT0 },
  { "SUB R*", 0x60, 1, ALT0 },
  { "SUB #*", 0x60, 2, ALT2 },
  { "SWAP", 0x4D, 0, ALT0 },

  { "TO R*", 0x10, 1, ALT0 },

  { "UMULT R*", 0x80, 1, ALT1 },
  { "UMULT #*", 0x80, 2, ALT3 },

  { "WITH R*", 0x20, 1, ALT0 },

  { "XOR R*", 0xC0, 1, ALT1 },
  { "XOR #*", 0xC0, 2, ALT3 },

  { "E", 0x100, -1, 0 }
};

