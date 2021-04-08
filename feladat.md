# Doctor Who (Minta ZH)

A kitűzött feladatra készítsen objektum elvű megoldást C++ nyelven az alábbi szempontok alapján:

Felsoroló osztály segítségével oldja meg a következő feladatot! A bemeneti adatokat tartalmazó szöveges állományokról feltételezzük, hogy helyesen vannak kitöltve, csak a létezésüket kell ellenőrizni. A szöveges állományt csak egyszer nyithatja meg olvasásra és nem használhat a szöveges állomány sorainak számától függő méretű változót. Ha a feladata üres fájlra nem értelmezhető, kezelje le külön ezt az esetet! Globális változókat nem használhat!

A Doctor Who nevű brit televíziós sorozat érdekessége, hogy néhány évadonként mindig új színész játssza a főszereplő (Doctor) karakterét. Egy szöveges állományban rögzítjük, hogy melyik évben ki játszotta a Doctor-t, és hogy abban az évadban milyen hosszú részeket adtak ki.

A fájl egy sorának felépítése: Elsőként az adott évadhoz tartozó év (pozitív természetes szám), majd a színész neve (egy szóközök nélküli sztring), majd epizódnév-hossz(perc) párok (egy szóközök nélküli sztring, pozitív természetes szám ) formájában. Az adatok szóközökkel vagy tabulátorjelekkel vannak egy soron belül elválasztva. A szöveges állomány sorait a színészek neve szerint rendezték. Feltehetjük, hogy a szöveges állomány helyesen van kitöltve.
Példa az állomány egy sorára:

```
2010 MattSmith EleventhHour 65 BeastBelow 45 VictoryOfTheDaleks 45 TimeOfAngels 40
```

Nem kell a megfelelt szintű megoldást elkészítenie, ha a kiváló szintűt megoldotta, de ajánlott először a megfelelt szinttel foglalkoznia. Ha azzal készen van, mutassa be a megoldását, és folytathatja a munkát.

A programját töltse fel a beadandó kezelő rendszerbe: http://assignment.elte.hu

## Megfelelt szint (3)

Adjuk meg a 2005, vagy az után forgatott évadok részei közül melyik volt a legrövidebb, és hogy melyik évben, melyik színész főszereplésével készült a rész.

## Kiváló szint (5)

Számoljuk meg, hogy hány olyan színész van, aki az összes általa játszott részben 40 perc vagy ennél hosszabb ideig szerepelt.
