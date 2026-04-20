# SBV: Super-Simple Binary Viewer

SBV is a super-simple binary viewer written in C++. It is designed to be a minimalistic tool for viewing binary files in a human-readable format. SBV can read from both files and standard input, making it versatile for various use cases.

## Sample

```
binary-viewer > ./build/src/sbv helloworld.txt
Offset    +0 +1 +2 +3 +4 +5 +6 +7 +8 +9 +A +B +C +D +E +F  ASCII
00000000  48 65 6c 6c 6f 2c 20 57 6f 72 6c 64 0a           Hello, World.
```

```
binary-viewer > cat helloworld.txt | ./build/src/sbv
Offset    +0 +1 +2 +3 +4 +5 +6 +7 +8 +9 +A +B +C +D +E +F  ASCII
00000000  48 65 6c 6c 6f 2c 20 57 6f 72 6c 64 0a           Hello, World.
```

## Build (Out-of-Source)

```sh
cmake -G Ninja -B build
cmake --build build
```
