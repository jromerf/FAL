
// Nombre y Apellidos

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

#include <iostream>
#include <fstream>
#include <vector>

// función que resuelve el problema
/* P { 0 < n <= presos.size() and creciente(presos) }
*  Q { r = ( forall: i 0 <= i < n : presos[i] != r ) }
   Q { r = ( exist c : (forall i: 0 <= i < n : presos[i] != c) : c ))} //creo que este está bien
*/
char resolver(std::vector<char> presos,char c_act,char c_esperado, int i) {
    char r;
    if (c_act != c_esperado) {
        r = c_esperado;
    }
    else if (i == presos.size()) {
        r = c_esperado + 1;
    }
    else {
        r = resolver(presos, presos[i], c_esperado + 1, i + 1);
    }
    return r;
}

// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {

    // leer los datos de la entrada
    char ini, fin; int i = 0;
    std::cin >> ini >> fin;
    std::vector<char> presos(fin - ini);

    while (i < presos.size()) {
        std::cin >> presos[i];
        i++;
    }

    char sol = resolver(presos, presos[0], ini, 1);

    // escribir solución
    std::cout << sol << "\n";
}

int main() {
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("sample-C13.1.in");
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
