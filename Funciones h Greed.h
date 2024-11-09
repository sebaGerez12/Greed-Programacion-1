#pragma once

// DECLARACIÓN DE FUNCIONES

//FUNCION DADOS BLOQUEADORES
void dadosBloqueadores(int &primerBloqueador, int &segundoBloqueador);

//FUNCION DE TIRADA DE DADOS
void tiradaDeDados(int dados[], int cantidad);

//FUNCION SUMAR DADOS
int sumaDeDados(int dados[], int cantidad, int primerBloqueador, int segundoBloqueador);

//FUNCION PARA CONTAR DADOS BLOQUEADORES
int contarDadosBloqueados(int dados[], int cantidad, int primerBloqueador, int segundoBloqueador);

//FUNCION PARA VERIFICAR SI TODOS LOS DADOS RESTANTES SON IGUALES QUE LOS BLOQUEADORES
bool todosDadosCoincidenConBloqueadores(int dados[],int cantidad, int primerBloqueador, int segundoBloqueador);

//FUNCION MODO DE UN JUGADOR
void modoUnJugador();

// FUNCION MODO DE DOS JUGADORES
void modoDosJugadores();

// FUNCION PARA MOSTRAR ESTADISTICAS
void mostrarEstadisticas();

// FUNCION DE CREDITOS
void mostrarCreditos();

// FUNCION DE MENU PRINCIPAL
void mostrarMenu();

