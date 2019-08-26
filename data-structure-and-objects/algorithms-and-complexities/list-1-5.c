
void hanoi(int num_discos, char torre_a, char torre_b, char torre_c) {
    if(num_discos  > 1) {
        hanoi(num_discos-1, torre_a, torre_c, torre_b);
        printf("Mover: %c -> %c \n", torre_a, torre_b);
        hanoi(num_discos-1, torre_c, torre_b, torre_a);
    }
    else {
        printf("Mover: %c -> %c \n", torre_a, torre_b);
    }
}

main() {
    hanoi(4, 'A', 'B', 'C');
}
