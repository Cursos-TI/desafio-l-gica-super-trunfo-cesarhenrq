#include <stdio.h>

int main() {
    // Variáveis da Carta 1
    char estado1;
    char codigo1[4];
    char cidade1[50];
    unsigned long int populacao1;
    float area1, pib1, densidade_pop1, pib_per_capita1, super_poder1;
    int pontos_turisticos1;

    // Variáveis da Carta 2
    char estado2;
    char codigo2[4];
    char cidade2[50];
    unsigned long int populacao2;
    float area2, pib2, densidade_pop2, pib_per_capita2, super_poder2;
    int pontos_turisticos2;

    // Cadastro da Carta 1
    printf("Cadastro da Carta 1\n");
    printf("Estado (A-H): ");
    scanf(" %c", &estado1);
    printf("Código da Carta: ");
    scanf("%s", codigo1);
    printf("Nome da Cidade: ");
    scanf(" %[^\n]", cidade1);
    printf("População: ");
    scanf("%lu", &populacao1);
    printf("Área (km²): ");
    scanf("%f", &area1);
    printf("PIB (bilhões de reais): ");
    scanf("%f", &pib1);
    printf("Número de Pontos Turísticos: ");
    scanf("%d", &pontos_turisticos1);

    // Cadastro da Carta 2
    printf("\nCadastro da Carta 2\n");
    printf("Estado (A-H): ");
    scanf(" %c", &estado2);
    printf("Código da Carta: ");
    scanf("%s", codigo2);
    printf("Nome da Cidade: ");
    scanf(" %[^\n]", cidade2);
    printf("População: ");
    scanf("%lu", &populacao2);
    printf("Área (km²): ");
    scanf("%f", &area2);
    printf("PIB (bilhões de reais): ");
    scanf("%f", &pib2);
    printf("Número de Pontos Turísticos: ");
    scanf("%d", &pontos_turisticos2);

    // Cálculos
    densidade_pop1 = populacao1 / area1;
    pib_per_capita1 = pib1 * 1e9 / populacao1;
    super_poder1 = populacao1 + area1 + pib1 * 1e9 + pontos_turisticos1 + pib_per_capita1 + (1.0 / densidade_pop1);

    densidade_pop2 = populacao2 / area2;
    pib_per_capita2 = pib2 * 1e9 / populacao2;
    super_poder2 = populacao2 + area2 + pib2 * 1e9 + pontos_turisticos2 + pib_per_capita2 + (1.0 / densidade_pop2);

    // Variáveis para comparação
    int opcao1, opcao2;
    float valor1_carta1 = 0, valor1_carta2 = 0;
    float valor2_carta1 = 0, valor2_carta2 = 0;
    char nome_atributo1[30], nome_atributo2[30];
    int invertido1 = 0, invertido2 = 0;

    // Menu Interativo para o primeiro atributo
    printf("\nEscolha o PRIMEIRO atributo para comparar as cartas:\n");
    printf("1. População\n");
    printf("2. Área\n");
    printf("3. PIB\n");
    printf("4. Número de Pontos Turísticos\n");
    printf("5. Densidade Demográfica\n");
    printf("Opção: ");
    scanf("%d", &opcao1);

    // Validar a primeira escolha
    while(opcao1 < 1 || opcao1 > 5) {
        printf("Opção inválida! Escolha entre 1 e 5: ");
        scanf("%d", &opcao1);
    }

    // Preparar menu para o segundo atributo (excluindo o primeiro)
    printf("\nEscolha o SEGUNDO atributo para comparar as cartas:\n");
    for(int i = 1; i <= 5; i++) {
        if(i != opcao1) { // Exclui o atributo já escolhido
            switch(i) {
                case 1: printf("%d. População\n", i); break;
                case 2: printf("%d. Área\n", i); break;
                case 3: printf("%d. PIB\n", i); break;
                case 4: printf("%d. Número de Pontos Turísticos\n", i); break;
                case 5: printf("%d. Densidade Demográfica\n", i); break;
            }
        }
    }
    printf("Opção: ");
    scanf("%d", &opcao2);

    // Validar a segunda escolha
    while(opcao2 < 1 || opcao2 > 5 || opcao2 == opcao1) {
        printf("Opção inválida ou já escolhida! Escolha novamente: ");
        scanf("%d", &opcao2);
    }

    // Atribuir valores e nomes para o primeiro atributo
    switch(opcao1) {
        case 1: // População
            strcpy(nome_atributo1, "População");
            valor1_carta1 = populacao1;
            valor1_carta2 = populacao2;
            break;
        case 2: // Área
            strcpy(nome_atributo1, "Área");
            valor1_carta1 = area1;
            valor1_carta2 = area2;
            break;
        case 3: // PIB
            strcpy(nome_atributo1, "PIB");
            valor1_carta1 = pib1;
            valor1_carta2 = pib2;
            break;
        case 4: // Número de Pontos Turísticos
            strcpy(nome_atributo1, "Número de Pontos Turísticos");
            valor1_carta1 = pontos_turisticos1;
            valor1_carta2 = pontos_turisticos2;
            break;
        case 5: // Densidade Demográfica
            strcpy(nome_atributo1, "Densidade Demográfica");
            valor1_carta1 = densidade_pop1;
            valor1_carta2 = densidade_pop2;
            invertido1 = 1; // Inverte a regra para densidade demográfica
            break;
    }

    // Atribuir valores e nomes para o segundo atributo
    switch(opcao2) {
        case 1: // População
            strcpy(nome_atributo2, "População");
            valor2_carta1 = populacao1;
            valor2_carta2 = populacao2;
            break;
        case 2: // Área
            strcpy(nome_atributo2, "Área");
            valor2_carta1 = area1;
            valor2_carta2 = area2;
            break;
        case 3: // PIB
            strcpy(nome_atributo2, "PIB");
            valor2_carta1 = pib1;
            valor2_carta2 = pib2;
            break;
        case 4: // Número de Pontos Turísticos
            strcpy(nome_atributo2, "Número de Pontos Turísticos");
            valor2_carta1 = pontos_turisticos1;
            valor2_carta2 = pontos_turisticos2;
            break;
        case 5: // Densidade Demográfica
            strcpy(nome_atributo2, "Densidade Demográfica");
            valor2_carta1 = densidade_pop1;
            valor2_carta2 = densidade_pop2;
            invertido2 = 1; // Inverte a regra para densidade demográfica
            break;
    }

    // Calcular pontuação de cada carta nos dois atributos
    float pontos_carta1 = 0, pontos_carta2 = 0;

    // Para o primeiro atributo
    if (invertido1) {
        // Para densidade demográfica, menor valor ganha
        if (valor1_carta1 < valor1_carta2) {
            pontos_carta1 += valor1_carta1;
        } else if (valor1_carta1 > valor1_carta2) {
            pontos_carta2 += valor1_carta2;
        } else {
            // Em caso de empate, ambos recebem pontos
            pontos_carta1 += valor1_carta1;
            pontos_carta2 += valor1_carta2;
        }
    } else {
        // Para os outros atributos, maior valor ganha
        if (valor1_carta1 > valor1_carta2) {
            pontos_carta1 += valor1_carta1;
        } else if (valor1_carta1 < valor1_carta2) {
            pontos_carta2 += valor1_carta2;
        } else {
            // Em caso de empate, ambos recebem pontos
            pontos_carta1 += valor1_carta1;
            pontos_carta2 += valor1_carta2;
        }
    }

    // Para o segundo atributo
    if (invertido2) {
        // Para densidade demográfica, menor valor ganha
        if (valor2_carta1 < valor2_carta2) {
            pontos_carta1 += valor2_carta1;
        } else if (valor2_carta1 > valor2_carta2) {
            pontos_carta2 += valor2_carta2;
        } else {
            // Em caso de empate, ambos recebem pontos
            pontos_carta1 += valor2_carta1;
            pontos_carta2 += valor2_carta2;
        }
    } else {
        // Para os outros atributos, maior valor ganha
        if (valor2_carta1 > valor2_carta2) {
            pontos_carta1 += valor2_carta1;
        } else if (valor2_carta1 < valor2_carta2) {
            pontos_carta2 += valor2_carta2;
        } else {
            // Em caso de empate, ambos recebem pontos
            pontos_carta1 += valor2_carta1;
            pontos_carta2 += valor2_carta2;
        }
    }

    // Exibir resultados
    printf("\n=== RESULTADO DA COMPARAÇÃO ===\n\n");
    
    // Primeiro atributo
    printf("Atributo 1: %s\n", nome_atributo1);
    
    // Formatação específica para cada tipo de atributo
    if (opcao1 == 1) { // População
        printf("Carta 1 - %s: %lu\n", cidade1, populacao1);
        printf("Carta 2 - %s: %lu\n", cidade2, populacao2);
    } else if (opcao1 == 2) { // Área
        printf("Carta 1 - %s: %.2f km²\n", cidade1, area1);
        printf("Carta 2 - %s: %.2f km²\n", cidade2, area2);
    } else if (opcao1 == 3) { // PIB
        printf("Carta 1 - %s: %.2f bilhões\n", cidade1, pib1);
        printf("Carta 2 - %s: %.2f bilhões\n", cidade2, pib2);
    } else if (opcao1 == 4) { // Pontos Turísticos
        printf("Carta 1 - %s: %d\n", cidade1, pontos_turisticos1);
        printf("Carta 2 - %s: %d\n", cidade2, pontos_turisticos2);
    } else if (opcao1 == 5) { // Densidade Demográfica
        printf("Carta 1 - %s: %.2f hab/km²\n", cidade1, densidade_pop1);
        printf("Carta 2 - %s: %.2f hab/km²\n", cidade2, densidade_pop2);
    }
    
    // Resultado do primeiro atributo
    if (invertido1) {
        if (valor1_carta1 < valor1_carta2) {
            printf("Resultado do atributo 1: Carta 1 (%s) venceu!\n", cidade1);
        } else if (valor1_carta1 > valor1_carta2) {
            printf("Resultado do atributo 1: Carta 2 (%s) venceu!\n", cidade2);
        } else {
            printf("Resultado do atributo 1: Empate!\n");
        }
    } else {
        if (valor1_carta1 > valor1_carta2) {
            printf("Resultado do atributo 1: Carta 1 (%s) venceu!\n", cidade1);
        } else if (valor1_carta1 < valor1_carta2) {
            printf("Resultado do atributo 1: Carta 2 (%s) venceu!\n", cidade2);
        } else {
            printf("Resultado do atributo 1: Empate!\n");
        }
    }
    
    // Segundo atributo
    printf("\nAtributo 2: %s\n", nome_atributo2);
    
    // Formatação específica para cada tipo de atributo
    if (opcao2 == 1) { // População
        printf("Carta 1 - %s: %lu\n", cidade1, populacao1);
        printf("Carta 2 - %s: %lu\n", cidade2, populacao2);
    } else if (opcao2 == 2) { // Área
        printf("Carta 1 - %s: %.2f km²\n", cidade1, area1);
        printf("Carta 2 - %s: %.2f km²\n", cidade2, area2);
    } else if (opcao2 == 3) { // PIB
        printf("Carta 1 - %s: %.2f bilhões\n", cidade1, pib1);
        printf("Carta 2 - %s: %.2f bilhões\n", cidade2, pib2);
    } else if (opcao2 == 4) { // Pontos Turísticos
        printf("Carta 1 - %s: %d\n", cidade1, pontos_turisticos1);
        printf("Carta 2 - %s: %d\n", cidade2, pontos_turisticos2);
    } else if (opcao2 == 5) { // Densidade Demográfica
        printf("Carta 1 - %s: %.2f hab/km²\n", cidade1, densidade_pop1);
        printf("Carta 2 - %s: %.2f hab/km²\n", cidade2, densidade_pop2);
    }
    
    // Resultado do segundo atributo
    if (invertido2) {
        if (valor2_carta1 < valor2_carta2) {
            printf("Resultado do atributo 2: Carta 1 (%s) venceu!\n", cidade1);
        } else if (valor2_carta1 > valor2_carta2) {
            printf("Resultado do atributo 2: Carta 2 (%s) venceu!\n", cidade2);
        } else {
            printf("Resultado do atributo 2: Empate!\n");
        }
    } else {
        if (valor2_carta1 > valor2_carta2) {
            printf("Resultado do atributo 2: Carta 1 (%s) venceu!\n", cidade1);
        } else if (valor2_carta1 < valor2_carta2) {
            printf("Resultado do atributo 2: Carta 2 (%s) venceu!\n", cidade2);
        } else {
            printf("Resultado do atributo 2: Empate!\n");
        }
    }
    
    // Resultado final
    printf("\n=== RESULTADO FINAL ===\n");
    printf("Soma dos atributos para %s: %.2f\n", cidade1, pontos_carta1);
    printf("Soma dos atributos para %s: %.2f\n", cidade2, pontos_carta2);
    
    if (pontos_carta1 > pontos_carta2) {
        printf("VENCEDOR FINAL: Carta 1 (%s)!\n", cidade1);
    } else if (pontos_carta1 < pontos_carta2) {
        printf("VENCEDOR FINAL: Carta 2 (%s)!\n", cidade2);
    } else {
        printf("RESULTADO FINAL: Empate!\n");
    }

    return 0;
}