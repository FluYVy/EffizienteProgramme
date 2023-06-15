**Aufgabe 5: Effiziente Programme**
# <a name="_toc137737015"></a>**Inhalt**
[Inhalt	1](#_toc137737015)

[1.	Originale Code – 29.03.2023	2](#_toc137737016)

[2.	If-Optimierung (1) – 29.03.2023	2](#_toc137737017)

[3.	Flag: int zu bool – 29.03.2023	3](#_toc137737018)

[4.	Array: int zu char – 29.03.2023	4](#_toc137737019)

[5.	Lebende: int zu char – 29.03.2023	4](#_toc137737020)

[6.	If-Optimierung (2) – 29.03.2023	5](#_toc137737021)

[7.	zaehlLebende geändert – 29.03.2023	5](#_toc137737022)

[8.	PrintSpielfeld geändert – 29.03.2023	6](#_toc137737023)

[9.	PrüfeRegeln und FindNachbarn geändert – 29.03.2023	7](#_toc137737024)

[10.	Spielfeld: int zu char array – 30.03.2023	8](#_toc137737025)

[11.	Nachbarn und Temp: int zu char – 30.03.2023	8](#_toc137737026)

[12.	Ersetzung der restlichen ints – 30.03.2023	9](#_toc137737027)

[13.	Text und Zahlenausgabe deaktiviert – 19.04.2023	9](#_toc137737028)

[14.	Memcpy bearbeitet und zusätzlich verwendet – 19.04.2023	10](#_toc137737029)

[15.	prüfeRegeln, zaehlLebende und findNachbarn zusammengeführt – 03.05.2023	10](#_toc137737030)

[16.	FindNachbarn: iy und ix wurden gelöscht – 11.05.2023	12](#_toc137737031)

[17.	findNachbarn optimierung – 11.05.2023	13](#_toc137737032)

[18.	Datentypen wurden angepasst – 11.05.2023	13](#_toc137737033)

[19.	Nachbarn wird nicht übergeben – 11.05.2023	14](#_toc137737034)

[20.	Run.bat bearbeitet – 11.05.2023	14](#_toc137737035)

[21.	Dateitypen bearbeitet (2) – 15.05.2023	15](#_toc137737036)

[22.	Alle Funktionen in main gefügt – 14.06.2023	15](#_toc137737037)

[23.	getNeighbours wurde überarbeitet – 14.06.2023	18](#_toc137737038)

[24.	Displayausgabe überarbeitet – 14.06.2023	19](#_toc137737039)




1. # <a name="_toc137737016"></a>**Originale Code – 29.03.2023**
FPS: 0,0179

Zeit: 56 Sekunden

Prozentuelle Verbesserung: 0%

Beschreibung:

Der Vorgegebene Originale Code ohne Veränderungen. Hier wurde gelernt wie man das Programm bearbeiten, kompilieren und ausführen kann.


1. # <a name="_toc137737017"></a>**If-Optimierung (1) – 29.03.2023**
FPS: 0,0186

Zeit: 53,8 Sekunden

Prozentuelle Verbesserung: 3,929%

**Beschreibung:**

Mehrere If-Abfragen in der Funktion pruefeRegeln wurden zu einem Switch zusammengefasst.

**Codeausschnitte:**

|Vorher|Nachher|
| :- | :- |
|<p>if(spielfeld[x][y] == 1){</p><p>`	`if(lebende == 2){</p><p>`		`temp[x][y] = 1;</p><p>`	`}</p><p>}</p><p>if(spielfeld[x][y] == 1){</p><p>`	`if(lebende == 3){</p><p>`		`temp[x][y] = 1;</p><p>`	`}</p><p>}</p><p>if(spielfeld[x][y] == 1){</p><p>`	`if(lebende < 2){</p><p>`		`temp[x][y] = 0;</p><p>`	`}</p><p>}</p><p>if(spielfeld[x][y] == 1){</p><p>`	`if(lebende > 3){						temp[x][y] = 0;</p><p>`	`}</p><p>}</p>|<p>if(spielfeld[x][y] == 1){</p><p>`	`switch(lebende == 2){</p><p>`		`case 2:</p><p>`			`temp[x][y] = 1;</p><p>`			`break;</p><p>`		`case 3:</p><p>`			`temp[x][y] = 1;</p><p>`			`break;</p><p>`	`}</p><p></p><p>`	`if(lebende < 2){</p><p>`		`temp[x][y] = 0;</p><p>`	`}</p><p>`	`if(lebende > 3){						temp[x][y] = 0;</p><p>`	`}</p><p>}</p>|


1. # <a name="_toc137737018"></a>**Flag: int zu bool – 29.03.2023**
FPS: 0,0190

Zeit: 52,5 Sekunden

Prozentuelle Verbesserung: 2,416%

**Beschreibung:**

Die Variable flag, die vorher ein Int war, wurde zu einem bool geändert. Um einen bool verwenden zu können, muss man zuerst eine neue Bibliothek einbinden (mit „#include <stdbool.h>“).

**Codeausschnitte:**

|Vorher|Nachher|
| :- | :- |
|<p>flag = 3 \* 7 ;			</p><p>if(ix != 1){</p><p>`	`flag += 1 \* 7;</p><p>}</p><p>if(iy != 1 \* 7){</p><p>`	`flag +=2;</p><p>}</p><p>if(flag >3 \* 7){</p><p>`	`lebende += nachbarn[ix][iy] \* 7;</p><p>}</p>|<p>flag = false;</p><p>if(ix != 1){</p><p>`	`flag = true;</p><p>}</p><p>if(iy != 1 \* 7){</p><p>`	`flag = true;</p><p>}</p><p>if(flag){</p><p>`	`lebende += nachbarn[ix][iy] \* 7;</p><p>}</p>|
1. # <a name="_toc137737019"></a>**Array: int zu char – 29.03.2023**
FPS: 0,0191

Zeit: 52,4 Sekunden

Prozentuelle Verbesserung: 0,190%

**Beschreibung:**

Da Ints größer und somit langsamer sind wie zum Beispiel chars und die Zahlen in dem Array „array“ immer im Zahlenbereich eines chars sind, wurde der Datentyp des Arrays geändert.

**Codeausschnitte:**

|Vorher|Nachher|
| :- | :- |
|const static int array[XMAX][YMAX]= {…}|const static char array[XMAX][YMAX]= {…}|


1. # <a name="_toc137737020"></a>**Lebende: int zu char – 29.03.2023**
FPS: 0,0191

Zeit: 52,3 Sekunden

Prozentuelle Verbesserung: 0,191%

**Beschreibung:**

Wie schon früher erwähnt wurde, sind chars schneller als ints. Deshalb wurde lebende geänder. Die Variablen x und y wurden nicht geändert, da nicht gewusst wurde, ob der Spielbereich vergrößert werden wird.

**Codeausschnitte:**

|Vorher|Nachher|
| :- | :- |
|int lebende;|char lebende;|
1. # <a name="_toc137737021"></a>**If-Optimierung (2) – 29.03.2023**
FPS: 0,0194

Zeit: 51,6 Sekunden

Prozentuelle Verbesserung: 1,338%

**Beschreibung:**

Da bei der else-if-Abfrage, der if-Anteil nicht ausgeführt wird, wenn der erste Teil zustimmt, ist es schneller eine else-if-Abfrage zu verwenden als zwei separate ifs.

**Codeausschnitt:**

|Vorher|Nachher|
| :- | :- |
|<p>if(spielfeld[x][y] == 0 ){…}</p><p>if(spielfeld[x][y] == 1){…}</p>|<p>if(spielfeld[x][y] == 0 ){…}</p><p>else if(spielfeld[x][y] == 1){…}</p>|


1. # <a name="_toc137737022"></a>**zaehlLebende geändert – 29.03.2023**
FPS: 0,0205

Zeit: 48,8 Sekunden

Prozentuelle Verbesserung: 5,426 %

**Beschreibung:**

Aus ähnlichen Gründen wie der vorherigen Optimierung, wurde der Ablauf der Funktion verändert.

**Codeausschnitte:**

|Vorher|Nachher|
| :- | :- |
|<p>if(spielfeld[x][y] == 1){</p><p>`	`switch(lebende == 2){</p><p>`		`case 2:</p><p>`			`temp[x][y] = 1;</p><p>`			`break;</p><p>`		`case 3:</p><p>`			`temp[x][y] = 1;</p><p>`			`break;</p><p>`	`}</p><p></p><p>`	`if(lebende < 2){</p><p>`		`temp[x][y] = 0;</p><p>`		`if(lebende > 3){						temp[x][y] = 0;</p><p>`		`}</p><p>`	`}</p><p>}</p>|<p>if(spielfeld[x][y] == 1){</p><p>`	`if(lebende < 2 || lebende > 3){</p><p>`		`temp[x][y] = 0;</p><p>`	`}else{</p><p>`		`switch(lebende == 2){</p><p>`			`case 2:</p><p>`				`temp[x][y] = 1;</p><p>`				`break;</p><p>`			`case 3:</p><p>`				`temp[x][y] = 1;</p><p>`				`break;</p><p>`		`}</p><p>`	`}</p><p>}</p>|
|<p>flag = false;</p><p>		</p><p>if(ix != 1){</p><p>`	`flag = true;</p><p>}</p><p>if(iy != 1 \* 7){</p><p>`	`flag = true;</p><p>}</p><p>if(flag){</p><p>`	`lebende += nachbarn[ix][iy] \* 7;</p><p>}</p>|<p>if(ix != 1 || iy != 7){</p><p>`	`lebende += nachbarn[ix][iy];</p><p>}</p>|


1. # <a name="_toc137737023"></a>**PrintSpielfeld geändert – 29.03.2023**
FPS: 0,0205

Zeit: 48,7 Sekunden

Prozentuelle Verbesserung: 0,205%



**Beschreibung:**

Zu diesem Zeitpunkt war zwar noch nicht bekannt, wie die revers-Funktion funktioniert und was sie genau macht, aber es wurde erkannt, dass man ihr den Wert des Spielfeldes an einer bestimmten Position mitgeben sollte.

**Codeausschnitte:**

|Vorher|Nachher|
| :- | :- |
|<p>if(spielfeld[x][y] == 1){</p><p>`	`revers(1);</p><p>} else{</p><p>`	`revers(0);</p><p>}</p>|revers(spielfeld[x][y]);|


1. # <a name="_toc137737024"></a>**PrüfeRegeln und FindNachbarn geändert – 29.03.2023**
FPS: 0,0210

Zeit: 47,6 Sekunden

Prozentuelle Verbesserung: 2,259%

**Beschreibung:**

Die Switch-Abfrage in der pruefeRegeln-Funktion wurde durch ein if ersetzt. Zusätzlich wurde die temp-Variable entfernt, da diese unnötig ist.

**Codeausschnitte:**

|Vorher|Nachher|
| :- | :- |
|<p>switch(lebende == 2){</p><p>`	`case 2:</p><p>`		`temp[x][y] = 1;</p><p>`		`break;</p><p>`	`case 3:</p><p>`		`temp[x][y] = 1;</p><p>`		`break;</p><p>}</p>|<p>if(lebende == 2 || lebende == 3){</p><p>`	`temp[x][y] = 1;</p><p>}</p>|
|<p>temp = spielfeld[osx][osy];</p><p>nachbarn[ix][iy] = temp;</p>|nachbarn[ix][iy] = spielfeld[osx][osy];|


1. # <a name="_toc137737025"></a>**Spielfeld: int zu char array – 30.03.2023**
FPS: 0,0214

Zeit: 46,8 Sekunden

Prozentuelle Verbesserung: 1,681%

**Beschreibung:**

Das Array spielfeld bestand zuvor aus ints, aber da diese groß und langsam sind, wurden diese durch chars ersetzt. Dafür mussten alle Erwähnungen des Arrays ersetzt werden.


1. # <a name="_toc137737026"></a>**Nachbarn und Temp: int zu char – 30.03.2023**
FPS: 0,0217

Zeit: 46,0 Sekunden

Prozentuelle Verbesserung: 1,709%

**Beschreibung:**

Wie im vorherigen Schritt erwähnt wurde, wurden die Arrays nachbarn und temp zu char-Arrays umgewandelt. Da nun keine bools mehr verwendet werden, kann die Einbindung der Bibliothek für diese, welche zuvor hinzugefügt wurde, wieder gelöscht werden.


1. # <a name="_toc137737027"></a>**Ersetzung der restlichen ints – 30.03.2023**
FPS: 0,0236

Zeit: 42,4 Sekunden

Prozentuelle Verbesserung: 7,826%

**Beschreibung:**

Da das Programm nun besser verstanden wurde, wurden alle ints durch chars oder in manchen Fällen durch shorts ersetzt.


1. # <a name="_toc137737028"></a>**Text und Zahlenausgabe deaktiviert – 19.04.2023**
FPS: 0,0352

Zeit: 28,4 Sekunden

Prozentuelle Verbesserung: 33,019%

**Beschreibung:**

Da die Ausgabe der Anzahl der lebenden Nachbarn einer Position nur zur Überprüfung der Richtigkeit der Funktionen und der Logik dient und sehr viel Zeit und Rechenkraft verbraucht, wurde diese entfernt.

**Codeausschnitte:**

|Vorher|Nachher|
| :- | :- |
|<p>gotoxy(0,0);</p><p>cprintf("%2d %2d",x , y);</p><p>findNachbarn(x,y,spielfeld,nachbarn);</p><p>lebende = zaehlLebende(nachbarn);</p><p>gotoxy(x,y);</p><p>cprintf("%d",lebende);</p><p>pruefeRegeln(x,y,lebende, temp, spielfeld);</p>|<p>findNachbarn(x,y,spielfeld,nachbarn);</p><p>lebende = zaehlLebende(nachbarn);</p><p>pruefeRegeln(x,y,lebende, temp, spielfeld);</p>|
1. # <a name="_toc137737029"></a>**Memcpy bearbeitet und zusätzlich verwendet – 19.04.2023**
FPS: 0,0370

Zeit: 27,0 Sekunden

Prozentuelle Verbesserung: 4,930%

**Beschreibung:**

Durch die Analysierung des Codes wurde herausgefunden, dass die memcpy-Funktion einen effizienteren Weg ermöglicht, die Werte eines Arrays in ein anderes zu kopieren.

**Codeausschnitte:**

|Vorher|Nachher|
| :- | :- |
|<p>unsigned short x,y;</p><p>for(y = 0; y< YMAX; y++){</p><p>`	`for(x = 0; x< XMAX; x++){</p><p>`		`spielfeld[x][y] = array[x][y];</p><p>`	`}</p><p>}</p>|memcpy(spielfeld, array, XMAX\*YMAX);|


1. # <a name="_toc137737030"></a>**prüfeRegeln, zaehlLebende und findNachbarn zusammengeführt – 03.05.2023**
FPS: 0,0610

Zeit: 16,4 Sekunden

Prozentuelle Verbesserung: 39,259%



**Beschreibung:**

Nach Untersuchung der Funktionen wurde entdeckt, dass die Funktionen pruefeRegeln, zaehlLebende und findNachbarn alle die Anzahl der lebenden Nachbarn eines Punktes benötigen. Da die Übergabe dieser Variablen sehr ineffizient ist, wurden diese Funktionen zu einer zusammengefasst, damit die Anzahl der lebenden Nachbarn in einer einzigen lokalen Variable gespeichert werden kann.

**Zusammenfassung der Funktionen:**

void findNachbarn(short x, unsigned char y, char spielfeld[][YMAX], char nachbarn[][BOXSIZE], char temp[][YMAX]){

`	`unsigned char osx, ix;

`	`unsigned char osy, iy; 

`	`signed short ofy;

`	`signed short ofx;	

`	`char lebende = 0;

`	`for(ofy = y-1, iy=0; ofy <= (unsigned char)y+1; ++ofy , ++iy){

`		`for(ofx = x-1,ix = 0; ofx <= (unsigned char)x+1; ++ofx , ++ix){

`			`if( ofy < 0){

`				`osy = YMAX-1;

`			`}

`			`else if( ofy > YMAX-1)	{

`				`osy = 0;	

`			`}else {

`				`osy = ofy;

`			`}



`			`if( ofx < 0){

`				`osx = XMAX-1;

`			`} else if( ofx > XMAX-1)	{

`				`osx = 0;

`			`}

`			`else {

`				`osx = ofx;

`			`}

`			`lebende += spielfeld[osx][osy];				

`		`}

`	`}	

`	`if(spielfeld[x][y] == 0 ){

`		`if(lebende == 3){

`			`temp[x][y] = 1;

`		`}

`	`}else if(spielfeld[x][y] == 1){

`		`if(lebende < 2 || lebende > 3){

`			`temp[x][y] = 0;

`		`}else{

`				`temp[x][y] = 1;

`		`}

`	`}

}


1. # <a name="_toc137737031"></a>**FindNachbarn: iy und ix wurden gelöscht – 11.05.2023**
FPS: 0,0625

Zeit: 16,0 Sekunden

Prozentuelle Verbesserung: 2,439%

**Beschreibung:**

Da durch die vorherige Veränderung iy und ix in der FindNachbarn-Methode nicht mehr benötigt werden, wurden diese gelöscht. Diese Änderung wurde später verworfen, da nach der folgenden Änderung ein Logik-Fehler gefunden wurde und vermutet wurde, dass dieser innerhalb dieser Änderung passierte, was nicht stimmte. 





**Codeausschnitte:**

|Vorher|<p>for(ofy = y-1, iy=0; ofy <= (unsigned char)y+1; ++ofy , ++iy){</p><p>`	`for(ofx = x-1,ix = 0; ofx <= (unsigned char)x+1; ++ofx , ++ix){…}</p><p>}</p>|
| :- | :- |
|Nachher|<p>for(ofy = y-1; ofy <= (unsigned char)y+1; ++ofy){</p><p>`	`for(ofx = x-1; ofx <= (unsigned char)x+1; ++ofx){…}</p><p>}</p>|


1. # <a name="_toc137737032"></a>**findNachbarn optimierung – 11.05.2023**
FPS: 0,0719

Zeit: 13,9 Sekunden

Prozentuelle Verbesserung: 13,125%

**Beschreibung:**

Es wurde versucht die Funktion für die Zählung der lebenden Nachbarn zu optimieren. Dies erwies sich allerdings als falsch.

**Codeausschnitte:**

|Vorher|Nachher|
| :- | :- |
|<p>if( ofy < 0){</p><p>`	`osy = YMAX-1;</p><p>}</p><p>else if( ofy > YMAX-1)	{</p><p>`	`osy = 0;</p><p>}</p><p>else {…}</p>|<p>if(ofy > YMAX-1){</p><p>`	`if(ofy == 255){</p><p>`		`osy = YMAX-1;</p><p>`	`}else{</p><p>`		`osy = 0;</p><p>`	`}</p><p>}</p><p>else {…}</p>|



1. # <a name="_toc137737033"></a>**Datentypen wurden angepasst – 11.05.2023**
FPS: 0,0680

Zeit: 14,7 Sekunden

Prozentuelle Verbesserung: 10,366%

**Beschreibung:**

Da verstanden wurde, dass die Größe des Feldes gleich bleiben wird und somit in der Spanne eines chars liegt, wurden die restlichen shorts im Programm ersetzt. 


1. # <a name="_toc137737034"></a>**Nachbarn wird nicht übergeben – 11.05.2023**
FPS: 0,0694

Zeit: 14,4 Sekunden

Prozentuelle Verbesserung: 2,041%

**Beschreibung:**

Da durch vorherige Änderungen das Array „nachbarn“ nicht mehr benötigt wird wurde dieses gelöscht.


1. # <a name="_toc137737035"></a>**Run.bat bearbeitet – 11.05.2023**
FPS: 0,1

Zeit: 10,0 Sekunden

Prozentuelle Verbesserung: 30,556%


**Beschreibung:**

Auf <https://github.com/ilmenit/CC65-Advanced-Optimizations> befindet sich eine Anleitung mit einigen Tipps für das effiziente Programmieren mit dem cc65-Compiler. Dort wird im zweiten Punkt beschrieben, dass man beim Start des Kompilierungsvorgangs die Befehle -Osir und -Cl hinzufügen soll. Genauere Information findet man auf <https://cc65.github.io/doc/coding.html>.

**Codeausschnitte:**

|Vorher|Nachher|
| :- | :- |
|cl65 -t c64 -o conway.prg conway.c|cl65 -t c64 -Osir -Cl -o conway.prg conway.c|


1. # <a name="_toc137737036"></a>**Dateitypen bearbeitet (2) – 15.05.2023**
FPS: 0,1010

Zeit: 9,9 Sekunden

Prozentuelle Verbesserung: 1,000%

**Beschreibung:**

Im vorherigen Schritt erwähntem Tutorial wurde noch ein Tipp unter „What else to optimize was not covered in this tutorial?“ genannt. Dort wird geschrieben, dass man statt „a = a + 1;“ oder „a += 1;“ „++a“ verwenden soll. Dies wurde auch hier angewandt. 

**Codeausschnitte:**

|Vorher|Nachher|
| :- | :- |
|<p>for(y = 0; y< YMAX; y++){</p><p>`	`for(x = 0; x< XMAX; x++){…}</p><p>}</p>|<p>for(y = 0; y< YMAX; ++y){</p><p>`	`for(x = 0; x< XMAX; ++x){…}</p><p>}</p>|


1. # <a name="_toc137737037"></a>**Alle Funktionen in main gefügt – 14.06.2023**
FPS: 0,1235

Zeit: 8,1 Sekunden

Prozentuelle Verbesserung: 18,182%

**Beschreibung:**

Da es schneller ist etwas auszuführen, als eine Funktion auszuführen wurden alle Funktionen in die main-Funktion kopiert.

**While-Schleife in der main-Funktion:**

for(y = 0; y< YMAX; ++y){

`	`for(x = 0; x< XMAX; ++x){

`		`char osx, ix,  osy, iy, ofy, ofx;

char lebende = 0;

`		`for(ofy = y, iy=0; ofy <= y+2; ++ofy , ++iy){

`			`for(ofx = x,ix = 0; ofx <= x+2; ++ofx , ++ix){

`				`if( ofy < 1)	{

`					`osy = YMAX-1;

`				`}

`				`else if( ofy > YMAX)	{

`					`osy = 0;

`				`}

`				`else {

`					`osy = ofy-1;

`				`}



`				`if( ofx < 1){

`					`osx = XMAX-1;

`				`} else if( ofx > XMAX)	{

`					`osx = 0;

`				`}

`				`else {

`					`osx = ofx-1;

`				`}

`				`lebende += spielfeld[osx][osy];				

`			`}

`		`}	

`		`if(spielfeld[x][y] == 0 ){

`			`if(lebende == 3){

`				`temp[x][y] = 1;

`			`}

`		`}else{

`			`if(lebende < 3 || lebende > 4){

`				`temp[x][y] = 0;

`			`}else{

`				`temp[x][y] = 1;

`			`}

`		`}

}

}

memcpy(spielfeld,temp,XMAX\*YMAX);

++round;

for(y = 0; y< YMAX; ++y){

`	`for(x = 0; x< XMAX; ++x){

`		`revers(spielfeld[x][y]);

`		`cputcxy (x, y, 32);

`	`}

}


1. # <a name="_toc137737038"></a>**getNeighbours wurde überarbeitet – 14.06.2023**
FPS: 0,1852

Zeit: 5,4 Sekunden

Prozentuelle Verbesserung: 33,333%

**Beschreibung:**

Die Art die Anzahl der lebenden Nachbarn zu erhalten wurde überarbeitet.

**Codeausschnitte:**

|Vorher|Nachher|
| :- | :- |
|<p>char osx, ix,  osy, iy, ofy, ofx;</p><p></p><p>for(ofy = y, iy=0; ofy <= y+2; ++ofy , ++iy){</p><p>`	`for(ofx = x,ix = 0; ofx <= x+2; ++ofx , ++ix){</p><p>	</p><p>`		`if( ofy < 1){</p><p>`			`osy = YMAX-1;		</p><p>`		`}</p><p>`		`else if( ofy > YMAX){</p><p>`			`osy = 0;	</p><p>`		`}</p><p>`		`else {</p><p>`			`osy = ofy-1;</p><p>`		`}</p><p>		</p><p>`		`if( ofx < 1){</p><p>`			`osx = XMAX-1;</p><p>`		`} else if( ofx > XMAX){</p><p>`			`osx = 0;</p><p>`		`}</p><p>`		`else {</p><p>`			`osx = ofx-1;</p><p>`		`}</p><p>`		`lebende += spielfeld[osx][osy];	</p><p>`		`}</p><p>`	`}	</p>|<p>char yStart, xStart, yEnd, xEnd;</p><p>if(y == 0){</p><p>`	`yStart = YMAX - 1;</p><p>`	`yEnd = y + 1;</p><p>}else if(y == YMAX - 1){</p><p>`	`yEnd = 0;</p><p>`	`yStart = y - 1;</p><p>}else{</p><p>`	`yStart = y - 1;</p><p>`	`yEnd = y + 1;</p><p>}</p><p>if(x == 0){</p><p>`	`xStart = XMAX - 1;</p><p>`	`xEnd = x + 1;</p><p>}else if(x == XMAX - 1){</p><p>`	`xEnd = 0;</p><p>`	`xStart = x - 1;</p><p>}else{</p><p>`	`xStart = x - 1;</p><p>`	`xEnd = x + 1;</p><p>}</p><p>lebende = spielfeld[xStart][yStart] + spielfeld[x][yStart] + spielfeld[xEnd][yStart] + spielfeld[xStart][y] + spielfeld[xEnd][y] + spielfeld[xStart][yEnd] + spielfeld[x][yEnd] + spielfeld[xEnd][yEnd];</p>|


1. # <a name="_toc137737039"></a>**Displayausgabe überarbeitet – 14.06.2023**
FPS: 0,2174

Zeit: 4,6 Sekunden

Prozentuelle Verbesserung: 14,815%

**Beschreibung:**

Die Art wie das Spielfeld auf den Bildschirm ausgegeben wird, wurde verändert. Hier wird ganz am Anfang die Farbe der Zeichen umgekehrt und, wenn spielfeld an einem bestimmten Punkt 1 beträgt, ein Leerzeichen an die Stelle schreibt. Um den Bildschirm wieder vollständig zu löschen wird die clrscr-Methode verwendet.

**Codeausschnitt:**

|Code|Erklärung|
| :- | :- |
|<p>Revers(1);</p><p>…</p><p>clrscr();</p><p>…</p><p>for(y = 0; y< YMAX; ++y){</p><p>`	`for(x = 0; x< XMAX; ++x){</p><p>`		`if(spielfeld[x][y] == 1){</p><p>` 			`cputcxy (x, y, 32);</p><p>`		`}</p><p>`	`}</p><p>}</p>|<p>Kehrt die Farbe der Zeichen um</p><p></p><p>Löscht den Bildschirm</p><p></p><p></p><p></p><p>Wenn spielfeld an der Position x/y = 1, dann…</p><p>Schreibe ein Leerzeichen an diese Stelle</p>|





