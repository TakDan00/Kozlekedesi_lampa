# Okos közlekedési lámpa rendszer

## 📌 Projekt leírás

A projekt célja egy Arduino alapú közlekedési lámpa rendszer megvalósítása, amely képes kezelni a jármű- és gyalogosforgalmat. A rendszer nyomógombos vezérléssel működik, és vizuális valamint hangjelzést biztosít a gyalogosok számára.

A megoldás tartalmaz LED-es jelzéseket, hangjelzést (buzzer), valamint LCD kijelzőn megjelenített visszaszámlálást.

---

## ⚙️ Felhasznált eszközök

* Arduino Uno
* Breadboard
* LED-ek (5 db)
* Ellenállások (220Ω)
* Nyomógomb
* Buzzer (piezo)
* LCD 16x2 kijelző
* Vezetékek

---

## 🔌 Kapcsolási rajz

A rendszer breadboard-on került kialakításra. A LED-ek, gomb, buzzer és LCD kijelző az Arduino digitális és analóg lábaira csatlakoznak.

### Főbb bekötések:

* Autós lámpák:

  * Piros: D2
  * Sárga: D3
  * Zöld: D4

* Gyalogos lámpák:

  * Piros: D5
  * Zöld: D6

* Nyomógomb:

  * D7 (INPUT_PULLUP)

* Buzzer:

  * D8

* LCD kijelző:

  * RS: A0
  * E: A1
  * D4–D7: A2–A5

---

## 🧠 Működés

A rendszer alapállapotban az autós forgalmat engedi (zöld jelzés), míg a gyalogosok számára piros jelzés aktív.

A nyomógomb megnyomásával a rendszer egy vezérelt állapotváltási folyamatot indít:

1. Autós zöld → sárga
2. Autós sárga → piros
3. Gyalogos zöld aktiválása
4. LCD kijelzőn visszaszámlálás (másodpercben)
5. Hangjelzés (buzzer)
6. Gyalogos zöld villogása a végén
7. Autós piros + sárga átmenet
8. Visszatérés alapállapotba

---

## 🖥️ Kijelző működése

Az LCD kijelző megjeleníti:

* aktuális állapotot
* gyalogos átkelési időt
* visszaszámlálást másodpercben

Ez növeli a rendszer használhatóságát és felhasználóbarát működését.

---

## 🔊 Hangjelzés

A buzzer hangjelzést ad:

* folyamatos jelzés a gyalogos átkelés alatt
* szaggatott jelzés a visszaszámlálás során

Ez a funkció különösen hasznos látássérült felhasználók számára.

---

## 🧩 Megvalósítás

A rendszer Arduino C++ nyelven készült, a működés `loop()` ciklusban történik, eseményvezérelt logikával.

A program fő elemei:

* állapotkezelés
* időzítések (`delay`)
* digitális ki-/bemenetek kezelése
* LCD vezérlés (`LiquidCrystal` könyvtár)

---

## 📈 Továbbfejlesztési lehetőségek

* többirányú kereszteződés kezelése
* 7 szegmenses kijelző használata
* forgalomérzékelés (szenzorokkal)
* intelligens időzítés

---

## 📷 Projekt bemutatása

<img width="974" height="663" alt="image" src="https://github.com/user-attachments/assets/dc0f1916-738b-4008-a1d0-00e8d087f550" />
<img width="957" height="743" alt="image" src="https://github.com/user-attachments/assets/2e7dcdea-e6d3-4e74-9194-48c1df566629" />



---

## 🧾 Forráskód



---

## 👨‍💻 Készítette

* Név: Takács Dániel
* Neptun kód: SUSHBA

---
