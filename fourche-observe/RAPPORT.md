# Binome:

- **Nadine SAADI**
- **Ilyas RACHEDI**

## Fonctions ajoutées à coté de truefalse [multif]

- "testfunc_sleep" : permet de faire la meme chose que testfunc mais avec une latance de temps diffirente (5 secondes pour "true" et 2 secondes pour "false") en utilisant un sleep

## Expérieces de l'exercice 7 [course]
Toujours la meme commande : 
```./course
```
- **expérience 1**
```
===============depart=============
je suis le fils num : 8
je suis le fils num : 9
je suis le fils num : 1
je suis le fils num : 2
je suis le fils num : 4
je suis le fils num : 3
je suis le fils num : 0
je suis le fils num : 7
je suis le fils num : 6
je suis le fils num : 5

===============arrive=============
je suis le fils num : 1
je suis le fils num : 9
je suis le fils num : 8
je suis le fils num : 4
je suis le fils num : 2
je suis le fils num : 6
je suis le fils num : 5
je suis le fils num : 0
je suis le fils num : 3
je suis le fils num : 7

```
- **expérience 2**
```
===============depart=============
je suis le fils num : 2
je suis le fils num : 0
je suis le fils num : 8
je suis le fils num : 6
je suis le fils num : 1
je suis le fils num : 9
je suis le fils num : 4
je suis le fils num : 3
je suis le fils num : 7
je suis le fils num : 5

===============arrive=============
je suis le fils num : 1
je suis le fils num : 2
je suis le fils num : 0
je suis le fils num : 5
je suis le fils num : 6
je suis le fils num : 8
je suis le fils num : 9
je suis le fils num : 3
je suis le fils num : 7
je suis le fils num : 4
```
- **expérience 3**
```
===============depart=============
je suis le fils num : 0
je suis le fils num : 5
je suis le fils num : 3
je suis le fils num : 8
je suis le fils num : 1
je suis le fils num : 9
je suis le fils num : 7
je suis le fils num : 2
je suis le fils num : 4
je suis le fils num : 6

===============arrive=============
je suis le fils num : 0
je suis le fils num : 1
je suis le fils num : 5
je suis le fils num : 2
je suis le fils num : 3
je suis le fils num : 8
je suis le fils num : 6
je suis le fils num : 9
je suis le fils num : 4
je suis le fils num : 7
```

## Réponses aux questions de l'exercice 8 [observe]
 
**Question1**
Le pseudo-code du programme:

Debut
	int N <- 3
	pid : pid_t
	status : entier

	pour i allant de 0 a N par pas de 1 Faire
	        forker le processus et garder la valeur de retour dans pid
	        switch(pid)
	      	  case -1
	      	      Message d'erreur et un exit failure
	      	  case 0
	              Tant que 1 (True) Faire
	        	  imprimer un message qui affiche le pid du fils et de son pere
	        	  sleep(5)
	              Fin boucle
	Fin boucle

	vérifier que system("ps -a") n'est pas égal a -1
	Tant que wait(NULL) n'est pas égal à -1 faire
   	    afficher une chaine de caractères qui montre que le processus est terminé
	Fin boucle
Fin

   
**Question2**
En utilisant la commande kill sur le processus père dans le terminal, tout les processus qu'il a crée sont devenus des processus orphelins, avec comme père le processus de pid 1.

**Question3**
En tuant un des processus fils, ce dernier devient un processus zombie ( en utilisant la commande ps -a, on voit <defunct> s'afficher sur la ligne qui décrit le processus ). Cela est arrivé car le processus fils a terminé son exécution, mais il reste présent sur le système, en attente d'etre pris en compte par son père.
	
