#include <stdio.h>
#define MAX_PACIENTES 20

#define TEMP_MIN 36.0
#define TEMP_MAX 37.5
#define FREC_MIN 60
#define FREC_MAX 100
#define SAT_MIN 95
#define SAT_MAX 100
#define SIST_MIN 90 
#define SIST_MAX 120
#define DIAST_MIN 60
#define DIAST_MAX 80

typedef struct {

char nombre[50]; /* nombre completo */
int edad;
char cedula[20];
float temperatura; /* grados c */
int frecCardiaca; /* 1pm */
int saturacion; /* % Sp02 */
int presionSist; /* mmHg */
int presionDiast; /* mmHg */

} Paciente;
float CalcularPromedioTemperatura (Paciente pacientes [], int cantidad);
float CalcularPromedioFrecuencia (Paciente pacientes [], int cantidad);
float CalcularPromedioSaturacion (Paciente pacientes [], int cantidad);
float CalcularPromedioSistolica (Paciente pacientes [], int cantidad);
float CalcularPromedioDiastolica (Paciente pacientes [], int cantidad);

void MostrarPromedios (Paciente pacientes [], int cantidad);
void EvaluarPacientes (Paciente pacientes [], int cantidad);
void MostrarOpciones();
int CargarPacientes(Paciente pacientes[]);
void GuardarPacientes(Paciente pacientes[], int cantidadPacientes);
int RegistrarPaciente(Paciente pacientes[], int cantidadPacientes);

void MostrarPacientes(Paciente pacientes[], int cantidadPacientes);
// Main no recibe datos, muestra la identificacion y coordina el menu del programa, devuelve 0 cuando termina correctamente.
int main() {
int opcion;
    Paciente pacientes[MAX_PACIENTES];
   int cantidadPacientes;
cantidadPacientes = CargarPacientes(pacientes);

printf("Nathalie Ramirez Salcedo\n");
printf("Numero de carnet: 202501345876\n");
printf("Entregable final\n\n");
do { 
MostrarOpciones ();
printf("Escriba una opcion: ");

scanf("%d", &opcion);

switch (opcion) {
    case 1:
    cantidadPacientes = RegistrarPaciente (pacientes, cantidadPacientes);
    GuardarPacientes(pacientes, cantidadPacientes);
        break;
    case 2:
    MostrarPacientes(pacientes, cantidadPacientes);
        break; 
    case 3:
    MostrarPromedios(pacientes, cantidadPacientes);
        break;
    case 4:
    EvaluarPacientes(pacientes, cantidadPacientes);
        break;
    case 5:
    printf("Saliendo...\n");
        break;
    default:
    printf("La opcion ingresada no es valida\n");
        
}
} while (opcion != 5);
return 0;
}
// Esta funcion no recibe datos ya que los () estan vacios, se muestran en pantalla las 5 opciones y no devuelve nada porque es tipo void.

void MostrarOpciones() { 
printf("\nControl de pacientes\n");
printf("1. Ingresar paciente\n");
printf("2. Mostrar todos los pacientes registrados\n");
printf("3. Mostrar promedios generales de signos vitales\n");
printf("4. Evaluar el estado de los pacientes\n");
printf("5. Salir del sistema\n");
}
// Recibe una lista de pacientes y la cantidad, guarda un paciente nuevo y devuelve la cantidad actualizada.

int RegistrarPaciente(Paciente pacientes[], int cantidadPacientes) {
if(cantidadPacientes >= MAX_PACIENTES) {
printf("Capacidad maxima alcanzada. No se pueden registrar mas pacientes.\n");
return cantidadPacientes;
}
printf("Nombre completo:");
scanf (" %[^\n]", pacientes[cantidadPacientes].nombre);

printf("Edad: ");
scanf("%d", &pacientes[cantidadPacientes].edad);

printf("Cedula: ");
scanf(" %s", pacientes[cantidadPacientes].cedula);

printf("Temperatura corporal (grados C): ");
scanf("%f", &pacientes[cantidadPacientes].temperatura);

printf("Frecuencia cardiaca (lpm): ");
scanf("%d", &pacientes[cantidadPacientes].frecCardiaca);

printf("Saturacion de oxigeno (%%): ");
scanf("%d", &pacientes[cantidadPacientes].saturacion);

printf("Presion sistolica (mmHg): ");
scanf("%d", &pacientes[cantidadPacientes].presionSist);

printf("Presion diastolica (mmHg): ");
scanf("%d", &pacientes[cantidadPacientes].presionDiast);
cantidadPacientes++;
return cantidadPacientes;
}
// Recibe el arreglo de pacientes y la cantidad registrada, muestra y recorre todos los registros, no devuelve resultados,si no hay pacientes muestra un aviso.

