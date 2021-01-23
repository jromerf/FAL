
// Nombre y Apellidos

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

#include <iostream>
#include <fstream>
#include <vector>


// función que resuelve el problema
// comentario sobre el coste, O(f(N)), donde N es ...
/*
bool resolver(std::vector<int> elems,int d) {
    
    int i = 0, j = 1;
    bool esDivertido = true, esMayor = false;
    std::vector<int> repeticiones(1000);

    while (i < elems.size()) {
        repeticiones[elems[i]]++;
        if (repeticiones[elems[i]] > d)
            esDivertido = false;
        i++;
    }

    while (j < elems.size() && esMayor == false && esDivertido == true) {
        if (elems[j - 1] > elems[j] || abs(elems[j-1] - elems[j]) > 1)
            esMayor = true;
        j++;
    }

    return esDivertido && !esMayor;
}
*/

/* P { 0 <= n <= 1000 and d > 0 }
*  Q { b = (forall i: 0 <= i <= n-1: not esMayor(elems) and esDivertido(elems,d)) donde 
        esMayor = (forall j : 0 <= j <= n-1 : (elems[j] > elems[j+1]) or (elems[j+1] - elems[j] > 1))
        esDivertido = ((#k : 0 <= k <= n-1 : elems[k] = elems[k+1]) <= d) }
   Coste O(n) donde n = elems.size()
*/
bool resolver(std::vector<int> elems, int d) {

    int i = 0, reps = 0;
    bool esDivertido = true, esMayor = false;

    while (i < elems.size() - 1  && !esMayor && esDivertido) {

        if (elems[i] > elems[i + 1] || elems[i + 1] - elems[i] > 1)
            esMayor = true;
        /*En este algoritmo podemos verificar sólo con el siguiente porque el problema nos indica que la diferencia entre v[i] y v[i+1] puede ser de 
        como máximo 1, si no dijera esto y sólo pusiera que es estrictamente creciente , este algoritmo no valdría, valdría el anterior*/
        if (elems[i] == elems[i + 1]) 
            reps++;
        else 
            reps = 0;
        if (d <= reps)
            esDivertido = false;
        i++;
    }
    return esDivertido && !esMayor;
}


// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {

    // leer los datos de la entrada
    int d, n, i = 0;
    std::cin >> d >> n;
    std::vector<int> elems(n);

    while (i < n) {
        std::cin >> elems[i];
        i++;
    }

    bool sol = resolver(elems,d);

    // escribir solución
    if (sol == true) std::cout << "SI\n";
    else std::cout << "NO\n";
}

int main() {
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("sample-C06.1.in");
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
