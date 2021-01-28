
// Nombre y Apellidos

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

#include <iostream>
#include <fstream>


// función que resuelve el problema
// comentario sobre el coste, O(f(N)), donde N es ...
bool resolver(int num, int &s_iz,int &s_dr,int digito_actual) {
    bool r = true;
    if (num / 10 == 0) {
        s_iz = num % 10;
    }
    else {
        int digito_actual = num % 10;
        s_dr += digito_actual;
        r = resolver(num/10, s_iz, s_dr,digito_actual);

        if ((s_iz % digito_actual == 0 )&& 
            ((s_dr - digito_actual) % digito_actual  == 0) && digito_actual != 0 &&  r == true)
            r = true;
        else
            r = false;

        s_iz += digito_actual;
        s_dr -= digito_actual;
    }
    return r;
}

// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    int num, s_iz = 0, s_dr = 0,digito_actual = 0;
    // leer los datos de la entrada
    std::cin >> num;
    int sol = resolver(num,s_iz,s_dr,digito_actual);

    // escribir solución
    if (sol == true)
        std::cout << "SI\n";
    else
        std::cout << "NO\n";
}

int main() {
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("casos.txt");
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
