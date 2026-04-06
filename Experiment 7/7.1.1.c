#include <stdio.h>
#include <stdlib.h>

struct Node {
	int data;
	struct Node *left, *right;
};

struct Node* createNode(int data) {
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->data = data;
	newNode->left = newNode->right = NULL;
	return newNode;
}

struct Node* insertNode(struct Node* root, int data) {
	if (root == NULL)
		return createNode(data);

	if (data < root->data)
		root->left = insertNode(root->left, data);
	else
		root->right = insertNode(root->right, data);

	return root;
}

void inorderTraversal(struct Node* root) {
	if (root != NULL) {
		inorderTraversal(root->left);
		printf("%d ", root->data);
		inorderTraversal(root->right);
	}
}

void preorderTraversal(struct Node* root) {
	if (root != NULL) {
		printf("%d ", root->data);
		preorderTraversal(root->left);
		preorderTraversal(root->right);
	}
}

void postorderTraversal(struct Node* root) {
	if (root != NULL) {
		postorderTraversal(root->left);
		postorderTraversal(root->right);
		printf("%d ", root->data);
		}
}

struct Node* findMin(struct Node* root) {
		while (root && root->left != NULL)
		root = root->left;
		return root;
}

struct Node* deleteNode(struct Node* root, int data, int *found) {
		if (root == NULL)
		return NULL;

		if (data < root->data) {
	root->left = deleteNode(root->left, data, found);
	} else if (data > root->data) {
		root->right = deleteNode(root->right, data, found);
	} else {
	*found = 1;

	if (root->left == NULL) {
	struct Node* temp = root->right;
	free(root);
	return temp;
		} else if (root->right == NULL) {
			struct Node* temp = root->left;
			free(root);
			return temp;
		}

		struct Node* temp = findMin(root->right);
		root->data = temp->data;
		root->right = deleteNode(root->right, temp->data, found);
		}
		return root;
}
int main() {
		struct Node* root = NULL;
		int choice, data;

		 while (1) {
			printf("1. Insert Node\n");
			printf("2. In-Order Traversal\n");
			printf("3. Pre-Order Traversal\n");
			printf("4. Post-Order Traversal\n");
			printf("5. Delete Node\n");
			printf("6. Exit\n");
			printf("Choice: ");

			if (scanf("%d", &choice) != 1) {
		while (getchar() != '\n');
		continue;
		}

		switch (choice) {
			case 1:
				printf("Data: ");
				scanf("%d", &data);
				root = insertNode(root, data);
				break;

			case 2:
				if (root == NULL)
					printf("The tree is empty\n");
				else {
					inorderTraversal(root);
					printf("\n");
				}
				break;

			case 3:
				if (root == NULL)
					printf("The tree is empty\n");
				else {
					preorderTraversal(root);
					printf("\n");
					}
				    break;

			case 4:
				if (root == NULL)
					printf("The tree is empty\n");
				else {
					postorderTraversal(root);
					printf("\n");
				}
				break;

				case 5: {
					printf("Delete: ");
					scanf("%d", &data);
					int found = 0;
					root = deleteNode(root, data, &found);
					if (!found)
					printf("Value not found\n");
					break;
			}

			case 6:
			return 0;

			default:
			printf("Invalid choice\n");
		}
	}

	return 0;
}