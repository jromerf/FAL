
// Nombre y Apellidos

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

#include <iostream>
#include <fstream>
#include <vector>

// función que resuelve el problema
// comentario sobre el coste, O(f(N)), donde N es ...
int resolver(const std::vector<int> &elems,int ini,int fin) {
    int r,mitad;

    if (ini == fin - 1) {
        if (elems[ini] > elems[fin])
            r = elems[fin];
        else
            r = elems[ini];
    }
    else {
        mitad = (ini + fin) / 2;
        if (elems[ini] > elems[mitad]) {
            ini = mitad; //r = resolver(elems, mitad, fin);
        }
        else {
            fin = mitad; //r = resolver(elems, ini, mitad);
        }
        r = resolver(elems, ini, fin);
    }
    return r;
}

// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {

    // leer los datos de la entrada
    int n, i = 0;
    std::cin >> n;

    if (!std::cin)  // fin de la entrada
        return false;
    std::vector<int> elems(n);
    while (i < n) {
        std::cin >> elems[i];
        i++;
    }

    int sol = resolver(elems,0,elems.size()-1);

    // escribir sol
    std::cout << sol << "\n";
    return true;
}

int main() {
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("sample-C14.1.in");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

    while (resuelveCaso());

    // para dejar todo como estaba al principio
#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif
    return 0;
}
