# SigSTP tasks

Author: Yaksh Bariya
GitHub: https://github.com/thunder-coding


## Project Structure

```
.
├── build            # The build output will go here
├── screenshots      # Screenshots for all the tasks output
├── CMakeLists.txt   # CMake build recipe for the project
├── README.md        # :-)  You are here right now  (-:
├── Task-1           # Solution for Task-1
├── Task-2           # Solution for Task-2
└── Task-3           # Solution for Task-3
```


## Building

In order to build this project, you need CMake for the build generation. Make/Ninja for the build process. I would recommend Ninja as it is faster than Make. A C++ compiler supporting atleast C++20 is required (GCC/LLVM Clang)

On any Ubuntu/Debian box, these can be installed using:

```sh
sudo apt install cmake ninja-build clang
```

On Arch Linux/derivatives:
```sh
sudo pacman -S cmake ninja clang
```

On Windows:
```sh
# I have no idea, since it's been atleast 3 years since I have used Windows
# I guess installing a new version of mingw, CMake and ninja should do the work.
# CMake: https://cmake.org/download/
# Ninja: https://github.com/ninja-build/ninja/releases
```

The actual build:
```sh
cd /path/to/this/directory
# Generate the build files
cmake . -B build -G Ninja            # If using Ninja
cmake . -B build -G "Unix Makefiles" # If using Make
# Now do the actual build
ninja -C build/                      # If using Ninja
make -C build/                       # If using Make
```



## Running

After the build is completed successfully, the compiled binaries should be available in `./build`.

- `./build/Task-1` is the compiled solution for Task 1
- `./build/Task-2` is the compiled solution for Task 2
- `./build/Task-3` is the compiled solution for Task 3



## Tests

Each task directory does contain some small tests to ensure that the code is working as expected. In order to make sure the tests work, each solution is compiled as a static library, then the final executable is linked to it. The `./build` directory also contains the test runners for each Task

- `./build/Task-1-Tasks` is the compiled tests for Task 1
- `./build/Task-2-Tasks` is the compiled tests for Task 2
- `./build/Task-3-Tasks` is the compiled tests for Task 3