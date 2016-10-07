typedef struct {
    char titulo[50];
    char nacionalidad[50];
    char director[50];
    int anio;
    int id_peliculas;
    int flag_estado;
}ePeliculas;

typedef struct {
    char nombre[50];
    char pais_origen[50];
    int id_director;
    int flag_estado;
}eDirectores;

typedef struct{
    int anio;
    int mes;
    int dia;
    int flag_estado;
}eFecha;

int getOpcion(int opc);

void iniciarDatosArray(ePeliculas arrayPeli[], int cantElementos, int valor);
int buscarPrimerOcurrencia(ePeliculas arrayPeli[], int cantElementos, int valor);

void iniciarDatosArrayD(eDirectores arrayPeli[], int cantElementos, int valor);
int buscarPrimerOcurrenciaD(eDirectores arrayPeli[], int cantElementos, int valor);

void iniciarDatosArrayF(eFecha arrayPeli[], int cantElementos, int valor);
int buscarPrimerOcurrenciaF(eFecha arrayPeli[], int cantElementos, int valor);



void obtenerDatosPorTeclado( char mensaje[], char input[]);
int validarSoloLetras(char soloString[]);
int getStringValidado(char mensaje[], char input[]);
int esNumerico(char strInput[]);
int getNumerosString(char mensaje[],char input[]);

