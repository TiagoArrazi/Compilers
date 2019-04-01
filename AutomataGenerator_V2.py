
def set_level(level):
    return level * '\t'

if __name__ == '__main__':

    alphabet = int(input('Quantos símbolos no alfabeto? '))
    symbols = ['' for i in range(alphabet)]

    for i in range(alphabet):
        symbols[i] = input(f'Qual é o símbolo {i}? ')

    states_amount = int(input('Quantos estados? '))
    states = ['' for i in range(states_amount)]

    for i in range(states_amount):
        states[i] = input(f'Qual é o estado {i}? ')

    initial_state = str()
    while initial_state not in states:
          initial_state = input('Qual é o estado inicial? ')

    final_states_amount = int(input('Quantos estados finais? '))
    final_states = ['' for i in range(final_states_amount)]

    for i in range(final_states_amount):
        _state = input(f'Qual é o estado final {i}? ')
        while _state not in states:
            _state = input(f'Estado inexistente, qual é o estado final {i}? ')
        final_states[i] = _state

    alpha_delta = [[input(f'Para o estado {state} e o símbolo {symbol}, qual é o próximo estado? ') for symbol in symbols]
                   for state in states]

    num_delta = [[states.index(state) if state in states else -1 for state in row ] for row in alpha_delta]

    print(f'\nAlfabeto -> {symbols}')
    print(f'Estados -> {states}')
    print(f'Estado inicial -> {initial_state}')
    print(f'Estados finais -> {final_states}')

    print('\nMatriz alfa de transição')
    for row in alpha_delta:
        print(row)

    print('\nMatriz numérica de transição')
    for row in num_delta:
        print(row)

    print('\nLinguagem\n')
    for i in range(len(states)):
        for j in range(len(symbols)):
            print(f'Para o estado {states[i]} e o símbolo {symbols[j]}, o próximo estado é {alpha_delta[i][j]}')

    automaton_name = input('Insira o nome do autômato: ')

    with open(f'{automaton_name}.c', 'w+') as automaton:
        automaton.write('#include <stdio.h>')
        automaton.write('\n#include <stdlib.h>')
        automaton.write('\n#include <conio.h>\n\n')

        automaton.write('int p = 0;\n')
        automaton.write('char fita[255];\n')
        for state in states:
            automaton.write(f'void {state}();\n')

        automaton.write(f'void aceita();\n')
        automaton.write(f'void rejeita();\n')

        automaton.write('\n\nint main(){\n\n')
        automaton.write(f'{set_level(1)}gets(fita);\n')
        automaton.write(f'{set_level(1)}{initial_state}();\n')
        automaton.write(f'{set_level(1)}return 0;\n')
        automaton.write('}\n')

        for line in range(len(states)):
            automaton.write(f'\nvoid {states[line]}(){"{"}\n')
            for col in range(len(symbols)):
                if num_delta[line][col] != -1:
                    if col == 0:
                        automaton.write(f'\n{set_level(1)}if(fita[p] == \'{symbols[col]}\'){"{"}\n') # Identação regular
                        automaton.write(f'{set_level(2)}p++;\n')
                        automaton.write(f'{set_level(2)}{states[num_delta[line][col]]}();\n')
                        automaton.write(f'{set_level(1)}{"}"}\n')
                    else:
                        automaton.write(f'\n{set_level(1)}else')
                        automaton.write(f'\n{set_level(2)}if(fita[p] == \'{symbols[col]}\'){"{"}\n') # Identação +1
                        automaton.write(f'{set_level(3)}p++;\n')
                        automaton.write(f'{set_level(3)}{states[num_delta[line][col]]}();\n')
                        automaton.write(f'{set_level(2)}{"}"}\n')



            if states[line] in final_states:
                automaton.write(f'{set_level(1)}else\n')
                automaton.write(f'{set_level(2)}if(fita[p] == \'\\0\'){"{"}\n')
                automaton.write(f'{set_level(3)}aceita();\n')
                automaton.write(f'{set_level(2)}{"}"}')

            automaton.write(f'\n{set_level(1)}else{"{"}\n')
            automaton.write(f'{set_level(2)}rejeita();\n')



            automaton.write(f'{set_level(1)}{"}"}\n{"}"}')

        automaton.write('\nvoid aceita(){\n')
        automaton.write(f'\n{set_level(1)}printf("ACEITO");\n')
        automaton.write(f'{set_level(1)}exit(0);\n')
        automaton.write('}\n')

        automaton.write('\nvoid rejeita(){\n')
        automaton.write(f'\n{set_level(1)}printf("REJEITADO");\n')
        automaton.write(f'{set_level(1)}exit(-1);\n')
        automaton.write('}\n')
