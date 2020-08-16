[build-menu]
FT_00_LB=_Compile
FT_00_CM=g++ -Wall -std=c++17 -g -c *.cpp
FT_00_WD=
FT_01_LB=_Build
FT_01_CM=g++ -Wall -std=c++17 -g -o "%e" *.o -lsfml-graphics -lsfml-window -lsfml-system
FT_01_WD=
EX_01_LB=
EX_01_CM=
EX_01_WD=
