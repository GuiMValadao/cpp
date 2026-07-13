#include <iostream>

using namespace std;
int main(void) {
    /* Streams (Fluxos?) são usados para enviar ou exibir dados em uma tela de computador (console)
    cout é um exemplo de um stream de saída(output) e requer apenas o header #include <iostream>.
    Para exibir valores na tela, usa-se o operador << (chamado de operador de inserção) para passar os dados para o stream cout. 
    Ambos cout e << são responsáveis por:
        - converter a representação interna (linguagem da máquina) do valor para uma forma 
            aceitável para humanos
        - transferir a forma convertida para o dispositivo de output, o console.*/
    
    // Exemplo:
    int valor_esperado = 1234;
    cout << "Exibindo o valor da variável valor_esperado: "<< valor_esperado;
    cout << "\n\nO operador << pode ser usado múltiplas vezes para exibir valores de tipos diferentes para um mesmo stream cout.";
    cout << "\n\ncout também aceita expressões. O dobro do valor_esperado é "<< 2 * valor_esperado;
    cout << "\n\nManipuladores podem ser usados para alterar a base numérica de uma variável."<<
    "\n\nPor exemplo, para exibir o valor_esperado 123 em hexadecimal, usa-se 'hex'" << hex << valor_esperado << dec << endl << "\n";
    /* Um manipulador é uma função que altera uma das propriedades de um stream chamada basefieled (campo de base).
    Por padrão, números usam a base 10. Para exibir números em base 8, usa-se oct, em base 16 hex e 
    para retornar à base 10 usa-se dec. Após usado, todas as ocorrências seguintes naquele fluxo 
    usarão a base definida. 
    Outra forma de alterar a base numérica é usando o manipulador setbase. Ele recebe
    como parâmetro o número da base pretendida (8, 10 ou 16) e requer o cabeçalho iomanip.
    */

}