#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <windows.h>
#include <stdlib.h>
#include <stdint.h>

void retardo(unsigned long int);
void mostrar(unsigned char);
unsigned long int fvelocidad(unsigned long int);

void auto_fantastico(unsigned long int);
void carrera(unsigned long int);
void choque(unsigned long int);
void bateriaDescargandose(unsigned long int);
void chocaLos5(unsigned long int);

int main() {
    char contrasenia[] = "abc10";
    char contra[20];
    int intentos = 3, contador = 0;
    int i;

    while (intentos > 0) {
        printf("Ingrese su contraseña: ");
        for (i = 0; i < 5; i++) {
            contra[i] = _getch();
            printf("*");
        }
        contra[5] = '\0';

        if (strcmp(contra, contrasenia) != 0) {
            intentos--;
            contador++;
            system("cls");
            printf("Contrasenia incorrecta, le quedan %d intentos\n", intentos);
        } else {
            break;
        }
    }

    if (contador < 3) {
        system("cls");
        printf("Bienvenido al sistema\n");
    } else {
        printf("\nPassword no valida\n");
        return 0;
    }

    int opcion = 0;
    unsigned long int velocidadAux = 145000000;
    unsigned long int velocidad = velocidadAux;

    do {
        printf("\n(1) Autos fantastico\n");
        printf("(2) La carrera\n");
        printf("(3) El choque\n");
        printf("(4) Bateria descargandose\n");
        printf("(5) Choca los 5\n");
        printf("(6) Salir\n");

        printf("\nIngrese la opcion que desee visualizar: ");
        scanf("%d", &opcion);

        while (opcion < 1 || opcion > 6) {
            printf("Valor erroneo, ingrese nuevamente: ");
            scanf("%d", &opcion);
        }

        switch (opcion) {
            case 1:
                system("cls");
                auto_fantastico(velocidad);
                break;
            case 2:
                system("cls");
                carrera(velocidad);
                break;
            case 3:
                system("cls");
                choque(velocidad);
                break;
            case 4:
                system("cls");
                bateriaDescargandose(velocidad);
                break;
            case 5:
                system("cls");
                chocaLos5(velocidad);
                break;
            case 6:
                system("cls");
                printf("Sistema apagado\n");
                break;
            default:
                system("cls");
                printf("No existe secuencia para ese numero\n");
        }

        velocidad = velocidadAux;
        opcion = 0;

    } while (opcion != 6);

    return 0;
}

void retardo(unsigned long int a) {
    while (a) a--;
}

void mostrar(unsigned char dato) {
    unsigned char mascara;
    for (mascara = 128; mascara > 0; mascara >>= 1) {
        if (dato & mascara)
            printf("*");
        else
            printf("_");
    }
    printf("\n");
}

unsigned long int fvelocidad(unsigned long int velocidad) {
    if ((velocidad - 4800000) > 9600000) {
        if (GetAsyncKeyState(VK_UP) & 0x0001) {
            velocidad -= 4800000;
        }
    }
    if (GetAsyncKeyState(VK_DOWN) & 0x0001) {
        velocidad += 4800000;
    }
    return velocidad;
}

void auto_fantastico(unsigned long int velocidad) {
    unsigned int dato;
    int t, i;

    while (1) {
        dato = 0x80;
        for (t = 0; t < 8; t++) {
            printf("Presione ESC para regresar al menu principal\n");
            printf("Pulse la flecha para arriba para incrementar la velocidad, o para abajo para disminuirla\n");
            printf("Demora: %lu\n", velocidad);
            mostrar(dato);
            retardo(velocidad);
            system("cls");
            dato >>= 1;
            velocidad = fvelocidad(velocidad);
            if (GetAsyncKeyState(VK_ESCAPE) & 0x0001)
                return;
        }

        dato = 0x01;
        for (i = 0; i < 6; i++) {
            printf("Presione ESC para regresar al menu principal\n");
            printf("Pulse la flecha para arriba para incrementar la velocidad, o para abajo para disminuirla\n");
            printf("Demora: %lu\n", velocidad);
            dato <<= 1;
            mostrar(dato);
            retardo(velocidad);
            system("cls");
            velocidad = fvelocidad(velocidad);
            if (GetAsyncKeyState(VK_ESCAPE) & 0x0001)
                return;
        }
    }
}

void carrera(unsigned long int velocidad) {
    uint8_t tabla[] = {
        0x80, 0x80, 0x40, 0x40, 0x20, 0x20, 0x10, 0x10,
        0x88, 0x48, 0x24, 0x14, 0x0A, 0x06, 0x03, 0x01
    };

    int i;
    while (1) {
        for (i = 0; i < 16; ++i) {
            printf("Presione ESC para regresar al menu principal\n");
            printf("Pulse la flecha para arriba para incrementar la velocidad, o para abajo para disminuirla\n");
            printf("Demora: %lu\n", velocidad);
            mostrar(tabla[i]);
            retardo(velocidad);
            system("cls");
            velocidad = fvelocidad(velocidad);
            if (GetAsyncKeyState(VK_ESCAPE) & 0x0001)
                return;
        }
    }
}

void choque(unsigned long int velocidad) {
    uint8_t tabla[] = {
        0x81, 0x42, 0x24, 0x18, 0x18, 0x24, 0x42
    };

    int i;
    while (1) {
        for (i = 0; i < 7; ++i) {
            printf("Presione ESC para volver al menu principal\n");
            printf("Pulse la flecha para arriba para incrementar la velocidad, o para abajo para disminuirla\n");
            printf("Demora: %lu\n", velocidad);
            mostrar(tabla[i]);
            retardo(velocidad);
            system("cls");
            velocidad = fvelocidad(velocidad);
            if (GetAsyncKeyState(VK_ESCAPE) & 0x0001)
                return;
        }
    }
}

void bateriaDescargandose(unsigned long int velocidad) {
    unsigned int dato = 0xFF;
    int i;

    while (1) {
        for (i = 0; i < 9; ++i) {
            printf("Presione ESC para regresar al menu principal\n");
            printf("Demora: %lu\n", velocidad);
            mostrar(dato);
            dato <<= 1;
            retardo(velocidad);
            system("cls");
            velocidad = fvelocidad(velocidad);
            if (GetAsyncKeyState(VK_ESCAPE) & 0x0001)
                return;
        }
        dato = 0xFF;
    }
}

void chocaLos5(unsigned long int velocidad) {
    unsigned char tabla[] = {
        0x00, 0x81, 0xC3, 0xE7, 0xFF, 0xE7, 0xC3, 0x81
    };
    int i;

    while (1) {
        for (i = 0; i < 8; i++) {
            printf("Presione ESC para regresar al menu principal\n");
            printf("Pulse la flecha para arriba para incrementar la velocidad, o para abajo para disminuirla\n");
            printf("Demora: %lu\n", velocidad);
            mostrar(tabla[i]);
            retardo(velocidad);
            system("cls");
            velocidad = fvelocidad(velocidad);
            if (GetAsyncKeyState(VK_ESCAPE) & 0x0001)
                return;
        }
    }
}