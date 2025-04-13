# 🐚 Crafting Custom Shellcode in x64 Assembly (Windows)

## 🎥 Watch the Video

[![Watch the video](https://img.youtube.com/vi/9-CgePQP9Io/hqdefault.jpg)](https://www.youtube.com/watch?v=9-CgePQP9Io)

This is **Episode 1** of the **Windows Shellcoding Series** — stay tuned for more advanced topics!

---

This folder contains the source code and resources used in my YouTube video:
**"Crafting Custom Shellcode In x64 Assembly"**, the **first episode** of the *Windows Shellcoding Series*.

In this video, I demonstrate how to write a custom shellcode in 64-bit assembly for Windows that executes `calc.exe` using a direct call to `WinExec`.

---

## 🧠 What You’ll Learn

- Writing custom x64 shellcode for Windows
- Resolving Windows API addresses at runtime
- Converting and reversing strings to push into the stack
- Using `nasm` to assemble assembly code
- Extracting raw opcodes with `objdump`
- Running the shellcode with a C shellcode runner

---

## 📂 File Overview

```
.
├── shellcode.asm             # Custom x64 assembly calling WinExec
├── findaddr.c                # Finds WinExec address at runtime
├── hexdeal.py                # Hex manipulation tool (imported from HexDeal repo)
├── shellcode-extract.py      # Shellcode Extractor (imported from Shellcode-Extractor repo)
├── exec.c                    # C-based shellcode runner
└── README.md                 # This file
```

---

## 🧩 Tools Used

### 🔍 `findaddr.c`

A simple C program to find the memory address of `WinExec`, to hardcode it.

```cmd
gcc findaddr.c -o findaddr.exe
./findaddr.exe
```

---

### 🧪 `hexdeal.py`

Used to convert the string `"calc.exe"` to hexadecimal and reverse it, so it can be pushed onto the stack in the correct order.

Get it here: [https://github.com/Sayan690/HexDeal](https://github.com/Sayan690/HexDeal)

Example:

```cmd
python3 hexdeal.py hex "calc.exe" -rev
```

---

### ⚙️ `nasm` & `objdump`

Assemble your shellcode with:

```cmd
nasm -f win64 shellcode.asm -o shellcode.o
```

Extract opcodes:

```cmd
objdump -d shellcode.o | python3 shellcode-extract.py
```

---

### 📦 Shellcode-Extractor

This tool is used to neatly extract raw shellcode from the binary output.

Repo: [https://github.com/Neetx/Shellcode-Extractor](https://github.com/Neetx/Shellcode-Extractor/blob/master/shellcode_extractor.py)

---

### 🚀 `exec.c`

A minimal C shellcode runner that executes the assembled and extracted shellcode.

Compile and run:

```cmd
gcc exec.c -o exec.exe
./exec.exe
```

---

## 📜 License

MIT License  
(c) 2025 Sayan
