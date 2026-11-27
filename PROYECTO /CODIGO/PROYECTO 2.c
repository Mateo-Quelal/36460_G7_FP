/*
LIBRERIAS

stdio.h: Sirve para mostrar mensajes en pantalla (printf) y leer lo que el
usuario escribe por teclado (scanf).
*/
#include <stdio.h>

/*
string.h: Sirve para manejar y comparar textos o cadenas de caracteres
(por ejemplo, nombres de marcas).
*/
#include <string.h>

/*
CONSTANTES DE CONFIGURACION (BUENA PRACTICA: EVITAR NUMEROS SUELTOS)
*/
#define MAX_MARCAS 20        /* Maximo de marcas distintas que se pueden guardar */
#define UNIDADES_POR_CAJA 12 /* Cada caja de proveedor trae 12 botellas */

/*
PROTOTIPOS DE FUNCIONES
Declaramos aqui las funciones para que el compilador las conozca antes de main.
*/
void mostrarMenu(void);
int leerEnteroPositivo(const char *mensaje);
float leerFlotantePositivo(const char *mensaje);
int seleccionarMarca(char marca[][50], int stock[], int totalMarcas);
void verificarAlertaStock(char marca[], int stockActual, int stockMinimo);

void registrarMarca(char marca[][50], int stock[], int minimo[],
                    float pNormal[], float pCombo[], float pMadrugada[],
                    int ingresadas[], int vendidas[], int bajas[],
                    int *totalMarcas);

void ingresarBotellas(char marca[][50], int stock[], int ingresadas[],
                      int totalMarcas);

void registrarVenta(char marca[][50], int stock[], int minimo[],
                    float pNormal[], float pCombo[], float pMadrugada[],
                    int vendidas[], float *caja, int totalMarcas);

void registrarBaja(char marca[][50], int stock[], int minimo[],
                   int bajas[], int totalMarcas);

void verInventario(char marca[][50], int stock[], int minimo[],
                   int totalMarcas);

void mostrarCierre(char marca[][50], int stock[], int ingresadas[],
                   int vendidas[], int bajas[], float caja, int totalMarcas);

/*
FUNCION PRINCIPAL: main
Funcion compuesta que coordina el ciclo del programa y llama a las demas
funciones segun la opcion elegida por el usuario.
*/
int main(void) {
    /* Arreglos para guardar los datos de cada marca de botella */
    char marca[MAX_MARCAS][50];
    int stock[MAX_MARCAS];
    int minimo[MAX_MARCAS];
    float pNormal[MAX_MARCAS];
    float pCombo[MAX_MARCAS];
    float pMadrugada[MAX_MARCAS];
    int ingresadas[MAX_MARCAS];
    int vendidas[MAX_MARCAS];
    int bajas[MAX_MARCAS];

    /* Variables de control general */
    float caja = 0.0f;
    int totalMarcas = 0;
    int opcion = 0;

    /* El bucle while mantiene el programa abierto hasta que el usuario elija 6 */
    while (opcion != 6) {
        mostrarMenu();
        scanf("%d", &opcion);

        if (opcion == 1) {
            registrarMarca(marca, stock, minimo, pNormal, pCombo, pMadrugada,
                           ingresadas, vendidas, bajas, &totalMarcas);
        } else if (opcion == 2) {
            ingresarBotellas(marca, stock, ingresadas, totalMarcas);
        } else if (opcion == 3) {
            registrarVenta(marca, stock, minimo, pNormal, pCombo, pMadrugada,
                           vendidas, &caja, totalMarcas);
        } else if (opcion == 4) {
            registrarBaja(marca, stock, minimo, bajas, totalMarcas);
        } else if (opcion == 5) {
            verInventario(marca, stock, minimo, totalMarcas);
        } else if (opcion == 6) {
            mostrarCierre(marca, stock, ingresadas, vendidas, bajas, caja, totalMarcas);
        } else {
            printf("Opcion no valida. Intenta de nuevo.\n");
        }
    }

    return 0;
}

/*
FUNCIONES AUXILIARES (TAREAS PEQUENAS Y REUTILIZABLES)
*/

/* mostrarMenu: Solo se encarga de imprimir las opciones disponibles en pantalla. */
void mostrarMenu(void) {
    printf("\nMENU PRINCIPAL\n");
    printf("1. Registrar marca\n");
    printf("2. Ingresar botellas\n");
    printf("3. Registrar venta\n");
    printf("4. Registrar rotura o cortesia VIP\n");
    printf("5. Ver inventario\n");
    printf("6. Cierre de noche y salir\n");
    printf("Opcion: ");
}

