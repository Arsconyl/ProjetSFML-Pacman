/*

Test des méthodes de base sur un graphe sauf les opérations de dessin

L'info associée aux sommets est un string  (par exemple)
L'info associée aux arêtes est un char     (par exemple)

*/
#include <iostream>
#include "Fenetre/Graphe.h"

using namespace std;
int main()
{
    //Graphe<char, string> g2;			// pour vérifier que l'opérateur = et que le destructeur fonctionnent bien


    Graphe<int,int> g1;	// création à vide
    //Sommet<int> * s0, *s1, *s2, *s3;
    Sommet<int> *S[25];

    //------------------ on insère des nouveaux sommets isolés --------------------

    /*s0 = g1.creeSommet('1');
    s1 = g1.creeSommet('2');
    s2 = g1.creeSommet('3');
    s3 = g1.creeSommet('4');*/

    for(unsigned int i = 0; i<25; i++)
    {
        S[i] = g1.creeSommet(i);
    }

    //----------------- on connecte certains sommets -------------------

    //Arete<int,int> * a0, * a1, *a2, *a3;
    Arete<int,int> *A[36];

    /*a0 = g1.creeArete(0,s1,s0);
    a1 = g1.creeArete(5,s2,s1);
    a2 = g1.creeArete(2,s3,s2);
    a3 = g1.creeArete(2,s3,s1);*/

    A[0] = g1.creeArete(-2, S[0], S[5]);
    A[1] = g1.creeArete(-1, S[0], S[6]);
    A[2] = g1.creeArete(0, S[0], S[1]);
    A[3] = g1.creeArete(-2, S[1], S[6]);
    A[4] = g1.creeArete(-1, S[1], S[7]);
    A[5] = g1.creeArete(0, S[1], S[2]);
    A[6] = g1.creeArete(-2, S[2], S[7]);
    A[7] = g1.creeArete(0, S[2], S[3]);
    A[8] = g1.creeArete(-2, S[3], S[8]);
    A[9] = g1.creeArete(0, S[3], S[4]);
    A[10] = g1.creeArete(-3, S[4], S[8]);
    A[11] = g1.creeArete(-2, S[4], S[9]);
    A[12] = g1.creeArete(-2, S[5], S[10]);
    A[13] = g1.creeArete(-1, S[5], S[11]);
    A[14] = g1.creeArete(0, S[5], S[6]);
    A[15] = g1.creeArete(-2, S[6], S[11]);
    A[16] = g1.creeArete(-1, S[6], S[12]);
    A[17] = g1.creeArete(0, S[6], S[7]);
    A[18] = g1.creeArete(-2, S[7], S[12]);
    A[19] = g1.creeArete(0, S[7], S[8]);
    A[20] = g1.creeArete(-2, S[8], S[13]);
    A[21] = g1.creeArete(0, S[8], S[9]);
    A[22] = g1.creeArete(-3, S[8], S[12]);
    A[23] = g1.creeArete(-3, S[9], S[13]);
    A[24] = g1.creeArete(-2, S[9], S[14]);
    A[25] = g1.creeArete(-2, S[10], S[15]);
    A[26] = g1.creeArete(0, S[10], S[11]);
    A[27] = g1.creeArete(-3, S[11], S[15]);
    A[28] = g1.creeArete(-2, S[11], S[16]);
    A[29] = g1.creeArete(0, S[11], S[12]);
    A[30] = g1.creeArete(-3, S[12], S[16]);
    A[33] = g1.creeArete(-2, S[12], S[17]);
    A[34] = g1.creeArete(-1, S[12], S[18]);
    A[35] = g1.creeArete(0, S[12], S[13]);
    A[36] = g1.creeArete(-2, S[13], S[18]);
    A[37] = g1.creeArete(-1, S[13], S[19]);
    A[38] = g1.creeArete(0, S[13], S[14]);
    A[39] = g1.creeArete(-2, S[14], S[19]);
    A[40] = g1.creeArete(-2, S[15], S[20]);
    A[41] = g1.creeArete(0, S[15], S[16]);
    A[42] = g1.creeArete(-3, S[16], S[20]);
    A[43] = g1.creeArete(-2, S[16], S[21]);
    A[44] = g1.creeArete(0, S[16], S[17]);
    A[45] = g1.creeArete(-3, S[17], S[21]);
    A[46] = g1.creeArete(-2, S[17], S[22]);
    A[47] = g1.creeArete(-1, S[17], S[23]);
    A[48] = g1.creeArete(0, S[17], S[18]);
    A[46] = g1.creeArete(-2, S[18], S[23]);
    A[47] = g1.creeArete(-1, S[18], S[24]);
    A[48] = g1.creeArete(0, S[18], S[19]);
    A[49] = g1.creeArete(-2, S[19], S[24]);
    A[50] = g1.creeArete(0, S[20], S[21]);
    A[51] = g1.creeArete(0, S[21], S[22]);
    A[52] = g1.creeArete(0, S[22], S[23]);
    A[53] = g1.creeArete(0, S[23], S[24]);

    A[54] = g1.creeArete(-3, S[3], S[7]);

    //------------------ faire le d8ssin du graphe sur papier en notant les noms et les degrés pour comprendre la suite ----------------
    /*cout << "Le graphe créé g1 est :" << endl << g1 << endl; //cin >> ch;

    cout << "Le nombre de sommets de g1 est : " << g1.nombreSommets() << endl;
    cout << "Le nombre d'arêtes de g1 est : " << g1.nombreAretes() << endl; //cin >> ch;

    PElement<Sommet<string>> * l0 = g1.voisins(s0);
    cout << "La liste des voisins de s0 est : " << endl << l0 << endl; //cin >> ch;

    PElement<Arete<char,string>> * adj0 = g1.aretesAdjacentes(s0);
    cout << "La liste des arêtes adjacentes à s0 est : " << endl << adj0 << endl; //cin >> ch;

    PElement<Sommet<string>> * l1 = g1.voisins(s1);
    cout << "La liste des voisins de s1 est : " << endl << l1 << endl;

    PElement<Arete<char,string>> * adj1 = g1.aretesAdjacentes(s1);
    cout << "La liste des arêtes adjacentes à s1 est : " << endl << adj1 << endl; //cin >> ch;

    Arete<char,string> * a = g1.getAreteParSommets(s1,s3);

    cout <<"L'arête joignant s1 et s3 est : " << endl << *a << endl; //cin >> ch;



    g2 = g1;
    			// à la fin de ce bloc, le destructeur est appelé pour g1.
			// cela permet de vérifier que l'op = a fait une vraie copie de g1

    cout <<"Le graphe créé g2 comme copie de g1 est :" << endl << g2 << endl; //cin >> ch;*/

    FenetreSFML<int, int> window;
    //sf::RenderWindow window(sf::VideoMode(1280, 720), "Graphe");

    while (window.isOpen())
    {
        // on inspecte tous les évènements de la fenêtre qui ont été émis depuis la précédente itération
        sf::Event event;
        while (window.pollEvent(event))
        {
            // évènement "fermeture demandée" : on ferme la fenêtre
            switch (event.type)
            {
                case sf::Event::Closed:
                {
                    window.close();
                    break;
                }
                default:
                    break;
            }
        }
        window.clear();
        g1.dessine(window);
        window.display();
    }

    return 0;
}
