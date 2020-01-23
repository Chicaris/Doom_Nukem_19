# Doom_Nukem_19

Jeu FPS 3D, mélange de Doom et de Duke Nukem, effectué grace à un raycasting 3D. Réalisation du cursus de l'ecole 19 (petite soeur belge de l'ecole 42 à Paris) en C et normé selon les normes de 42 (5 fonctions/fichiers, 25 lignes/fonctions...).


# ENGINE

Nous sommes partis sur un raycasting 3D pour réaliser ce projet pour plusieurs raisons. La première etant pour avoir une précision maximale de l'affichage (pas de distortion due à projection 2D vers 3D) et une vision posible dans n'importe quelle direction. Et la deuxième raison etant le challenge de faire ca d'une manière originale et interessante (niveau math et faisceau de vecteurs). 

<p align="center">
  <img src="/screenshot/screen10.png" width="300px"</img> 
</p>

Nous envoyons donc un vecteur partant du point d'origine de la camera, vers chaque pixel sur le plan de projection. Et ensuite, nous cherchons le pixel du point d'impacte le plus proche de notre labyrinth et le comparons avec le point d'impacte du monstre/objet le plus proche et affichons finalement le bon pixel ainsi trouvé.

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

Notre engine demandant une structure de map bien précise, ils nous etaient donc indispensable de faire un editeur afin de faciliter les tests et de permettre à l'utilisateur de créer ses propres labyrinth, positionner les divers objets (armes, munitions, clefs...) et aussi de positionner les monstres.

<p align="center">
     <img src="/screenshot/screen09.png" width="600px"</img>
</p>

<p align="center">
     <img src="/screenshot/screen08.png" width="600px"</img>
</p>

