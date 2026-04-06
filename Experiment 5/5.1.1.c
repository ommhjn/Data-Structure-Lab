#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int data;
	struct node *next;
} *NODE;

NODE getnode(int data) {
	NODE newnode = (NODE)malloc(sizeof(struct node));
	newnode->data = data;
	newnode->next = NULL;
	return newnode;
}

int count(NODE first) {
	if (first == NULL) return 0;

	int cnt = 0;
	NODE temp = first;
	do {
		cnt++;
		temp = temp->next;
	} while (temp != first);

	return cnt;
}

NODE create(NODE first) {
	int n, data;
	printf("How many nodes? ");
	scanf("%d", &n);

	if (n <= 0) return NULL;

	NODE last = NULL;

	for (int i = 0; i < n; i++) {
		scanf("%d", &data);
		NODE newnode = getnode(data);

		if (first == NULL) {
			first = newnode;
			last = newnode;
		} else {
			last->next = newnode;
			last = newnode;
		}
	}

	last->next = first;
	return first;
}

NODE insert(NODE first) {
	int pos, data;

	printf("Position: ");
	scanf("%d", &pos);

	printf("Element: ");
	scanf("%d", &data);

	int n = count(first);

	if (pos <= 0 || pos > n + 1) {
		printf("Position not found\n");
		return first;
	}

	NODE newnode = getnode(data);

	if (first == NULL) {
		newnode->next = newnode;
		return newnode;
	}

	if (pos == 1) {
		NODE last = first;
		while (last->next != first)
			last = last->next;

		newnode->next = first;
		last->next = newnode;
		return newnode;
	}

	NODE temp = first;
	for (int i = 1; i < pos - 1; i++)
		temp = temp->next;

	newnode->next = temp->next;
	temp->next = newnode;

	return first;
}

NODE deleteNode(NODE first) {
	if (first == NULL) {
		printf("CLL is empty\n");
		return NULL;
	}

	int pos;
	printf("Position: ");
	scanf("%d", &pos);

	int n = count(first);

	if (pos < 1 || pos > n) {
		printf("Position not found\n");
		return first;
	}

	if (n == 1) {
		printf("Deleted element: %d\n", first->data);
		free(first);
		return NULL;
	}

	NODE temp = first, prev = NULL;

	if (pos == 1) {
		NODE last = first;
		while (last->next != first)
			last = last->next;

		printf("Deleted element: %d\n", first->data);
		last->next = first->next;
		NODE newfirst = first->next;
		free(first);
		return newfirst;
	}

	for (int i = 1; i < pos; i++) {
		prev = temp;
		temp = temp->next;
	}

	printf("Deleted element: %d\n", temp->data);
	prev->next = temp->next;
	free(temp);

	return first;
}

void display(NODE first) {
	if (first == NULL) {
		printf("CLL is empty\n");
		return;
	}

	printf("Elements in CLL are: ");
	NODE temp = first;

	do {
		printf("%d -> ", temp->data);
		temp = temp->next;
	} while (temp != first);

	printf("\n");
}

NODE reverse(NODE first) {
	if (first == NULL) {
		printf("CLL is empty\n");
		return NULL;
	}

	if (first->next == first) {
		printf("CLL reversed\n");
		printf("%d -> \n", first->data);
		return first;
	}

	NODE prev = NULL, curr = first, next = NULL;
	NODE last = first;

	while (last->next != first)
		last = last->next;

	do {
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	} while (curr != first);

	first->next = prev;
	first = prev;

	printf("CLL reversed\n");

	NODE temp = first;
	do {
		printf("%d -> ", temp->data);
		temp = temp->next;
	} while (temp != first);

	printf("\n");

	return first;
}

NODE concat(NODE first) {
	printf("Creating second CLL to concatenate...\n");

	int n, data;
	printf("How many nodes in second CLL? ");
	scanf("%d", &n);

	if (n <= 0) return first;

	NODE second = NULL, last2 = NULL;

	for (int i = 0; i < n; i++) {
		scanf("%d", &data);
		NODE newnode = getnode(data);

		if (second == NULL) {
			second = newnode;
			last2 = newnode;
		} else {
			last2->next = newnode;
			last2 = newnode;
		}
	}

	last2->next = second;

	if (first == NULL) {
		printf("Concatenated CLL:\n");
		NODE temp = second;
		do {
			printf("%d -> ", temp->data);
			temp = temp->next;
		} while (temp != second);
		printf("\n");
		return second;
	}

	NODE last1 = first;
	while (last1->next != first)
		last1 = last1->next;

	last1->next = second;
	last2->next = first;

	printf("Concatenated CLL:\n");
	NODE temp = first;
	do {
		printf("%d -> ", temp->data);
		temp = temp->next;
	} while (temp != first);
	printf("\n");

	return first;
}

int main() {
	NODE first = NULL;
	int choice;

	while (1) {
		printf("1.Create 2.Insert 3.Delete 4.Display 5.Reverse 6.Concat 7.Exit\n");
		printf("choice: ");
		scanf("%d", &choice);

		switch (choice) {
			case 1:
				first = create(first);
				break;
			case 2:
				first = insert(first);
				break;
			case 3:
				first = deleteNode(first);
				break;
			case 4:
				display(first);
				break;
			case 5:
				first = reverse(first);
				break;
			case 6:
				first = concat(first);
				break;
			case 7:
				exit(0);
		}
	}
}