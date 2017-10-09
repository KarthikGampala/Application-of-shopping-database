//creating the item structure
typedef struct ITEM{
int itemID;
char itemName[500];
double price;
float offer;
int quantity;
char type[100];
}ITEM;
//creating the tree strucure
typedef struct TREE{
ITEM item;
struct TREE *left;
struct TREE *right;
}TREE;
//creating the node structure 
typedef struct node{
	int data;
	struct node *next;
}NODE;
TREE *head;
int number=1;
/* Changes the first chracter of the search to UPPER CASE and remaining to lower case */
void changeItemName(char str[100])  {
int i;
	if(str[0]>='a' && str[0]<='z') {
		str[0]=str[0]-32;
	}
	for(i=1;i<strlen(str);i++) {
			
		if(str[i]<'a' && str[i]>='A') {
			str[i]=str[i]+32;
		}
	}
}

/* Checks all the item names having the searching string as substring*/
int isSubString(char str1[30],char str2[30]) {
	int i,j,flag=1;
	int count1=strlen(str1);
	int count2=strlen(str2);
	for(i=0;i<strlen(str1);i++) {
		if(str1[i]!=str2[i]) {
			flag=0;
			break;
		}
		
	}
	if(flag==1)
		return 1;
	else
		return 0;
		    
}
/* Searching items by its Type*/
void searchType(TREE *btree,char str[]) {
	if(btree!=NULL) {	
		if(strcmp(str,btree->item.type)==0) {		
			printf("product ID:%d\nproductName:%s\nProductcost: %.1lf\nProduct availability %d\nProduct offer:%.1f\n",btree->item.itemID,btree->item.itemName,btree->item.price,btree->item.quantity,btree->item.offer);
			printf("---------------------\n");
		}
		searchType(btree->left,str);
		searchType(btree->right,str);
	}
}
int count;

/*Searching By Item ID*/
void searchByItemId(TREE *btree,int ItemId)   {
	if(btree!=NULL) {
		searchByItemId(btree->left,ItemId);
		if(btree->item.itemID==ItemId) {
			printf("ITEM FOUND WITH ITEMID=%d:\n",ItemId);
			printf("product ID:%d\nproductName:%s\nProductcost: %.1lf\nProduct availability %d\nProduct offer:%.1f\n",btree->item.itemID,btree->item.itemName,btree->item.price,btree->item.quantity,btree->item.offer);
			printf("---------------------\n");
			count=1;
		}
		searchByItemId(btree->right,ItemId);
	}
}
/* Searchin the products by item Name */
void searchByItemName(TREE *btree,char itemName[])   {
	if(btree!=NULL){	
		if(isSubString(itemName,btree->item.itemName)==1) {
			printf("product ID:%d\nproductName:%s\nProductcost: %.1lf\nProduct availability %d\nProduct offer:%.1f\n",btree->item.itemID,btree->item.itemName,btree->item.price,btree->item.quantity,btree->item.offer);
			printf("---------------------\n");
			count=2;
		}
		searchByItemName(btree->left,itemName);
		searchByItemName(btree->right,itemName);
	}
}
/* Searching products Based on Price */
void searchByPrice(TREE *btree,float price)  {	
	if(btree!=NULL) {
		searchByPrice(btree->left,price);
		if(btree->item.price<=price){	
			printf("product ID:%d\nproductName:%s\nProductcost: %.1lf\nProduct availability %d\nProduct offer:%.1f\n",btree->item.itemID,btree->item.itemName,btree->item.price,btree->item.quantity,btree->item.offer);
			printf("---------------------\n");
			count=3;
		}
		searchByPrice(btree->right,price);
	}
}
//searching based on quantity
void searchByquantity(TREE *btree,int quantity) {
	if(btree!=NULL) {
		searchByquantity(btree->left,quantity);
		if(btree->item.quantity>=quantity) {
			printf("%d ITEMS ARE AVILABLE OF THIS COMPANY:\n",quantity);
			printf("product ID:%d\nproductName:%s\nProductcost: %.1lf\nProduct availability %d\nProduct offer:%.1f\n",btree->item.itemID,btree->item.itemName,btree->item.price,btree->item.quantity,btree->item.offer);
			printf("---------------------\n");
			count=4;
		}
		searchByquantity(btree->right,quantity);
	}
}
//seartching based on offer
void searchByOffer(TREE *btree,float offer) {
	if(btree!=NULL) {
		searchByOffer(btree->left,offer);
		if(btree->item.offer>=offer) {	
			printf("product ID:%d\nproductName:%s\nProductcost: %.1lf\nProduct availability %d\nProduct offer:%.1f\n",btree->item.itemID,btree->item.itemName,btree->item.price,btree->item.quantity,btree->item.offer);
			printf("---------------------\n");
			count=5;
		}
		searchByOffer(btree->right,offer);
	}
}

