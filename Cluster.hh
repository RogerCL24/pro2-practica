/** @file Cluster.hh
    @brief Especificación de la clase Cluster 
*/

#ifndef CLUSTER_HH
#define CLUSTER_HH

#include "Procesador.hh"
#include "Proceso.hh"
#ifndef NO_DIAGRAM
#include <iostream>
#include <string>
#include "BinTree.hh"
#include <utility>
#include <map>
#endif

/** @class Cluster
    @brief Representa un clúster compuesto por procesadores 

    Los procesadores estan distribuidos en forma de árbol binario, con identificadores únicos.
    Cada procesador puede tener dos, uno o cero procesadores sucesores, también llamados auxiliares. 
    Todo clúster ha de tener como mínimo un procesador.
*/

class Cluster {

private:
    /** @brief Estructura de procesadores del cluster */
    BinTree<string> Tprc;
    /** @brief Mapa de procesadores ordenado crecientemente por su id */
    map <string, Procesador> mprc;
  
   /** @brief Operación de lectura de un árbol de procesadores
      \pre  a es vacío; 
      \post a contiene el árbol de procesadores leído de la entrada
  */
    static void leer_arbol(BinTree<string>& a, map <string, Procesador>& mpr);
    
    /** @brief Operación de escritura de un árbol de procesadores
      \pre  cierto
      \post Se ha escrito a por el canal de salida estándard
  */
    static void escribir_arbol(const BinTree<string>& a);

public:

    //Constructoras

    /** @brief Creadora por defecto. 

      Se ejecuta automáticamente al declarar un clúster.
      \pre <em>cierto</em>
      \post El resultado es un clúster no inicializado
  */
    Cluster();

    //Modificadoras

    /** @brief Añade un proceso en un procesador
     
      \pre no existe p en el procesador con iD = id, 
      la memoria de p <= memoria contigua más grande del procesador
      \post El resultado es el procesador con ID = id con los procesos originales más p 
    */
    void add_job_prc(string id, Proceso p);

    /** @brief Elimina un proceso del procesador 
     
        \pre Existe un proceso en el procesador ,con ID = idprc, con ID = idjob
        \post El procesador con ID = isprc contiene sus procesos originales menos el proceso con ID = idjob 
    */
    void eliminar_job_prc(string idprc, int idjob);

    /** @brief Avanza el tiempo del cluster
     
      \pre <em>cierto</em>
      \post El resultado es el tiempo original más t y la eliminación de los procesos con tiempo <= t
    */
    void avanzar_tiempo_prc(int t);
 
    /** @brief Añade un clúster al clúster original
     
      \pre <em>cierto</em>
      \post El resultado es el p.i. más c en la posición del procesador con ID = id
  */
    void añadir_cluster(const Cluster& c, string id);

    /** @brief Compacta todos los procesadores del clúster 
     
      \pre <em>cierto</em>
      \post El resultado es el p.i. con todos los procesadores compactados (usando la op compactar_mem de la classe Procesador)
  */
    void compactar();
    
    //Consultoras

    /** @brief Consultora de la existencia de un procesador

      \pre El p.i. está inicializado
      \post El resultado indica si existe el procesador con ID = id en el p.i.
  */
    bool existe_prc(string id) const; 

    /** @brief Consultora de un procesador 

      \pre Existe un procesador en el p.i. con ID = id
      \post El resultado es el procesador con ID = id que contiene el p.i.
  */
    Procesador consultar_prc(string id) const;

    /** @brief Consultora de la existencia de un procesador auxiliar apartir de otro procesador

      \pre El p.i. está inicializado
      \post El resultado indica si en el procesador con ID = id del p.i. existe un procesador auxiliar
  */
      bool existe_aux(string id) const;

    //Lectura y escritura

     /** @brief Operación de lectura

      \pre Hay preparados en el canal standard de entrada los datos de un cluster
      \post El parámetro ímplicito pasa a tener los atributos leídos del canal standard de entrada
    */
    void leer();

    /** @brief Operación de escritura de una estructura

      \pre <em>cierto</em>
      \post Se ha escrito la estructura del parámetro implícito en el canal
      standard de salida. 
    */
    void escribir_est() const; //escribe la estructura del cluster

    /** @brief Operación de escritura de todos los procesadores

      \pre <em>cierto</em>
      \post Se han escrito los procesos de todos los procesadores del parámetro implícito en el canal
      standard de salida. 
    */
    void escribir_todos() const; //usa "escribir_proc" para todos los id

    /** @brief Operación de escritura de un procesador

      \pre Existe el procesador con ID = id en el p.i.
      \post Se han escrito los procesos del procesador con ID = id del parámetro implícito en el canal
      standard de salida. 
    */
    void escribir_prc(string id) const; //escribe los procesos del procesador con ID=id
    
};
#endif