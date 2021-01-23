
// Nombre y Apellidos

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

#include <iostream>
#include <fstream>

struct estados{
    int picos;
    int valles;
};


// función que resuelve el problema
// El coste O(n) donde n = numero de elementos del array temperaturas 
//Q ={  p = #x: 0 < x < N and (v[x-1] < v[x] and v[x] > v[x+1]) 
//      v = #y: 0 < y < N and (v[y-1] > v[y] and v[y] < v[y+1]) }        
estados resolver(const int temperaturas[],int n) {
    estados res = { 0,0 };
    
    int i = 1;

    while (i < n - 1)
    {
        if (temperaturas[i - 1] < temperaturas[i] && temperaturas[i] > temperaturas[i + 1])
            res.picos++;
        if (temperaturas[i - 1] > temperaturas[i] && temperaturas[i] < temperaturas[i + 1])
            res.valles++;
        i++;
    }

    return res;
}

// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    int N; 
    std::cin >> N; 
    // leer los datos de la entrada

    int temperaturas[10000],i=0;
    while (i<N) {
        
        std::cin >> temperaturas[i];
        i++;
    }
    
    estados sol = resolver(temperaturas,N);

    // escribir solución
    std::cout << sol.picos << " " << sol.valles << "\n";
}

int main() {
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("sample-C01.1.in");
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
