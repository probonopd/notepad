#!/bin/bash
mkdir Notepad.AppDir
wget https://github.com/AppImage/AppImageKit/releases/download/11/AppRun-x86_64 -O Notepad.AppDir/AppRun
cp notepad.desktop Notepad.AppDir
mkdir Notepad.AppDir/bin
cp build/bin/notepad Notepad.AppDir/bin
mkdir Notepad.AppDir/share
cp -r build/bin/translations Notepad.AppDir/share/translations
cp LICENSE Notepad.AppDir/share
cp notepad.svg Notepad.AppDir
wget https://github.com/AppImage/AppImageKit/releases/download/11/appimagetool-x86_64.AppImage
chmod +x appimagetool-x86_64.AppImage
./appimagetool-x86_64.AppImage Notepad.AppDir
