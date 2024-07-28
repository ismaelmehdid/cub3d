<h1 align="center">
	🎮  CUB3D 🕹️
</h1>

## 💡 About the project

> This project is a reproduction of ``wolfenstein 3D`` in ``C`` using ``raycasting``.

### Instructions

**Compiling the game**

To compile, go to the project directory and run :

```shell
$ git submodule update --init --recursive
$ make
```

**Running the game**

```shell
./cub3d <path/to/map.cub>
```

The program takes a map file as an argument. Maps are available in the `game_data/maps` directory.
For example:

- `./cub3d game_data/maps/fun_map.cub` should run.

## Controls

Controls for movement and rotation are:

- `W`: move forward
- `S`: move backward
- `A`: strafe left
- `D`: strafe right
- `left arrow`: rotate left
- `right arrow`: rotate right
- `mouse`: rotate by moving the mouse (bonus only)

---
This project was developed collaboratively with [Andrii Syvash](https://github.com/redarling).
