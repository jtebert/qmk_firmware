# Julia Ebert's Preonic Layout

Build it:

```shell
make preonic/rev3:jtebert
```

This will generate the hex file: `.build/preonic_rev3_jtebert.bin`

I don't have the board yet to test flashing it. According to the Preonic readme (one level up), run:

```shell
make preonic/rev3:jtebert:dfu-util
```

---

## Setup

```shell
./util/qmk_install.sh
make git-submodule
```

I also had to install the following dependencies to get it to compile:

```shell
sudo apt install dfu-util gcc-arm-none-eabi
```

## TODO

- Fix follower/non-master hand not showing correct persistent layer
- Add reset key for each half (currently only on lefts)
- There's a useless "RGB_TOG" key (left hand).