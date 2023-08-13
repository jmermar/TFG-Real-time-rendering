call build.bat %1

SET PATH=%PATH%;${pwd}

build\%1\rasterizer.exe