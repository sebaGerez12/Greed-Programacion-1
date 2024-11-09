#include<iostream>
using namespace std;
#include "Funciones h Greed.h"
#include "rlutil.h"

// DEFINICIÓN DE FUNCIONES



//FUNCION DADOS BLOQUEADORES
//Generar los numeros aleatorios para los bloqueadores
void dadosBloqueadores(int &primerBloqueador, int &segundoBloqueador){
    primerBloqueador = rand() % 6 + 1;
    segundoBloqueador = rand() % 6 + 1;
}

//FUNCION DE TIRADA DE DADOS
//Genera los numeros aleatorios para la tirada de dados
void tiradaDeDados(int dados[], int cantidad){
        for (int i=0; i<cantidad; i++){
            dados[i] = rand() % 6 + 1;
        }
}

//FUNCION SUMAR DADOS
//Suma los dados de la tirada de dados ecepto los que son iguals a los bloqueadores
int sumaDeDados(int dados[], int cantidad, int primerBloqueador, int segundoBloqueador){
    int suma = 0;
    for (int i=0; i<cantidad; i++){
        if (dados[i] != primerBloqueador && dados[i] != segundoBloqueador)
        suma += dados[i];
    }
    return suma;
}

//FUNCION PARA CONTAR DADOS BLOQUEADORES
//Resta los dados de la tirada de dados en el caso que sean iguales a los bloqueadores
int contarDadosBloqueados(int dados[], int cantidad, int primerBloqueador, int segundoBloqueador){
    int dadosBloqueados = 0;
    for (int i=0; i<cantidad; i++){
        if(dados[i]==primerBloqueador || dados[i]== segundoBloqueador){
            dadosBloqueados++;
        }
    }
    return dadosBloqueados;
}

//FUNCION PARA VERIFICAR SI TODOS LOS DADOS RESTANTES SON IGUALES QUE LOS BLOQUEADORES
//Esto evalua si es que los dados de la tirada de dados son iguales a los de los bloqueadores no importa cual sea la n° de ronda
bool todosDadosCoincidenConBloqueadores(int dados[],int cantidad, int primerBloqueador, int segundoBloqueador){
    for (int i=0; i<cantidad; i++){
        if (dados[i] != primerBloqueador && dados [i] != segundoBloqueador){
            return false;
        }
    }
    return true;
}


