#include <stdio.h>

void towerOfHanoi(int n, char source, char middle, char destination) {
    // Base case: If there's only one disk, move it directly from source to destination
    if (n == 1) {
        printf("Move disk 1 from %c to %c\n", source, destination);
        return;
    }

    // Move top n-1 disks from source to middle, using destination as a temporary rod
    towerOfHanoi(n - 1, source, destination, middle);

    // Move the nth disk from source to destination
    printf("Move disk %d from %c to %c\n", n, source, destination);

    // Move the n-1 disks from middle to destination, using source as a temporary rod
    towerOfHanoi(n - 1, middle, source, destination);
}

int main() {
    int n = 3;  // Number of disks
    printf("Solution for Tower of Hanoi with %d disks:\n", n);
    towerOfHanoi(n, 'A', 'B', 'C');  // 'A' is source, 'B' is middle, 'C' is destination
    return 0;
}