/*
leerEnteroPositivo: Pide un numero entero y repite la pregunta si el usuario
ingresa un numero negativo, evitando errores por datos invalidos.
*/
int leerEnteroPositivo(const char *mensaje) {
    int valor;
    do {
        printf("%s", mensaje);
        scanf("%d", &valor);
        if (valor < 0) {
            printf("Error: el valor no puede ser negativo.\n");
        }
    } while (valor < 0);
    return valor;
}

/* leerFlotantePositivo: Igual que la anterior, pero para precios con decimales. */
float leerFlotantePositivo(const char *mensaje) {
    float valor;
    do {
        printf("%s", mensaje);
        scanf("%f", &valor);
        if (valor < 0.0f) {
            printf("Error: el precio no puede ser negativo.\n");
        }
    } while (valor < 0.0f);
    return valor;
}

/*
seleccionarMarca: Muestra la lista de marcas con su stock actual y devuelve
el indice (posicion en el arreglo) de la marca elegida, o menos uno si no existe.
*/
int seleccionarMarca(char marca[][50], int stock[], int totalMarcas) {
    int i, eleccion;
    for (i = 0; i < totalMarcas; i++) {
        printf("%d. %s (Stock: %d botellas)\n", i + 1, marca[i], stock[i]);
    }
    printf("Elija marca: ");
    scanf("%d", &eleccion);
    eleccion--; /* Convertimos de numeracion 1..N a indice 0..N menos 1 */

    if (eleccion < 0 || eleccion >= totalMarcas) {
        printf("Marca no valida.\n");
        return -1;
    }
    return eleccion;
}

/*
verificarAlertaStock: Revisa si tras una salida de botellas el stock quedo
igual o por debajo del minimo critico para avisar que hay que pedir mas.
*/
void verificarAlertaStock(char marca[], int stockActual, int stockMinimo) {
    if (stockActual <= stockMinimo) {
        printf("ALERTA: Quedan pocas botellas de %s (%d disponibles, minimo: %d).\n",
               marca, stockActual, stockMinimo);
    }
}

/*
FUNCIONES COMPUESTAS DEL PROCESO (OPERACIONES DEL NEGOCIO)
*/

/*
registrarMarca: Crea una nueva marca de botella con su stock inicial,
stock minimo y precios segun tipo de venta (normal, combo o madrugada).
*/
void registrarMarca(char marca[][50], int stock[], int minimo[],
                    float pNormal[], float pCombo[], float pMadrugada[],
                    int ingresadas[], int vendidas[], int bajas[],
                    int *totalMarcas) {
    int idx = *totalMarcas;

    if (idx >= MAX_MARCAS) {
        printf("Limite maximo de marcas alcanzado.\n");
        return;
    }

    printf("Nombre de marca (sin espacios): ");
    scanf("%s", marca[idx]);

    stock[idx] = leerEnteroPositivo("Stock inicial (botellas): ");
    minimo[idx] = leerEnteroPositivo("Stock minimo para alerta: ");
    pNormal[idx] = leerFlotantePositivo("Precio normal: ");
    pCombo[idx] = leerFlotantePositivo("Precio combo: ");
    pMadrugada[idx] = leerFlotantePositivo("Precio madrugada: ");

    /* Iniciamos los contadores de la jornada para esta marca */
    ingresadas[idx] = stock[idx];
    vendidas[idx] = 0;
    bajas[idx] = 0;

    (*totalMarcas)++;
    printf("Marca guardada correctamente.\n");
}

/*
ingresarBotellas: Suma botellas recibidas del proveedor, ya sea en cajas
cerradas (12 botellas) o como botellas sueltas.
*/
void ingresarBotellas(char marca[][50], int stock[], int ingresadas[],
                      int totalMarcas) {
    int id, tipo, cajas, cant;

    if (totalMarcas == 0) {
        printf("Primero registra al menos una marca.\n");
        return;
    }

    id = seleccionarMarca(marca, stock, totalMarcas);
    if (id == -1) return;

    printf("1. Por cajas (%d botellas)  2. Botellas sueltas: ", UNIDADES_POR_CAJA);
    scanf("%d", &tipo);

    if (tipo == 1) {
        cajas = leerEnteroPositivo("Cantidad de cajas: ");
        cant = cajas * UNIDADES_POR_CAJA;
    } else if (tipo == 2) {
        cant = leerEnteroPositivo("Cantidad de botellas sueltas: ");
    } else {
        printf("Tipo de ingreso no valido.\n");
        return;
    }

    if (cant > 0) {
        stock[id] += cant;
        ingresadas[id] += cant;
        printf("Ingreso guardado. Stock actual de %s: %d botellas.\n", marca[id], stock[id]);
    } else {
        printf("La cantidad debe ser mayor a cero.\n");
    }
}

