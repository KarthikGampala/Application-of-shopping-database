/* Printing Tree's ItemID ,Item name,Item Name, Item price,Item quantity,item  */
void printingTree(TREE *btree) {
   if(btree==NULL)
     return;
   else{    
     printf("%d %s %.1lf %d %.1f\n",btree->item.itemID,btree->item.itemName,btree->item.price,btree->item.quantity,btree->item.offer);
     printingTree(btree->left); 
     printingTree(btree->right);
     }
}

/*Inserting 0 and 1 in linked list node  */
NODE *inserting(NODE *node, int x) {
	NODE *top ;
	top = (NODE *) malloc (sizeof(NODE));
	top->data = x;
	if(node==NULL) 
		top->next=NULL;
	else 
		top->next=node;
	return top;
}
/* Swaping the Last node in binary tree with node (item Purchased) if its Quantity becomes Zero*/
void swap(TREE *h,TREE *node)  {
	TREE *temp;
	temp=(TREE *)malloc(sizeof(TREE));
	temp->item=h->item;
  	
  	h->item=node->item;
   	
  	node->item=temp->item;
}
/* Deleting the record in the file after Purchasing if its quantity becomes zero*/
void filedel(int itemID)   {
	FILE *fileptr1, *fileptr2;
    char filename[40]="data.txt",feild[10]="quantity";
    char ch,str[100],a[100],b[100][100];
    int delete_line, temp = 1;
    //open file in read mode
    fileptr1 = fopen(filename, "r");
   int i=0,count=1,j,k;
   while(fgets(a,sizeof(a),fileptr1) != NULL)
	{
		 i=0,j=0,k=0;
		while(a[i] != '\0')
		{
			if(a[i] == ',')
			{
				b[k][j] = '\0';
				j = 0;
				k++;
			}
			else
			{
				b[k][j] = a[i];
				j++;
			}
			i++;
		}
		if(itemID==atoi(b[0]))
		{
			delete_line=count;
			strcpy(str,a);
		}
		count++;
	}
      rewind(fileptr1);
    //open new file in write mode
    
    fileptr2 = fopen("replica.c", "w");
    ch = getc(fileptr1);
    while (ch != EOF)
    {
        if (ch == '\n')
           { 
           	temp++;
            }
            //except the line to be deleted
            if (temp != delete_line)
            {
                //copy all lines in file replica.c
                putc(ch, fileptr2);
            }
	ch = getc(fileptr1);
   }
    fclose(fileptr1);
    fclose(fileptr2);
    remove(filename);
    //rename the file replica.c to original name
    rename("replica.c", filename);
}

/* Deleting in binary Tree if the purchased quntity becomes 0*/
void bdel(TREE *node)  {
	//sprintf("\nentering\n");
	TREE *root=head,*tepe;
	int l=1;int val,flag=0;
	NODE *binary=NULL;
	int temp=number-1;
		while(temp!=0)
		{
			val=temp%2;
			temp=temp/2;
			binary = inserting(binary,val);
		}
		binary=binary->next;	

while(binary!=NULL)
{
         //if binary value of positon is equal to 0 go left and right for 1
			if(binary->data==1)
			{
				if(binary->next==NULL)
				{
					swap(root,node);
					flag=1;
					//root=NULL;
					
              	}
				else{
					tepe=root;
					root=root->right;
					
				}
			}
			if(binary->data==0)
			{
				if(binary->next==NULL)
                { 
					
                    swap(root,node);
                    flag=2;
                    
				}
				else{
					tepe=root;
					root=root->left;
					
				}
			}
			
				binary=binary->next;
			
         }
         printf("----------------------------\n");
         if(flag==1)
         tepe->right=NULL;

         else if(flag==2)
         tepe->left=NULL;

}
/* Modifying quantity on Purchasing in Binary Tree*/
void Modify(TREE *node)  {
  node->item.quantity-=1;
  TREE *nhead=head;
  TREE *temp;
  	char database[10]="data.txt";
  if(node->item.quantity==0)
  {
	printf("%s \n",node->item.itemName);
  	filedel(node->item.itemID);
  	bdel(node);
  	printf("\n\n\n");
  	printingTree(head);
  	
}
else  addstackindatabase(database,node->item.itemID,-1);
}

/* Function for purchasing an item by the user*/
void Purchasing(TREE *tree,int id,char check[])  {	
	if(tree==NULL) 
   		 return; 
   		 
  else {
		if(tree->item.itemID==id)
		{	
                        printf("TOTAL COST:%f",tree->item.price-(tree->item.price*(tree->item.price/100.00)));
                        printf("product ID:%d\nproductName:%s\nProductcost: %.1lf\nProduct availability %d\nProduct offer:%.1f\n",tree->item.itemID,tree->item.itemName,tree->item.price,tree->item.quantity,tree->item.offer);
		        printf("----------------------------------------------------------------------------\n");
		        printf("Do You want to purchase this item\t {y} or {n}:\t");
		        scanf("%s",check);
		        if(strcmp(check,"y")==0){
			printf("SuCceSFuLly PurChAsed,  Thank You and Visit Again\n");
		        Modify(tree);
		        }
		}
		Purchasing(tree->left,id,check);
		Purchasing(tree->right,id,check);
     }
}
