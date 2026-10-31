# fwmem

Alat za analizu zauzeća memorije firmwarea, pisan u Bashu i Pythonu.
Projekt iz kolegija *Programiranje skriptnih jezika*.

## Problem

Mikrokontroleri imaju malo flasha i RAM-a. Kad firmware preraste kapacitet
čipa, ne može se učitati. `fwmem` iz izlaza alata `size`, `nm` i linkerove
`.map` datoteke izvlači zauzeće memorije, uspoređuje dva builda i upozorava
(ili odbija commit) kad se prekorači zadani prag.

## Planirane mogućnosti

- [ ] zauzeće sekcija (`.text`, `.rodata`, `.data`, `.bss`) i postotak kapaciteta
- [ ] najveće funkcije i varijable (top N)
- [ ] zauzeće po objektnim modulima iz `.map` datoteke
- [ ] usporedba dvaju buildova / dvaju git commitova
- [ ] izvještaj: tablice u terminalu, HTML/PNG s grafovima
- [ ] provjera praga s izlaznim kodom, git hook / CI

## Struktura repozitorija

```
src/                 skripte alata (Bash, Python)
tests/               testovi (bats, pytest)
config/              primjer konfiguracije (kapacitet čipa, pragovi)
samples/demo_fw/     mali C projekt za demonstraciju
docs/                izvješća i dokumentacija
```

## Zahtjevi

`gcc`, `make`, `binutils` (`size`, `nm`), `git`, `python3`, `matplotlib`.
Na Arch Linuxu:

```
sudo pacman -S --needed base-devel git python python-matplotlib
```

## Brzi početak: prevođenje demo projekta

```
make -C samples/demo_fw                              # -Os, build/ u demo_fw
make -C samples/demo_fw OPT=-O0 BUILD=build/O0       # drugi build za usporedbu
size samples/demo_fw/build/demo.elf
nm --size-sort -S samples/demo_fw/build/demo.elf | tail
```

## Konvencije

- grane: `main` (stabilno), `feature/<naziv>` za novu funkcionalnost
- commit poruke: kratki imperativ na engleskom, npr. `Add section size parser`
