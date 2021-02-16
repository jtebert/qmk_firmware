# Julia Ebert's Preonic Layout

Build it:

```shell
make preonic/rev3:jtebert
```

This will generate the hex file: `.build/preonic_rev3_jtebert.bin`

Install it:

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