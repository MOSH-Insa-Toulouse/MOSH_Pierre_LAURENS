
# Projet Smart Device
# MICRO-CONTROLEURS ET OPEN-SOURCE HARDWARE:
# Projet de Construction d'un capteur de gaz 
>LAURENS [Pierre](mailto:plaurens@etud.insa-toulouse.fr) - TOUZANI Ismail 


<a href="./README_EN.md">Version Anglaise</a>

Ce projet, faisant partie du Master 5ISS de l'INSA Toulouse, a été developpé dans le but de créer un capteur de gas intelligent capable de détecter plusieurs types de gas qui pourront être dangereux pour la santé humaine.
Après avoir construit le capteur dans l'atelier AIME de l'INSA, il sera donc nécessaire de le régler pour en extraire les informations utiles: cela se fera grâce au logiciel LTSpice IV pour la partie éléctronique analogique. Ensuite, et afin de récupérer les données du capteur et les communiquer à travers le réseau LoRA, on utilisera une carte Arduino Uno et une puce RN2483. Enfin, nous utiliserons le logiciel KiCAD pour effectuer le schéma adéquat du câblage entre les différents composants.

# Contenu du Projet
Le projet est constitué des répertoires suivants:
-   **Mosh (Arduino IDE)**: Contient les fichiers des tps effectués en utilisant l'IDE d'Arduino ainsi que les fichiers du projet.

-   **KiCAD**: Contient les fichiers nécessaires à la réalisation du PCB.
Ce fichier est composé de 3 dossiers.
    - **Projet Kicad** : contenant la première version de notre projet.
    - **Projet Kicad plan de masse** : contenant le même projet que le fichier ci-dessus mais avec la réalisation du plan de masse.
    - **Projet Kicad Aime plan de masse** : contenant le PCB du capteur de Gaz réalisé dans les locaux du AIME.

-   **LTSpice**: Contient les fichiers nécessaires à la partie éléctronique analogique.

  
### Partie collection de données et communication LoRA: 
Dans cette partie, nous avons testé la collection de données et communication LoRA avec un capteur de test:

<img width="360" height="280" src="Mosh/images_Mosh/image_mosh_final.jpg" title="Schéma PCB">
Ci-dessus l'image du montage permettant d'interconnecter le module LoRa, l'Arduino UNO et le capteur de Gaz.
Ci-dessous une série d'images montrant le résultat de notre montage avec la réception et l'envoi de la valeur du capteur.

![Schéma PCB](/Mosh/images_Mosh/result_pot_dernierevaleur.png)
![Schéma PCB](/Mosh/images_Mosh/Resultat_potentiometre.png)
![Schéma PCB](/Mosh/images_Mosh/valeur_internetthings.png)
### Partie construction du shield/PCB: 
Dans cette partie, nous avons construit notre propre shield/PCB grâce à KiCAD :

Un Zoom sur la conception du capteur de Gaz AIME sur Eeschema:

![Schéma électronique du capteur](/Kicad/Projet_Kicad_Aime_plan_masse/image_capteur.png)

Puis ci-dessous, l'ensemble du Capteur Intelligent designé sur Eeschema:

![Schéma électronique du capteur intelligent](/Kicad/Projet_Kicad_Aime_plan_masse/capture_Aime_capteur_Eeaschema.png)

Conception du layout avec le traçage des routes et la création des footprints et leur positionnement sur la carte.


![Schéma PCB](/Kicad/Projet_Kicad_Aime_plan_masse/PCB_final_Aime_Capteur.png)

Vue 3D de la carte avec et sans plan de masse:
![Schéma Shield Avant 3D](/Kicad/Projet_Kicad_Aime_plan_masse/PcB_Aime_Sensor.png)
![Schéma Shield 3D](/Kicad/Projet_Kicad_Aime_plan_masse/Sensor_Aime_shield_3D.png)

Si nous réduisons le nombre de route sur le devant de la carte pour privilégier l'arrière:

![Schéma PCB](/Kicad/Projet_Kicad_Aime_plan_masse/PCB_final_Aime_Capteur_2.png)

![Schéma Shield Avant 3D](/Kicad/Projet_Kicad_Aime_plan_masse/PcB_Aime_Sensor_2.png)

![Schéma Shield Avant 3D](/Kicad/Projet_Kicad_Aime_plan_masse/PcB_Aime_Shield_arriere_3D.png)



Nous avons réalisé un plan de masse pour réduire la consommation en cuivre et limiter le routage en une seule couche. En effet, nous avons  supprimé toutes les routes sur la couche avant de notre shield(rouge) présentent sur la photo ci-dessus.
Le plan de masse permet également de réaliser le routage sur une seule couche, la couche arrière  de notre Shield. Pour finir, nous avons ainsi respecté les contraintes de routage définies par l'INSA.

### Partie électronique analogique: 
Concernant cette partie, nous avons étudier, en utilisant LTSPice IV, la partie électronique analogique du module Smart Device où nous serons amené à mesurer la résistance, le faible courant avec un microcontrôleur et effectuer un filtrage passe bas pour extraire les informations utiles de notre capteur de gaz. 

<a href="/LTspice/UF_Smart_Device_ Partie_analogique_avec_LTSpice_IV.pdf">Rapport_LTSPice</a>


### Choix de Conception

 - Nous avons modifié la forme du contour du shield en un rectangle plus grand que l'Arduino UNO pour faciliter le routage et l'inclusion de la puce LoRa.

- Au niveau du PCB, nous avons du faire face à des avertissements de type "Pad près d'un pad" au moment de la validation de notre PCB. Nous avons remarqué que ces messages ciblés les capacité qui que nous avons choisi dans les librairie génériques qui se sont avérés plus petites que ceux que nous utiliserons en réalité. Les marges de pistes sont trop épaisses par rapport à l'espacement entre les 2 broches des capacités provoquant un chevauchent de celles-ci entre elles. Pour changer cela, il faudrait choisir d'autres empreintes pour ces composants, car compte tenu des contraintes de fabrication qui nous sont imposées, nous ne pouvons pas réduire l'épaisseur des pistes). 

- Nous avons effectué tous les routage sur une seule couche de cuivre sur la carte pour rendre possible sa fabrication à l'INSA. Les pistes sont sur la partie "Bottom" qui est aussi le plan de masse. Les composants sont quand eux positionnés sur la partie "Top".
