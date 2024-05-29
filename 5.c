#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct Event {
    char name;
    int start;
    int end;
};

int compare(const void *a, const void *b) {
    return ((struct Event*)a)->end - ((struct Event*)b)->end;
}

int interval_scheduling(struct Event *events, int n) {
    qsort(events, n, sizeof(struct Event), compare);

    struct Event *schedule = malloc(n * sizeof(struct Event));
    if (schedule == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }

    int schedule_index = 0;
    int last_end_time = INT_MIN;

    for (int i = 0; i < n; i++) {
        if (events[i].start >= last_end_time) {
            schedule[schedule_index++] = events[i];
            last_end_time = events[i].end;
        }
    }

    printf("Schedule:\n");
    for (int i = 0; i < schedule_index; i++) {
        printf("%c\t%d\t%d\n", schedule[i].name, schedule[i].start, schedule[i].end);
    }

    free(schedule);

    return schedule_index;
}

int main() {
    printf("Sameeksha Gupta 22BCP343\n");

    int n;
    printf("Enter the number of events: ");
    scanf("%d", &n);

    struct Event *events = malloc(n * sizeof(struct Event));
    if (events == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }

    printf("Enter the events in the format (name start_time end_time):\n");
    for (int i = 0; i < n; i++) {
        scanf(" %c %d %d", &events[i].name, &events[i].start, &events[i].end);
    }

    int max_events = interval_scheduling(events, n);
    printf("Maximum number of events that can be scheduled: %d\n", max_events);

    free(events);

    return 0;
}
