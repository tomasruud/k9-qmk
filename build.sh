#!/bin/sh
git submodule update --init --recursive

dest="qmk_firmware/keyboards/keychron/k9_pro/ansi/rgb/keymaps/tomasruud"

rm -rfd $dest
mkdir -p $dest
cp keymap.c $dest/keymap.c

(cd qmk_firmware && util/docker_build.sh keychron/k9_pro/ansi/rgb:tomasruud)

rm -rfd $dest

rm -f keychron_k9_pro_ansi_rgb_tomasruud.bin
mv qmk_firmware/keychron_k9_pro_ansi_rgb_tomasruud.bin .
