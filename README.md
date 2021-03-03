# bawm
Minimalistic C Window Manager for the X11 Display Server

# Is bawm in [insert distro]'s repo?

#### ***This is temporary, as I haven't added support with repology***

- [X] Arch Linux
- [ ] Gentoo
- [ ] Ubuntu
- [ ] Debian
- [ ] Void
- [ ] Solus
- [ ] Fedora
- [ ] RHEL


# Compiling/Running

## Compiling

If you aren't a packager but want to run `bawm` on your desktop, do the following, but first read the advisory:

***NOTE:*** bawm WILL break from time to time.

If you're still wanting to run `bawm`, even with the advisory, do the following:

Compile:
```sh
$ autoreconf
$ automake --add-missing
$ ./configure
$ make
$ sudo make install # A work in progress,
# I think it'll be working by 0.3(?)
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

If you want to start `bawm` from a display manager, put this in `bawm.desktop`:
```
[Desktop Entry]
Type=Application
Version=0.2
Name=bawm
Comment=The Worst Window Manager
Path=[wherever you installed it]
Exec=bawm
```

To run, see the section below.

## Running

To run bawm in X11, do the following:

- Make sure you've compiled bawm and installed it.
- Make sure you've put `exec bawm` in your `~/.xinitrc`. 
- Run `startx` 

# Dependencies


**If you do not want to install through your**
**package manager, or are creating a packge, you need:**

**For compiling:**
- libx11 (or, X11)
- gcc
- autotools/automake


# Community

IRC? No

Matrix? No

Discord? [Yes!](https://discord.gg/gkj93pRtzK)
