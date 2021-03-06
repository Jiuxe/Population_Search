#include"lectura.cpp"
#include"relief.cpp"
#include"AGAM.cpp"
#include<string.h>
#include <ctime> 
using namespace std;

void Algoritmo1NN(vector< vector<double> > matrizParticion, vector< vector<string> > target, int test, int fil, int col){

    vector<double> W(fil,1);
    funcionEvaluacion(matrizParticion, target, test, fil, col, W, true);
}

int main(int argc, char* argv[]){

    if(argc != 3){
        cout << "Numero de Parametros No Valido" << endl;
        exit(-1);
    }

    int fil = 0 ,col = 0, pausa;
    char* f = argv[1];
    int semilla = atoi(argv[2]);
    unsigned t0, t1;
    double time;

    lectura(f, fil, col);
    cout << "FILAS: " << fil << " COL: " << col << endl;
    
    vector<double> matriz(fil*col,0);
    vector<double> W(col,0);
    
    /********************--PARTICIONES--*************************************/
     vector< vector<double> > matrizParticion(5);
     vector< vector<string> > targetDataParticion(5);

    /*************************--CLASES EXISTENTES--**************************************/
    vector<string> targetData(fil, "");

    /************************************************************************************/
    obtenerDatos(matriz, f, fil, col, targetData);
    normalizarDatos(matriz, fil, col);
    particionMatriz(matrizParticion, matriz, targetData, targetDataParticion, fil, col);
    //imprimirArreglo(matrizParticion[i],fil/5, col);

    /*************************--EJECUCIONES 1-NN--**************************************
    cout << "------------------ 1-NN ---------------" << endl;
    t0=clock();
    Algoritmo1NN(matrizParticion,targetDataParticion,0,fil,col);    
    t1 = clock();
    time = (double(t1-t0)/CLOCKS_PER_SEC);
    cout << "Tiempo de ejecucion: " << time << endl << endl;
    t0=clock();
    Algoritmo1NN(matrizParticion,targetDataParticion,1,fil,col);    
    t1 = clock();
    time = (double(t1-t0)/CLOCKS_PER_SEC);
    cout << "Tiempo de ejecucion: " << time << endl << endl;
    t0=clock();
    Algoritmo1NN(matrizParticion,targetDataParticion,2,fil,col);    
    t1 = clock();
    time = (double(t1-t0)/CLOCKS_PER_SEC);
    cout << "Tiempo de ejecucion: " << time << endl << endl;
    t0=clock();
    Algoritmo1NN(matrizParticion,targetDataParticion,3,fil,col);    
    t1 = clock();
    time = (double(t1-t0)/CLOCKS_PER_SEC);
    cout << "Tiempo de ejecucion: " << time << endl << endl;
    t0=clock();
    Algoritmo1NN(matrizParticion,targetDataParticion,4,fil,col);    
    t1 = clock();
    time = (double(t1-t0)/CLOCKS_PER_SEC);
    cout << "Tiempo de ejecucion: " << time << endl << endl;

    /*************************--EJECUCIONES RELIEF--**********************************
    cout << "------------------ RELIEF ---------------" << endl;
    t0=clock();
    relief(matrizParticion,targetDataParticion,0,fil,col,W);    
    t1 = clock();
    time = (double(t1-t0)/CLOCKS_PER_SEC);
    cout << "Tiempo de ejecucion: " << time << endl << endl;
    t0=clock();
    relief(matrizParticion,targetDataParticion,1,fil,col,W);
    t1 = clock();
    time = (double(t1-t0)/CLOCKS_PER_SEC);
    cout << "Tiempo de ejecucion: " << time << endl << endl;
    t0=clock();
    relief(matrizParticion,targetDataParticion,2,fil,col,W);
    t1 = clock();
    time = (double(t1-t0)/CLOCKS_PER_SEC);
    cout << "Tiempo de ejecucion: " << time << endl << endl;
    t0=clock();
    relief(matrizParticion,targetDataParticion,3,fil,col,W);
    t1 = clock();
    time = (double(t1-t0)/CLOCKS_PER_SEC);
    cout << "Tiempo de ejecucion: " << time << endl << endl;
    t0=clock();
    relief(matrizParticion,targetDataParticion,4,fil,col,W);
    t1 = clock();
    time = (double(t1-t0)/CLOCKS_PER_SEC);
    cout << "Tiempo de ejecucion: " << time << endl << endl;


    /*************************--EJECUCIONES BL********************************************
    cout << "------------------Busquedas Local---------------" << endl;
    t0=clock();
    busquedaLocal(matrizParticion,targetDataParticion,0,fil,col,W, semilla);
    t1 = clock();
    time = (double(t1-t0)/CLOCKS_PER_SEC);
    cout << "Tiempo de ejecucion: " << time << endl << endl;
    t0=clock();
    busquedaLocal(matrizParticion,targetDataParticion,1,fil,col,W, semilla);
    t1 = clock();
    time = (double(t1-t0)/CLOCKS_PER_SEC);
    cout << "Tiempo de ejecucion: " << time << endl << endl;
    t0=clock();
    busquedaLocal(matrizParticion,targetDataParticion,2,fil,col,W, semilla);
    t1 = clock();
    time = (double(t1-t0)/CLOCKS_PER_SEC);
    cout << "Tiempo de ejecucion: " << time << endl << endl;
    t0=clock();
    busquedaLocal(matrizParticion,targetDataParticion,3,fil,col,W, semilla);
    t1 = clock();
    time = (double(t1-t0)/CLOCKS_PER_SEC);
    cout << "Tiempo de ejecucion: " << time << endl << endl;
    t0=clock();
    busquedaLocal(matrizParticion,targetDataParticion,4,fil,col,W, semilla);
    t1 = clock();
    time = (double(t1-t0)/CLOCKS_PER_SEC);
    cout << "Tiempo de ejecucion: " << time << endl << endl;
    /*******************--EJECUCIONES GENETICOS GENERACIONALES--**************************************/
    cout << "******** GENETICOS GENERACIONALES BLX ***********" << endl;    
    t0=clock();
    ModeloGeneracional(0,matrizParticion,targetDataParticion,0,fil,col,semilla);
    t1 = clock();
    time = (double(t1-t0)/CLOCKS_PER_SEC);
    cout << "Tiempo de ejecucion: " << time << endl << endl;
    t0=clock();
    ModeloGeneracional(0,matrizParticion,targetDataParticion,1,fil,col,semilla);
    t1 = clock();
    time = (double(t1-t0)/CLOCKS_PER_SEC);
    cout << "Tiempo de ejecucion: " << time << endl << endl;
    t0=clock();
    ModeloGeneracional(0,matrizParticion,targetDataParticion,2,fil,col,semilla);
    t1 = clock();
    time = (double(t1-t0)/CLOCKS_PER_SEC);
    cout << "Tiempo de ejecucion: " << time << endl << endl;
    t0=clock();
    ModeloGeneracional(0,matrizParticion,targetDataParticion,3,fil,col,semilla);
    t1 = clock();
    time = (double(t1-t0)/CLOCKS_PER_SEC);
    cout << "Tiempo de ejecucion: " << time << endl << endl;
    t0=clock();
    ModeloGeneracional(0,matrizParticion,targetDataParticion,4,fil,col,semilla);
    t1 = clock();
    time = (double(t1-t0)/CLOCKS_PER_SEC);
    cout << "Tiempo de ejecucion: " << time << endl << endl;

    cout << "******** GENETICOS GENERACIONALES CA ***********" << endl;    
    t0=clock();
    ModeloGeneracional(1,matrizParticion,targetDataParticion,0,fil,col,semilla);
    t1 = clock();
    time = (double(t1-t0)/CLOCKS_PER_SEC);
    cout << "Tiempo de ejecucion: " << time << endl << endl;
    t0=clock();
    ModeloGeneracional(1,matrizParticion,targetDataParticion,1,fil,col,semilla);
    t1 = clock();
    time = (double(t1-t0)/CLOCKS_PER_SEC);
    cout << "Tiempo de ejecucion: " << time << endl << endl;
    t0=clock();
    ModeloGeneracional(1,matrizParticion,targetDataParticion,2,fil,col,semilla);
    t1 = clock();
    time = (double(t1-t0)/CLOCKS_PER_SEC);
    cout << "Tiempo de ejecucion: " << time << endl << endl;
    t0=clock();
    ModeloGeneracional(1,matrizParticion,targetDataParticion,3,fil,col,semilla);
    t1 = clock();
    time = (double(t1-t0)/CLOCKS_PER_SEC);
    cout << "Tiempo de ejecucion: " << time << endl << endl;
    t0=clock();
    ModeloGeneracional(1,matrizParticion,targetDataParticion,4,fil,col,semilla);
    t1 = clock();
    time = (double(t1-t0)/CLOCKS_PER_SEC);
    cout << "Tiempo de ejecucion: " << time << endl << endl;

    /*******************--EJECUCIONES GENETICOS ESTACIONARIOS--**************************************/
    cout << "******** GENETICOS ESTACIONARIOS BLX ***********" << endl;
    t0=clock();
    ModeloEstacionario(0,matrizParticion,targetDataParticion,0,fil,col,semilla);
    t1 = clock();
    time = (double(t1-t0)/CLOCKS_PER_SEC);
    cout << "Tiempo de ejecucion: " << time << endl << endl;
    t0=clock();
    ModeloEstacionario(0,matrizParticion,targetDataParticion,1,fil,col,semilla);
    t1 = clock();
    time = (double(t1-t0)/CLOCKS_PER_SEC);
    cout << "Tiempo de ejecucion: " << time << endl << endl;
    t0=clock();
    ModeloEstacionario(0,matrizParticion,targetDataParticion,2,fil,col,semilla);
    t1 = clock();
    time = (double(t1-t0)/CLOCKS_PER_SEC);
    cout << "Tiempo de ejecucion: " << time << endl << endl;
    t0=clock();
    ModeloEstacionario(0,matrizParticion,targetDataParticion,3,fil,col,semilla);
    t1 = clock();
    time = (double(t1-t0)/CLOCKS_PER_SEC);
    cout << "Tiempo de ejecucion: " << time << endl << endl;
    t0=clock();
    ModeloEstacionario(0,matrizParticion,targetDataParticion,4,fil,col,semilla);
    t1 = clock();
    time = (double(t1-t0)/CLOCKS_PER_SEC);
    cout << "Tiempo de ejecucion: " << time << endl << endl;

    cout << "******** GENETICOS ESTACIONARIOS CA ***********" << endl;
    t0=clock();
    ModeloEstacionario(1,matrizParticion,targetDataParticion,0,fil,col,semilla);
    t1 = clock();
    time = (double(t1-t0)/CLOCKS_PER_SEC);
    cout << "Tiempo de ejecucion: " << time << endl << endl;
    t0=clock();
    ModeloEstacionario(1,matrizParticion,targetDataParticion,1,fil,col,semilla);
    t1 = clock();
    time = (double(t1-t0)/CLOCKS_PER_SEC);
    cout << "Tiempo de ejecucion: " << time << endl << endl;
    t0=clock();
    ModeloEstacionario(1,matrizParticion,targetDataParticion,2,fil,col,semilla);
    t1 = clock();
    time = (double(t1-t0)/CLOCKS_PER_SEC);
    cout << "Tiempo de ejecucion: " << time << endl << endl;
    t0=clock();
    ModeloEstacionario(1,matrizParticion,targetDataParticion,3,fil,col,semilla);
    t1 = clock();
    time = (double(t1-t0)/CLOCKS_PER_SEC);
    cout << "Tiempo de ejecucion: " << time << endl << endl;
    t0=clock();
    ModeloEstacionario(1,matrizParticion,targetDataParticion,4,fil,col,semilla);
    t1 = clock();
    time = (double(t1-t0)/CLOCKS_PER_SEC);
    cout << "Tiempo de ejecucion: " << time << endl << endl;

    /**************************--EJECUCIONES MEMETICOS 10,1.0--**************************************/
    cout << "******** MEMETICOS 10,1.0 ***********" << endl;
    t0=clock();
    ModeloGeneracional(0,matrizParticion,targetDataParticion,0,fil,col,semilla,1);
    t1 = clock();
    time = (double(t1-t0)/CLOCKS_PER_SEC);
    cout << "Tiempo de ejecucion: " << time << endl << endl;
    t0=clock();
    ModeloGeneracional(0,matrizParticion,targetDataParticion,1,fil,col,semilla,1);
    t1 = clock();
    time = (double(t1-t0)/CLOCKS_PER_SEC);
    cout << "Tiempo de ejecucion: " << time << endl << endl;
    t0=clock();
    ModeloGeneracional(0,matrizParticion,targetDataParticion,2,fil,col,semilla,1);
    t1 = clock();
    time = (double(t1-t0)/CLOCKS_PER_SEC);
    cout << "Tiempo de ejecucion: " << time << endl << endl;
    t0=clock();
    ModeloGeneracional(0,matrizParticion,targetDataParticion,3,fil,col,semilla,1);
    t1 = clock();
    time = (double(t1-t0)/CLOCKS_PER_SEC);
    cout << "Tiempo de ejecucion: " << time << endl << endl;
    t0=clock();
    ModeloGeneracional(0,matrizParticion,targetDataParticion,4,fil,col,semilla,1);
    t1 = clock();
    time = (double(t1-t0)/CLOCKS_PER_SEC);
    cout << "Tiempo de ejecucion: " << time << endl << endl;

    /**************************--EJECUCIONES MEMETICOS 10,0.1--**************************************/
    cout << "******** MEMETICOS 10,0.1 ***********" << endl;
    t0=clock();
    ModeloGeneracional(0,matrizParticion,targetDataParticion,0,fil,col,semilla,2);
    t1 = clock();
    time = (double(t1-t0)/CLOCKS_PER_SEC);
    cout << "Tiempo de ejecucion: " << time << endl << endl;
    t0=clock();
    ModeloGeneracional(0,matrizParticion,targetDataParticion,1,fil,col,semilla,2);
    t1 = clock();
    time = (double(t1-t0)/CLOCKS_PER_SEC);
    cout << "Tiempo de ejecucion: " << time << endl << endl;
    t0=clock();
    ModeloGeneracional(0,matrizParticion,targetDataParticion,2,fil,col,semilla,2);
    t1 = clock();
    time = (double(t1-t0)/CLOCKS_PER_SEC);
    cout << "Tiempo de ejecucion: " << time << endl << endl;
    t0=clock();
    ModeloGeneracional(0,matrizParticion,targetDataParticion,3,fil,col,semilla,2);
    t1 = clock();
    time = (double(t1-t0)/CLOCKS_PER_SEC);
    cout << "Tiempo de ejecucion: " << time << endl << endl;
    t0=clock();
    ModeloGeneracional(0,matrizParticion,targetDataParticion,4,fil,col,semilla,2);
    t1 = clock();
    time = (double(t1-t0)/CLOCKS_PER_SEC);
    cout << "Tiempo de ejecucion: " << time << endl << endl;

    /**************************--EJECUCIONES MEMETICOS 10,0.1mejor--**************************************/
    cout << "******** MEMETICOS 10,1.0 mejor ***********" << endl;
    t0=clock();
    ModeloGeneracional(0,matrizParticion,targetDataParticion,0,fil,col,semilla,3);
    t1 = clock();
    time = (double(t1-t0)/CLOCKS_PER_SEC);t0=clock();
    ModeloGeneracional(0,matrizParticion,targetDataParticion,0,fil,col,semilla);
    t1 = clock();
    time = (double(t1-t0)/CLOCKS_PER_SEC);
    cout << "Tiempo de ejecucion: " << time << endl << endl;
    t0=clock();
    ModeloGeneracional(0,matrizParticion,targetDataParticion,1,fil,col,semilla);
    t1 = clock();
    time = (double(t1-t0)/CLOCKS_PER_SEC);
    cout << "Tiempo de ejecucion: " << time << endl << endl;
    t0=clock();
    ModeloGeneracional(0,matrizParticion,targetDataParticion,2,fil,col,semilla);
    t1 = clock();
    time = (double(t1-t0)/CLOCKS_PER_SEC);
    cout << "Tiempo de ejecucion: " << time << endl << endl;
    t0=clock();
    ModeloGeneracional(0,matrizParticion,targetDataParticion,3,fil,col,semilla);
    t1 = clock();
    time = (double(t1-t0)/CLOCKS_PER_SEC);
    cout << "Tiempo de ejecucion: " << time << endl << endl;
    t0=clock();
    ModeloGeneracional(0,matrizParticion,targetDataParticion,4,fil,col,semilla);
    t1 = clock();
    time = (double(t1-t0)/CLOCKS_PER_SEC);
    cout << "Tiempo de ejecucion: " << time << endl << endl;
    t0=clock();
    ModeloGeneracional(0,matrizParticion,targetDataParticion,0,fil,col,semilla);
    t1 = clock();
    time = (double(t1-t0)/CLOCKS_PER_SEC);
    cout << "Tiempo de ejecucion: " << time << endl << endl;
    t0=clock();
    ModeloGeneracional(0,matrizParticion,targetDataParticion,1,fil,col,semilla);
    t1 = clock();
    time = (double(t1-t0)/CLOCKS_PER_SEC);
    cout << "Tiempo de ejecucion: " << time << endl << endl;
    t0=clock();
    ModeloGeneracional(0,matrizParticion,targetDataParticion,2,fil,col,semilla);
    t1 = clock();
    time = (double(t1-t0)/CLOCKS_PER_SEC);
    cout << "Tiempo de ejecucion: " << time << endl << endl;
    t0=clock();
    ModeloGeneracional(0,matrizParticion,targetDataParticion,3,fil,col,semilla);
    t1 = clock();
    time = (double(t1-t0)/CLOCKS_PER_SEC);
    cout << "Tiempo de ejecucion: " << time << endl << endl;
    t0=clock();
    ModeloGeneracional(0,matrizParticion,targetDataParticion,4,fil,col,semilla);
    t1 = clock();
    time = (double(t1-t0)/CLOCKS_PER_SEC);
    cout << "Tiempo de ejecucion: " << time << endl;
    t0=clock();
    ModeloGeneracional(0,matrizParticion,targetDataParticion,1,fil,col,semilla,3);
    t1 = clock();
    time = (double(t1-t0)/CLOCKS_PER_SEC);
    cout << "Tiempo de ejecucion: " << time << endl << endl;
    t0=clock();
    ModeloGeneracional(0,matrizParticion,targetDataParticion,2,fil,col,semilla,3);
    t1 = clock();
    time = (double(t1-t0)/CLOCKS_PER_SEC);
    cout << "Tiempo de ejecucion: " << time << endl << endl;
    t0=clock();
    ModeloGeneracional(0,matrizParticion,targetDataParticion,3,fil,col,semilla,3);
    t1 = clock();
    time = (double(t1-t0)/CLOCKS_PER_SEC);
    cout << "Tiempo de ejecucion: " << time << endl << endl;
    t0=clock();
    ModeloGeneracional(0,matrizParticion,targetDataParticion,4,fil,col,semilla,3);
    t1 = clock();
    time = (double(t1-t0)/CLOCKS_PER_SEC);
    cout << "Tiempo de ejecucion: " << time << endl << endl;

    /**************************- EXPERIMENTO 1 -*************************************/
    cout << "******** AGGMS-BLX  ***********" << endl;
    t0=clock();
    ModeloGeneracionalMejorSustituto(0,matrizParticion,targetDataParticion,0,fil,col,semilla);
    t1 = clock();
    time = (double(t1-t0)/CLOCKS_PER_SEC);
    cout << "Tiempo de ejecucion: " << time << endl << endl;
    t0=clock();
    ModeloGeneracionalMejorSustituto(0,matrizParticion,targetDataParticion,1,fil,col,semilla);
    t1 = clock();
    time = (double(t1-t0)/CLOCKS_PER_SEC);
    cout << "Tiempo de ejecucion: " << time << endl << endl;
    t0=clock();
    ModeloGeneracionalMejorSustituto(0,matrizParticion,targetDataParticion,2,fil,col,semilla);
    t1 = clock();
    time = (double(t1-t0)/CLOCKS_PER_SEC);
    cout << "Tiempo de ejecucion: " << time << endl << endl;
    t0=clock();
    ModeloGeneracionalMejorSustituto(0,matrizParticion,targetDataParticion,3,fil,col,semilla);
    t1 = clock();
    time = (double(t1-t0)/CLOCKS_PER_SEC);
    cout << "Tiempo de ejecucion: " << time << endl << endl;
    t0=clock();
    ModeloGeneracionalMejorSustituto(0,matrizParticion,targetDataParticion,4,fil,col,semilla);
    t1 = clock();
    time = (double(t1-t0)/CLOCKS_PER_SEC);
    cout << "Tiempo de ejecucion: " << time << endl << endl;
    /**************************- EXPERIMENTO 2 -*************************************/
    cout << "******** AGGMS-CR ***********" << endl;
    t0=clock();
    ModeloGeneracionalMejorSustituto(2,matrizParticion,targetDataParticion,0,fil,col,semilla);
    t1 = clock();
    time = (double(t1-t0)/CLOCKS_PER_SEC);
    cout << "Tiempo de ejecucion: " << time << endl << endl;
    t0=clock();
    ModeloGeneracionalMejorSustituto(2,matrizParticion,targetDataParticion,1,fil,col,semilla);
    t1 = clock();
    time = (double(t1-t0)/CLOCKS_PER_SEC);
    cout << "Tiempo de ejecucion: " << time << endl << endl;
    t0=clock();
    ModeloGeneracionalMejorSustituto(2,matrizParticion,targetDataParticion,2,fil,col,semilla);
    t1 = clock();
    time = (double(t1-t0)/CLOCKS_PER_SEC);
    cout << "Tiempo de ejecucion: " << time << endl << endl;
    t0=clock();
    ModeloGeneracionalMejorSustituto(2,matrizParticion,targetDataParticion,3,fil,col,semilla);
    t1 = clock();
    time = (double(t1-t0)/CLOCKS_PER_SEC);
    cout << "Tiempo de ejecucion: " << time << endl << endl;
    t0=clock();
    ModeloGeneracionalMejorSustituto(2,matrizParticion,targetDataParticion,4,fil,col,semilla);
    t1 = clock();
    time = (double(t1-t0)/CLOCKS_PER_SEC);
    cout << "Tiempo de ejecucion: " << time << endl << endl;
    /***********************************************************************************/

    cout << "******** AGE-CR ***********" << endl;
    t0=clock();
    ModeloEstacionarioMejorSustituto(2,matrizParticion,targetDataParticion,0,fil,col,semilla);
    t1 = clock();
    time = (double(t1-t0)/CLOCKS_PER_SEC);
    cout << "Tiempo de ejecucion: " << time << endl << endl;
    t0=clock();
    ModeloEstacionario(2,matrizParticion,targetDataParticion,1,fil,col,semilla);
    t1 = clock();
    time = (double(t1-t0)/CLOCKS_PER_SEC);
    cout << "Tiempo de ejecucion: " << time << endl << endl;
    t0=clock();
    ModeloEstacionario(2,matrizParticion,targetDataParticion,2,fil,col,semilla);
    t1 = clock();
    time = (double(t1-t0)/CLOCKS_PER_SEC);
    cout << "Tiempo de ejecucion: " << time << endl << endl;
    t0=clock();
    ModeloEstacionario(2,matrizParticion,targetDataParticion,3,fil,col,semilla);
    t1 = clock();
    time = (double(t1-t0)/CLOCKS_PER_SEC);
    cout << "Tiempo de ejecucion: " << time << endl << endl;
    t0=clock();
    ModeloEstacionario(2,matrizParticion,targetDataParticion,4,fil,col,semilla);
    t1 = clock();
    time = (double(t1-t0)/CLOCKS_PER_SEC);
    cout << "Tiempo de ejecucion: " << time << endl << endl;


    /*************************************************************************************************/

    cout << "***************- FIN EJECUCION ARCHIVO -*****************" << endl << endl;
}
