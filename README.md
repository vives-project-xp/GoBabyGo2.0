# GoBabyGo2.0

## Nodige onderdelen

- Auto
- MicroController
- Motor driver voor te kunnen sturen

## Bestellijst
| **Onderdeel**            | **Prijs** | **Link**                                                                                                                                                                                                                                                                |
|--------------------------|-----------|-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| **Motor Driver**         | €5.29     | https://www.amazon.com.be/-/en/OcioDual-Stepper-Electronics-Projects-Raspberry/dp/B07YNR5KWP/ref=sr_1_10?crid=13WDD3RB1V2TC&keywords=l298n+motor+driver&qid=1695624708&sprefix=l298n+motor+driver%2Caps%2C69&sr=8-10                                                    |
| **ESP32**                | €11.37    | https://www.amazon.com.be/-/en/ESP-32S-Development-Antenna-Bluetooth-Arduino/dp/B07XH45MWW/ref=sr_1_27?crid=2R7CSQ30VFE6H&keywords=esp32&qid=1695629494&sprefix=esp32%2Caps%2C166&sr=8-27&th=1                                                                          |
| **Joystick**             | €14.21    | https://www.amazon.com.be/-/en/Potentiometer-JH-D202X-R2-Controller-Photography-Accessories/dp/B09J2C4DN5/ref=sr_1_3?crid=357R56FNH75R6&keywords=Joystick+potentiometer+JH-D202X-R4+10K&qid=1695624613&sprefix=joystick+potentiometer+jh-d202x-r4+10k%2Caps%2C66&sr=8-3 |
| **DC-DC Buck Converter** | €11.88    | https://www.amazon.com.be/-/en/Hailege-Converter-1-25-36V-Adjustable-Step-down/dp/B07XRF9NWP/ref=sr_1_7?crid=1PQTSHA11MF1Q&keywords=dc+to+dc+buck+converter+adjustable&qid=1695628749&sprefix=dc+to+dc+buck+converter+adjustable%2Caps%2C71&sr=8-7                      |
| **Optocoupler** | €7.85    | https://www.amazon.com.be/-/en/BOJACK-Optocoupler-Installation-Spacing-Package/dp/B08CXKZ98W/ref=sr_1_6?crid=1FXUJNO9624LN&keywords=optocoupler&qid=1695634939&sprefix=optocoupler%2Caps%2C69&sr=8-6                      |

## Rand info

Batterij is 12v 

De huidige electronica komen de kabels met het volgende overeen:

![Driver](./Img/DriverPicture.jpg)

De 7Pin Connector:
- Blauw: low high speed
- geel: vooruit
- Groen: achteruit
- zwart: grond
- empty
- wit: aanuitknop
- rood: aanuitknop

## Motor driver
Om de richting te bepalen van de auto gebruiken we een motortje. Dit motortje wordt aangestuurd a.d.h.v een driver. 
Via deze driver kunnen we de richting en de snelheid van de motor bepalen. De driver die wij gebruiken is de L298N.
Hoe je de driver kunt gebruiken met een ESP kun je vinden in het mapje "Programma's".

![Aansluitschema Driver](./Img/Aansluitschema%20L298N%20H-brug.jpg) 

nikita: autodementeren en bestuderen(2u), schets(1u), les(2u),bespreken project(2u), schets affiche(30min)

