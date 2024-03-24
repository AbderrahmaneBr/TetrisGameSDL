# TetrisGameSDL
<h2>A. Set up Environment</h2>
<ol>
<li><b>Download Cmake:</b></li>
<b>https://cmake.org/download/</b>
<br><br>
<li><b>Clone SDL2 Repo:</b></li>
  
```bash
git clone https://github.com/libsdl-org/SDL.git -b SDL2
```

<li>Open Terminal <b style="color:#0e0e0e;">AS ADMINISTRATOR!</b></li>
  
```bash
cd SDL
md build
cd build
cmake .. -G "MinGW Makefiles"
mingw32-make install
```

</ol>
<h2>B. Working On Project</h2>
<ol>
<li><b>Clone this repo:</b></li>

```bash
git clone https://github.com/AbderrahmaneBr/TetrisGameSDL.git
```

<li>Build Project using CMake</li>
  
```bash
cd TetrisGameSDL
md build
cd build
cmake .. -DCMAKE_C_COMPILER=gcc -DCMAKE_CXX_COMPILER=g++ -G "Unix Makefiles"
cmake --build .
.\TetrisGame.exe
```

</ol>
