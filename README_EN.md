
# Smart Device Project
# MICROCONTROLLERS AND OPEN-SOURCE HARDWARE:
# Gas Sensor Construction Project

    LAURENS Pierre - TOUZANI Ismail - Krishna Sujan
>LAURENS [Pierre](mailto:plaurens@etud.insa-toulouse.fr) - TOUZANI Ismail - Krishna Sujan

<a href="./README.md">French version</a>

This project, part of the Master 5ISS of INSA Toulouse, was developed with the aim of creating an intelligent gas sensor capable of detecting several types of gas that could be dangerous to human health. After having built the sensor in the AIME workshop of INSA, it will be necessary to adjust it to extract the useful information: this will be done using the LTSpice IV software for the analogical electronic part. Then, in order to retrieve the sensor data and communicate them through the LoRA network, an Arduino Uno card and a RN2483 chip will be used. Finally, we will use the KiCAD software to make the appropriate wiring diagram between the different components.
Content of the Project

# Contenu du Projet
The project consists of the following directories:
-   **KiCAD**: Contains the files needed to build the PCB.
    - **Projet Kicad**: containing the first version of our project.
    - **Projet Kicad plan de masse** : containing the same project as the above file but with the realization of the plan de masse.
    - **Kicad Aime plan de masse project** : containing the PCB of the gas sensor realized in the premises of the AIME.
-   **Mosh (Arduino IDE)**: Contains the files of the gps performed using the Arduino IDE as well as the project files.
-   **LTSpice**: Contains the files needed for the analog electronic part.

  
### Data collection and LoRA communication part:
In this section we have tested the LoRA data collection and communication with a test sensor:

<img width="360" height="280" src="Mosh/images_Mosh/image_mosh_final.jpg" title="PCB schematic">

Above is an image of the assembly for interconnecting the LoRa module, the arduino UNO and the gas sensor.
Below is a series of images showing the result of our assembly with the reception and sending of the sensor value.

![PCB Schematic](/Mosh/images_Mosh/result_pot_dernierevaleur.png)
![PCB Schematic](/Mosh/images_Mosh/Resultat_potentiometre.png)
![PCB Schematic](/Mosh/images_Mosh/valeur_internetthings.png)
### Construction part of the shield/PCB:
In this part, we have built our own shield/PCB thanks to KiCAD :

A Zoom on the design of the AIME gas sensor on Eeschema:

![Sensor circuit diagram](/Kicad/Projet_Kicad_Aime_plan_masse/image_capteur.png)

Then below, the entire Intelligent Sensor designed on Eeschema:

![Electronic diagram of the intelligent sensor](/Kicad/Projet_Kicad_Aime_plan_masse/capture_Aime_capteur_Eeaschema.png)

Layout design with the tracing of roads and the creation of footprints and their positioning on the map.


![Schéma PCB](/Kicad/Projet_Kicad_Aime_plan_masse/PCB_final_Aime_Capteur_datasheet.png)

![Schéma Shield Avant 3D](/Kicad/Projet_Kicad_Aime_plan_masse/Shield_3D_final_Aime_Capteur_datasheet.png)

![Schéma Shield Arrière 3D](/Kicad/Projet_Kicad_Aime_plan_masse/Shield_3D_arriere_final_Aime_Capteur_datasheet.png)

We carried out a ground plan to reduce copper consumption and limit single-layer routing. Indeed, we removed all the routes on the front layer of our shield(red) present on the picture above. The ground plan also allows us to do the routing on a single layer, the back layer of our Shield. Finally, we have respected the routing constraints defined by the INSA.

### Analog electronic part:
Concerning this part, we have studied, using LTSPice IV, the analog electronic part of the Smart Device module where we will measure the resistance, the low current with a microcontroller and perform a low-pass filtering to extract the useful information from our gas sensor.

<a href="/LTspice/UF_Smart_Device_ Partie_analogique_avec_LTSpice_IV.pdf">Rapport_LTSPice (french version)</a>