//FUNCION MODO DE UN JUGADOR
void modoUnJugador(){

    string nombre;
    int primerBloqueador, segundoBloqueador;
    int cantidadDados = 5;
    int dados[cantidadDados];
    int ronda = 1;
    char decisionContinuarRonda = 's';
    int totalDePuntos = 0;

    cout << endl;
    rlutil::setColor(rlutil::BROWN);
    cout << "Ingrese nombre ---> ";
    rlutil::setColor(rlutil::BLUE);
    cin >> nombre;
    rlutil::setColor(rlutil::BROWN);
    cout << endl;
    system("cls");

    //Llamamos a la funcion de dados Bloqueadores por fuera del ciclo para que solo se active una vez
    dadosBloqueadores(primerBloqueador, segundoBloqueador);


    // Arranca el juego
    cout << "Inicia la partida. Buena suerte!" << endl << endl;
    rlutil::setColor(rlutil::BLUE);
    cout << nombre;
    rlutil::setColor(rlutil::BROWN);
    cout << ", Estas preparado?" << endl << endl;
    system("pause");
    system("cls");



    // Ciclo para continuar con la ronda
    while (decisionContinuarRonda == 's' || decisionContinuarRonda == 'S') {
        system("cls");
        rlutil::setColor(rlutil::BROWN);
            cout << "=============" << endl;
            cout << " RONDA " << ronda << endl;
            cout << "=============" << endl << endl;
            rlutil::setColor(rlutil::WHITE);
            cout << "Dados Bloqueadores ---> ";
            rlutil::setColor(rlutil::RED);
            cout << primerBloqueador << " | " << segundoBloqueador << endl << endl;
            rlutil::setColor(rlutil::WHITE);

            // LLamado a funcion para tirada de dados
            tiradaDeDados(dados, cantidadDados);
            cout << "Los dados lanzados dieron estos numeros ---> ";
            for (int i = 0; i < cantidadDados; i++) {
            rlutil::setColor(rlutil::GREEN);
            cout << dados[i] << " | ";
            rlutil::setColor(rlutil::WHITE);
            }

            // Dados que fueron bloqueados en esta ronda
            cout << endl << endl;
            int dadosBloqueados = contarDadosBloqueados(dados, cantidadDados, primerBloqueador, segundoBloqueador);
            cout << "Dados bloqueados esta ronda ---> ";
            rlutil::setColor(rlutil::RED);
            cout << dadosBloqueados << endl << endl;
            rlutil::setColor(rlutil::WHITE);

            // Contar cantidad de dados libres restantes
            int dadosLibres = cantidadDados - dadosBloqueados;
            cout << "Cantidad de dados libres que quedan para sumar ---> ";
            rlutil::setColor(rlutil::GREEN);
            cout << dadosLibres << endl << endl;
            rlutil::setColor(rlutil::WHITE);

            // Verificación de todos los dados restantes coincidan con los dados bloqueadores
            if (todosDadosCoincidenConBloqueadores(dados, cantidadDados, primerBloqueador, segundoBloqueador)) {
            rlutil::setColor(rlutil::RED);
            cout << "Todos los dados coinciden con los bloqueadores, " << nombre << " pierde todos los puntos acumulados." << endl;
            rlutil::setColor(rlutil::WHITE);
            //Entonces el total de puntos pasa a ser 0
            totalDePuntos = 0;
            }
            else {
            // Llamado a la funcion para Suma de dados
            int sumaDeRonda = sumaDeDados(dados, cantidadDados, primerBloqueador, segundoBloqueador);
            cout << "Suma de dados en esta ronda ---> ";
            rlutil::setColor(rlutil::GREEN);
            cout << sumaDeRonda << " puntos" << endl << endl;
            rlutil::setColor(rlutil::WHITE);
            // Suma total de puntos de las rondas hasta el momento
            totalDePuntos += sumaDeRonda;
            cout << "Acumulados hasta ahora para " << nombre << " ---> ";
            rlutil::setColor(rlutil::BROWN);
            rlutil::setBackgroundColor(rlutil::BLACK);
            cout << totalDePuntos << " puntos" << endl << endl << endl;
            rlutil::setColor(rlutil::WHITE);
            }
            // Restar los dados bloqueadores que coinciden con la tirada de dados
            cantidadDados -= dadosBloqueados;
            if (cantidadDados <= 0) {
            cout << endl;
            cout << "No quedan mas dados por tirar." << endl;
            break;
            }
            // Preguntar si se juega otra ronda
            if (ronda < 5) {
                    while (true) {
                        cout << nombre << ", queres jugar otra ronda? (";
                        rlutil::setColor(rlutil::GREEN);
                        cout << "S=SI ";
                        rlutil::setColor(rlutil::WHITE);
                        cout << "/";
                        rlutil::setColor(rlutil::RED);
                        cout << " N=NO";
                        rlutil::setColor(rlutil::WHITE);
                        cout << "): ";
                        cin >> decisionContinuarRonda;
                        if (decisionContinuarRonda == 's' || decisionContinuarRonda == 'S') {
                                break; // Continua jugando
                                }
                                else if (decisionContinuarRonda == 'n' || decisionContinuarRonda == 'N') {
                                    system("cls");
                                    rlutil::setColor(rlutil::BROWN);
                                    cout << "Tomaste la desicion de no jugar esta ronda." << endl << endl;
                                    rlutil::setColor(rlutil::WHITE);
                                    break; // Termina el juego
                                    }
                                    else { // Caracter incorreto a S o N
                                            rlutil::setColor(rlutil::RED);

                                        cout << "--------------------------------------------------------------------------------------" << endl;
                                        cout << "OPCION INVALIDA. Por favor, ingresa 'S' para continuar o 'N' para no jugar otra ronda." << endl;
                                        cout << "______________________________________________________________________________________" << endl << endl;
                                        rlutil::setColor(rlutil::WHITE);
                                        }
                                    }
            }
            else {
            rlutil::setColor(rlutil::BROWN);
            cout << "Ya no se permiten mas tiradas." << endl << endl << endl << endl;
            rlutil::setColor(rlutil::WHITE);
            break;
            }
            ronda++;
    }
    system("pause");
    system("cls");

    cout << "------------------------------------------------"<< endl;
    cout << "Juego terminado. ";
    rlutil::setColor(rlutil::BLUE);
    cout << nombre;
    rlutil::setColor(rlutil::WHITE);
    cout << " cosecha un total de ";
    rlutil::setColor(rlutil::BROWN);
    cout << totalDePuntos;
    rlutil::setColor(rlutil::WHITE);
    cout << " puntos! " << endl;
    cout << "------------------------------------------------"<< endl << endl << endl;
    system("pause");
    system("cls");
}



