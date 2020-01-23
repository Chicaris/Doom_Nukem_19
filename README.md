# Doom_Nukem_19

Jeu FPS ("First Person Shooter") 3D; mélange de Doom et de Duke Nukem, effectué grâce à un raycasting 3D sur API SDL. Réalisation du cursus de l'école 19 (petite soeur belge de l'école 42 à Paris) en C et normé selon les normes de 42 (5 fonctions/fichiers, 25 lignes/fonctions...).


# ENGINE

Nous sommes partis sur un raycasting 3D pour réaliser ce projet pour plusieurs raisons. La première étant pour avoir une précision maximale de l'affichage (pas de distortion due à une projection 2D vers 3D) et une vision posible dans n'importe quelle direction. Et la deuxième raison étant le challenge de faire ca d'une manière originale et intéressante (niveau math et faisceau de vecteurs). 

<p align="center">
  <img src="/screenshot/screen10.png" width="300px"</img> 
</p>

Nous générons donc un vecteur partant du point d'origine de la caméra, vers chaque pixel sur le plan de projection. Ensuite, nous cherchons le pixel du point d'impact  avec l'objet le plus proche dans notre labyrinthe ainsi que sa couleur à partir de la texture y étant associée, le comparons avec le point d'impact  du monstre/objet dynamique le plus proche et affichons finalement le  pixel ainsi trouvé ... en utilisant la librairie sans support GPU

<p align="center">
  <img src="/screenshot/screen06.png" width="600px"</img> 
</p>

<p align="center">
    <img src="/screenshot/screen01.png" width="400px" height="400"</img> 
    <img src="/screenshot/screen00.png" width="400px" height="400"</img> 
    <img src="/screenshot/screen02.png" width="400px" height="400"</img>
    <img src="/screenshot/screen03.png" width="400px" height="400"</img>
    <img src="/screenshot/screen04.png" width="400px" height="400"</img>
    <img src="/screenshot/screen07.png" width="400px" height="400"</img>
</p>

# EDITOR

Notre "game engine" demandant une structure de jeu (carte, objects, textures, animations,...)  bien précise, il   était donc indispensable de créer un éditeur afin de faciliter les tests et de permettre à l'utilisateur de créer ses propres labyrinthes, positionner les divers objets (murs, armes, munitions, monstres, clefs, ...) .


<p align="center">
     <img src="/screenshot/screen09.png" width="600px"</img>
</p>

<p align="center">
     <img src="/screenshot/screen08.png" width="600px"</img>
</p>

