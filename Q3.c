#include <stdio.h>

void updateSectorStatus(int grid[3][3], int row, int col, int bit, int value);
void querySectorStatus(int grid[3][3], int row, int col);
void runSystemDiagnostic(int grid[3][3]);

int main() {
    int grid[3][3] = {0};
    int choice, row, col, bit, value;
    int rows = 3, cols = 3;

    while (1) {
        printf("\n===== IESCO Power Grid Monitoring System =====\n");
        printf("1. Update Sector Status\n");
        printf("2. Query Sector Status\n");
        printf("3. Run System Diagnostic\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        if (choice == 4) {
            printf("Exiting system...\n");
            break;
        }

        if (choice == 1){
            printf("Enter sector row (0-%d): ", rows - 1);
            scanf("%d", &row);
            printf("Enter sector column (0-%d): ", cols - 1);
            scanf("%d", &col);
            printf("Select flag to update:\n");
            printf("0 - Power (1=ON, 0=OFF)\n");
            printf("1 - Overload (1=Overloaded, 0=Normal)\n");
            printf("2 - Maintenance (1=Required, 0=Not required)\n");
            scanf("%d", &bit);
            printf("Enter value (1=set, 0=clear): ");
            scanf("%d", &value);

            updateSectorStatus(grid, row, col, bit, value);
        }
        else if (choice == 2) {
            printf("Enter sector row and column: ");
            scanf("%d %d", &row, &col);
            querySectorStatus(grid, row, col);
        }
        else if (choice == 3) {
            runSystemDiagnostic(grid);
        }
        else {
            printf("Invalid choice.\n");
        }
    }

    return 0;
}

void updateSectorStatus(int grid[3][3], int row, int col, int bit, int value){
    if (row < 0 || row >= 3 || col < 0 || col >= 3) {
        printf("Invalid coordinates.\n");
        return;
    }

    if (value == 1)
        grid[row][col] = grid[row][col] | (1 << bit);
    else
        grid[row][col] = grid[row][col] & (~(1 << bit));

    printf("Sector (%d,%d) updated.\n", row, col);
}

void querySectorStatus(int grid[3][3], int row, int col) {
    if (row < 0 || row >= 3 || col < 0 || col >= 3){
        printf("Invalid coordinates.\n");
        return;
    }

    int status = grid[row][col];
    printf("\nStatus of Sector (%d,%d):\n", row, col);
    printf("Power: %s\n", (status & 1) ? "ON" : "OFF");
    printf("Overload: %s\n", (status & (1 << 1)) ? "YES" : "NO");
    printf("Maintenance: %s\n", (status & (1 << 2)) ? "REQUIRED" : "NOT REQUIRED");
}

void runSystemDiagnostic(int grid[3][3]) {
    int overloadCount = 0, maintenanceCount = 0;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (grid[i][j] & (1 << 1))
                overloadCount++;
            if (grid[i][j] & (1 << 2))
                maintenanceCount++;
        }
    }

    printf("\nSystem Diagnostic Report:\n");
    printf("Total overloaded sectors: %d\n", overloadCount);
    printf("Total sectors needing maintenance: %d\n", maintenanceCount);
}
