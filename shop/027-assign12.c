/* This function prints the exixting database in binary tree using recursion */
void printTree(TREE *btree) {
	if(btree==NULL)
		return;							
	else{    
		printf("%d %s %.1lf %d %.1f\n",btree->item.itemID,btree->item.itemName,btree->item.price,btree->item.quantity,btree->item.offer);
		printTree(btree->left); 
		printTree(btree->right);
	}
}
/* This fucntion insert's 0 or 1 into the binary linked list */
NODE *insertBinaryLinkedList(NODE *node, int x) {
	NODE *top ;
	top = (NODE *) malloc (sizeof(NODE));					
	top->data = x;
	if(node==NULL) 
		top->next=NULL;
	else 
		top->next=node;
	return top;
}

/* This function creates a new node */

TREE *newNode(TREE *new,char string[]) {
	int i,j=0,count=0;
	char str[500];
	new->left=NULL;
	new->right=NULL;
	for(i=0;string[i]!='\0';i++){
		if(string[i]!=',') {
			str[j]=string[i];
			j++;
		}
		if(string[i]==',') {
			str[j]='\0';
			count++;
			//updating into new node created
			if(count==1)
				new->item.itemID=atoi(str);
			if(count==2)
				strcpy(new->item.itemName,str);
			if(count==3)
				new->item.price=atof(str);
			if(count==5)
				new->item.offer=atof(str);
			if(count==4)
				new->item.quantity=atoi(str);
			if(count==6)
				strcpy(new->item.type,str);	
			j=0;    
		}
	}
	return new;
}

/* This function inserts a new node in the tree by using binay numbering method */

TREE *insertItem(TREE *node,NODE *binary) {
TREE *root=(TREE *)malloc(sizeof(TREE));
root=head;
       if(root==NULL)
          return node; 
		binary=binary->next;
		while(binary!=NULL) {
         //if binary value of positon is equal to 0 go left and right for 1
         
			if(binary->data==1)  {
				if(binary->next==NULL)  {
					root->right=node;
              			}
				else{
					root=root->right;
				}
			}
			if(binary->data==0)  {
				if(binary->next==NULL) { 
					root->left=node;
				}
				else{
					root=root->left;
				}
			}
			binary=binary->next;
         }
   return head;
}         

/* This function creates the Binary tree by taking data from database  */

TREE *createDataSet(TREE *btree)	{
	FILE *fp1=fopen("data.txt","r");
	
	int temp,val,j=0;
	char ch,string[1000];
	NODE *binary=NULL;
	
	if(feof(fp1))
		return NULL;

	fscanf(fp1,"%c",&ch);
	
	while(!feof(fp1))  {
		while(ch!='\n') {
			string[j]=ch;
			fscanf(fp1,"%c",&ch);
			j++;
		}

		if(ch=='\n')  {
		
			TREE *node=(TREE *)malloc(sizeof(TREE));
			binary=NULL;
			string[j]='\0';
			node=newNode(node,string);
			fscanf(fp1,"%c",&ch);
			
			j=0;
			temp=number;
			//converting position to binary and creating a linked list
			while(temp!=0){
				val=temp%2;
				temp=temp/2;
				binary = insertBinaryLinkedList(binary, val);
			}
			
			head=insertItem(node,binary);
			number++;
		}
	}
	
	//fclose(fp1);			//printf("id__=%d \n",head->item.itemID);
	return head; 
}

void printingtype(char str[]) {
	printf("\n\n\t\tTHE TYPE OF ITEMS AVAILABLE\n");
	printf("Mobiles\nHeadphones\nWatches\nLaptops\nCameras\n");
	printf("ENTER THE NAME OF THE FIELD YOU WANT TO SEARCH FOR:");
	scanf("%s",str);
	changeItemName(str);
	searchType(head,str);
}
void insertinTree(char str[][100]) {
           int temp=number,val;
           NODE *binary=NULL;//(NODE *)malloc(sizeof(NODE));
           TREE *new=(TREE *)malloc(sizeof(TREE));
           new->item.itemID=atoi(str[0]);
           strcpy(new->item.itemName,str[1]);
           new->item.price=atof(str[2]);
           new->item.quantity=atoi(str[3]);
           new->item.offer=atof(str[4]);
           strcpy(new->item.type,str[5]);
           new->left=NULL;
           new->right=NULL;
 	   while(temp!=0){
	   		val=temp%2;
			temp=temp/2;
			binary = insertBinaryLinkedList(binary, val);
	    }
	    insertItem(new,binary);
            printTree(head);
}
/* Taking data and Adding new item only by Admin */
void addItem() {
	char str[10][100];
	int i; 
	FILE *fp1=fopen("data.txt","a+");
	
	printf("ENTER ITEM ID:");
	scanf("%s",str[0]);

	printf("\nENTER ITEM NAME:");
	scanf("%s",str[1]);

	printf("\nENTER ITEM PRICE:");
	scanf("%s",str[2]);

	printf("\nENTER ITEM QUANTITY:");
	scanf("%s",str[3]);

	printf("\nENTER ITEM OFFER:");
	scanf("%s",str[4]);

	printf("\nENTER ITEM TYPE:");
	scanf("%s",str[5]);
       insertinTree(str);
        for(int i=0;i<6;i++) 
        	fprintf(fp1,"%s,",str[i]);
        	  
	fclose(fp1);
}
/*  Checks Whether the user id given by user is valid or not */
int checkValidUserID(char str[]){
	int i,j;
	for(i=0;str[i]!='\0';i++){ 
		if(str[i]==' ')
			return 0;
	}     
	for(i=0;str[i]!='\0';i++) {
		if(str[i]=='@') {
			for(j=i+2;str[j]!='\0';j++) {
				if(str[j]=='.') {
					return 1;
				}
			}
		}
	}           
}

