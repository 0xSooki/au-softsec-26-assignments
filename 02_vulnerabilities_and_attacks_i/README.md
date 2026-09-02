# Assignment 2

In this assignment you are required to perform [Stack-based Buffer Overflow (CWE-121)](https://cwe.mitre.org/data/definitions/121.html).

## Preliminaries

This excercise requires a Linux environment with `gcc`.

```sh
sudo apt install build-essential    # on Debian, Ubuntu, etc.
sudo pacman -S base-devel           # on Arch Linux, Manjaro, etc.
```

Alternatively, if you are on a Windows machine, you can use a virtual machine, WSL or Docker. We have provided devcontainers for this purpose, which you can use with [VS Code](https://code.visualstudio.com/docs/remote/containers) or GitHub Codespaces and includes all necessary tools in order to solve the assignments.

## Learning Objectives

- Understand the stack layout of a function call: buffers, saved base pointer, saved return address.
- Overflow a stack buffer to overwrite the saved return address.
- Redirect execution to a function that is never called.

## Tasks

1. Find the address of the `win` function
2. Determine exactly how many bytes of input comes before the return address.
3. Exploit the buffer overflow by crafting a payload that replaces the return address with the address of `win`.

Consider the program `vuln.c`:

```c
#include <stdio.h>
#include <stdlib.h>

void win() {
    printf("You won! Flag: FLAG{ret2win_overwrite_the_return_address}\n");
    fflush(stdout);
}

void vuln() {
    char buf[64];
    printf("Enter your name: ");
    scanf("%s", buf);
    printf("Hello, %s\n", buf);
}

int main(void) {
    setvbuf(stdout, NULL, _IONBF, 0);
    vuln();
    return 0;
}
```

The goal is to execute `win`, **without modifying the source code**. Thus, you **cannot** make edits to the given program, but rather overwrite the programs return address to the address of the `win` function.

The target can be compiled **with mitigations disabled** using:

```bash
gcc -fno-stack-protector -no-pie -o vuln vuln.c
./vuln
```

where `-fno-stack-protector` removes the stack canary, `-no-pie` fixes the code at a known address so the functions address doesn't change in-between runs.

Raw bytes can be feed to the program using `printf`, `python` or `echo` and the pipe operator.

```sh
python -c "import os; os.write(1, b'AAAAA\x00\x00\x00')" | ./vuln
echo -en "AAAAA\x00\x00\x00" | ./vuln
printf 'AAAAA\x00\x00\x00' | ./vuln
```

<details>
<summary>Hint</summary>

The command [`objdump -M intel -d {binary name here}`](https://man.archlinux.org/man/objdump.1) disassembles the binary, showing its assembly code in Intel syntax.

</details>

### Report

In 1–3 sentences each: What was your approach? What was your command that exploited the stack overflow? How did you find the offset? What happens without `-fno-stack-protector` and/or without `-no-pie`?

### What to submit

- The report answering the questions above.
