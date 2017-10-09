//function to modify price in tree
void modifypriceintree(TREE *btree,int itemid,float price) {
	if(btree!=NULL) {
		if(btree->item.itemID==itemid) {
			btree->item.price=price;
		}
		modifypriceintree(btree->left,itemid,price);
		modifypriceintree(btree->right,itemid,price);
	}	
}
//function to modify offer in tree
void modifyofferintree(TREE *btree,int itemid,float offer) {
	if(btree!=NULL)  {
		if(btree->item.itemID==itemid) {
			btree->item.offer=offer;
		}
		modifyofferintree(btree->left,itemid,offer);
		modifyofferintree(btree->right,itemid,offer);
	}	
}
//function to modify quantity in tree
void modifyquantityintree(TREE *btree,int itemid,int quantity) {
	if(btree!=NULL) {
		if(btree->item.itemID==itemid) {
			btree->item.quantity=quantity;
		}
		modifyquantityintree(btree->left,itemid,quantity);
		modifyquantityintree(btree->right,itemid,quantity);
	}	
}
//function to modify stack in tree
void addstackintree(TREE *btree,int itemid,int add) {
	if(btree!=NULL) {
		if(btree->item.itemID==itemid) {
			btree->item.quantity=btree->item.quantity+add;
		}
		addstackintree(btree->left,itemid,add);
		addstackintree(btree->right,itemid,add);
	}	
}
//function to modify price in file
void modifypriceindatabase(char filename[],int itemID,float price) {
	FILE *fileptr1, *fileptr2;
	char ch,str[200],a[100],b[100],bt[100][100],buffer[20];
	int delete_line, temp = 1,i=0,count=1,j,k;
	fileptr1 = fopen(filename, "r");
	while(fgets(a,sizeof(a),fileptr1) != NULL) {
		i=0,j=0,k=0;
		while(a[i] != ',') {
			b[j] = a[i];
			j++;
			i++;
		}
		b[j]='\0';
		if(itemID==atoi(b)) {
			delete_line=count;
			strcpy(str,a);
		}
		count++;
	}
	rewind(fileptr1);
	fileptr2 = fopen("replica.txt", "w+");
	ch = getc(fileptr1);
	while (ch != EOF) {
		if (ch == '\n') { 
			temp++;
		}
		//except the line to be deleted
		if (temp != delete_line) {
			//copy all lines in file replica.txt
			putc(ch, fileptr2);
		}
		ch = getc(fileptr1);
	}
	fclose(fileptr1);
	fclose(fileptr2);
	remove(filename);
	//rename the file replica.c to original name
	rename("replica.txt", filename);
	i=0,j=0,k=0;
	while(str[i]!='\0') {

		if(str[i] == ',') {
			bt[k][j] = '\0';
			j = 0;
			k++;
		}
		else {
			bt[k][j] = str[i];
			j++;
		}    
		i++;
	}
	snprintf(buffer, sizeof(buffer), "%.1f", price);
	strcpy(bt[2],buffer);
	fileptr1 = fopen(filename, "a+");	
	for(i=0;i<6;i++) {
		fprintf(fileptr1,"%s,",bt[i]);
	}
	fprintf(fileptr1,"\n");
	fclose(fileptr1);
}
//function to modify quantity in file
void modifyquantityindatabase(char filename[],int itemID,int quantity) {
	FILE *fileptr1, *fileptr2;
	char ch,str[200],a[100],b[100],bt[100][100],buffer[20];
	int delete_line, temp = 1,i=0,count=1,j,k;
	fileptr1 = fopen(filename, "r");
	while(fgets(a,sizeof(a),fileptr1) != NULL) {
		i=0,j=0,k=0;
		while(a[i] != ',') {
			b[j] = a[i];
			j++;
			i++;
		}
		b[j]='\0';
		if(itemID==atoi(b)) {
			delete_line=count;
			strcpy(str,a);
		}
		count++;
	}
	rewind(fileptr1);
	fileptr2 = fopen("replica.txt", "w+");
	ch = getc(fileptr1);
	while (ch != EOF) {
		if (ch == '\n') { 
			temp++;
		}
		//except the line to be deleted
		if (temp != delete_line) {
			//copy all lines in file replica.txt
			putc(ch, fileptr2);
		}
		ch = getc(fileptr1);
	}
	fclose(fileptr1);
	fclose(fileptr2);
	remove(filename);
	//rename the file replica.c to original name
	rename("replica.txt", filename);
	i=0,j=0,k=0;
	while(str[i]!='\0') {
		if(str[i] == ',') {
			bt[k][j] = '\0';
			j = 0;
			k++;
		}
		else {
			bt[k][j] = str[i];
			j++;
		}    
		i++;
	}
	snprintf(buffer, sizeof(buffer), "%d",quantity);
	strcpy(bt[3],buffer);
	fileptr1 = fopen(filename, "a+");	
	for(i=0;i<6;i++) {
		fprintf(fileptr1,"%s,",bt[i]);
	}
	fprintf(fileptr1,"\n");
	fclose(fileptr1);
}
//function to modify offer in file
void modifyofferindatabase(char filename[],int itemID,float offer) {
	FILE *fileptr1, *fileptr2;
	char ch,str[200],a[100],b[100],bt[100][100],buffer[20];
	int delete_line, temp = 1,i=0,count=1,j,k;
	fileptr1 = fopen(filename, "r");
	while(fgets(a,sizeof(a),fileptr1) != NULL) {
		i=0,j=0,k=0;
		while(a[i] != ',') {
			b[j] = a[i];
			j++;
			i++;
		}
		b[j]='\0';
		if(itemID==atoi(b)) {
			delete_line=count;
			strcpy(str,a);
		}
		count++;
	}
	rewind(fileptr1);
	fileptr2 = fopen("replica.txt", "w+");
	ch = getc(fileptr1);
	while (ch != EOF) {
		if (ch == '\n') { 
			temp++;
		}
		//except the line to be deleted
		if (temp != delete_line) {
			//copy all lines in file replica.txt
			putc(ch, fileptr2);
		}
		ch = getc(fileptr1);
	}
	fclose(fileptr1);
	fclose(fileptr2);
	remove(filename);
	//rename the file replica.c to original name
	rename("replica.txt", filename);
	i=0,j=0,k=0;
	while(str[i]!='\0') {
		if(str[i] == ',') {
			bt[k][j] = '\0';
			j = 0;
			k++;
		}
		else {
			bt[k][j] = str[i];
			j++;
		}    
		i++;
	}
	snprintf(buffer, sizeof(buffer), "%.1f",offer);
	strcpy(bt[4],buffer);
	fileptr1 = fopen(filename, "a+");	
	for(i=0;i<6;i++) {
		fprintf(fileptr1,"%s,",bt[i]);
	}
	fprintf(fileptr1,"\n");
	fclose(fileptr1);
}
//function to modify stack in file
void addstackindatabase(char filename[],int itemID,int added) {
	FILE *fileptr1, *fileptr2;
	char ch,str[200],a[100],b[100],bt[100][100],buffer[20];
	int delete_line, temp = 1,i=0,count=1,j,k,new;
	fileptr1 = fopen(filename, "r");
	while(fgets(a,sizeof(a),fileptr1) != NULL) {
		i=0,j=0,k=0;
		while(a[i] != ',') {
			b[j] = a[i];
			j++;
			i++;
		}
		b[j]='\0';
		if(itemID==atoi(b)) {
			delete_line=count;
			strcpy(str,a);
		}
		count++;
	}
	rewind(fileptr1);
	fileptr2 = fopen("replica.txt", "w+");
	ch = getc(fileptr1);
	while (ch != EOF) {
		if (ch == '\n') { 
			temp++;
		}
		//except the line to be deleted
		if (temp != delete_line) {
			//copy all lines in file replica.txt
			putc(ch, fileptr2);
		}
		ch = getc(fileptr1);
	}
	fclose(fileptr1);
	fclose(fileptr2);
	remove(filename);
	//rename the file replica.c to original name
	rename("replica.txt", filename);
	i=0,j=0,k=0;
	while(str[i]!='\0') {
		if(str[i] == ',') {
			bt[k][j] = '\0';
			j = 0;
			k++;
		}
		else {
			bt[k][j] = str[i];
			j++;
		}    
		i++;
	}
	new=atoi(bt[3])+added;
	snprintf(buffer, sizeof(buffer), "%d",new);
	strcpy(bt[3],buffer);
	fileptr1 = fopen(filename, "a+");	
	for(i=0;i<6;i++) {
		fprintf(fileptr1,"%s,",bt[i]);
	}
	fprintf(fileptr1,"\n");
	fclose(fileptr1);
}
//function to modify things on admin intrest
void modify() {
	int t,option,itemID,quantity,new;
	float price,offer;
	char database[10]="data.txt";
		printf("if you want to modify price press-----> 1\nif you want to modify quantity press-----> 2\nif you want to modify offer press-----> 3\nif you want add stack to existing itemspress---->4\n");
		scanf("%d",&option);
		if(option==1) {
			printf("enter the itemID:");
			scanf("%d",&itemID);
			printf("details of item\n");
			searchByItemId(head,itemID);
			if(count!=1) printf("NO ITEM FOUND\n");
			else {
			printf("enter the new price:RS/-");
			scanf("%f",&price);
			modifypriceintree(head,itemID,price);
			modifypriceindatabase(database,itemID,price);
			printf("sucessfully modified and here is new item properties\n");
			searchByItemId(head,itemID);
			}
		}
		else if(option==2) {
			printf("enter the itemID:");
			scanf("%d",&itemID);
			printf("details of item\n");
			searchByItemId(head,itemID);
			if(count!=1) printf("NO ITEM FOUND\n");
			else {
			printf("enter the new quantity:");
			scanf("%d",&quantity);
			modifyquantityintree(head,itemID,quantity);
			modifyquantityindatabase(database,itemID,quantity);
			printf("sucessfully modified and here is the item new properties\n");
			searchByItemId(head,itemID);
			}
		}
		else if(option==3) {
			printf("enter the itemID:");
			scanf("%d",&itemID);
			printf("details of item\n");
			searchByItemId(head,itemID);
			if(count!=1) printf("NO ITEM FOUND\n");
			else {
			printf("enter the new offer:");
			scanf("%f",&offer);
			modifyofferintree(head,itemID,offer);
			modifyofferindatabase(database,itemID,offer);
			printf("sucessfully modified and here is the item new properties\n");
			searchByItemId(head,itemID);
			}
		}
		else if(option==4) {
			printf("enter the itemID:");
			scanf("%d",&itemID);
			printf("details of item\n");
			searchByItemId(head,itemID);
			if(count!=1) printf("NO ITEM FOUND\n");
			else {
			printf("enter the stack to be added: ");
			scanf("%d",&new);
			addstackintree(head,itemID,new);
			addstackindatabase(database,itemID,new);
			printf("sucessfully added and here is the added item properties\n");
			searchByItemId(head,itemID);
			}
		}
}
