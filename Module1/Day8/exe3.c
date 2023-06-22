#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100
#define MAX_LINE_LENGTH 100

struct LogEntry {
    int entryNo;
    char sensorNo[10];
    float temperature;
    int humidity;
    int light;
    char time[9];
};

void extractData(struct LogEntry entries[], int *numEntries) {
    FILE *file = fopen("data.csv", "r");
    if (file == NULL) {
        printf("Failed to open the file.\n");
        exit(1);
    }

    char line[MAX_LINE_LENGTH];
    char *token;

    *numEntries = 0;
    while (fgets(line, sizeof(line), file) != NULL) {
        token = strtok(line, ",");
        entries[*numEntries].entryNo = atoi(token);

        token = strtok(NULL, ",");
        strcpy(entries[*numEntries].sensorNo, token);

        token = strtok(NULL, ",");
        entries[*numEntries].temperature = atof(token);

        token = strtok(NULL, ",");
        entries[*numEntries].humidity = atoi(token);

        token = strtok(NULL, ",");
        entries[*numEntries].light = atoi(token);

        token = strtok(NULL, ",");
        strcpy(entries[*numEntries].time, token);

        (*numEntries)++;
    }

    fclose(file);
}

void displayData(const struct LogEntry entries[], int numEntries) {
    printf("%-8s %-10s %-12s %-8s %-8s\n", "EntryNo", "SensorNo", "Temperature", "Humidity", "Light");
    for (int i = 0; i < numEntries; i++) {
        printf("%-8d %-10s %-12.2f %-8d %-8d\n", entries[i].entryNo, entries[i].sensorNo, entries[i].temperature,
               entries[i].humidity, entries[i].light);
    }
}

int main() {
    struct LogEntry entries[MAX_ENTRIES];
    int numEntries;

    extractData(entries, &numEntries);
    displayData(entries, numEntries);

    return 0;
}
