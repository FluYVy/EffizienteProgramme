set mypath=%cd%
cd %mypath%\cc65\bin
cl65 -t c64 -o %mypath%\conway.prg %mypath%\conway.c
cd %mypath%\Vice\bin
x64dtv %mypath%\conway.prg