typedef struct LinkList
{
	int data;
	struct LinkList *next;
}Node, *pNode;

void list_init(pNode *list);

void list_h_insert(pNode *list, int data);

void list_t_insert(pNode *list, int data);

void list_show(pNode *list);
