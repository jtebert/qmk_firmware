# Artemis 75

![Artemis 75](https://i.imgur.com/285lQp8.jpg)

This is a handwired 75% ortholinear keyboard (15 x 6 grid).

This is configured with both Colemak (default) and QWERTY layouts, with a shortcut to switch between them. Each layout also features a function layer and emoji layer.

It was made as a final project for Harvard's Physics 223: Electronics for Scientists, by Julia Ebert and Jennifer Shum. The default layout is incredibly personalized, to the point that it's probably not useful for most people. But it does feature an entire layer dedicated to emoji! You can read about the design and creation of this board [on my documentation website](https://docs.juliaebert.com/projects/keyboard).

## Known issues and planned additions:

- If you are using the layout set as Colemak on the keyboard (and keeping QWERTY on the OS side), this sometimes causes weird issues (in particular programs) with mis-mapped key combos. (For example, typing `Ctrl`+`s` on the Colemak keyboard comes out as `Ctrl`+`r`.) Still working on figuring out why this happens and how to solve it.
- Some of the unicode input can be replaced with AltGr/dead key implementations (which are OS-independent). This should be possible using the international options in `keymap_extras`
- I don't know if the layout metadata in `info.json` isn't correct
- US Flag unicode doesn't work in some programs (2nd character overwriting 1st character) (ex: works in Gedit but not VS Code)
- Eventually I want to add keyboard shortcuts/layers for improved international character input (basically Colemak AltGr keys entirely on the keyboard, not needing to rely on OS having dead keys)

## Use and Support

* Keyboard Maintainer: [Julia Ebert](https://github.com/jtebert) ([julia@juliaebert.com](mailto:julia@juliaebert.com))
* Hardware Supported: Handwired, Teensy 2.0
* Hardware Availability: Bill of materials available [in the keyboard build guide](https://docs.juliaebert.com/projects/keyboard#bill-of-materials)

Make example for this keyboard (after setting up your build environment):

    make artemis75:default

See the [build environment setup](https://docs.qmk.fm/#/getting_started_build_tools) and the [make instructions](https://docs.qmk.fm/#/getting_started_make_guide) for more information. Brand new to QMK? Start with our [Complete Newbs Guide](https://docs.qmk.fm/#/newbs).

