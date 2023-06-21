//Compute Total Seconds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

unsigned long computeTotalSeconds(char* timeString) {
    char* token = strtok(timeString, ":");
    unsigned long hours = strtoul(token, NULL, 10);

    token = strtok(NULL, ":");
    unsigned long minutes = strtoul(token, NULL, 10);

    token = strtok(NULL, ":");
    unsigned long seconds = strtoul(token, NULL, 10);

    unsigned long totalSeconds = (hours * 3600) + (minutes * 60) + seconds;
    return totalSeconds;
}

int main() {
    char timeString[] = "10:12:50";
    printf("Input Time String: %s\n", timeString);

    unsigned long totalSeconds = computeTotalSeconds(timeString);

    printf("Total Seconds: %lu\n", totalSeconds);

    return 0;
}
