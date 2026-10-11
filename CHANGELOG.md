# Changelog

All notable changes to this project are documented in this file.

The format is based on [Keep a Changelog](https://keepachangelog.com/en/1.1.0/),
and this project adheres to [Semantic Versioning](https://semver.org/spec/v2.0.0.html).

## [Unreleased]

## [1.0.1] - 2026-10-11

### Added

- GNU GPL v3 (`GPL-3.0-or-later`) license and SPDX headers.
- `VFD_INITIALIZE_VERSION` constant in the sketch as the single source of the
  version number.
- README with wiring, build and release instructions.
- GitHub Actions workflow that compiles the sketch for Arduino Uno and Nano.
- GitHub Actions workflow that publishes a GitHub Release for a `vX.Y.Z` tag,
  or creates the tag and release when started manually from the Actions tab,
  after checking that the version matches the sketch.

### Fixed

- The sketch did not compile: `startAddres` was misspelled and the
  `updateFixedAddres()` call in `setup()` was missing its semicolon.

## [1.0.0] - 2014-04-18

### Added

- First release: PT6312 VFD initialization (5 digits, 16 segments), display
  memory clearing, maximum brightness and a fixed-address write of a test
  pattern.

[Unreleased]: https://github.com/ebaketa/vfd_initialize/compare/v1.0.1...HEAD
[1.0.1]: https://github.com/ebaketa/vfd_initialize/compare/v1.0.0...v1.0.1
[1.0.0]: https://github.com/ebaketa/vfd_initialize/releases/tag/v1.0.0
