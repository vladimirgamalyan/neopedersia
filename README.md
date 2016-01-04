# neopedersia

[![Build Status](https://travis-ci.org/vladimirgamalian/neopedersia.svg)](https://travis-ci.org/vladimirgamalian/neopedersia)
[![Coverity Scan Build Status](https://scan.coverity.com/projects/5719/badge.svg)](https://scan.coverity.com/projects/5719)

<p align="center"><img src="bin/assets/doc/hero.png" /></p>

Nexus Wars style game.

## Status

The project is currently on the early stages of development, and is not yet playable.

## Building

Dependencies:

* cmake
* SDL2
* SDL2_image
* SDL2_ttf

The project also uses libSDL2pp, C++11 bindings library for SDL2.
It's included into git repository as a submodule, so if you've
obtained source through git, don't forget to run ```git submodule
init && git submodule update```.

Quickstart:
```
git clone https://github.com/vladimirgamalian/neopedersia.git
cd neopedersia
git submodule init && git submodule update
cmake && make
cd ./bin && ./neopedersia
```

## Author

* [Vladimir Gamalian](https://github.com/vladimirgamalian)

## License

[MIT License](http://opensource.org/licenses/MIT)

The project also bundles third party software under its own licenses:

* extlibs/SDL2pp (C++11 SDL2 wrapper library) - zlib license