// This Creates a Login, allowing existing users to enter for Shopping  

void logIn() {
	int j,k,flag=0,h;
	char search[20];
	while(1) {
		char emailid[100],fileline[100],userid[100],password[100],*pass;
		int id;
		FILE *fp=fopen("userdetails.txt","r+");

		printf("ENTER YOUR EMAIL ID:");
		scanf("%s",emailid);
		while(fgets(fileline,sizeof(fileline),fp)!=NULL) {
			for(j=0;fileline[j]!=' ';j++) {
				userid[j]=fileline[j];
			}
			userid[j]='\0';
			if(strcmp(userid,emailid)==0) {
				pass=getpass("ENTER YOUR PASSWORD:");
				j++;k=0;
				while(fileline[j]!='\n') {
					password[k]=fileline[j];
					k++;j++;
				}
				password[k]='\0';
				if(strcmp(pass,password)==0) {
					flag=1;
					break;
				}
				else{
					printf("YOUR USER ID OR PASSWORD IS WRONG\n");
					flag=2;
					break;  
				}
			}
			else
				flag=0;
		}   
		if(flag==0)
			printf("NO SUCH USER ID EXISTS\n");           
		fclose(fp);
		if(flag==1) { 
		        char str[100],check[3];
			printingtype(str);
			searching(str);
			printf("ENTER THE ITEM ID YOU WANT TO PURCHASE:");
			scanf("%d",&id);
			Purchasing(head,id,check);
			if(strcmp(check,"n")==0) {
			printf("want to search for another product--[1]\n leave --[0]");
			scanf("%d",&h);
			if(h==0) {
			printf("Thank yOu aNd viSiT AgaIn"); exit(-1);
			}
			
			else {
			printingtype(search);
			searching(search);
			printf("ENTER THE ITEM YOU WANT TO PURCHASE:");
			scanf("%d",&id);Purchasing(head,id,check);
			}
		}
			
			break;
		}
	}
}
/*  Creating a new sign up for new users */

void signUp() {
	FILE *fp1;
	int flag;
	fp1=fopen("userdetails.txt","a+");
	while(1) {
		char str[100];
		printf("ENTER YOUR EMAIL ID:");
		scanf("%s",str);
		flag=checkValidUserID(str); 
		if(flag==0) {
			printf("INVALID USER ID\n");
		}
		if(flag==1) {
			fprintf(fp1,"%s",str);    
			break;
		}
	}
	while(1) {
		char *pass,pass1[100],pass2[100];
		pass=getpass("ENTER YOUR PASSWORD:");
		strcpy(pass1,pass);
		printf("\n");   

		pass=getpass("RE-ENTER YOUR PASSWORD:");
		strcpy(pass2,pass);  
		if(strcmp(pass1,pass2)==0) {
			fprintf(fp1," %s\n",pass1);
			printf("YOU HAVE Sucessfully Signed Up Now Login\n");
			fclose(fp1);
			break;
		}
		else {
			printf("BOTH PASSWORDS DIDN'T MATCH\n");
		}
		fp1=fopen("userdetails.txt","r+");
		logIn();
		fclose(fp1);
	}
}

/*  */

void adminLogin()  {
	int n;int p;
	while(1) {
		printf("ENTER YOUR ADMIN ID:");
		char admin[100],*pass;
		scanf("%s",admin);
		if(strcmp(admin,"iiits@iiits.in")==0) {
			pass=getpass("ENTER YOUR PASSWORD:");
			if(strcmp(pass,"iiits@123")==0) {
				printf("1.MODIFY\n2.SEARCH\n3.ADD ITEM\n");
				scanf("%d",&n);
				switch(n) { 
					case 1:
						modify();
						break;
					case 2:
						search();
						break;
					case 3:
						addItem();
						printf("Want to add another Item..? yes=1 no=0\n");
						scanf("%d",&p);
						if(p==1) addItem();
						else printf("Thank you ...!\n");
						break;
				}
				break;
			}
			else
				printf("INCORRECT PASSWORD\n");
		}
		else
			printf("YOU ARE NOT ADMIN\n");
	}  
}
