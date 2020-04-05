#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

typedef struct PCs {
   int velocidad; //GHz
   int anio; //(2000 - 2017)
   int cant_nucleos; // (1 - 4)
   char tipo_cpu[10];
} PC;

PC generar_PC();
void devolver_PC(PC pcs[], int cant);
void cargar_PCs(PC pcs[], int cant);
void listar_PCs(PC pcs[], int cant);

void PC_vieja(PC pcs[], int cant);
void PC_veloz(PC pcs[], int cant);

int main()
{
    //Para tener numeros aleatorios cada vez que ejecutamos
    time_t t;
    srand((unsigned) time(&t));

    int cant_pc;
    

    printf("Ingrese cantidad de pc's: ");
    scanf("%d", &cant_pc);
    printf("\n");

    PC pcs[cant_pc];

    cargar_PCs(pcs, cant_pc);
    listar_PCs(pcs, cant_pc);

    printf("\n*** PC ALEATORIA ***\n");
    devolver_PC(pcs, cant_pc);

    PC_vieja(pcs, cant_pc);
    PC_veloz(pcs, cant_pc);


    getchar();
    getchar();
    return 0;
}

PC generar_PC()
{
    PC pc;
    char tipos[6][10]={"Intel", "AMD", "Celeron", "Athlon", "Core", "Pentium"};
    
    pc.velocidad = rand() % 3 + 1;
    pc.anio = rand() % 18 + 2000;
    pc.cant_nucleos = rand() % 4 + 1;
    strcpy (pc.tipo_cpu, tipos[rand() % 6]);

    return pc;
}

void devolver_PC(PC pcs[], int cant)
{
    int rand_num = 0;
    rand_num = rand() % cant;

    printf("PC velocidad: %d\n", pcs[rand_num].velocidad);
    printf("PC anio: %d\n", pcs[rand_num].anio);
    printf("PC cant_nucleos: %d\n", pcs[rand_num].cant_nucleos);
    printf("PC tipo CPU: \n");
    puts(pcs[rand_num].tipo_cpu);

    printf("\n");
}

void cargar_PCs(PC pcs[], int cant)
{
    for(int i = 0; i < cant; i++)
    {
        PC pc = generar_PC();
        pcs[i] = pc;
    }
}

void listar_PC(PC pc)
{
    printf("PC velocidad: %d\n", pc.velocidad);
    printf("PC anio: %d\n", pc.anio);
    printf("PC cant_nucleos: %d\n", pc.cant_nucleos);

    printf("PC tipo CPU: \n");
    puts(pc.tipo_cpu);

    printf("\n");
}

void listar_PCs(PC pcs[], int cant)
{
    for(int i = 0; i < cant; i++)
    {
        listar_PC(pcs[i]);
    }
}

void PC_vieja(PC pcs[], int cant)
{
    int anio_comp = 3000;
    PC pc;

    for(int i = 0; i < cant; i++)
    {
        if(pcs[i].anio < anio_comp)
        {
            anio_comp = pcs[i].anio;
            pc = pcs[i];
        }
    }

    puts("*** PC MAS VIEJA ***");
    listar_PC(pc);

}

void PC_veloz(PC pcs[], int cant)
{
    int vel_comp = 4;
    PC pc;

    for(int i = 0; i < cant; i++)
    {
        if(pcs[i].velocidad > vel_comp)
        {
            vel_comp = pcs[i].velocidad;
            pc = pcs[i];
        }
    }

    puts("*** PC MAS VELOZ ***");
    listar_PC(pc);
}