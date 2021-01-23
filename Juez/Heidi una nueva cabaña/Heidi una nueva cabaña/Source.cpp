
// Nombre y Apellidos

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

#include <iostream>
#include <fstream>
#include <vector>

// función que resuelve el problema
// comentario sobre el coste, O(f(N)), donde N es ...
std::vector<int> resolver(std::vector<int> &valle,int l,int &cad_mas_larga) {
    std::vector<int> llanos(valle.size());
    int i = valle.size() - 2,max = valle[valle.size() - 1],reps = 1,j = 0;
    cad_mas_larga = 0;
    while (i >= 0) {
        if (valle[i] == valle[i + 1] && valle[i] >= max) {
            reps++;
            if (reps == l) {
                llanos[j] = i + l - 1;
                j++;
            }
        }
        else {
            reps = 1;
        }
        if (valle[i] > max)
            max = valle[i];
        if (reps >= l)
            cad_mas_larga = reps;
        i--;
    }
    llanos.resize(j);
    return llanos;
}

// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {

    // leer los datos de la entrada
    int datos, l,i = 0,cad_mas_larga;
    std::cin >> datos >> l;

    if (!std::cin)  // fin de la entrada
        return false;

    std::vector<int> valle(datos);

    while (i < datos) {
        std::cin >> valle[i];
        i++;
    }
    
    std::vector<int> sol = resolver(valle,l,cad_mas_larga);

    // escribir sol
    i = 0;
    std::cout << cad_mas_larga << " " << sol.size();
    while (i < sol.size()) {
        std::cout << " " << sol[i];
        i++;
    }
    std::cout << "\n";
    return true;
}

int main() {
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("sample-C08.1.in");
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