void MostrarPacientes(Paciente pacientes[], int cantidadPacientes) { 
   
    if (cantidadPacientes == 0) {
    printf("No hay pacientes registrados\n");
    return;
    }
    int i;

for (i = 0; i < cantidadPacientes; i++) {
printf("\nPaciente #%d\n", i + 1);
printf("Nombre: %s\n", pacientes[i].nombre);
printf("Edad: %d años\n", pacientes[i].edad);
printf("Cédula: %s \n", pacientes[i].cedula);
printf("Temperatura: %.1f grados C\n", pacientes[i].temperatura);
printf("Frecuencia cardíaca: %d lpm\n", pacientes[i].frecCardiaca);
printf("Saturación: %d %% \n", pacientes[i].saturacion);
printf("Presión sistólica: %d mmHg \n", pacientes[i].presionSist);
printf("Presión diastólica: %d mmHg \n", pacientes[i].presionDiast);
}
}
// Esta funcion recibe los pacientes y la cantidad registrada, luego recorre los pacientes y suma sus temperaturas y al final devuelve el promedio de las temperaturas.
float CalcularPromedioTemperatura (Paciente pacientes [], int cantidad){
float suma =0;

int i;

for (i = 0; i < cantidad; i++) {
 suma = suma + pacientes[i].temperatura;
}
return suma / cantidad;
}

// Esta funcion recibe los pacientes y la cantidad registrada, luego recorre los pacientes y suma sus frecuencias cardiacas y al final devuelve el promedio de las frecuencias.

float CalcularPromedioFrecuencia (Paciente pacientes [], int cantidad){
float suma =0;

int i;

for (i = 0; i < cantidad; i++) {
 suma = suma + pacientes[i].frecCardiaca;
}
return suma / cantidad;
}

// Esta funcion recibe los pacientes y la cantidad registrada, luego recorre los pacientes y suma sus saturaciones de oxigeno y al final devuelve el promedio de las saturaciones.

float CalcularPromedioSaturacion (Paciente pacientes [], int cantidad){
float suma =0;

int i;

for (i = 0; i < cantidad; i++) {
 suma = suma + pacientes[i].saturacion;
}
return suma / cantidad;
}

// Esta funcion recibe los pacientes y la cantidad registrada, luego recorre los pacientes y suma su presion sistolica y al final devuelve el promedio de las presiones.

float CalcularPromedioSistolica (Paciente pacientes [], int cantidad){
float suma =0;

int i;

for (i = 0; i < cantidad; i++) {
 suma = suma + pacientes[i].presionSist;
}
return suma / cantidad;
}

// Esta funcion recibe los pacientes y la cantidad registrada, luego recorre los pacientes y suma su presion diastolica y al final devuelve el promedio de las presiones.

float CalcularPromedioDiastolica (Paciente pacientes [], int cantidad){
float suma =0;

int i;

for (i = 0; i < cantidad; i++) {
 suma = suma + pacientes[i].presionDiast;
}
return suma / cantidad;
}

// Esta funcion recibe el arreglo de pacientes y la cantidad registrada, primero revisa si existen pacientes, después muestra los cinco promedios generales y no devuelve ningun valor porque es void.

void MostrarPromedios(Paciente pacientes[], int cantidad){

     if (cantidad == 0) {
     printf("No hay pacientes registrados\n");
    return;
     }

  printf("Temperatura promedio: %.2f grados C\n", CalcularPromedioTemperatura (pacientes, cantidad)); 
  printf("Frecuencia cardiaca promedio: %.2f lpm\n", CalcularPromedioFrecuencia(pacientes, cantidad));
  printf("Saturacion promedio: %.2f %%\n", CalcularPromedioSaturacion(pacientes, cantidad));
  printf("Presion sistolica promedio: %.2f mmHg\n", CalcularPromedioSistolica(pacientes, cantidad));
  printf("Presion diastolica promedio: %.2f mmHg\n", CalcularPromedioDiastolica(pacientes, cantidad));

}

