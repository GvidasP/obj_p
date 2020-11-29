# Testavimo rezultatai

## `std::vector` konteinerio rezultatai

#### **studentai1000.txt**

`Failo nuskaitymas uztruko: 0.007017`
`Studentu rusiavimas i 2 kategorijas uztruko: 1.55e-05`

#### **studentai10000.txt**

`Failo nuskaitymas uztruko: 0.0655178`
`Studentu rusiavimas i 2 kategorijas uztruko: 0.0001741`

#### **studentai100000.txt**

`Failo nuskaitymas uztruko: 0.624028`
`Studentu rusiavimas i 2 kategorijas uztruko: 0.0017944`

#### **studentai1000000.txt**

`Failo nuskaitymas uztruko: 6.27143`
`Studentu rusiavimas i 2 kategorijas uztruko: 0.0179453`

#### **studentai10000000.txt**

`Failo nuskaitymas uztruko: 70.446`
`Studentu rusiavimas i 2 kategorijas uztruko: 0.192344`

## `std::list` konteinerio rezultatai

#### **studentai1000.txt**

`Failo nuskaitymas uztruko: 0.0075417`
`Studentu rusiavimas i 2 kategorijas uztruko: 2.58e-05`

#### **studentai10000.txt**

`Failo nuskaitymas uztruko: 0.0662531`
`Studentu rusiavimas i 2 kategorijas uztruko: 0.0002963`

#### **studentai100000.txt**

`Failo nuskaitymas uztruko: 0.650927`
`Studentu rusiavimas i 2 kategorijas uztruko: 0.0043415`

#### **studentai1000000.txt**

`Failo nuskaitymas uztruko: 6.23435`
`Studentu rusiavimas i 2 kategorijas uztruko: 0.039285`

#### **studentai10000000.txt**

`Failo nuskaitymas uztruko: 65.6967`
`Studentu rusiavimas i 2 kategorijas uztruko: 0.40923`

## Sistemos parametrai:

**CPU**: Intel Core i7-8565U
**RAM**: 16.0GB
**SDD**: 476GB Western Digital WDC PC SN720 SDAPNTW-512G-1006

## v1.0 palyginimai

**Naudota strategija:** Studentų struktūroje kintamasis `category`, kuris nusprendžia, kuriai kategorijai priklauso studentas. Todėl atliksiu palyginimą su 1) ir 2) strategijomis, aprašytomis užduotyje, naudodamas **studentai1000000.txt** failą.

## Esama strategija

`Studentu rusiavimas i 2 kategorijas uztruko: 0.039285`, naudojant `list` konteinerį.
`Studentu rusiavimas i 2 kategorijas uztruko: 0.0179453`, naudojant `vector` konteinerį.

## 1 strategija

Naudojamas **partition_copy** algoritmas studentus išskaidyti į 2 grupes
`Studentu rusiavimas i 2 kategorijas uztruko: 0.43925`, naudojant `vector` konteinerį
`Studentu rusiavimas i 2 kategorijas uztruko: 0.454077`, naudojant `list` konteinerį

## 2 strategija

Naudojamas **remove_copy_if** algoritmas. Studentai iš vieno konteinerio perkeliami į kitą ir ištrinami iš esamo.
`Studentu rusiavimas i 2 kategorijas uztruko: 0.185952`, naudojant `vector` konteinerį
`Studentu rusiavimas i 2 kategorijas uztruko: 0.18629`, naudojant `list` konteinerį
