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