
// Nombre y Apellidos

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

#include <iostream>
#include <fstream>
#include <vector>



int sumando(std::vector<int> imagen,int c ,int f) {
    int total = 0;
    if (c == f)
        total = imagen[c];
    else if (c == f - 1) {
        total = imagen[c] + imagen[f];
    }
    else {
        int m = (c + f) / 2;
        total += sumando(imagen, c, m);
        total += sumando(imagen, m + 1, f);
    }
    return total;
}



int divideyvenceras(const std::vector<int> &imagen, int c , int f,bool &degradado) {
    int r = 0;
    if (c == f) { 
        //2^0 = 1 
        r = imagen[c];
        degradado = true;
    }
    else if (c == f - 1) {
        r = imagen[c] + imagen[f];
        degradado = imagen[c] < imagen[f];
    }
    else {
        int m = (c + f) / 2;
        bool deg1 = true, deg2 = true;
        int r1 = 0, r2 = 0;
        r1 += divideyvenceras(imagen, c, m,deg1);
        r2 += divideyvenceras(imagen, m + 1, f,deg2);
        degradado = deg1 && deg2 && (r1 < r2);
        r = r1 + r2;
    }
    return r;
}

// función que resuelve el problema
// comentario sobre el coste, O(f(N)), donde N es ...
bool resolver(const std::vector<std::vector<int>> &imagen, const int &filas ) {
    bool degradado = true; int suma = 0;
    for (int i = 0; i < filas && degradado == true; i++)
        suma = divideyvenceras(imagen[i], 0, imagen[i].size() - 1,degradado);
    return degradado;
}

// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {

    // leer los datos de la entrada
    int n, m;

    std::cin >> n >> m;
    if (!std::cin)  // fin de la entrada
        return false;

    std::vector<std::vector<int>> imagen(n,std::vector<int>(m));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            std::cin >> imagen[i][j];

    bool sol = resolver(imagen,n);

    // escribir sol
    if (sol == true) std::cout << "SI\n";
    else std::cout << "NO\n";
    return true;
}

int main() {
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("sample-C17.1.in");
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