/*
registrarVenta: Descuenta botellas vendidas verificando que haya stock
suficiente, calcula el dinero segun la tarifa y revisa el stock minimo.
*/
void registrarVenta(char marca[][50], int stock[], int minimo[],
                    float pNormal[], float pCombo[], float pMadrugada[],
                    int vendidas[], float *caja, int totalMarcas) {
    int id, cant, tarifa;
    float precioUnitario;

    if (totalMarcas == 0) {
        printf("No hay marcas registradas.\n");
        return;
    }

    id = seleccionarMarca(marca, stock, totalMarcas);
    if (id == -1) return;

    cant = leerEnteroPositivo("Botellas vendidas: ");
    if (cant == 0) {
        printf("La cantidad debe ser mayor a cero.\n");
        return;
    }

    /* Buena practica: bloquear ventas si no alcanza el stock disponible */
    if (cant > stock[id]) {
        printf("Error: stock insuficiente. Solo quedan %d botellas.\n", stock[id]);
        return;
    }

    printf("Tarifa: 1. Normal  2. Combo  3. Madrugada: ");
    scanf("%d", &tarifa);

    if (tarifa == 1) {
        precioUnitario = pNormal[id];
    } else if (tarifa == 2) {
        precioUnitario = pCombo[id];
    } else if (tarifa == 3) {
        precioUnitario = pMadrugada[id];
    } else {
        printf("Tarifa no valida. Venta cancelada.\n");
        return;
    }

    stock[id] -= cant;
    vendidas[id] += cant;
    *caja += cant * precioUnitario;

    printf("Venta registrada. Total cobrado: $%.2f\n", cant * precioUnitario);
    verificarAlertaStock(marca[id], stock[id], minimo[id]);
}

/*
registrarBaja: Descuenta botellas completas que salen sin cobro (rotura,
defecto o cortesia VIP) y verifica si se alcanzo el stock minimo.
*/
void registrarBaja(char marca[][50], int stock[], int minimo[],
                   int bajas[], int totalMarcas) {
    int id, motivo, cant;

    if (totalMarcas == 0) {
        printf("No hay marcas registradas.\n");
        return;
    }

    id = seleccionarMarca(marca, stock, totalMarcas);
    if (id == -1) return;

    printf("1. Rotura o defecto  2. Cortesia VIP: ");
    scanf("%d", &motivo);
    if (motivo != 1 && motivo != 2) {
        printf("Motivo no valido.\n");
        return;
    }

    cant = leerEnteroPositivo("Cantidad de botellas: ");
    if (cant == 0) {
        printf("La cantidad debe ser mayor a cero.\n");
        return;
    }

    if (cant > stock[id]) {
        printf("Error: no puedes dar de baja mas botellas de las que hay (%d).\n", stock[id]);
        return;
    }

    stock[id] -= cant;
    bajas[id] += cant;
    printf("Baja registrada correctamente.\n");
    verificarAlertaStock(marca[id], stock[id], minimo[id]);
}

/*
verInventario: Muestra el estado actual de cada marca e indica cuales
necesitan pedido porque estan en o bajo su stock minimo.
*/
void verInventario(char marca[][50], int stock[], int minimo[],
                   int totalMarcas) {
    int i;
    if (totalMarcas == 0) {
        printf("No hay marcas registradas.\n");
        return;
    }

    printf("\nINVENTARIO ACTUAL\n");
    for (i = 0; i < totalMarcas; i++) {
        printf("%s | Stock: %d | Minimo: %d", marca[i], stock[i], minimo[i]);
        if (stock[i] <= minimo[i]) {
            printf(" -> PEDIR MAS");
        }
        printf("\n");
    }
}

/*
mostrarCierre: Calcula y muestra el resumen final de la jornada (ingresos,
ventas, bajas por rotura o VIP, stock final y dinero esperado en caja).
*/
void mostrarCierre(char marca[][50], int stock[], int ingresadas[],
                   int vendidas[], int bajas[], float caja, int totalMarcas) {
    int i;
    int sumaVendidas = 0;
    int sumaBajas = 0;
    int sumaStock = 0;

    printf("\nRESUMEN DE CIERRE\n");
    for (i = 0; i < totalMarcas; i++) {
        printf("%s -> Ingreso: %d | Vendidas: %d | Bajas: %d | Final: %d\n",
               marca[i], ingresadas[i], vendidas[i], bajas[i], stock[i]);
        sumaVendidas += vendidas[i];
        sumaBajas += bajas[i];
        sumaStock += stock[i];
    }

    printf("\nTotal botellas vendidas: %d\n", sumaVendidas);
    printf("Total botellas rotura o VIP: %d\n", sumaBajas);
    printf("Stock final en bodega: %d\n", sumaStock);
    printf("Dinero esperado en caja: $%.2f\n", caja);
}
