# izp-laboratore
IZP - Počítačové laboratoře

## Ladicí techniky a nástroje
### GDB

- Spusťte debugger
```sh
gdb buggy
```

- Argument -tui způsobí částečné textové uživatelské rozhraní:
```sh
gdb -tui buggy
```
- Nastavte breakpoint na funkci main:
```sh
(gdb) break main
```
nebo 
```sh
(gdb) b main
```
- Spusťte program s argumenty:
```sh
(gdb) run arg1 arg2 arg3
```
nebo
```sh
(gdb) r arg1 arg2 arg3
```

- Pomocí příkazů next, step, finish, cont procházejte průběhem programu:
```sh
(gdb) next           - (nebo jen n) proveď další řádek programu
(gdb) step           - (nebo jen s) proveď další krok (do) podprogramu
(gdb) finish         - (nebo je fin) spusť funkci do jejího konce
(gdb) cont           - pokračuj ve spuštění programu
(gdb) list           - (nebo jen l) zobraz 10 dalších řádků kódu blízko aktuálnímu.
```

##### Při průchodu sledujte hodnoty proměnných:
- Tisk hodnoty výrazu (nebo proměnné):
```sh
(gdb) print EXPR
```

- Zobrazování hodnoty výrazu při krokování:
```sh
(gdb) display EXPR
```

- Podmíněný breakpoint:
```sh
(gdb) b 7 if c == '%'
```

- Vynucená změna hodnoty proměnné:
```sh
(gdb) set VAR = EXPR
```
