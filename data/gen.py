import regex

MODES = [
    "accumulator",
    "absolute",
    "absolute,X",
    "absolute,Y",
    "immediate",
    "implied",
    "indirect",
    "(indirect,X)",
    "(indirect),Y",
    "relative",
    "zeropage",
    "zeropage,X",
    "zeropage,Y",
]

instructions = {}

with open("masswerk_nmos.txt", "r") as fobj:
    stage = 0
    last_instruction = None
    for line in fobj.read().split("\n"):
        if not line:
            continue
        if line[0] != " ":
            last_instruction = line.lower()
            instructions[last_instruction] = {}
            stage = 0
        elif line.startswith("    addressing"):
            stage = 1
        elif stage == 1:
            mode, _, opcode, _, _ = [x.strip() for x in line.split("\t")]
            instructions[last_instruction][mode] = opcode

# opcodes = {}
# for mnemonic, modes in instructions.items():
#     opcodes[mnemonic] = []
#     for mode in MODES:
#         if mode in modes:
#             code = f'0x{modes[mode]}'
#         else:
#             code = '____'
#         opcodes[mnemonic].append(code)

print('# Table generated from https://www.masswerk.at/6502/6502_instruction_set.html')
print('nmos:')
for mnemonic, modes in instructions.items():
    print(f'  - {mnemonic}:')
    for mode in MODES:
        if mode in modes:
            print(f'      {mode}: 0x{modes[mode].upper()}')

# print('const char *instructions[] = {');
# for mnemonic in opcodes:
#     print(f'    "{mnemonic}",');
# print('};')
# print()
# print(f'const byte opcodes[][{len(MODES)}] = {{');
# for codes in opcodes.values():
#     print(f'    {{{", ".join([x.ljust(4) for x in codes])}}},');
# print('};')
# # print(opcodes)