// FUNCION MODO DE DOS JUGADORES
void modoDosJugadores() {

    string nombreJ1, nombreJ2;
    int primerBloqueador, segundoBloqueador;
    int cantidadDados = 5;
    int dados[cantidadDados];
    int ronda = 1;
    char decisionContinuarRonda = 's';
    int totalDePuntosJ1 = 0, totalDePuntosJ2 = 0;
    int mejorPuntaje = 0;
    string mejorJugador;

    cout << endl;
    rlutil::setColor(rlutil::BROWN);
    cout << " Ingrese nombre para Jugador 1 ---> ";
    rlutil::setColor(rlutil::BLUE);
    cin >> nombreJ1;
    rlutil::setColor(rlutil::BROWN);
    cout << endl;
    cout << " Ingrese nombre para Jugador 2 ---> ";
    rlutil::setColor(rlutil::GREEN);
    cin >> nombreJ2;
    rlutil::setColor(rlutil::BROWN);
    cout << endl;
    system("cls");

    //Llamamos a la funcion de dados Bloqueadores por fuera del ciclo para que solo se active una vez
    dadosBloqueadores(primerBloqueador, segundoBloqueador);

    // Arranca el juego con el jugador 1
    cout << "Inicia la partida. Buena suerte!" << endl << endl;
    cout << "Arranca jugando ";
    rlutil::setColor(rlutil::BLUE);
    cout << nombreJ1;
    rlutil::setColor(rlutil::BROWN);
    cout << ", Estas preparado?" << endl << endl;
    system("pause");
    system("cls");

    // Ciclo para continuar con la ronda
    while (decisionContinuarRonda == 's' || decisionContinuarRonda == 'S') {
        system("cls");
        rlutil::setColor(rlutil::BROWN);
            cout << "============================" << endl;
            cout << " RONDA " << ronda << " | Turno de ";
            rlutil::setColor(rlutil::BLUE);
            cout << nombreJ1 << endl;
            rlutil::setColor(rlutil::BROWN);
            cout << "============================" << endl << endl;
            rlutil::setColor(rlutil::WHITE);
            cout << "Dados Bloqueadores ---> ";
            rlutil::setColor(rlutil::RED);
            cout << primerBloqueador << " | " << segundoBloqueador << endl << endl;
            rlutil::setColor(rlutil::WHITE);

            // LLamado a funcion para tirada de dados
            tiradaDeDados(dados, cantidadDados);
            cout << "Los dados lanzados dieron estos numeros ---> ";
            for (int i = 0; i < cantidadDados; i++) {
            rlutil::setColor(rlutil::GREEN);
            cout << dados[i] << " | ";
            rlutil::setColor(rlutil::WHITE);
            }

            // Dados que fueron bloqueados en esta ronda
            cout << endl << endl;
            int dadosBloqueados = contarDadosBloqueados(dados, cantidadDados, primerBloqueador, segundoBloqueador);
            cout << "Dados bloqueados esta ronda ---> ";
            rlutil::setColor(rlutil::RED);
            cout << dadosBloqueados << endl << endl;
            rlutil::setColor(rlutil::WHITE);

            // Contar cantidad de dados libres restantes
            int dadosLibres = cantidadDados - dadosBloqueados;
            cout << "Cantidad de dados libres que quedan para sumar ---> ";
            rlutil::setColor(rlutil::GREEN);
            cout << dadosLibres << endl << endl;
            rlutil::setColor(rlutil::WHITE);

            // Verificación de todos los dados restantes coincidan con los dados bloqueadores
            if (todosDadosCoincidenConBloqueadores(dados, cantidadDados, primerBloqueador, segundoBloqueador)) {
            rlutil::setColor(rlutil::RED);
            cout << "Todos los dados coinciden con los bloqueadores, " << nombreJ1 << " pierde todos los puntos acumulados." << endl;
            rlutil::setColor(rlutil::WHITE);
            //Entonces el total de puntos pasa a ser 0
            totalDePuntosJ1 = 0;
            }
            else {
            // Llamado a la funcion para Suma de dados
            int sumaDeRonda = sumaDeDados(dados, cantidadDados, primerBloqueador, segundoBloqueador);
            cout << "Suma de dados en esta ronda ---> ";
            rlutil::setColor(rlutil::GREEN);
            cout << sumaDeRonda << " puntos" << endl << endl;
            rlutil::setColor(rlutil::WHITE);
            // Suma total de puntos de las rondas hasta el momento
            totalDePuntosJ1 += sumaDeRonda;
            cout << "Acumulados hasta ahora para " << nombreJ1 << " ---> ";
            rlutil::setColor(rlutil::BROWN);
            rlutil::setBackgroundColor(rlutil::BLACK);
            cout << totalDePuntosJ1 << " puntos" << endl << endl << endl;
            rlutil::setColor(rlutil::WHITE);
            }
            // Restar los dados bloqueadores que coinciden con la tirada de dados
            cantidadDados -= dadosBloqueados;
            if (cantidadDados <= 0) {
            cout << endl;
            cout << "No quedan mas dados por tirar." << endl << endl << endl;
            break;
            }
            // Preguntar si se juega otra ronda
            if (ronda < 5) {
                    while (true) {
                        cout << nombreJ1 << ", queres jugar otra ronda? (";
                        rlutil::setColor(rlutil::GREEN);
                        cout << "S=SI ";
                        rlutil::setColor(rlutil::WHITE);
                        cout << "/";
                        rlutil::setColor(rlutil::RED);
                        cout << " N=NO";
                        rlutil::setColor(rlutil::WHITE);
                        cout << "): ";
                        cin >> decisionContinuarRonda;
                        if (decisionContinuarRonda == 's' || decisionContinuarRonda == 'S') {
                                break; // Continua jugando
                                }
                                else if (decisionContinuarRonda == 'n' || decisionContinuarRonda == 'N') {
                                    system("cls");
                                    rlutil::setColor(rlutil::BROWN);
                                    cout << "Jugador 1 no quiso jugar esta ronda y el total de puntos obtenidos es: " << totalDePuntosJ1 << endl << endl;
                                    rlutil::setColor(rlutil::WHITE);
                                    break; // Termina el jugador 1 y va el jugador 2
                                    }
                                    else { // Caracter incorreto a S o N
                                            rlutil::setColor(rlutil::RED);

                                        cout << "--------------------------------------------------------------------------------------" << endl;
                                        cout << "OPCION INVALIDA. Por favor, ingresa 'S' para continuar o 'N' para no jugar otra ronda." << endl;
                                        cout << "______________________________________________________________________________________" << endl << endl;
                                        rlutil::setColor(rlutil::WHITE);
                                        }
                                    }
            }
            else {
            rlutil::setColor(rlutil::BROWN);
            cout << "Ya no se permiten mas tiradas." << endl << endl << endl << endl;
            rlutil::setColor(rlutil::WHITE);
            break;
            }
            ronda++;
    }
    system("pause");
    system("cls");



    // Reseteo para el turno del jugador 2
    ronda = 1;
    decisionContinuarRonda = 's';
    cantidadDados = 5;
    dadosBloqueadores(primerBloqueador, segundoBloqueador);

    // Sigue el juego con el jugador 2
    rlutil::setColor(rlutil::BROWN);
    cout << "Continua jugando ";
    rlutil::setColor(rlutil::GREEN);
    cout << nombreJ2;
    rlutil::setColor(rlutil::BROWN);
    cout << ", Estas preparado?" << endl << endl;
    system("pause");
    system("cls");


    // Ciclo para continuar con la ronda
    while (decisionContinuarRonda == 's' || decisionContinuarRonda == 'S') {
        system("cls");
        rlutil::setColor(rlutil::BROWN);
            cout << "============================" << endl;
            cout << " RONDA " << ronda << " | Turno de ";
            rlutil::setColor(rlutil::GREEN);
            cout << nombreJ2 << endl;
            rlutil::setColor(rlutil::BROWN);
            cout << "============================" << endl << endl;
            rlutil::setColor(rlutil::WHITE);
            cout << "Dados Bloqueadores ---> ";
            rlutil::setColor(rlutil::RED);
            cout << primerBloqueador << " | " << segundoBloqueador << endl << endl;
            rlutil::setColor(rlutil::WHITE);

            // LLamado a funcion para tirada de dados
            tiradaDeDados(dados, cantidadDados);
            cout << "Los dados lanzados dieron estos numeros ---> ";
            for (int i = 0; i < cantidadDados; i++) {
            rlutil::setColor(rlutil::GREEN);
            cout << dados[i] << " | ";
            rlutil::setColor(rlutil::WHITE);
            }

            // Dados que fueron bloqueados en esta ronda
            cout << endl << endl;
            int dadosBloqueados = contarDadosBloqueados(dados, cantidadDados, primerBloqueador, segundoBloqueador);
            cout << "Dados bloqueados esta ronda ---> ";
            rlutil::setColor(rlutil::RED);
            cout << dadosBloqueados << endl << endl;
            rlutil::setColor(rlutil::WHITE);

            // Contar cantidad de dados libres restantes
            int dadosLibres = cantidadDados - dadosBloqueados;
            cout << "Cantidad de dados libres que quedan para sumar ---> ";
            rlutil::setColor(rlutil::GREEN);
            cout << dadosLibres << endl << endl;
            rlutil::setColor(rlutil::WHITE);

            // Verificación de todos los dados restantes coincidan con los dados bloqueadores
            if (todosDadosCoincidenConBloqueadores(dados, cantidadDados, primerBloqueador, segundoBloqueador)) {
            rlutil::setColor(rlutil::RED);
            cout << "Todos los dados coinciden con los bloqueadores, " << nombreJ2 << " pierde todos los puntos acumulados." << endl;
            rlutil::setColor(rlutil::WHITE);
            //Entonces el total de puntos pasa a ser 0
            totalDePuntosJ2 = 0;
            }
            else {
            // Llamado a la funcion para Suma de dados
            int sumaDeRonda = sumaDeDados(dados, cantidadDados, primerBloqueador, segundoBloqueador);
            cout << "Suma de dados en esta ronda ---> ";
            rlutil::setColor(rlutil::GREEN);
            cout << sumaDeRonda << " puntos" << endl << endl;
            rlutil::setColor(rlutil::WHITE);

            // Suma total de puntos de las rondas hasta el momento
            totalDePuntosJ2 += sumaDeRonda;
            cout << "Acumulados hasta ahora para " << nombreJ2 << " ---> ";
            rlutil::setColor(rlutil::BROWN);
            rlutil::setBackgroundColor(rlutil::BLACK);
            cout << totalDePuntosJ2 << " puntos" << endl << endl << endl;
            rlutil::setColor(rlutil::WHITE);
            }
            // Restar los dados bloqueadores que coinciden con la tirada de dados
            cantidadDados -= dadosBloqueados;
            if (cantidadDados <= 0) {
            cout << endl;
            cout << "No quedan mas dados por tirar." << endl << endl << endl;
            break;
            }
            // Preguntar si se juega otra ronda
            if (ronda < 5) {
                    while (true) {
                        cout << nombreJ2 << ", queres jugar otra ronda? (";
                        rlutil::setColor(rlutil::GREEN);
                        cout << "S=SI ";
                        rlutil::setColor(rlutil::WHITE);
                        cout << "/";
                        rlutil::setColor(rlutil::RED);
                        cout << " N=NO";
                        rlutil::setColor(rlutil::WHITE);
                        cout << "): ";
                        cin >> decisionContinuarRonda;
                        if (decisionContinuarRonda == 's' || decisionContinuarRonda == 'S') {
                                break; // Continua jugando
                                }
                                else if (decisionContinuarRonda == 'n' || decisionContinuarRonda == 'N') {
                                    system("cls");
                                    rlutil::setColor(rlutil::BROWN);
                                    cout << "Jugador 1 no quiso jugar esta ronda y el total de puntos obtenidos es: " << totalDePuntosJ2 << endl << endl;
                                    rlutil::setColor(rlutil::WHITE);
                                    break; // Termina el jugador 1 y va el jugador 2
                                    }
                                    else { // Caracter incorreto a S o N
                                            rlutil::setColor(rlutil::RED);

                                        cout << "--------------------------------------------------------------------------------------" << endl;
                                        cout << "OPCION INVALIDA. Por favor, ingresa 'S' para continuar o 'N' para no jugar otra ronda." << endl;
                                        cout << "______________________________________________________________________________________" << endl << endl;
                                        rlutil::setColor(rlutil::WHITE);
                                        }
                                    }
            }
            else {
            rlutil::setColor(rlutil::BROWN);
            cout << "Ya no se permiten mas tiradas." << endl << endl << endl << endl;
            rlutil::setColor(rlutil::WHITE);
            break;
            }
            ronda++;
    }
    system("pause");
    system("cls");


    // Aca se termina Y da el ganador con su puntaje
    if (totalDePuntosJ1 > totalDePuntosJ2) {
        cout << "RESULTADO " << endl << endl;
        cout << " ---> ";
        rlutil::setColor(rlutil::BLUE);
        cout << nombreJ1;
        rlutil::setColor(rlutil::WHITE);
        cout << " le gana a ";
        rlutil::setColor(rlutil::GREEN);
        cout << nombreJ2;
        rlutil::setColor(rlutil::WHITE);
        cout << " con ";
        rlutil::setColor(rlutil::BROWN);
        cout << totalDePuntosJ1 << " puntos";
        rlutil::setColor(rlutil::WHITE);
        cout << ". FELICIDADES!" << endl << endl;
    }
    else if (totalDePuntosJ2 > totalDePuntosJ1) {
        cout << "RESULTADO " << endl << endl;
        cout << " ---> ";
        rlutil::setColor(rlutil::GREEN);
        cout << nombreJ2;
        rlutil::setColor(rlutil::WHITE);
        cout << " le gana a ";
        rlutil::setColor(rlutil::BLUE);
        cout << nombreJ1;
        rlutil::setColor(rlutil::WHITE);
        cout << " con ";
        rlutil::setColor(rlutil::BROWN);
        cout << totalDePuntosJ2 << " puntos";
        rlutil::setColor(rlutil::WHITE);
        cout << ". FELICIDADES!" << endl << endl;
    }
    else {
        cout << "RESULTADO " << endl << endl;
        cout << " ---> EMPATE: ";
        rlutil::setColor(rlutil::BROWN);
        cout << totalDePuntosJ1 << " puntos";
        rlutil::setColor(rlutil::WHITE);
        cout << "para ";
        rlutil::setColor(rlutil::BLUE);
        cout << nombreJ1;
        rlutil::setColor(rlutil::WHITE);
        cout << " y tambien para ";
        rlutil::setColor(rlutil::GREEN);
        cout << nombreJ2;
        rlutil::setColor(rlutil::WHITE);
        cout << ". A DESEMPATAR!" << endl << endl;
    }

    cout << "-------------------------------------------------------------------------------------" << endl << endl;
    system("pause");
    system("cls");

}



