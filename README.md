# Battleship Game

A console Battleship game written in C++.

## Features

- 10x10 board with row and column labels.
- Single player mode against a randomly generated opponent.
- Local multiplayer mode with two players, ship selection, manual placement, alternating turns, and win detection.
- Input validation for menu choices, coordinates, repeated shots, ship overlap, invalid direction, and ships outside the board.
- Unit tests for the core models.

## Board

- `~` hidden position
- `o` missed shot
- `<`, `=`, `>` ship pieces revealed by hits

Rows and columns use values from `0` to `9`.

## Build

Using MSYS2 Bash from PowerShell:

```powershell
& 'C:\msys64\usr\bin\bash.exe' scripts/compile.sh
```

Or compile directly with g++:

```powershell
& 'C:\msys64\ucrt64\bin\g++.exe' -g src\main.cpp src\Models\Grid\Grid.cpp src\Models\Player\Player.cpp src\Models\Position\Position.cpp src\Models\Ship\Ship.cpp -o src\battleship.exe
```

## Run

```powershell
.\src\battleship.exe
```

During a turn, type `q` for any coordinate to quit the current match.

## Tests

Compile and run tests with:

```powershell
& 'C:\msys64\usr\bin\bash.exe' scripts/compile_tests.sh
& 'C:\msys64\usr\bin\bash.exe' scripts/test.sh
```

The tests cover `Grid`, `Position`, `Player`, and `Ship`.
