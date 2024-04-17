#include <stdio.h>
#include <stdlib.h>

void clook(int *requests, int n, int head) {
int total_head_movements = 0;
int min_request = 0;
int max_request = 199;
int i, j;

for (i = 0; i < n - 1; i++) {
for (j = 0; j < n - i - 1; j++) {
if (requests[j] > requests[j + 1]) {
int temp = requests[j];
requests[j] = requests[j + 1];
requests[j + 1] = temp;
}
}
}
for (i = 0; i < n; i++) {
if (requests[i] >= head) {
min_request = i;
break;
}
}
printf("Sequence of disk head movement:\n");
for (i = min_request; i < n; i++) {
printf("%d ", requests[i]);
total_head_movements += abs(head - requests[i]);
head = requests[i];
}
for (i = 0; i < min_request; i++) {
printf("%d ", requests[i]);
total_head_movements += abs(head - requests[i]);
head = requests[i];
}

printf("\nTotal number of head movements: %d\n", total_head_movements);
}

int main() {
int n, head, i;

printf("Enter the total number of disk blocks: ");
scanf("%d", &n);
int *requests = (int *)malloc(n * sizeof(int));

printf("Enter the disk request string:\n");
for (i = 0; i < n; i++) {
scanf("%d", &requests[i]);
}

printf("Enter the current head position: ");
scanf("%d", &head);

clook(requests, n, head);

free(requests);

return 0;
}

