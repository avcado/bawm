# bawm
Minimalistic C Window Manager for the X11 Display Server

# Compiling/Running

## Compiling

### For Package Managers

If you're a packager and want to package `bawm` for your distro, make sure that
the binary from `bin/` is located in `/usr/local/bin/bawm` or `/usr/bin/bawm` (or `/bin/bawm`).

### Other

If you aren't a packager but want to run `bawm` on your desktop, do the following, but first read the advisory:

***NOTE:*** bawm WILL break from time to time.

If you're still wanting to run `bawm`, even with the advisory, do the following:

Compile:
```sh
$ make
mkdir: created directory 'bin'
Compiled!
$ sudo make install
'bin/bawm' -> '/usr/local/bin/bawm'
```

Setup `startx` to run bawm:
```sh
# If you want to overwrite your pre-existing file, use this
# (Useful if you're using a desktop environment)
echo "exec bawm" > ~/.xinitrc
cat ~/.xinitrc # Sanity check

# If you want to append it to a pre-existing file, use this:
# If you have to exec's, comment out any that are not exec bawm
echo "exec bawm" >> ~/.xinitrc
cat ~/.xinitrc # Sanity check
```

To run, see the section below.

## Running

To run bawm in X11, do the following:

- Make sure you've compiled bawm and installed it.
- Make sure you've put `exec bawm` in your `~/.xinitrc`. 
- Run `startx` 

# Dependencies


**For compiling:**
- (May be removed) libxdo
- libx11 (or, X11)

**For running with default config:**
- alacritty
- dmenu
