
// Nombre y Apellidos

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

#include <iostream>
#include <fstream>
#include <vector>



void tratarSolucion(const std::vector<int>& sol,const std::vector<int> &usadas,int &sols,std::vector<int> &cadena) { 

    if (usadas[0] > usadas[1] + usadas[2]) {
        int i = sols * sol.size(), j = 0;
        sols++;
        cadena.resize(sol.size() * sols);

        for (i; i < sol.size()*sols; i++) {
            cadena[i] = sol[j];
            j++;
           /* switch (sol[i])
            {
            case 0:
                std::cout <<"rojo ";
                break;
            case 1:
                std::cout << "azul ";
                break;
            case 2:
                std::cout << "verde ";
                break;
            default:
                break;
            }*/
        }
    //std::cout << "\n";
    }
}

// 0 = rojo , 1 = azul , 2 = verde
bool esValida(const std::vector<int> &sol,int k ,const std::vector<int> &usadas,const std::vector<int> &piezas) {

    if (sol[0] != 0)//si el primero no es rojo
        return false;
    
    if (usadas[sol[k]] >= piezas[sol[k]]) //haya suficientes piezas para poner
        return false;
    if (k >= 2) // no 2 verdes seguidos
        if (sol[k - 1] == sol[k] == 2)
            return false;
    if (sol[k] == 2) //si hay un verde 
        if(!(usadas[2] < usadas[1])) // v < a
            return false;

    return true;
}

void vueltaAtras(std::vector<int> &sol,int k,std::vector<int> &usadas,const std::vector<int> &piezas,int &sols,std::vector<int> &cadena){
    for (int i = 0; i < piezas.size(); i++) {
        sol[k] = i;
        if (esValida(sol, k, usadas, piezas)) {
            usadas[sol[k]]++;
            if (k == sol.size() - 1) {
                tratarSolucion(sol,usadas,sols,cadena);
            }
            else {
                vueltaAtras(sol, k + 1, usadas, piezas,sols,cadena);
            }
            usadas[sol[k]]--;
        }
    }
}


// función que resuelve el problema
// comentario sobre el coste, O(f(N)), donde N es ...
void resolver(int tam,const std::vector<int> &piezas) {
    std::vector<int> usadas(3,0);
    std::vector<int> sol(tam);
    std::vector<int> cadena;
    int sols = 0;
    vueltaAtras(sol, 0, usadas, piezas,sols, cadena);

    int c = 0, f = 0;;
    if (cadena.size() > 0) {
        for(int i = cadena.size() - tam; i >= 0; i = i - tam) {
            c = i; 
            f = c + tam;
            for (int j = i; j < f; j++) {
                switch (cadena[j])
                {
                case 0:
                    std::cout << "rojo ";
                    break;
                case 1:
                    std::cout << "azul ";
                    break;
                case 2:
                    std::cout << "verde ";
                    break;
                default:
                    break;
                }
            }
            std::cout << "\n";
        }

    }
    else {
        std::cout << "SIN SOLUCION \n";
    }
    std::cout << "\n";
}

// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {

    // leer los datos de la entrada
    int tam, a, r, v;

    std::cin >> tam >> a >> r >> v;

    if (tam == 0 && a == 0 && r == 0 && v == 0)
        return false;
    std::vector<int> piezas = { r,a,v }; //ordenadas por prioridad
    
    resolver(tam,piezas);

    // escribir sol
    std::cout << "\n";
    return true;
}

int main() {
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("sample-C20.1.in");
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
