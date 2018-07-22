#include "As4_header.h"


typedef struct TreeNode {
	DATA key;
	struct TreeNode *left;
	struct TreeNode *right;
}TreeNode, *PTNode;

typedef struct TreeManager {
	
	PTNode root;
	int size;
	//pointer too specif func
	COMPARE_KEYS CompareKeysFunc;
	PRINT_KEY PrintKeyFunc;
	DEL_KEY DelKeyFunc;
} TreeManager;



//private imp functions
PTNode InitNode(PTManager manager, DATA key)	//setting new node
{
	PTNode temp;
	if (NULL == (temp = (PTNode)malloc(sizeof(TreeNode)))) {
		printf("No memory for malloc(new node)\n");
		FreeFullTree(manager);
		exit(1);
	}
	temp->key = key;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}

int HightOfNode(PTNode tree)
{
	int left, right;
	if (tree == NULL)
		return -1;
	return (left = HightOfNode(tree->left) + 1) > (right = HightOfNode(tree->right) + 1) ? left : right;
}

void InOrderPrintRecursive(PTNode root, PRINT_KEY PrintKeyFunc)
{
	if (root == NULL) return;
	InOrderPrintRecursive(root->left, PrintKeyFunc);
	PrintKeyFunc(root->key);
	putch(' ');
	InOrderPrintRecursive(root->right, PrintKeyFunc);
}

void PrintKHighestRecursive(PTNode root, PRINT_KEY PrintKeyFunc,int *k)
{
	if (root == NULL)return;
		PrintKHighestRecursive(root->right, PrintKeyFunc, k);
		if (*k > 0) {
			PrintKeyFunc(root->key);
			putch(' ');
			(*k)--;
			PrintKHighestRecursive(root->left, PrintKeyFunc, k);
		}
}

void FreeSubRecursive(PTNode root, DEL_KEY delete)
{
	if (root == NULL) return;
	FreeSubRecursive(root->left, delete);
	FreeSubRecursive(root->right, delete);
	delete(root->key);
	free(root);
}


//interface implementation
PTManager InitManager(
	COMPARE_KEYS CompareKeysFunc,
	PRINT_KEY PrintKeyFunc,
	DEL_KEY DelKeyFunc)
{
	PTManager manager;
	if (NULL == CompareKeysFunc || NULL == PrintKeyFunc || NULL == DelKeyFunc) {
		printf("their was missing a function too set manager\n");
		return NULL;
	}

	if (NULL == (manager = (PTManager)malloc(sizeof(TreeManager)))) {
		printf("No memory for malloc(too Manager)\n");
		exit(1);
	}
	manager->root = NULL;
	manager->CompareKeysFunc = CompareKeysFunc;
	manager->PrintKeyFunc = PrintKeyFunc;
	manager->DelKeyFunc = DelKeyFunc;
	manager->size = 0;
	return manager;
}

void AddNode(PTManager manager, DATA key)
{
	PTNode temp, *curNode;
	if (NULL == key) {
		printf("their was no data sent too set new node\n");
		return;
	}
	temp = InitNode(manager,key);
	curNode = &(manager->root);
	while (*curNode != NULL) {			//search a good place to place it
		RESULT_CMP result = manager->CompareKeysFunc(key, (*curNode)->key);
		if (result == EQUAL) {
			printf("the key: ");
			manager->PrintKeyFunc(key);
			printf(" have been enter before (didn't added again)\n");
			manager->DelKeyFunc(temp->key);		//single free
			free(temp);
			return;								//most have return too not assign
		} else if (result == BIGGER) {			//very important too change only the address that curr pointing*
			curNode = &((*curNode)->right);
		} else if (result == SMALLER){
			curNode = &((*curNode)->left);
		}
	}
	manager->size++;
	*curNode = temp;
}

void PrintInorder(PTManager manager)
{
	if (manager->size == 0) {
		printf("their is no values in the tree\n");
		return;
	}
	InOrderPrintRecursive(manager->root, manager->PrintKeyFunc);
	putch('\n');
}

int HightKey(PTManager manager, DATA key)
{
	PTNode curNode = manager->root;
	while (curNode != NULL) {
		RESULT_CMP result = manager->CompareKeysFunc(curNode->key, key);
		if (result == BIGGER) { //curnode key is bigger
			curNode = curNode->left;
		} else if (result == SMALLER) {
			curNode = curNode->right;
		} else if (result == EQUAL) {
			int hight = HightOfNode(curNode);
			return hight;							//we found it we can exit from func
		}
	}
	return -2;
}

void HighestKey(PTManager manager)
{
	DATA highest;
	PTNode curNode = manager->root;
	if (manager->size == 0) {
		printf("their is no values in the tree\n");
		return;
	}
	while (curNode != NULL) {
		highest = curNode->key;
		curNode = curNode->right;
	}
	printf("the highest value key is ");
	manager->PrintKeyFunc(highest);
	putch('\n');
}

void PrintKHighest(PTManager manager, int k)
{		
	if (manager->size == 0) {
		printf("their is no values in the tree\n");
		return;
	}
	if (k > manager->size) {
		printf("you enter bigger number then their is in the tree\n");
		return;
	}
	printf("the largest %d values in the tree: ",k);
	PrintKHighestRecursive(manager->root, manager->PrintKeyFunc, &k);	//we got a copy of k we can change it
	putch('\n');
}


void FreeFullTree(PTManager manager)
{
	printf("free the tree!!\n");
	FreeSubRecursive(manager->root, manager->DelKeyFunc);
	manager->root = NULL;
	free(manager);				//my biggest mistake forgetting to free manager 
}