
# Smart Device Project
# MICROCONTROLLERS AND OPEN-SOURCE HARDWARE:
# Gas Sensor Construction Project

    LAURENS Pierre - TOUZANI Ismail
>LAURENS [Pierre](mailto:plaurens@etud.insa-toulouse.fr) - TOUZANI Ismail 

<a href="./README.md">French version</a>

This project, part of the Master 5ISS of INSA Toulouse, was developed with the aim of creating an intelligent gas sensor capable of detecting several types of gas that could be dangerous to human health. After having built the sensor in the AIME workshop of INSA, it will be necessary to adjust it to extract the useful information: this will be done using the LTSpice IV software for the analogical electronic part. Then, in order to retrieve the sensor data and communicate them through the LoRA network, an Arduino Uno card and a RN2483 chip will be used. Finally, we will use the KiCAD software to make the appropriate wiring diagram between the different components.
Content of the Project

# Contenu du Projet
The project consists of the following directories:
-   **KiCAD**: Contains the files needed to build the PCB.
-   **Mosh (Arduino IDE)**: Contains the files of the gps performed using the Arduino IDE as well as the project files.
-   **LTSpice**: Contains the files needed for the analog electronic part.

  
### Data collection and LoRA communication part:
In this section we have tested the LoRA data collection and communication with a test sensor:

<img width="360" height="280" src="Mosh/images_Mosh/image_mosh_final.jpg" title="PCB schematic">

![PCB Schematic](/Mosh/images_Mosh/result_pot_dernierevaleur.png)
![PCB Schematic](/Mosh/images_Mosh/Resultat_potentiometre.png)
![PCB Schematic](/Mosh/images_Mosh/valeur_internetthings.png)
### Construction part of the shield/PCB:
In this part, we have built our own shield/PCB thanks to KiCAD :

![Electronic schematic](/Kicad/Projet_Kicad/Eeschema_shield.png)
![PCB Schematic](/Kicad/Projet_Kicad/PCB_shield_capteur.png)
![3D Front Shield Schematic](/Kicad/Projet_Kicad/Shield_avant_3D.png)
![3D Back Shield Schematic](/Kicad/Projet_Kicad/Shield_arriere_3D.png)
Finally, we have made a ground plan:
![PCB Schematic](/Kicad/Projet_Kicad_plan_masse/Kicad_plan_masse.png)
![Schéma PCB avec Plan de masse en 3D](/Kicad/Projet_Kicad_plan_masse/shiel_final.png)
![3D Front Shield Schematic](/Kicad/Projet_Kicad_plan_masse/Shiel_avant_3D_plan_masse.png)
![3D Back Shield Schematic](/Kicad/Projet_Kicad_plan_masse/Kicad_arriere_3D_plan_masse.png)

We carried out a ground plan to reduce copper consumption and limit single-layer routing. Indeed, we removed all the routes on the front layer of our shield(red) present on the picture above. The ground plan also allows us to do the routing on a single layer, the back layer of our Shield. Finally, we have respected the routing constraints defined by the INSA.

### Analog electronic part:
Concerning this part, we have studied, using LTSPice IV, the analog electronic part of the Smart Device module where we will measure the resistance, the low current with a microcontroller and perform a low-pass filtering to extract the useful information from our gas sensor.

<a href="/LTspice/UF_Smart_Device_ Partie_analogique_avec_LTSpice_IV.pdf">Rapport_LTSPice (french version)</a>