// FUNCION PARA MOSTRAR ESTADISTICAS
void mostrarEstadisticas() {
    cout << "Estadisticas: " << endl;
}


// FUNCION DE CREDITOS
void mostrarCreditos() {
    cout << " " << endl;
    cout << "Desarrollado por el equipo 36." << endl;
    cout << " " << endl;
    cout << "Equipo completo:" << endl;
    cout << "1. Elias Santiago Alvarez Gorozito (Legajo 12345)" << endl;
    cout << "2. Bautista Gabriel Arroyo (Legajo 12345)" << endl;
    cout << "3. Maximiliano Joel Ayala (Legajo 12345)" << endl;
    cout << "4. Sebastian Roman Gerez (Legajo 32008)" << endl;
    cout << " " << endl;
    system("pause");
    system("cls");
    }



// FUNCION DE MENU PRINCIPAL
void mostrarMenu() {
    int opcion;
    do {
        rlutil::setBackgroundColor(rlutil::BLACK);
        rlutil::setColor(rlutil::BROWN);
        cout << endl;
        cout << "                               ********     ********     ********    ********    *******  " << endl;
        cout << "                              **********    *********    ********    ********    ******** " << endl;
        cout << "                              ***           ***   ***    ***         ***         ***   ***" << endl;
        cout << "                              ***           ***  ***     ********    ********    ***   ***" << endl;
        cout << "                              ***   ****    ********     ********    ********    ***   ***" << endl;
        cout << "                              ***    ***    ***   ***    ***         ***         ***   ***" << endl;
        cout << "                              **********    ***    ***   ********    ********    ******** " << endl;
        cout << "                               ********     ***     ***  ********    ********    *******  " << endl << endl << endl;
        rlutil::setColor(rlutil::BLUE);
        cout << "   Contaras con la suerte suficiente para superar a los bloqueadores y lograr la mayor cantidad de puntos? Intentalo...!" << endl;
        cout << endl << endl << endl << endl << endl << endl << endl << endl << endl <<endl;
        rlutil::setColor(rlutil::GREY);
        system("pause");
        system("cls");

        rlutil::setBackgroundColor(rlutil::BROWN);
        rlutil::setColor(rlutil::WHITE);
        cout << "          GREED            " << endl;
        rlutil::setBackgroundColor(rlutil::BLACK);
        rlutil::setColor(rlutil::WHITE);
        cout << "___________________________" << endl;
        rlutil::setColor(rlutil::GREEN);
        cout << "    1. MODO UN JUGADOR    " << endl;
        cout << "    2. MODO DOS JUGADORES " << endl;
        cout << "    3. ESTADISTICAS       " << endl;
        cout << "    4. CREDITOS           " << endl;
        rlutil::setColor(rlutil::WHITE);
        cout << "---------------------------" << endl;
        rlutil::setColor(rlutil::GREEN);
        cout << "    0. SALIR               " << endl;
        cout << endl << endl << endl;
        rlutil::setColor(rlutil::GREY);
        cout << "Seleccionar una opcion para continuar: ";
        cin >> opcion;


        switch (opcion) {
            case 1:
                system("cls");
                modoUnJugador();
                break;
            case 2:
                system("cls");
                modoDosJugadores();
                break;
            case 3:
                system("cls");
                mostrarEstadisticas();
                break;
            case 4:
                system("cls");
                mostrarCreditos();
                break;
            case 0:
                system("cls");
                cout << "Has salido del Juego. Vuelve pronto!" << endl;
                break;
            default:
                system("cls");
                cout << "Opcion invalida. Intente con otro caracter" << endl;
                break;
        }

        cout << endl;

    } while (opcion != 0);
}


