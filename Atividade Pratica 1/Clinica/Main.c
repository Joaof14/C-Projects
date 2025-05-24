
#include <stdio.h>
#include <stdlib.h>
#include "Medico.h"
#include "Paciente.h"
#include "Consulta.h"
#include "Relatorios.h"

int main (){
    int n;
    do {
        switch (n)
        {
        case 1:
            menuMedico();
            break;
            
        case 2:
        menuPaciente();
            /* code */
            break;
        case 3:
        menuRelatorios();
            /* code */
            break;
        case 4:
        menuConsultas();
            /* code */
            break;
        
        default:
        printf("Opção inválida");
            break;
        }
        
    }
    while (n != 0);
    
}



