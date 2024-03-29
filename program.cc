/**
 * @mainpage Práctica: Simulación del rendimiento de procesadores interconectados.
 
En esta práctica se construye un programa modular que simula el funcionamiento de una arquitectura multiprocesador. Se introducen las clases <em>Procesador</em>, <em>Proceso</em>, <em>Cluster</em>, <em>Area_espera</em>. <em>Prioridad</em>.

Sólo se documentan los elementos públicos.
*/

/** @file main.cc
    @brief Programa principal para el proyecto <em>Simulación del rendimiento de procesadores interconectados</em>
 
*/

#include "Procesador.hh"
#include "Proceso.hh"
#include "Cluster.hh"
#include "Area_espera.hh"
#include "Prioridad.hh"

using namespace std;

/** @brief Programa principal para el proyecto <em>Simulación del rendimiento de procesadores interconectados</em>
*/
int main() {
    Cluster c;
    c.leer();
    Area_espera ae;
    ae.leer();
    string comando;
    cin >> comando;
    while (comando != "fin") {
        if (comando == "cc" or comando == "configurar_cluster") {   //1
            cout << '#' << comando << endl;
            c.leer();  
        }
        else if (comando == "mc" or comando == "modificar_cluster") {        //2
            string id;
            cin >> id;
            Cluster c2;
            c2.leer();
            cout << '#' << comando << ' ' << id << endl;
            c.añadir_cluster(c2, id);         
        }

        else if (comando == "ap" or comando == "alta_prioridad") {         //3      
            string id_prior;
            cin >> id_prior;
            cout << '#' << comando << ' ' << id_prior << endl;
            ae.add_prior(id_prior);      
        }

        else if (comando == "bp" or comando == "baja_prioridad") {         //4   
            string id_prior;
            cin >> id_prior;
            cout << '#' << comando << ' ' << id_prior << endl;   
            ae.eliminar_prior(id_prior);     
        }
        
        else if (comando == "ape" or comando == "alta_proceso_espera") {       //5  
            string id_prior;
            cin >> id_prior;
            Proceso p;
            p.leer();
            cout << '#' << comando << ' ' << id_prior << ' ' << p.consultar_ID() << endl;     
            ae.add_job(p, id_prior); 
        }

        else if (comando == "app" or comando == "alta_proceso_procesador") {        //6
            string id;
            cin >> id;
            Proceso p;
            p.leer();
            cout << '#' << comando << ' ' << id << ' ' << p.consultar_ID() << endl;
            c.add_job_prc(id, p);             
        }

        else if (comando == "bpp" or comando == "baja_proceso_procesador") {        //7
            string idprc; //id procesador
            int idjob;     //id proceso
            cin >> idprc >> idjob;
            cout << '#' << comando << ' ' << idprc << ' ' << idjob << endl;
            c.eliminar_job_prc(idprc,idjob); 
        }

        else if (comando == "epc" or comando == "enviar_procesos_cluster") {        //8
            int n;
            cin >> n;
            cout << '#' << comando << ' ' << n << endl;
            ae.enviar_job_a_cluster(n, c);   
        }

        else if (comando == "at" or comando == "avanzar_tiempo") {     //9
            int t;
            cin >> t;
            cout << '#' << comando << ' ' << t << endl;
            c.avanzar_tiempo_prc(t);  
        }

        else if (comando == "ipri" or comando == "imprimir_prioridad") {   //10 
            string id_prior;
            cin >> id_prior;
            cout << '#' << comando << ' ' << id_prior << endl;
            map <string, Prioridad>::const_iterator it;
            ae.escribir_prior(id_prior, it);    
        }

        else if (comando == "iae" or comando == "imprimir_area_espera") {   //11
            cout << '#' << comando << endl;
            ae.escribir();  
        }
        else if (comando == "ipro" or comando == "imprimir_procesador") {   //12
            string id;
            cin >> id;
            cout << '#' << comando << ' ' << id << endl;
            map <string, Procesador>::const_iterator it;
            c.escribir_prc(id, it);     
        }
        
        else if (comando == "ipc" or comando == "imprimir_procesadores_cluster") {  //13
            cout << '#' << comando << endl;
            c.escribir_todos();   
        }
        else if (comando == "iec" or comando == "imprimir_estructura_cluster") {       //14
            cout << '#' << comando << endl;
            c.escribir_est(); 
        }
        else if (comando == "cmp" or comando == "compactar_memoria_procesador") {    //15
            string id;
            cin >> id; 
            cout << '#' << comando << ' ' << id << endl;
            c.compactar_prc(id);
                  
        }
    
        else if (comando == "cmc" or comando == "compactar_memoria_cluster") {      //16
            cout << '#' << comando << endl;
            c.compactar();   
        }
        cin >> comando;
    }
}