void news(TREE *head,int itemid)
{
	searchByItemId(head,itemid);
	if(count!=1)
    		printf("\tNOT FOUND ANY ITEM\n");
}
/* Options for user  and Searching based on user's option  */
void search() {
	int a,ItemId,quantity;
	char itemName[30];
   	float price,offer;
   printf("On What Basis Do You Want To Search For:\n");
   printf("Based on ItemId---->press 1\n");
    printf("Based on ItemName---->press 2\n");
    printf("Based on Price---->press 3\n");
    printf("Based on quantity---->press 4\n");
    printf("Based on offer---->press 5\n");
    printf("ENTER YOUR OPTION:");
    scanf("%d",&a);
    switch(a){
    	case 1:
    		printf("Enter The Id Of The Item You Want:");
    		scanf("%d",&ItemId);
    		searchByItemId(head,ItemId);
    		if(count!=1)
    		printf("\tNOT FOUND ANY ITEM\n");
    		break;
    	case 2:
    		printf("enter the name of item you want:");
   		scanf("%s",itemName);
   		changeItemName(itemName);
   		printf("ITEM FOUND WITH ITEMNAME=%s:\n",itemName);
   		searchByItemName(head,itemName);
   		if(count!=2)
    		printf("\tNOT FOUND ANY ITEM\n");
    		break;
    	case 3:
    		printf("enter the price of item you want:");
    		scanf("%f",&price);
    		printf("ITEM FOUND WHOSE PRICE IS LESS THAN %.1lf:\n",price);
    		searchByPrice(head,price);
    		if(count!=3)
    		printf("\tNOT FOUND ANY ITEM\n");
   		break;
   	case 4:
   		printf("enter the no of items of same company you want:");
   		scanf("%d",&quantity);
   		printf("%d items are present of below company\n",quantity);
   		searchByquantity(head,quantity);
   		if(count!=4)
    		printf("\tNOT FOUND ANY ITEM\n");
   		break;
   	case 5:
   		printf("enter the offer of the item of you want:");
   		scanf("%f",&offer);
   		printf("Below items are having the offer above or equal to %.1f\n",offer);
   		searchByOffer(head,offer);
   		if(count!=5)
    		printf("\tNOT FOUND ANY ITEM\n");
   		break;
   	}
}
void searchByItemIdType(TREE *btree,int ItemId,char str[])   {
	if(btree!=NULL) {
		searchByItemIdType(btree->left,ItemId,str);
		if(strcmp(str,btree->item.type)==0) {
		    if(btree->item.itemID==ItemId) {
			 printf("ITEM FOUND WITH ITEMID=%d:\n",ItemId);
			 printf("product ID:%d\nproductName:%s\nProductcost: %.1lf\nProduct availability %d\nProduct offer:%.1f\n",btree->item.itemID,btree->item.itemName,btree->item.price,btree->item.quantity,btree->item.offer);
			 printf("---------------------\n");
			 count=1;
	        	}
		}
		searchByItemIdType(btree->right,ItemId,str);
	}
}
/* Searchin the products by item Name */
void searchByItemNameType(TREE *btree,char itemName[],char str[])   {
	if(btree!=NULL){	
	   if(strcmp(str,btree->item.type)==0) {     
		if(isSubString(itemName,btree->item.itemName)==1) {
			printf("product ID:%d\nproductName:%s\nProductcost: %.1lf\nProduct availability %d\nProduct offer:%.1f\n",btree->item.itemID,btree->item.itemName,btree->item.price,btree->item.quantity,btree->item.offer);
			printf("---------------------\n");
			count=2;
		}
	   }
		searchByItemNameType(btree->left,itemName,str);
		searchByItemNameType(btree->right,itemName,str);
	}
}
/* Searching products Based on Price */
void searchByPriceType(TREE *btree,float price,char str[])  {	
	if(btree!=NULL) {
	
		searchByPriceType(btree->left,price,str);
		if(strcmp(str,btree->item.type)==0) {
            		if(btree->item.price<=price){	
		        	printf("product ID:%d\nproductName:%s\nProductcost: %.1lf\nProduct availability %d\nProduct offer:%.1f\n",btree->item.itemID,btree->item.itemName,btree->item.price,btree->item.quantity,btree->item.offer);
			printf("---------------------\n");
			count=3;
		}
		}
		searchByPriceType(btree->right,price,str);
	}
}
//searching based on quantity
void searchByquantityType(TREE *btree,int quantity,char str[]) {
	if(btree!=NULL) {
		searchByquantityType(btree->left,quantity,str);
		if(strcmp(str,btree->item.type)==0) {
		  if(btree->item.quantity>=quantity) {
			printf("%d ITEMS ARE AVILABLE OF THIS COMPANY:\n",quantity);
			printf("product ID:%d\nproductName:%s\nProductcost: %.1lf\nProduct availability %d\nProduct offer:%.1f\n",btree->item.itemID,btree->item.itemName,btree->item.price,btree->item.quantity,btree->item.offer);
			printf("---------------------\n");
			count=4;
		}
	       }
		searchByquantityType(btree->right,quantity,str);
	}
}
//seartching based on offer
void searchByOfferType(TREE *btree,float offer,char str[]) {
	if(btree!=NULL) {
		searchByOfferType(btree->left,offer,str);
		if(strcmp(str,btree->item.type)==0) {
		if(btree->item.offer>=offer) {	
			printf("product ID:%d\nproductName:%s\nProductcost: %.1lf\nProduct availability %d\nProduct offer:%.1f\n",btree->item.itemID,btree->item.itemName,btree->item.price,btree->item.quantity,btree->item.offer);
			printf("---------------------\n");
			count=5;
		}
	     }	
		searchByOfferType(btree->right,offer,str);
	}
}
void searching(char str[]) {
                   
 	int a,ItemId,quantity;
	char itemName[30];
   	float price,offer;
   printf("On What Basis Do You Want To Search For:\n");
   printf("Based on ItemId---->press 1\n");
    printf("Based on ItemName---->press 2\n");
    printf("Based on Price---->press 3\n");
    printf("Based on quantity---->press 4\n");
    printf("Based on offer---->press 5\n");
    printf("ENTER YOUR OPTION:");
    scanf("%d",&a);
    switch(a){
    	case 1:
    		printf("Enter The Id Of The Item You Want:");
    		scanf("%d",&ItemId);
    		searchByItemIdType(head,ItemId,str);
    		if(count!=1)
    		printf("\tNOT FOUND ANY ITEM\n");
    		break;
    	case 2:
    		printf("enter the name of item you want:");
   		scanf("%s",itemName);
   		changeItemName(itemName);
   		printf("ITEM FOUND WITH ITEMNAME=%s:\n",itemName);
   		searchByItemNameType(head,itemName,str);
   		if(count!=2)
    		printf("\tNOT FOUND ANY ITEM\n");
    		break;
    	case 3:
    		printf("enter the price of item you want:");
    		scanf("%f",&price);
    		printf("ITEM FOUND WHOSE PRICE IS LESS THAN %.1lf:\n",price);
    		searchByPriceType(head,price,str);
    		if(count!=3)
    		printf("\tNOT FOUND ANY ITEM\n");
   		break;
   	case 4:
   		printf("enter the no of items of same company you want:");
   		scanf("%d",&quantity);
   		printf("%d items are present of below company\n",quantity);
   		searchByquantityType(head,quantity,str);
   		if(count!=4)
    		printf("\tNOT FOUND ANY ITEM\n");
   		break;
   	case 5:
   		printf("enter the offer of the item of you want:");
   		scanf("%f",&offer);
   		printf("Below items are having the offer above or equal to %.1f\n",offer);
   		searchByOfferType(head,offer,str);
   		if(count!=5)
    		printf("\tNOT FOUND ANY ITEM\n");
   		break;
   	//case default:
   			//printf("")
   	}
}
