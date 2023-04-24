/** @file Proceso.hh
    @brief Especificación de la clase Proceso
*/


#ifndef PROCESO_HH
#define PROCESO_HH

#ifndef NO_DIAGRAM
#include <iostream>
#include <utility>
#endif
using namespace std;

/** @class Proceso
    @brief Representa un proceso en ejecución o en espera con id, memoria ocupada, tiempo de ejecución y prioridad del propio proceso

*/
class Proceso {

private:
    /** @brief Entero identificador del proceso */
    int id;

    /** @brief Tiempo de ejecución restante de el proceso */
    int t_ejec;

    /** @brief Pair de enteros con el índice de memoria y memoria ocupada del proceso
     
      first = índice de la posición que ocupa en el memoria, second = memoria que ocupa
    */
    pair <int, int> ind_mem; 

public:
    //Constructoras

    /** @brief Creadora por defecto.
     
        Se ejecuta automáticamente al declarar un proceso.
        \pre <em>cierto</em>
        \post El resultado es un proceso con todos los atributos enteros a -1 y la string con "???" 
    */
    Proceso();

    //Modificadoras

    /** @brief Añade el índice de la posición que ocupa en memoria 
     
      \pre <em>cierto</em>
      \post El resultado es el p.i. con el índice = ind
  */
    void add_indice (int ind);

    /** @brief Resta el tiempo de ejecución del proceso
     
      \pre <em> tiempo = T, T > 0 </em>
      \post El resultado es el p.i. con tiempo = T - t , tiempo >= 0
  */
    void restar_tiempo(int t);

    //Consultoras

    /** @brief Consultora del id del proceso
        \pre <em>cierto</em>
        \post El resultado el id del parámetro implícito
    */
    int consultar_ID() const;

    /** @brief Consultora de la memoria del proceso
        \pre <em>cierto</em>
        \post El resultado es la memoria del parámetro implícito
    */
    int consultar_MEM() const;

    /** @brief Consultora del índice del proceso
        \pre <em>cierto</em>
        \post El resultado es el índice de la posición que ocupa en la memoria del parámetro implícito
    */
    int consultar_ind() const;

    /** @brief Consultora del tiempo de ejecución restante del proceso
        \pre <em>cierto</em>
        \post El resultado es el tiempo de ejecución restante del parámetro implícito
    */
    int consultar_tiempo() const;

    //Lectura y escritura

    /** @brief Operación de lectura

      \pre Hay preparados en el canal standard de entrada los datos de un proceso
      \post El parámetro ímplicito pasa a tener los atributos leídos del canal standard de entrada
    */
    void leer();

    /** @brief Operación de escritura

      \pre <em>cierto</em>
      \post Se han escrito los atributos del parámetro implícito en el canal
      standard de salida. 
    */
    void escribir() const;

};
#endif