// Esta funcion recibe el arreglo de pacientes  y la cantidad registrada, revisa los cinco signos vitales de cada paciente, después muestra si cada paciente esta estable o si requiere revision medica, e indica cuales signos estan fuera del rango, no devuelve ningun valor.

void EvaluarPacientes (Paciente pacientes [], int cantidad){ 
     
    if (cantidad == 0) {
    printf("No hay pacientes registrados para evaluar\n");
    return;
}
int i;
int estable;
for (i = 0; i < cantidad; i++) {
    estable = 1;

    printf("\nPaciente: %s\n", pacientes[i].nombre);
    if (pacientes[i].temperatura < TEMP_MIN || pacientes[i].temperatura > TEMP_MAX) {
    printf("Temperatura fuera de rango\n");
    estable = 0;
    }
    if (pacientes[i].frecCardiaca < FREC_MIN || pacientes[i].frecCardiaca > FREC_MAX) {
    printf("Frecuencia cardiaca fuera de rango\n");
    estable = 0;
    }
    if (pacientes[i].saturacion < SAT_MIN || pacientes[i].saturacion > SAT_MAX) {
    printf("Saturacion de oxigeno fuera de rango\n");
    estable = 0;
    }

    if (pacientes[i].presionSist < SIST_MIN || pacientes[i].presionSist > SIST_MAX) {
    printf("Presion sistolica fuera de rango\n");
    estable = 0;
    }

    if (pacientes[i].presionDiast < DIAST_MIN || pacientes[i].presionDiast > DIAST_MAX) {
    printf("Presion Diastolica fuera de rango\n");
    estable = 0;
    }
if (estable == 1) {
    printf("Estado: ESTABLE\n");
} else {
    printf("Estado: REQUIERE REVISION MEDICA\n");
}
}
}
// Esta funcion recibe el arreglo de pacientes, intenta abrir pacientes.txt para leer los datos, guarda los pacientes encontrados en el arreglo y devuelve la cantidad de pacientes cargados. Si el archivo no existe, devuelve 0.
int CargarPacientes(Paciente pacientes[]) {
    FILE *archivo;
int cantidad = 0;
archivo = fopen("pacientes.txt", "r");
if (archivo == NULL) {
    return 0;
}
    while (cantidad < MAX_PACIENTES &&
       fscanf(archivo, " %[^\n]", pacientes[cantidad].nombre) == 1) {
if (fscanf(archivo, "%d %s %f %d %d %d %d",
           &pacientes[cantidad].edad,
           pacientes[cantidad].cedula,
           &pacientes[cantidad].temperatura,
           &pacientes[cantidad].frecCardiaca,
           &pacientes[cantidad].saturacion,
           &pacientes[cantidad].presionSist,
           &pacientes[cantidad].presionDiast) == 7) {
    cantidad++;
} else {
    break;
}
}
fclose(archivo);
return cantidad;
}
// Esta funcion recibe el arreglo de pacientes y la cantidad registrada, abre pacientes.txt para escribir, guarda cada paciente en dos lineas y cierra el archivo, no devuelve ningun valor.
void GuardarPacientes(Paciente pacientes[], int cantidadPacientes){
FILE *archivo;
int i;
archivo = fopen("pacientes.txt", "w");
if (archivo == NULL) {
    printf("No se pudo guardar la informacion.\n");
    return;
    }
    for (i = 0; i < cantidadPacientes; i++) {
fprintf(archivo, "%s\n", pacientes[i].nombre);
fprintf(archivo, "%d %s %.1f %d %d %d %d\n",
        pacientes[i].edad,
        pacientes[i].cedula,
        pacientes[i].temperatura,
        pacientes[i].frecCardiaca,
        pacientes[i].saturacion,
        pacientes[i].presionSist,
        pacientes[i].presionDiast);
}
fclose(archivo);
}
















