
// Nombre y Apellidos

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

#include <iostream>
#include <fstream>
#include <vector>



// función que resuelve el problema
// comentario sobre el coste, O(f(N)), donde N es ...
int resolver(std::vector<int> v) {
    
    int i = 0, unos = 0, ceros = 0, res = -1;

    while (i < v.size()) {
        
        if (v[i] == 0)
            ceros++;
        if (v[i] == 1)
            unos++;
        if (ceros == unos)
            res = i;
        i++;
    }
    return res;
}

// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {

    // leer los datos de la entrada
    int N, i = 0; 
    std::cin >> N;
    std::vector<int> v(N);

    while (i < N) {
        std::cin >> v[i];
        i++;
    }

    int sol = resolver(v);

    // escribir solución
    std::cout << sol << "\n";
}

int main() {
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("sample-C05.1.in");
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
