# VFD Initialize (PT6312)

Arduino sketch that initializes a vacuum fluorescent display (VFD) driven by a
Princeton Technology **PT6312** controller. It clears the display memory,
selects the 5-digit / 16-segment mode, switches the display on at maximum
brightness and writes a test pattern to the first digit.

## Wiring

| PT6312 signal | Arduino pin |
|---|---|
| DIN/DOUT (data) | D2 |
| CLK (clock) | D3 |
| STB (strobe) | D4 |
| GND | GND |

The pins are defined at the top of the sketch (`DAT`, `CLK`, `STB`).

## Build and upload

Open `vfd_initialize/vfd_initialize.ino` in the Arduino IDE, select your board
(e.g. Arduino Uno or Nano) and upload. With
[Arduino CLI](https://arduino.github.io/arduino-cli/):

```bash
arduino-cli compile --fqbn arduino:avr:uno vfd_initialize
arduino-cli upload  --fqbn arduino:avr:uno -p /dev/ttyACM0 vfd_initialize
```

## Versioning

The project uses [Semantic Versioning](https://semver.org/): `MAJOR.MINOR.PATCH`.

- **MAJOR**: incompatible changes (e.g. different pins or display mode by default).
- **MINOR**: new functionality that keeps existing behaviour.
- **PATCH**: bug fixes.

The current version is the `VFD_INITIALIZE_VERSION` constant in the sketch.
All changes are listed in [CHANGELOG.md](CHANGELOG.md).

### Making a release

1. Move the entries under `[Unreleased]` in `CHANGELOG.md` to a new
   `[X.Y.Z] - YYYY-MM-DD` section and update the comparison links at the bottom.
2. Set `VFD_INITIALIZE_VERSION` in the sketch to `"X.Y.Z"`.
3. Commit, then tag and push:

   ```bash
   git tag -a vX.Y.Z -m "vX.Y.Z"
   git push origin vX.Y.Z
   ```

The **Release** workflow then checks that the tag matches the version in the
sketch and publishes a GitHub Release with that version's changelog section.

Without a terminal, replace step 3 with: commit the changes to `master`, then on
GitHub open **Actions → Release → Run workflow**, enter `X.Y.Z` and click
**Run workflow**. The workflow creates the `vX.Y.Z` tag on the latest `master`
commit and publishes the release.

## License

Copyright (C) 2014-2026 Elvis Baketa

This program is free software: you can redistribute it and/or modify it under
the terms of the GNU General Public License as published by the Free Software
Foundation, either version 3 of the License, or (at your option) any later
version (`GPL-3.0-or-later`).

This program is distributed in the hope that it will be useful, but WITHOUT
ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
FOR A PARTICULAR PURPOSE. See the [`LICENSE`](LICENSE) file for the full
license text.
