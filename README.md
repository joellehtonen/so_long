# so_long

A simple top-down 2D game built in C using the MLX42 graphics library. The first game project from the [42 / Hive School](https://www.hive.fi) curriculum.

## Table of Contents

- [Overview](#overview)
- [Features](#features)
- [Project Structure](#project-structure)
- [Requirements](#requirements)
- [Installation](#installation)
- [Usage](#usage)
- [Controls](#controls)
- [Map Format](#map-format)
- [What I Learned](#what-i-learned)
- [What I Would Do Differently](#what-i-would-do-differently)
- [License](#license)

---

## Overview

So Long is a top-down 2D game where the player must collect all collectibles on the map and reach the exit. The game features smooth (non-tile-based) player movement, animated sprites, enemy AI, and configurable maps parsed from `.ber` files.

## Features

- Smooth, non-tile-based player movement in a tile-based world
- Sprite animations for the player character
- Enemy AI with patrol and chase behavior
- Map parsing and validation from `.ber` scene files
- Collectible and exit game loop
- Move counter displayed during gameplay
- Bonus mode with additional features

## Project Structure

```
so_long/
├── MLX42/        # Graphics library (submodule)
├── bonus/        # Bonus mode source files
├── library/      # Custom C standard library (libft)
├── maps/         # Map files (.ber)
├── sources/      # Core game source files
├── textures/     # Sprite and tile textures
└── Makefile
```

## Requirements

- GCC or Clang
- Make
- CMake (for building MLX42)
- OpenGL and GLFW (required by MLX42)

Install dependencies on Debian/Ubuntu:

```bash
sudo apt install cmake libglfw3-dev libgl1-mesa-dev
```

On macOS (with Homebrew):

```bash
brew install cmake glfw
```

## Installation

Clone the repository (including submodules):

```bash
git clone --recurse-submodules https://github.com/joellehtonen/so_long.git
cd so_long
make
```

To build the bonus version:

```bash
make bonus
```

## Usage

Run the program with a `.ber` map file as an argument:

```bash
./so_long maps/simple.ber
```

## Controls

| Key | Action |
|-----|--------|
| `W` | Move up |
| `A` | Move left |
| `S` | Move down |
| `D` | Move right |
| `Esc` | Quit |

Collect all the chickens on the map, then reach the exit!

## Map Format

Maps are defined in `.ber` files using a simple grid format:

```
1111111111
1P0C000001
100011C001
1C0E000001
1111111111
```

| Character | Meaning |
|-----------|---------|
| `1` | Wall |
| `0` | Empty space |
| `P` | Player start position |
| `C` | Collectible |
| `E` | Exit |

The map must be rectangular and fully enclosed by walls, contain exactly one player start, at least one collectible, and exactly one exit.

## What I Learned

- This was my first graphical project, so learning to use MLX42 from scratch was a core part of the experience
- I wanted player movement to feel smooth rather than tile-snapped like many of my peers implemented, so I had to figure out a way to make fluid movement work within a fundamentally tile-based world
- Animation took surprisingly long to get right, but it's one of those things I could spend endless time tinkering with — and I'm happy with how it turned out
- Map parsing and validation was a significant and important part of the project
- Designing the enemy behavior — how it moves, how threatening to make it, how to give the player a fair chance to outsmart it — took real thought, and I'm satisfied with the results

## What I Would Do Differently

Honestly, not much. It turned out pretty great. I would love to expand it further, but the project subject set many restrictions around what was allowed.

## License

This project was developed as part of the 42 / Hive School curriculum. No license is explicitly provided.
