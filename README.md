# FOC Actuator

This is a top level project tying together a complete package for my robotic actuators. It pins firmware, pcb designs, and CAD as submodules, maintaining individual history for each project while creating a hard link between versions. 

This project provides an authoritative source of truth defining what firmware, pcb revision, CAD hardware revisions, and C++ api belong together for a given actuator design. Branches label actuator configurations, which may be unstable or in progress. Commit tags with a version number in this repository generally indicate stable versions - i.e. a build which was actually used in something.

It is generally recommended to pin this submodule as a dependency in a project which uses it - for example, a top level robot repository, which might have monorepo style code for controller firmware, bootloaders, and PC software, would pin whatever version of this actuator was used as a submodule. 

## API

The API can be found under [api](api/). It depends on [dartt_audio](https://github.com/ocanath/dartt_audio), which also links [serial-cross-platform](https://github.com/ocanath/serial-cross-platform), [dartt](https://github.com/ocanath/dartt-protocol), and [byte-stuffing](https://github.com/ocanath/ - byte-stuffing), which are all also core dependencies.

## Firmware

The firmware can be found under [foc-code](foc-code/). You must initialize it after cloning with:

```bash
git submodule update --init foc-code
```

Or it will be empty.

## PCB

The pcb is pinned under [hp-foc-pcb](hp-foc-pcb/). You must initialize it after cloning:

The firmware can be found under [foc-code](foc-code/). You must initialize it after cloning:

```bash
git submodule update --init hp-foc-pcb
```

