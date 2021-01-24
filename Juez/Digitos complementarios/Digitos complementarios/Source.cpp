
// Nombre y Apellidos

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

#include <iostream>
#include <fstream>

struct resultado {
    int complementario;
    int inverso;
};

int inverso(int num,int &multiplicador,int &tamInv) {
    int r;
    if (num / 10 == 0) {
        r = num;
        multiplicador = 1;
    }
    else {
        r = inverso(num / 10, multiplicador,tamInv);
        multiplicador *= 10;
        r = num % 10 * multiplicador + r;
        tamInv*=10;
    }
    return r;
}

int complementario(int num,int multiplicador,int & tamComp) {
    int r;
    if (num / 10 == 0) {
        r = abs(num - 9)*multiplicador;
    }
    else {
        
        r = complementario(num / 10,multiplicador*10, tamComp);
        r = abs((num % 10) - 9) * multiplicador + r;
        tamComp *=10;
    }
    return r;
}

// función que resuelve el problema
// comentario sobre el coste, O(f(N)), donde N es ...
resultado resolver(int num) {
    resultado res = { 0,0 };
    int multiplicador = 1,tamComp = 1, tamInv = 1;
    res.complementario = complementario(num,multiplicador, tamComp);
    res.inverso = inverso(res.complementario, multiplicador, tamInv) * (tamComp/ tamInv);
    return res;
}

// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {

    // leer los datos de la entrada
    int num;
    std::cin >> num;
    
    resultado sol = resolver(num);

    // escribir solución
    std::cout << sol.complementario << " " << sol.inverso << "\n";
}

int main() {
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("sample-C11.1.in");
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
