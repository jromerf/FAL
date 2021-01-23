
// Nombre y Apellidos

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

// función que resuelve el problema
// comentario sobre el coste, O(f(N)), donde N es ...
//int resolver(const std::vector<int> &mapa) {
//    int i = 0,tramo_mas_largo = 0, cntTramo = 1;
//
//    while (i < mapa.size() - 1) {
//        if (mapa[i] >= mapa[i + 1]) {
//            cntTramo++;
//            if (cntTramo > tramo_mas_largo)
//                tramo_mas_largo = cntTramo;
//        }
//        else
//            cntTramo = 1;
//        i++;
//    }
//    return tramo_mas_largo;
//}

//int resolver(const std::vector<int>& mapa) {
//    int i = mapa.size() - 1, cntTramo = 1,maxTramo = 0;
//
//    while (i > 0) {
//        if (mapa[i-1] >= mapa[i]) {
//            cntTramo++;
//        }
//        else {
//            cntTramo = 1;
//        }
//        if(maxTramo < cntTramo)
//            maxTramo = cntTramo;
//        i--;
//    }
//    return maxTramo;
//}

int resolver(const std::vector<int>& mapa) {
    
    int maxTramo = 0,N = mapa.size();
    if (N != 0) {
        int n = 1, longitud = 1;
        while (n != mapa.size()) {
            if (mapa[n - 1] >= mapa[n])
                longitud++;
            else
                longitud = 1;
            maxTramo = std::max(longitud,maxTramo);
            n++;
        }
    }
    return maxTramo;
}


// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {

    // leer los datos de la entrada
    int n, i = 0;
    std::cin >> n;
    std::vector<int> mapa(n);

    while (i < n) {
        std::cin >> mapa[i];
        i++;
    }

    int sol = resolver(mapa);

    // escribir solución
    std::cout << sol << "\n";
}

int main() {
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("sample-C09.1.in");
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
