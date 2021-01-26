
// Nombre y Apellidos Javier Romero 

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

#include <iostream>
#include <fstream>
#include <vector>

/*

Como el vector está ordenado de forma creciente podemos determinar que si lo cantado más la suma de un indice i es < que el valor del vector en ese indice

cantado + i < cartilla[i] 

entonces podemos seguir buscando por la izquierda ya que tanto la suma de i + cantado será siempre menor que lo que hay en cartilla[i], lo mismo sucedería
para un valor mayor que cartilla[i], en este caso se tendría que encontrar a la derecha, es basicamente como una búsqueda donde el número buscado va variando
en cada iteración pero siempre sabemos si este es menor, mayor o igual al que encontremos en cartilla[i], vamos eliminando sectores del vector que no nos interesan
y cuando nos encontremos en una situacion de sólo 2 elementos, tenemos sólo dos opciones, que uno de ellos sea correcto o ninguno (C.B)

De esta forma tenemos un algoritmo con coste O(logn) donde n es igual al número de elementos del vector.
*/
/*solucionamos con ini y fin y con mitad */
int resolver(const std::vector<int>& cartilla, const int& cantado, int ini,int fin) {
    int r = -1;

    if (fin - 1 <= ini) {

        if (cantado + fin == cartilla[fin])
            r = cartilla[fin];
        if (cantado + ini == cartilla[ini])
            r = cartilla[ini];
    }
    else {
        int m = (ini + fin) / 2;
        if (cantado + m <= cartilla[m]) {
            r = resolver(cartilla, cantado, ini, m);
        }
        else {
            r = resolver(cartilla, cantado, m, fin);
        }
    }

    return r;
}

/****************** NO HACER CASO A LO DE ABAJO **********************/
//int resolver(const std::vector<int>& cartilla, const int& cantado, int pos) {
//    int r = -1;
//    if (pos < cartilla.size()-1) {
//
//        if (cantado + pos == cartilla[pos]) {
//            r = cartilla[pos];
//        }
//        else {
//            r = resolver(cartilla, cantado, pos + 1);
//        }
//    }
//    return r;
//}

// función que resuelve el problema
// comentario sobre el coste, O(f(N)), donde N es ...
//int resolver(const std::vector<int> &cartilla,const int &cantado,int pos) {
//    int r = -1;
//
//    if (cantado + pos <= cartilla[pos]) {
//        if (cantado + pos == cartilla[pos])
//            r = cartilla[pos];
//        else {
//            r = resolver(cartilla,cantado,pos-1);
//        }
//    }
//    return r;
//}
/****************** NO HACER CASO A LO DE ARRIBA **********************/

// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {

    // leer los datos de la entrada
    int n, cantado;
    std::cin >> n >> cantado;
    std::vector<int> cartilla(n);

    for (int i = 0; i < n; i++)
        std::cin >> cartilla[i];

    int sol = resolver(cartilla, cantado, 0, cartilla.size() - 1);

    // escribir solución
    if (sol == -1)
        std::cout << "NO\n";
    else
        std::cout << sol << "\n";
}

int main() {
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("sample-C15.1.in");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

    int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();

    // para dejar todo como estaba al principio
#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif
    return 0;
}
