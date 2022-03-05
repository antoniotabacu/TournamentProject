Mai intai retin numarul de echipe din fisier intr-o variabila pe care o voi pasa mai departe ca parametru anumitor functii care necesita sa cunoasca numarul de echipe, sau pentru a o modifica atunci cand numarul de echipe va deveni gradual mai mic.

Pentru prima cerinta generez lista intreaga de echipe prin adaugarea elementelor la inceput cu functia generate_list(). Apoi scriu in fisier folosind functia print_list().

Pentru a doua cerinta folosesc functiile nr_teams() si nr_teams_two() pentru a calcula cea mai apropiata putere a lui 2, numar ce va deveni noul numar de echipe pentru lista. Cu functia remove_element() calulez numarul de echipe care trebuie eliminate si elimin cate un element din lista pana cand raman cate trebuie. Folosesc, apoi, din nou print_list() pentru a scrie noua forma a listei in fisier. Daca checker-ul solicita cerinta doi, nu mai printez lista nefiltrata.

Pentru cerinta trei folosesc functia generate_q() pentru a genera coada, folosindu-se de lista creata anterior. Aceasta parcurge lista, grupeaza echipele cate doua generand un obiect de tipul MATCH pe care il introduce apoi in coada. Coada generata este folosita apoi ca parametru pentru functia generate_stiva(), care verifica echipele din fiecare meci si o introduce in stiva pe cea castigatoare(in cazul stivei de looseri se alege echipa care pierde).
Primul caz al acestui proces este tratat separat, iar apoi se continua cu functia regenerate_q(), care spre deosebire de generate_q(), se foloseste de o stiva pentru generarea cozii, nu de o lista.
Echipele sunt afisate in cadrul rundelor la fiecare etapa a acestui proces pana cand ramane o singura echipa.

Pentru cerinta patru, cand numarul de echipe devine 8, acestea sunt preluate din ultima stiva si introduse in arborele BST prin functia top8(). Aceasta parcurge stiva si introduce echipele in arbor, prima echipa devenind root-ul arborelului.
Functia Inorder traverseaza subarborii din stanga si dreapta si afiseaza echipele in ordinea punctajului si a denumirii.
Functia Inorder_to_stiva, inlocuieste scrierea in fisier cu transferarea echipelor sortate intr-o noua stiva. Inversez aceasta stiva pentru a putea pastra ordinea echipelor atunci cand le transfer in AVL. (ar fi fost mai eficient sa fac asta cu o coada pentru a nu mai fi nevoie de inversare, dar scrisesem functia pentru avl cand credeam ca trebuie folosite nesortate, inainte de BST, si ca pot folosi aceeasi stiva ca pentru BST).

Pentru cerinta 5 folosesc functia create_AVL(), care parcurge stiva si introduce echipele in arbore folosind functia avlInsert(). Aceasta foloseste functia AVLFixUp() care echilibreaza arborele prin rotatii. Radacina este mentinuta in root->left pentru a evita cazuri particulare si a usura implementarea. Am folosit root->nil pentru evitarea citirii din noduri nule. Afisez apoi echipele de pe nivelul doi folosind functia print_avl_level(), care creste nivelul la fiecare apel recursiv.

Toate obiectele alocate dinamic precum lista, stivele, coada si arborii sunt dezalocate dupa ce nu mai sunt folosite.