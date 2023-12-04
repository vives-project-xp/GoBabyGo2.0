# PCB

## inleiding

Ideal zouden we een PCB kunnen maken. Hier een korte aanzet om er aan te starten.

## componenten

### Gekozen componenten

De gebruikte componenten:
 - L298N : https://be.farnell.com/stmicroelectronics/l298n/ic-bridge-driver-dual-298/dp/403295?ICID=I-RP-STM7REC-1
 - ESP32 (->devkit<-) : https://www.mouser.be/ProductDetail/Espressif-Systems/ESP32-C3-DevKitC-02?qs=stqOd1AaK7%2F1Q62ysr4CMA%3D%3D
 - Voltage regulators : 
    -  5V: https://be.farnell.com/diodes-inc/az1117ch2-5-0trg1/ldo-dc-dc-conv-5v-0-8a-sot-223/dp/3942512
 - Optocouplers : https://be.farnell.com/isocom/sfh615a-2x/optocoupler-dip-4-tr-o-p/dp/1683348
 - Weerstanden en condesatoren: Zie bomlijst.

 ### Reden keuze

Zie architectuur documenten om te zien wat we willen berijken. </br>

- L298N: Het is een veel gebruikte motordriver en simple te gebruiken.
- ESP32 Devkit: Dit hebben we liggen en het is dan gemakelijker om een pcb te maken. Moet geen rekening houden met de USB -> UART interface en we hebben dan geen 3.3V LDO meer nodig dan.
- Voltage regulator: we hebben 5V nodig voor de ESP en de MotorDriver te logica te voeden.
- Optocouplers die hebben we nodig om 12 volt ingangen naar 3.3V over te zetten zodat we ze kunnen binnen lezen.

## Elektrische schema
